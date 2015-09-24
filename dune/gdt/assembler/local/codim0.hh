// This file is part of the dune-gdt project:
//   http://users.dune-project.org/projects/dune-gdt
// Copyright holders: Felix Schindler
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)

#ifndef DUNE_GDT_ASSEMLBER_LOCAL_CODIM0_HH
#define DUNE_GDT_ASSEMLBER_LOCAL_CODIM0_HH

#include <vector>

#include <dune/common/deprecated.hh>
#include <dune/common/dynmatrix.hh>
#include <dune/common/dynvector.hh>

#include <dune/stuff/common/memory.hh>
#include <dune/stuff/common/exceptions.hh>
#include <dune/stuff/common/parallel/threadstorage.hh>
#include <dune/stuff/common/tmp-storage.hh>
#include <dune/stuff/functions/interfaces.hh>
#include <dune/stuff/grid/walker/functors.hh>
#include <dune/stuff/grid/walker/wrapper.hh>
#include <dune/stuff/la/container/interfaces.hh>

#include <dune/gdt/discretefunction/default.hh>
#include <dune/gdt/localoperator/interface.hh>
#include <dune/gdt/localoperator/interfaces.hh>
#include <dune/gdt/localfunctional/interface.hh>
#include <dune/gdt/spaces/interface.hh>

namespace Dune {
namespace GDT {


template <class LocalVolumeTwoFormType>
class LocalVolumeTwoFormAssembler
{
  static_assert(is_local_volume_twoform<LocalVolumeTwoFormType>::value,
                "LocalVolumeTwoFormType has to be derived from LocalVolumeTwoFormInterface!");

public:
  explicit LocalVolumeTwoFormAssembler(const LocalVolumeTwoFormType& local_twoform)
    : local_volume_twoform_(local_twoform)
  {
  }

  /**
   *  \tparam T           Traits of the SpaceInterface implementation, representing the type of test_space
   *  \tparam A           Traits of the SpaceInterface implementation, representing the type of ansatz_space
   *  \tparam *d          dimDomain of test_space (* == T) or ansatz_space (* == A)
   *  \tparam *r          dimRange of test_space (* == T) or ansatz_space (* == A)
   *  \tparam *rC         dimRangeCols of test_space (* == T) or ansatz_space (* == A)
   *  \tparam EntityType  A model of Dune::Entity< 0 >
   *  \tparam M           Traits of the Dune::Stuff::LA::Container::MatrixInterface implementation, representing the
   * type of global_matrix
   *  \tparam R           RangeFieldType, i.e. double
   */
  template <class T, size_t Td, size_t Tr, size_t TrC, class A, size_t Ad, size_t Ar, size_t ArC, class EntityType,
            class M, class R>
  void assemble(const SpaceInterface<T, Td, Tr, TrC>& test_space, const SpaceInterface<A, Ad, Ar, ArC>& ansatz_space,
                const EntityType& entity, Stuff::LA::MatrixInterface<M, R>& global_matrix) const
  {
    // prepare
    const size_t rows = test_space.mapper().numDofs(entity);
    const size_t cols = ansatz_space.mapper().numDofs(entity);
    Dune::DynamicMatrix<R> local_matrix(rows, cols, 0.);
    // apply local two-form
    const auto test_base   = test_space.base_function_set(entity);
    const auto ansatz_base = ansatz_space.base_function_set(entity);
    assert(test_base.size() == rows);
    assert(ansatz_base.size() == cols);
    local_volume_twoform_.apply2(test_base, ansatz_base, local_matrix);
    // write local matrix to global
    const auto global_row_indices = test_space.mapper().globalIndices(entity);
    const auto global_col_indices = ansatz_space.mapper().globalIndices(entity);
    assert(global_row_indices.size() == rows);
    assert(global_col_indices.size() == cols);
    for (size_t ii = 0; ii < rows; ++ii) {
      const auto& local_matrix_row = local_matrix[ii];
      const size_t global_ii = global_row_indices[ii];
      for (size_t jj = 0; jj < cols; ++jj) {
        const size_t global_jj = global_col_indices[jj];
        global_matrix.add_to_entry(global_ii, global_jj, local_matrix_row[jj]);
      }
    } // write local matrix to global
  } // ... assemble(...)

private:
  const LocalVolumeTwoFormType& local_volume_twoform_;
}; // class LocalVolumeTwoFormAssembler


template <class GridViewImp, class LocalVolumeTwoFormType, class TestFunctionType, class AnsatzFunctionType,
          class FieldType>
class LocalVolumeTwoFormAccumulator : public Stuff::Grid::internal::Codim0ReturnObject<GridViewImp, FieldType>
{
  static_assert(std::is_base_of<LocalVolumeTwoFormInterface<typename LocalVolumeTwoFormType::Traits>,
                                LocalVolumeTwoFormType>::value,
                "LocalVolumeTwoFormType has to be derived from LocalVolumeTwoFormInterface!");
  static_assert(Stuff::is_localizable_function<TestFunctionType>::value,
                "TestFunctionType has to be derived from Stuff::LocalizableFunctionInterface!");
  static_assert(Stuff::is_localizable_function<AnsatzFunctionType>::value,
                "AnsatzFunctionType has to be derived from Stuff::LocalizableFunctionInterface!");

