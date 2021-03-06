// This file is part of the dune-gdt project:
//   https://github.com/dune-community/dune-gdt
// Copyright 2010-2016 dune-gdt developers and contributors. All rights reserved.
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)
// Authors:
//   Felix Schindler (2015 - 2016)

#ifndef DUNE_GDT_TEST_LINEARELLIPTIC_SWIPDG_DISCRETIZATION_HH
#define DUNE_GDT_TEST_LINEARELLIPTIC_SWIPDG_DISCRETIZATION_HH

#include <dune/xt/common/test/common.hh>
#include <dune/xt/functions/spe10/model1.hh>
#include <dune/xt/la/container.hh>

#include <dune/gdt/spaces/interface.hh>

#include "eocstudy.hh"
#include "discretizers/ipdg.hh"


template <class TestCaseType>
struct linearelliptic_SWIPDG_discretization : public ::testing::Test
{
  template <Dune::GDT::ChooseSpaceBackend space_backend, Dune::XT::LA::Backends la_backend, int polOrder>
  static void eoc_study()
  {
    using namespace Dune;
    using namespace Dune::GDT;
    TestCaseType test_case;
    test_case.print_header(DXTC_LOG_INFO);
    DXTC_LOG_INFO << std::endl;
    typedef LinearElliptic::IpdgDiscretizer<typename TestCaseType::GridType,
                                            XT::Grid::Layers::level,
                                            space_backend,
                                            la_backend,
                                            polOrder,
                                            typename TestCaseType::ProblemType::RangeFieldType,
                                            1,
                                            LocalEllipticIpdgIntegrands::Method::swipdg>
        Discretizer;
    Dune::GDT::Test::LinearEllipticEocStudy<TestCaseType, Discretizer> eoc_study(test_case);
    try {
      Dune::XT::Test::check_eoc_study_for_success(eoc_study, eoc_study.run(DXTC_LOG_INFO));
    } catch (Dune::XT::Common::Exceptions::spe10_data_file_missing&) {
      Dune::XT::Common::TimedLogger().get("gdt.test.linearelliptic.swipdg.discretization").warn()
          << "missing SPE10 data file!" << std::endl;
    }
  } // ... eoc_study()
}; // linearelliptic_SWIPDG_discretization

#endif // DUNE_GDT_TEST_LINEARELLIPTIC_SWIPDG_DISCRETIZATION_HH
