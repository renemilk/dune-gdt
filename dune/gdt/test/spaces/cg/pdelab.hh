// This file is part of the dune-gdt project:
//   https://github.com/dune-community/dune-gdt
// Copyright 2010-2016 dune-gdt developers and contributors. All rights reserved.
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)
// Authors:
//   Felix Schindler (2014 - 2016)
//   Tobias Leibner  (2014)

#ifndef DUNE_GDT_TEST_SPACES_CG_PDELAB_HH
#define DUNE_GDT_TEST_SPACES_CG_PDELAB_HH

#include <dune/xt/grid/type_traits.hh>

#include <dune/gdt/spaces/cg/dune-pdelab-wrapper.hh>

#include <dune/gdt/test/grids.hh>

#include <dune/xt/grid/type_traits.hh>

#if HAVE_DUNE_PDELAB


#define SPACE_CG_PDELAB_YASPGRID(dd, rr, pp)                                                                           \
  Dune::GDT::DunePdelabCgSpaceWrapper<Yasp##dd##dLeafGridViewType, pp, double, rr>

#define SPACES_CG_PDELAB(pp)                                                                                           \
  SPACE_CG_PDELAB_YASPGRID(1, 1, pp), SPACE_CG_PDELAB_YASPGRID(2, 1, pp), SPACE_CG_PDELAB_YASPGRID(3, 1, pp)

#define SPACE_CG_PDELAB_YASPGRID_LEVEL(dd, rr, pp)                                                                     \
  Dune::GDT::DunePdelabCgSpaceWrapper<Yasp##dd##dLevelGridViewType, pp, double, rr>

#define SPACES_CG_PDELAB_LEVEL(pp)                                                                                     \
  SPACE_CG_PDELAB_YASPGRID_LEVEL(1, 1, pp)                                                                             \
  , SPACE_CG_PDELAB_YASPGRID_LEVEL(2, 1, pp), SPACE_CG_PDELAB_YASPGRID_LEVEL(3, 1, pp)


#if HAVE_DUNE_ALUGRID


#define SPACE_CG_PDELAB_ALUCONFORMGRID(dd, rr, pp)                                                                     \
  Dune::GDT::DunePdelabCgSpaceWrapper<AluConform##dd##dLeafGridViewType, pp, double, rr>

#define SPACE_CG_PDELAB_ALUCUBEGRID(dd, rr, pp)                                                                        \
  Dune::GDT::DunePdelabCgSpaceWrapper<AluCube##dd##dLeafGridViewType, pp, double, rr>

#define SPACES_CG_PDELAB_ALUGRID(pp)                                                                                   \
  SPACE_CG_PDELAB_ALUCONFORMGRID(2, 1, pp)                                                                             \
  , SPACE_CG_PDELAB_ALUCONFORMGRID(3, 1, pp), SPACE_CG_PDELAB_ALUCUBEGRID(2, 1, pp),                                   \
      SPACE_CG_PDELAB_ALUCUBEGRID(3, 1, pp)


#define SPACE_CG_PDELAB_ALUCUBEGRID_LEVEL(dd, rr, pp)                                                                  \
  Dune::GDT::DunePdelabCgSpaceWrapper<AluCube##dd##dLevelGridViewType, pp, double, rr>

#define SPACES_CG_PDELAB_ALUGRID_LEVEL(pp)                                                                             \
  SPACE_CG_PDELAB_ALUCUBEGRID_LEVEL(2, 1, pp)                                                                          \
  , SPACE_CG_PDELAB_ALUCUBEGRID_LEVEL(3, 1, pp)


#endif // HAVE_DUNE_ALUGRID
#endif // HAVE_DUNE_PDELAB

template <class T>
double pdelab_cg_tolerance(const T& param)
{
  typedef typename T::GridViewType::Grid Grid;
  const auto dim = param.dimDomain;
  const auto tolerance = Dune::XT::Grid::is_conforming_alugrid<Grid>::value ? (dim == 3 ? 1.35e-13 : 1.4e-14)
                                                                            : (dim == 3 ? 2.49e-14 : 1e-15);
  return tolerance;
}

#endif // DUNE_GDT_TEST_SPACES_CG_PDELAB_HH