  typedef LocalVolumeTwoFormAccumulator<GridViewImp, LocalVolumeTwoFormType, TestFunctionType, AnsatzFunctionType,
                                        FieldType> ThisType;
  typedef Stuff::Grid::internal::Codim0ReturnObject<GridViewImp, FieldType> BaseType;

public:
  typedef typename BaseType::GridViewType GridViewType;
  typedef typename BaseType::EntityType EntityType;

  LocalVolumeTwoFormAccumulator(const GridViewType& grd_vw, const LocalVolumeTwoFormType& local_op,
                                const TestFunctionType& test_function, const AnsatzFunctionType& ansatz_function,
                                const Stuff::Grid::ApplyOn::WhichEntity<GridViewType>& where)
    : grid_view_(grd_vw)
    , local_operator_(local_op)
    , test_function_(test_function)
    , ansatz_function_(ansatz_function)
    , result_(0)
    , finalized_(false)
    , where_(where)
  {
  }

  LocalVolumeTwoFormAccumulator(const ThisType& other) = default;
  virtual ~LocalVolumeTwoFormAccumulator() = default;

  virtual bool apply_on(const GridViewType& grid_view, const EntityType& entity) const override final
  {
    return where_.apply_on(grid_view, entity);
  }

  virtual FieldType compute_locally(const EntityType& entity) override final
  {
    DynamicMatrix<FieldType> local_twoform_result(1, 1, 0.);
    this->local_operator_.apply2(
        *test_function_.local_function(entity), *ansatz_function_.local_function(entity), local_twoform_result);
    return local_twoform_result[0][0];
  } // ... compute_locally(...)

  virtual void apply_local(const EntityType& entity) override
  {
    *result_ += compute_locally(entity);
  }

  virtual void finalize() override
  {
    if (!finalized_) {
      finalized_result_ = result_.sum();
      finalized_result_ = grid_view_.comm().sum(finalized_result_);
      finalized_        = true;
    }
  } // ... finalize(...)

  virtual FieldType result() const override final
  {
    if (!finalized_)
      DUNE_THROW(Stuff::Exceptions::you_are_using_this_wrong, "Call finalize() first!");
    return finalized_result_;
  }

private:
  const GridViewType& grid_view_;
  const LocalVolumeTwoFormType& local_operator_;
  const TestFunctionType& test_function_;
  const AnsatzFunctionType& ansatz_function_;
  DS::PerThreadValue<FieldType> result_;
  bool finalized_;
  const Stuff::Grid::ApplyOn::WhichEntity<GridViewType>& where_;
  FieldType finalized_result_;
}; // class LocalVolumeTwoFormAccumulator


template <class GridViewType, class LocalOperatorType, class SourceType, class RangeType>
class LocalOperatorApplicator : public Stuff::Grid::internal::Codim0Object<GridViewType>
{
  static_assert(is_local_operator<LocalOperatorType>::value,
                "LocalOperatorType has to be derived from LocalOperatorInterface!");
  static_assert(Stuff::is_localizable_function<SourceType>::value,
                "SourceType has to be derived from Stuff::LocalizableFunctionInterface!");
  static_assert(is_discrete_function<RangeType>::value, "RangeType has to be a DiscreteFunctionDefault!");
  typedef Stuff::Grid::internal::Codim0Object<GridViewType> BaseType;

public:
  using typename BaseType::EntityType;

