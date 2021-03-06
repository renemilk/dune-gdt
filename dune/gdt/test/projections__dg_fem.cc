// This file is part of the dune-gdt project:
//   https://github.com/dune-community/dune-gdt
// Copyright 2010-2016 dune-gdt developers and contributors. All rights reserved.
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)
// Authors:
//   Felix Schindler (2014, 2016)

#include <dune/xt/common/test/main.hxx>

#include "projections.hh"
#include "spaces/dg/fem.hh"

using namespace Dune::GDT::Test;

#if HAVE_DUNE_FEM


typedef testing::Types<SPACES_DG_FEM(1)
#if HAVE_DUNE_ALUGRID
                           ,
                       SPACES_DG_FEM_ALUGRID(1)
#endif
                       >
    SpaceTypes;

TYPED_TEST_CASE(ProjectionTest, SpaceTypes);
TYPED_TEST(ProjectionTest, produces_correct_results)
{
  this->produces_correct_results();
}


#else // HAVE_DUNE_FEM


TEST(DISABLED_ProjectionTest, produces_correct_results)
{
}


#endif // HAVE_DUNE_FEM
