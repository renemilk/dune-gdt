// This file is part of the dune-gdt project:
//   https://github.com/dune-community/dune-gdt
// Copyright 2010-2016 dune-gdt developers and contributors. All rights reserved.
// License: Dual licensed as BSD 2-Clause License (http://opensource.org/licenses/BSD-2-Clause)
//      or  GPL-2.0+ (http://opensource.org/licenses/gpl-license)
//          with "runtime exception" (http://www.dune-project.org/license.html)
// Authors:
//   Felix Schindler (2017)

#ifndef DUNE_GDT_OPERATORS_BASE_BINDINGS_HH
#define DUNE_GDT_OPERATORS_BASE_BINDINGS_HH
#if HAVE_DUNE_PYBINDXI

#include <dune/pybindxi/pybind11.h>

#include <dune/xt/la/container.hh>

#include "base.hh"

namespace Dune {
namespace GDT {
namespace bindings {


template <class OperatorType>
class MatrixOperatorBase
{
public:
  typedef OperatorType type;
  typedef GDT::SystemAssembler<typename OperatorType::RangeSpaceType,
                               typename OperatorType::GridViewType,
                               typename OperatorType::SourceSpaceType>
      BaseType;
  typedef pybind11::class_<type, BaseType> bound_type;

  static bound_type bind(pybind11::module& m, const std::string& class_id)
  {
    namespace py = pybind11;
    using namespace pybind11::literals;

    typedef typename type::RangeSpaceType R;
    typedef typename type::SourceSpaceType S;
    typedef GDT::SystemAssembler<R, typename type::GridViewType, typename type::SourceSpaceType> I;
    typedef typename XT::LA::Container<typename type::RangeFieldType, type::MatrixType::vector_type>::VectorType V;

    bound_type c(m, std::string(class_id).c_str(), std::string(class_id).c_str());

    // from MatrixOperatorBase
    c.def_static("pattern", [](const R& space) { return type::pattern(space); });

    c.def("pattern", [](type& self) { return self.pattern(self.range_space()); });
    c.def("matrix", [](type& self) { return self.matrix(); });
    c.def("source_space", [](type& self) { return self.source_space(); });
    c.def("range_space", [](type& self) { return self.range_space(); });
    c.def("apply", [](type& self, const V& source, V& range) { self.apply(source, range); }, "source"_a, "range"_a);
    c.def("apply",
          [](type& self, const GDT::ConstDiscreteFunction<S, V>& source, GDT::DiscreteFunction<R, V>& range) {
            self.apply(source, range);
          },
          "source"_a,
          "range"_a);
    c.def("apply2",
          [](type& self, const V& range, const V& source) { return self.apply2(range, source); },
          "range"_a,
          "source"_a);
    c.def("apply2",
          [](type& self,
             const GDT::ConstDiscreteFunction<R, V>& range,
             const GDT::ConstDiscreteFunction<S, V>& source) { return self.apply2(range, source); },
          "range"_a,
          "source"_a);
    c.def("apply_inverse",
          [](type& self, const V& range, V& source, const XT::Common::Configuration& opts) {
            self.apply_inverse(range, source, opts);
          },
          "range"_a,
          "source"_a,
          "opts"_a);
    c.def("apply_inverse",
          [](type& self,
             const GDT::ConstDiscreteFunction<R, V>& range,
             GDT::ConstDiscreteFunction<S, V>& source,
             const XT::Common::Configuration& opts) { self.apply_inverse(range, source, opts); },
          "range"_a,
          "source"_a,
          "opts"_a);
    c.def("invert_options", [](type& self) { return self.invert_options(); });
    c.def("invert_options", [](type& self, const std::string& type) { return self.invert_options(type); }, "type"_a);

    // from OperatorInterface
    c.def(
        "apply_inverse",
        [](type& self, const V& range, V& source, const std::string& type) { self.apply_inverse(range, source, type); },
        "range"_a,
        "source"_a,
        "type"_a);
    c.def("apply_inverse",
          [](type& self,
             const GDT::ConstDiscreteFunction<R, V>& range,
             GDT::ConstDiscreteFunction<S, V>& source,
             const std::string& type) { self.apply_inverse(range, source, type); },
          "range"_a,
          "source"_a,
          "type"_a);
    c.def("apply_inverse",
          [](type& self, const V& range, V& source) { self.apply_inverse(range, source); },
          "range"_a,
          "source"_a);
    c.def("apply_inverse",
          [](type& self, const GDT::ConstDiscreteFunction<R, V>& range, GDT::ConstDiscreteFunction<S, V>& source) {
            self.apply_inverse(range, source);
          },
          "range"_a,
          "source"_a);
    c.def("induced_norm", [](type& self, const V& range) { return self.induced_norm(range); }, "range"_a);
    c.def("induced_norm",
          [](type& self, const GDT::ConstDiscreteFunction<R, V>& range) { return self.induced_norm(range); },
          "range"_a);

    return c;
  } // ... bind(...)

}; // class MatrixOperatorBase


} // namespace bindings
} // namespace GDT
} // namespace Dune

#endif // HAVE_DUNE_PYBINDXI
#endif // DUNE_GDT_OPERATORS_BASE_BINDINGS_HH