  LocalOperatorApplicator(const GridViewType& grid_view, const LocalOperatorType& local_operator,
                          const SourceType& source, RangeType& range,
                          const Stuff::Grid::ApplyOn::WhichEntity<GridViewType>& where)
    : grid_view_(grid_view)
    , local_operator_(local_operator)
    , source_(source)
    , range_(range)
    , where_(where)
  {
  }

  virtual bool apply_on(const GridViewType& grid_view, const EntityType& entity) const
  {
    return where_.apply_on(grid_view, entity);
  }

  virtual void apply_local(const EntityType& entity)
  {
    local_operator_.apply(source_, *range_.local_discrete_function(entity));
  }

private:
  const GridViewType& grid_view_;
  const LocalOperatorType& local_operator_;
  const SourceType& source_;
  RangeType& range_;
  const Stuff::Grid::ApplyOn::WhichEntity<GridViewType>& where_;
}; // class LocalOperatorApplicator


namespace LocalAssembler {


template <class LocalOperatorImp>
class DUNE_DEPRECATED_MSG("Use LocalVolumeTwoFormAssembler instead (10.09.2015)!") Codim0Matrix
{
  static_assert(
      std::is_base_of<LocalOperator::Codim0Interface<typename LocalOperatorImp::Traits>, LocalOperatorImp>::value,
      "LocalOperatorImp has to be derived from LocalOperator::Codim0Interface!");

public:
  typedef LocalOperatorImp LocalOperatorType;

  explicit Codim0Matrix(const LocalOperatorType& op)
    : localOperator_(op)
  {
  }

  const LocalOperatorType& localOperator() const
  {
    return localOperator_;
  }

private:
  static const size_t numTmpObjectsRequired_ = 1;

public:
  std::vector<size_t> numTmpObjectsRequired() const
  {
    return {numTmpObjectsRequired_, localOperator_.numTmpObjectsRequired()};
  }

  /**
   *  \tparam T           Traits of the SpaceInterface implementation, representing the type of testSpace
   *  \tparam A           Traits of the SpaceInterface implementation, representing the type of ansatzSpace
   *  \tparam *d          dimDomain of testSpace (* == T) or ansatzSpace (* == A)
   *  \tparam *r          dimRange of testSpace (* == T) or ansatzSpace (* == A)
   *  \tparam *rC         dimRangeCols of testSpace (* == T) or ansatzSpace (* == A)
   *  \tparam EntityType  A model of Dune::Entity< 0 >
   *  \tparam M           Traits of the Dune::Stuff::LA::Container::MatrixInterface implementation, representing the
   * type of systemMatrix
   *  \tparam R           RangeFieldType, i.e. double
   */
  template <class T, size_t Td, size_t Tr, size_t TrC, class A, size_t Ad, size_t Ar, size_t ArC, class EntityType,
            class M, class R>
  void assembleLocal(const SpaceInterface<T, Td, Tr, TrC>& testSpace, const SpaceInterface<A, Ad, Ar, ArC>& ansatzSpace,
                     const EntityType& entity, Dune::Stuff::LA::MatrixInterface<M, R>& systemMatrix,
                     std::vector<std::vector<Dune::DynamicMatrix<R>>>& tmpLocalMatricesContainer,
                     std::vector<Dune::DynamicVector<size_t>>& tmpIndicesContainer) const
  {
    // check
    assert(tmpLocalMatricesContainer.size() >= 1);
    assert(tmpLocalMatricesContainer[0].size() >= numTmpObjectsRequired_);
    assert(tmpLocalMatricesContainer[1].size() >= localOperator_.numTmpObjectsRequired());
    assert(tmpIndicesContainer.size() >= 2);
    // get and clear matrix
    auto& localMatrix = tmpLocalMatricesContainer[0][0];
    localMatrix *= 0.0;
    auto& tmpOperatorMatrices = tmpLocalMatricesContainer[1];
    // apply local operator (result is in localMatrix)
    localOperator_.apply(
        testSpace.base_function_set(entity), ansatzSpace.base_function_set(entity), localMatrix, tmpOperatorMatrices);
    // write local matrix to global
    auto& globalRows  = tmpIndicesContainer[0];
    auto& globalCols  = tmpIndicesContainer[1];
    const size_t rows = testSpace.mapper().numDofs(entity);
    const size_t cols = ansatzSpace.mapper().numDofs(entity);
    assert(globalRows.size() >= rows);
    assert(globalCols.size() >= cols);
    testSpace.mapper().globalIndices(entity, globalRows);
    ansatzSpace.mapper().globalIndices(entity, globalCols);
    for (size_t ii = 0; ii < rows; ++ii) {
      const auto& localRow  = localMatrix[ii];
      const size_t globalII = globalRows[ii];
      for (size_t jj = 0; jj < cols; ++jj) {
        const size_t globalJJ = globalCols[jj];
        systemMatrix.add_to_entry(globalII, globalJJ, localRow[jj]);
      }
    } // write local matrix to global
  } // ... assembleLocal(...)

private:
  const LocalOperatorType& localOperator_;
}; // class Codim0Matrix


template <class LocalFunctionalImp>
class Codim0Vector
{
  static_assert(
      std::is_base_of<LocalFunctional::Codim0Interface<typename LocalFunctionalImp::Traits>, LocalFunctionalImp>::value,
      "LocalFunctionalImp has to be derived from LocalFunctional::Codim0Interface!");

public:
  typedef LocalFunctionalImp LocalFunctionalType;

