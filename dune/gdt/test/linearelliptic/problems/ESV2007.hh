// This file is part of the dune-gdt project:
//   https://github.com/dune-community/dune-gdt
// Copyright 2010-2016 dune-gdt developers and contributors. All rights reserved.
// License: BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)
// Authors:
//   Felix Schindler (2015 - 2016)

#ifndef DUNE_GDT_TESTS_LINEARELLIPTIC_PROBLEMS_ESV2007_HH
#define DUNE_GDT_TESTS_LINEARELLIPTIC_PROBLEMS_ESV2007_HH

#if HAVE_DUNE_ALUGRID
#include <dune/alugrid/grid.hh>
#endif
#include <dune/grid/yaspgrid.hh>

#include <dune/xt/functions/constant.hh>
#include <dune/xt/functions/ESV2007.hh>
#include <dune/xt/grid/boundaryinfo.hh>
#include <dune/xt/grid/gridprovider/cube.hh>

#include <dune/gdt/test/stationary-testcase.hh>
#include <dune/gdt/test/grids.hh>

#include "base.hh"

namespace Dune {
namespace GDT {
namespace LinearElliptic {


template <class E, class D, int d, class R, int r = 1>
class ESV2007Problem : public ProblemBase<E, D, d, R, r>
{
  static_assert(AlwaysFalse<E>::value, "Not available for these dimensions!");
};


template <class EntityImp, class DomainFieldImp, class RangeFieldImp>
class ESV2007Problem<EntityImp, DomainFieldImp, 2, RangeFieldImp, 1>
    : public ProblemBase<EntityImp, DomainFieldImp, 2, RangeFieldImp, 1>
{
  typedef ProblemBase<EntityImp, DomainFieldImp, 2, RangeFieldImp, 1> BaseType;
  typedef XT::Functions::ConstantFunction<EntityImp, DomainFieldImp, 2, RangeFieldImp, 1> ScalarConstantFunctionType;
  typedef XT::Functions::ConstantFunction<EntityImp, DomainFieldImp, 2, RangeFieldImp, 2, 2> MatrixConstantFunctionType;
  typedef XT::Functions::ESV2007::Testcase1Force<EntityImp, DomainFieldImp, 2, RangeFieldImp, 1> ForceType;

public:
  static const size_t default_integration_order = 2;

  static XT::Common::Configuration default_grid_cfg()
  {
    XT::Common::Configuration cfg;
    cfg["type"] = XT::Grid::cube_gridprovider_default_config()["type"];
    cfg["lower_left"] = "[-1 -1]";
    cfg["upper_right"] = "[1 1]";
    return cfg;
  }

  static XT::Common::Configuration default_boundary_info_cfg()
  {
    return XT::Grid::alldirichlet_boundaryinfo_default_config();
  }

  ESV2007Problem(const size_t integration_order = default_integration_order,
                 const XT::Common::Configuration& grd_cfg = default_grid_cfg(),
                 const XT::Common::Configuration& bnd_cfg = default_boundary_info_cfg())
    : BaseType(
          new ScalarConstantFunctionType(1, "diffusion_factor"),
          new MatrixConstantFunctionType(XT::Functions::internal::unit_matrix<RangeFieldImp, 2>(), "diffusion_tensor"),
          new ForceType(integration_order, "force"),
          new ScalarConstantFunctionType(0, "dirichlet"),
          new ScalarConstantFunctionType(0, "neumann"),
          grd_cfg,
          bnd_cfg)
  {
  }
}; // class ESV2007Problem< ..., 1 >


template <class G, class R = double, int r = 1>
class ESV2007TestCase
    : public Test::StationaryTestCase<G,
                                      LinearElliptic::ESV2007Problem<typename G::template Codim<0>::Entity,
                                                                     typename G::ctype,
                                                                     G::dimension,
                                                                     R,
                                                                     r>>
{
  typedef typename G::template Codim<0>::Entity E;
  typedef typename G::ctype D;
  static const size_t d = G::dimension;
  typedef XT::Functions::ESV2007::Testcase1ExactSolution<E, D, d, R, r> ExactSolutionType;

public:
  typedef LinearElliptic::ESV2007Problem<E, D, d, R, r> ProblemType;

private:
  typedef Test::StationaryTestCase<G, ProblemType> BaseType;

#if DXT_DISABLE_LARGE_TESTS

  template <class T, bool anything = true>
  struct Helper
  {
    static XT::Common::Configuration value(XT::Common::Configuration cfg)
    {
      cfg["num_elements"] = "[4 4]";
      return cfg;
    }
  };

#else // DXT_DISABLE_LARGE_TESTS

  template <class T, bool anything = true>
  struct Helper
  {
    static_assert(AlwaysFalse<T>::value, "Please add a configuration for this grid type!");
    static XT::Common::Configuration value(XT::Common::Configuration cfg)
    {
      return cfg;
    }
  };

  template <bool anything>
  struct Helper<Yasp2Grid, anything>
  {
    static XT::Common::Configuration value(XT::Common::Configuration cfg)
    {
      cfg["num_elements"] = "[8 8]";
      return cfg;
    }
  };

#if HAVE_DUNE_ALUGRID

  template <bool anything>
  struct Helper<AluConform2dGridType, anything>
  {
    static XT::Common::Configuration value(XT::Common::Configuration cfg)
    {
      cfg["num_elements"] = "[4 4]";
      cfg["num_refinements"] = "2";
      return cfg;
    }
  };

  template <bool anything>
  struct Helper<AluSimplex2dGridType, anything>
  {
    static XT::Common::Configuration value(XT::Common::Configuration cfg)
    {
      cfg["num_elements"] = "[8 8]";
      return cfg;
    }
  };

#endif // HAVE_DUNE_ALUGRID
#endif // DXT_DISABLE_LARGE_TESTS

  static XT::Common::Configuration grid_cfg()
  {
    auto cfg = ProblemType::default_grid_cfg();
    cfg = Helper<typename std::decay<G>::type>::value(cfg);
    return cfg;
  }

public:
  using typename BaseType::GridType;

  ESV2007TestCase(const size_t num_refs =
#if DXT_DISABLE_LARGE_TESTS
                      1
#else
                      3
#endif
                  )
    : BaseType(XT::Grid::make_cube_grid<GridType>(grid_cfg()).grid_ptr(), num_refs)
    , problem_()
    , exact_solution_()
  {
  }

  virtual const ProblemType& problem() const override final
  {
    return problem_;
  }

  virtual void print_header(std::ostream& out = std::cout) const override final
  {
    out << "+==================================================================+\n"
        << "|+================================================================+|\n"
        << "||  Testcase ESV2007: smooth data, homogeneous dirichlet          ||\n"
        << "||  (see testcase 1, page 23 in Ern, Stephansen, Vohralik, 2007)  ||\n"
        << "|+----------------------------------------------------------------+|\n"
        << "||  domain = [-1, 1] x [-1, 1]                                    ||\n"
        << "||  diffusion = 1                                                 ||\n"
        << "||  force     = 1/2 pi^2 cos(1/2 pi x) cos(1/2 pi y)              ||\n"
        << "||  dirichlet = 0                                                 ||\n"
        << "||  exact solution = cos(1/2 pi x) cos(1/2 pi y)                  ||\n"
        << "|+================================================================+|\n"
        << "+==================================================================+" << std::endl;
  }

  virtual bool provides_exact_solution() const override final
  {
    return true;
  }

  virtual const ExactSolutionType& exact_solution() const override final
  {
    return exact_solution_;
  }

private:
  const ProblemType problem_;
  const ExactSolutionType exact_solution_;
}; // class ESV2007TestCase


} // namespace LinearElliptic
} // namespace GDT
} // namespace Dune

#endif // DUNE_GDT_TESTS_LINEARELLIPTIC_PROBLEMS_ESV2007_HH
