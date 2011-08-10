#ifndef DUNE_FUNCTIONALS_DISCRETEFUNCTIONSPACE_SUBSPACE_AFFINE_HH
#define DUNE_FUNCTIONALS_DISCRETEFUNCTIONSPACE_SUBSPACE_AFFINE_HH

// dune-fucntionals includes
#include <dune/functionals/basefunctionset/local/lagrange.hh>
#include <dune/functionals/discretefunction/continuous.hh>

// dune-fem-tools includes
#include <dune/fem-tools/function/functiontools.hh>
#include <dune/fem-tools/function/runtimefunction.hh>
#include <dune/fem-tools/space/projection.hh>

namespace Dune
{

namespace Functionals
{

namespace DiscreteFunctionSpace
{

namespace Subspace
{

namespace Affine
{

template< class BaseSpaceImp >
class Dirichlet
{
public:

  typedef BaseSpaceImp
    BaseSpaceType;

  typedef Dirichlet< BaseSpaceType >
    ThisType;

  typedef typename BaseSpaceType::SuperSpaceType
    SuperSpaceType;

  typedef typename BaseSpaceType::FunctionSpaceType
    FunctionSpaceType;

  typedef typename BaseSpaceType::GridPartType
    GridPartType;

  enum{ polynomialOrder = BaseSpaceType::polynomialOrder };

private:
  typedef Dune::FemTools::Function::Runtime< FunctionSpaceType >
    RuntimeFunctionType;

public:
  typedef Dune::Functionals::DiscreteFunction::Continuous::BlockVector< SuperSpaceType >
    AffineShiftType;

  typedef typename BaseSpaceType::ConstraintsType
    ConstraintsType;

  typedef typename BaseSpaceType::BaseFunctionSetType
    BaseFunctionSetType;

  typedef typename BaseSpaceType::DomainType
    DomainType;

  typedef typename BaseSpaceType::DomainFieldType
    DomainFieldType;

  typedef typename BaseSpaceType::RangeFieldType
    RangeFieldType;

  typedef typename BaseSpaceType::RangeType
    RangeType;

  typedef typename BaseSpaceType::JacobianRangeType
    JacobianRangeType;

  typedef typename BaseSpaceType::HessianRangeType
    HessianRangeType;

  typedef typename BaseSpaceType::MapperType
    MapperType;

  static const unsigned int dimDomain = BaseSpaceType::dimDomain;

  static const unsigned int dimRange = BaseSpaceType::dimRange;

  /**
      @name Convenience Types
      @{
   **/
  typedef typename SuperSpaceType::IteratorType
    IteratorType;

  typedef typename SuperSpaceType::EntityType
    EntityType;
  /**
      @}
   **/

  Dirichlet( const BaseSpaceType& baseSpace, const std::string expression = "[0.0;0.0;0.0]" )
    : baseSpace_( baseSpace ),
      runtimeFunction_( expression ),
      affineShift_( baseSpace.superSpace(), "affineShift", runtimeFunction_, "dirichlet" )
  {
  }

  const BaseSpaceType& baseSpace() const
  {
    return baseSpace_;
  }

  const SuperSpaceType& superSpace() const
  {
    return baseSpace_.superSpace();
  }

  const AffineShiftType& affineShift() const
  {
    return affineShift_;
  }

  const GridPartType& gridPart() const
  {
    return baseSpace_.gridPart();
  }

  const BaseFunctionSetType& baseFunctionSet() const
  {
    return baseSpace_.baseFunctionSet();
  }

  int order() const
  {
    return baseSpace_.order();
  }

  const ConstraintsType& constraints() const
  {
    return baseSpace_.constraints();
  }

  const MapperType& map() const
  {
    return baseSpace_.map();
  }

  bool continuous() const
  {
    return baseSpace_.continuous();
  }

  /**
      @name Convenience methods
      @{
   **/
  IteratorType begin() const
  {
    return baseSpace_.gridPart().template begin< 0 >();
  }

  IteratorType end() const
  {
    return baseSpace_.gridPart().template end< 0 >();
  }
  /**
      @}
   **/

private:

  //! copy constructor
  Dirichlet( const ThisType& );

  //! assignment operator
  ThisType& operator=( const ThisType& );

  const BaseSpaceType& baseSpace_;
  const RuntimeFunctionType runtimeFunction_;
  const AffineShiftType affineShift_;
}; // end class Dirichlet

} // end of namespace Affine

} // end namespace Subspace

} // end namespace DiscreteFunctionSpace

} // end of namespace Functionals

} // end of namespace Dune

#endif // DUNE_FUNCTIONALS_DISCRETEFUNCTIONSPACE_SUBSPACE_AFFINE_HH