  explicit Codim0Vector(const LocalFunctionalType& func)
    : localFunctional_(func)
  {
  }

  const LocalFunctionalType& localFunctional() const
  {
    return localFunctional_;
  }

private:
  static const size_t numTmpObjectsRequired_ = 1;

public:
  std::vector<size_t> numTmpObjectsRequired() const
  {
    return {numTmpObjectsRequired_, localFunctional_.numTmpObjectsRequired()};
  }

  /**
   *  \tparam T           Traits of the SpaceInterface implementation, representing the type of testSpace
   *  \tparam d           dimDomain of testSpace
   *  \tparam r           dimRange of testSpace
   *  \tparam rC          dimRangeCols of testSpace
   *  \tparam EntityType  A model of Dune::Entity< 0 >
   *  \tparam V           Traits of the Dune::Stuff::LA::Container::VectorInterface implementation, representing the
   * type of systemVector
   *  \tparam R           RangeFieldType, i.e. double
   */
  template <class T, size_t d, size_t r, size_t rC, class EntityType, class V, class R>
  void assembleLocal(const SpaceInterface<T, d, r, rC>& testSpace, const EntityType& entity,
                     Dune::Stuff::LA::VectorInterface<V, R>& systemVector,
                     std::vector<std::vector<Dune::DynamicVector<R>>>& tmpLocalVectorContainer,
                     Dune::DynamicVector<size_t>& tmpIndices) const
  {
    // check
    assert(tmpLocalVectorContainer.size() >= 2);
    assert(tmpLocalVectorContainer[0].size() >= numTmpObjectsRequired_);
    assert(tmpLocalVectorContainer[1].size() >= localFunctional_.numTmpObjectsRequired());
    // get and clear vector
    auto& localVector = tmpLocalVectorContainer[0][0];
    localVector *= 0.0;
    auto& tmpFunctionalVectors = tmpLocalVectorContainer[1];
    // apply local functional (result is in localVector)
    localFunctional_.apply(testSpace.base_function_set(entity), localVector, tmpFunctionalVectors);
    // write local vector to global
    const size_t size = testSpace.mapper().numDofs(entity);
    assert(tmpIndices.size() >= size);
    testSpace.mapper().globalIndices(entity, tmpIndices);
    for (size_t ii = 0; ii < size; ++ii) {
      systemVector.add_to_entry(tmpIndices[ii], localVector[ii]);
    } // write local matrix to global
  } // ... assembleLocal(...)

private:
  const LocalFunctionalType& localFunctional_;
}; // class Codim0Vector


template <class GridViewImp, class LocalOperatorType, class TestFunctionType, class AnsatzFunctionType, class FieldType>
class Codim0OperatorAccumulateFunctor : public Stuff::Grid::Codim0Functor<GridViewImp>
{
  static_assert(
      std::is_base_of<LocalOperator::Codim0Interface<typename LocalOperatorType::Traits>, LocalOperatorType>::value,
      "LocalOperatorType has to be derived from LocalOperator::Codim0Interface!");
  static_assert(Stuff::is_localizable_function<TestFunctionType>::value,
                "TestFunctionType has to be derived from Stuff::LocalizableFunctionInterface!");
  static_assert(Stuff::is_localizable_function<AnsatzFunctionType>::value,
                "AnsatzFunctionType has to be derived from Stuff::LocalizableFunctionInterface!");

