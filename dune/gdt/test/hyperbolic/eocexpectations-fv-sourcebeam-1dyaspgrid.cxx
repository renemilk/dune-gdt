// This file is part of the dune-gdt project:
//   https://github.com/dune-community/dune-gdt
// Copyright 2010-2016 dune-gdt developers and contributors. All rights reserved.
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)
// Authors:
//   Felix Schindler (2016)
//   Tobias Leibner  (2016)

#include "config.h"

#include <dune/grid/yaspgrid.hh>

#include <dune/gdt/test/hyperbolic/discretizers/fv.hh>

#include "problems/fokkerplanck/sourcebeam.hh"
#include "eocexpectations.hh"


namespace Dune {
namespace GDT {
namespace Tests {


template <bool anything>
class HyperbolicEocExpectations<Hyperbolic::SourceBeamTestCase<Yasp1, double>, Hyperbolic::ChooseDiscretizer::fv, 1,
                                NumericalFluxes::godunov, TimeStepperMethods::explicit_euler, anything>
    : public internal::HyperbolicEocExpectationsBase<1>
{
  typedef Hyperbolic::SourceBeamTestCase<Yasp1, double> TestCaseType;

public:
  static std::vector<double> results(const TestCaseType& test_case, const std::string type)
  {
    if (type == "L1") {
      if (Dune::XT::Common::FloatCmp::eq(test_case.t_end(), 4.0))
        return {3.25e-01, 1.63e-01};
      else if (Dune::XT::Common::FloatCmp::eq(test_case.t_end(), 4.0 / 5.0))
        return {9.16e-02, 4.08e-02};
      else
        EXPECT_TRUE(false) << "test results missing for t_end = " << Dune::XT::Common::to_string(test_case.t_end());
    } else
      EXPECT_TRUE(false) << "test results missing for type: " << type;
    return {};
  } // ... results(...)
}; // HyperbolicEocExpectations

template <bool anything>
class HyperbolicEocExpectations<Hyperbolic::SourceBeamTestCase<Yasp1, double>, Hyperbolic::ChooseDiscretizer::fv, 1,
                                NumericalFluxes::godunov_with_reconstruction, TimeStepperMethods::explicit_euler,
                                anything> : public internal::HyperbolicEocExpectationsBase<1>
{
  typedef Hyperbolic::SourceBeamTestCase<Yasp1, double> TestCaseType;

public:
  static std::vector<double> results(const TestCaseType& test_case, const std::string type)
  {
    if (type == "L1") {
      if (test_case.num_refinements() == 1) {
        if (Dune::XT::Common::FloatCmp::eq(test_case.t_end(), 4.0))
          return {2.63e-01, 1.39e-01};
        else if (Dune::XT::Common::FloatCmp::eq(test_case.t_end(), 4.0 / 5.0))
          return {7.07e-02, 3.13e-02};
        else
          EXPECT_TRUE(false) << "test results missing for type: " << type;
      }
    } else
      EXPECT_TRUE(false) << "test results missing for type: " << type;
    return {};
  } // ... results(...)
}; // HyperbolicEocExpectations

template class HyperbolicEocExpectations<Hyperbolic::SourceBeamTestCase<Yasp1, double>,
                                         Hyperbolic::ChooseDiscretizer::fv, 1, NumericalFluxes::godunov,
                                         TimeStepperMethods::explicit_euler>;

template class HyperbolicEocExpectations<Hyperbolic::SourceBeamTestCase<Yasp1, double>,
                                         Hyperbolic::ChooseDiscretizer::fv, 1,
                                         NumericalFluxes::godunov_with_reconstruction,
                                         TimeStepperMethods::explicit_euler>;


} // namespace Tests
} // namespace GDT
} // namespace Dune
