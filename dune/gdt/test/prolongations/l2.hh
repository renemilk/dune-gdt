// This file is part of the dune-gdt project:
//   https://github.com/dune-community/dune-gdt
// Copyright 2010-2016 dune-gdt developers and contributors. All rights reserved.
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)
// Authors:
//   Felix Schindler (2016)

#ifndef DUNE_GDT_TEST_PROLONGATIONS_L2_HH
#define DUNE_GDT_TEST_PROLONGATIONS_L2_HH

#include <dune/common/unused.hh>

#include <dune/gdt/prolongations/l2.hh>

#include "base.hh"

namespace Dune {
namespace GDT {
namespace Test {


template <class SpaceType>
struct L2ProlongationLocalizableOperatorTest
    : public LocalizableProlongationOperatorBase<SpaceType, SpaceType, L2ProlongationLocalizableOperator>
{
  typedef LocalizableProlongationOperatorBase<SpaceType, SpaceType, L2ProlongationLocalizableOperator> BaseType;
  using typename BaseType::ProlongationOperatorType;

  void constructible_by_ctor(const double tolerance = 1e-15)
  {
    this->prepare(tolerance);

    auto grid_view = this->fine_space_.grid_view();
    const auto& source = this->coarse_discrete_function_;
    auto& range = this->fine_discrete_function_;

    DUNE_UNUSED ProlongationOperatorType w_over_integrate(0, grid_view, source, range);
    DUNE_UNUSED ProlongationOperatorType wo_over_integrate(grid_view, source, range);
  } // ... constructible_by_ctor(...)

  void constructible_by_factory(const double tolerance = 1e-15)
  {
    this->prepare(tolerance);

    auto grid_view = this->fine_space_.grid_view();
    const auto& source = this->coarse_discrete_function_;
    auto& range = this->fine_discrete_function_;

    auto w_gv_w_oi DUNE_UNUSED = make_global_l2_prolongation_localizable_operator(grid_view, source, range, 1);
    auto w_gv_wo_oi DUNE_UNUSED = make_global_l2_prolongation_localizable_operator(grid_view, source, range);
    auto wo_gv_w_oi DUNE_UNUSED = make_global_l2_prolongation_localizable_operator(source, range, 1);
    auto wo_gv_wo_oi DUNE_UNUSED = make_global_l2_prolongation_localizable_operator(source, range);
  } // ... constructible_by_factory(...)
};


template <class SpaceType>
struct L2ProlongationOperatorTest : public ProlongationOperatorBase<SpaceType, SpaceType, L2ProlongationOperator>
{
  typedef ProlongationOperatorBase<SpaceType, SpaceType, L2ProlongationOperator> BaseType;
  using typename BaseType::ProlongationOperatorType;

  void constructible_by_ctor(const double tolerance = 1e-15)
  {
    this->prepare(tolerance);

    auto grid_view = this->fine_space_.grid_view();
    const auto& source DUNE_UNUSED = this->coarse_discrete_function_;
    auto& range DUNE_UNUSED = this->fine_discrete_function_;

    DUNE_UNUSED ProlongationOperatorType w_over_integrate(0, grid_view);
    DUNE_UNUSED ProlongationOperatorType wo_over_integrate(grid_view);
  } // ... constructible_by_ctor(...)

  void constructible_by_factory(const double tolerance = 1e-15)
  {
    this->prepare(tolerance);

    auto grid_view = this->fine_space_.grid_view();

    auto w_over_integrate DUNE_UNUSED = make_l2_prolongation_operator(grid_view, 1);
    auto wo_over_integrate DUNE_UNUSED = make_l2_prolongation_operator(grid_view);
  } // ... constructible_by_factory(...)

  void free_function_callable(const double tolerance = 1e-15)
  {
    this->prepare(tolerance);

    auto grid_view = this->fine_space_.grid_view();
    const auto& source = this->coarse_discrete_function_;
    auto& range = this->fine_discrete_function_;

    prolong_l2(grid_view, source, range, 1);
    prolong_l2(grid_view, source, range);
    prolong_l2(source, range, 1);
    prolong_l2(source, range);
  } // ... free_function_callable(...)
};


} // namespace Test
} // namespace GDT
} // namespace Dune

#endif // DUNE_GDT_TEST_PROLONGATIONS_L2_HH