  typedef Codim0OperatorAccumulateFunctor<GridViewImp, LocalOperatorType, TestFunctionType, AnsatzFunctionType,
                                          FieldType> ThisType;
  typedef Stuff::Grid::Codim0Functor<GridViewImp> BaseType;
  typedef DSC::TmpMatricesStorage<FieldType> TmpMatricesProviderType;

public:
  typedef typename BaseType::GridViewType GridViewType;
  typedef typename BaseType::EntityType EntityType;

  Codim0OperatorAccumulateFunctor(const GridViewType& grd_vw, const LocalOperatorType& local_op,
                                  const TestFunctionType& test_function, const AnsatzFunctionType& ansatz_function)
    : grid_view_(grd_vw)
    , local_operator_(local_op)
    , test_function_(test_function)
    , ansatz_function_(ansatz_function)
    , result_(0)
    , tmp_storage_(new TmpMatricesProviderType({1, local_operator_.numTmpObjectsRequired()}, 1, 1))
    , finalized_(false)
  {
  }

  Codim0OperatorAccumulateFunctor(const ThisType& other)
    : grid_view_(other.grid_view_)
    , local_operator_(other.local_operator_)
    , test_function_(other.test_function_)
    , ansatz_function_(other.ansatz_function_)
    , result_(other.result_)
    , tmp_storage_(new TmpMatricesProviderType({1, local_operator_.numTmpObjectsRequired()}, 1, 1))
    , finalized_(other.finalized_)
  {
  }

  virtual ~Codim0OperatorAccumulateFunctor() = default;

  FieldType compute_locally(const EntityType& entity)
  {
    assert(tmp_storage_->matrices().size() >= 2);
    assert(tmp_storage_->matrices()[0].size() >= 1);
    auto& local_operator_result = tmp_storage_->matrices()[0][0];
    auto& tmp_matrices          = tmp_storage_->matrices()[1];
    // get the local functions
    const auto local_test_function   = test_function_.local_function(entity);
    const auto local_ansatz_function = ansatz_function_.local_function(entity);
    // apply the local operator
    this->local_operator_.apply(*local_test_function, *local_ansatz_function, local_operator_result, tmp_matrices);
    assert(local_operator_result.rows() >= 1);
    assert(local_operator_result.cols() >= 1);
    return local_operator_result[0][0];
  } // ... compute_locally(...)

  virtual void apply_local(const EntityType& entity) override
  {
    *result_ += compute_locally(entity);
  }

  virtual void finalize() override
  {
    if (!finalized_) {
      finalized_result_ = result_.sum();
      finalized_result_ = grid_view_.comm().sum(finalized_result_);
      finalized_        = true;
    }
  } // ... finalize(...)

  FieldType result() const
  {
    if (!finalized_)
      DUNE_THROW(Stuff::Exceptions::you_are_using_this_wrong, "Call finalize() first!");
    return finalized_result_;
  }

private:
  const GridViewType& grid_view_;
  const LocalOperatorType& local_operator_;
  const TestFunctionType& test_function_;
  const AnsatzFunctionType& ansatz_function_;
  DS::PerThreadValue<FieldType> result_;
  std::unique_ptr<TmpMatricesProviderType> tmp_storage_;
  bool finalized_;
  FieldType finalized_result_;
}; // class Codim0OperatorAccumulateFunctor


} // namespace LocalAssembler
} // namespace GDT
} // namespace Dune

#endif // DUNE_GDT_ASSEMLBER_LOCAL_CODIM0_HH
