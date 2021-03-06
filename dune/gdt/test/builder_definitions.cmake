set(DXT_BIN_COUNT "12" CACHE STRING "number of bins for test targets" )
add_custom_target(test_binaries_builder_0 DEPENDS test_empty test_hyperbolic__fv_discretization__yaspgrid_laxfriedrichs_euler test_linearelliptic__cg_discretization_AO2013TestCase_Alu2_Simp_nonc_fem_eigen_sparse test_linearelliptic__cg_discretization_Spe10Model1TestCase_Yasp2_fem_istl_sparse test_linearelliptic__swipdg_discretization_ER2007TestCase_Alu2_Simp_nonc_fem_eigen_sparse test_linearelliptic__swipdg_discretization_ER2007TestCase_Yasp2_fem_istl_sparse test_operators__laplace__localizable_product test_projections__l2__cg_pdelab test_projections__l2_local_localizable__rt_pdelab test_projections__lagrange__cg_fem test_prolongations__fv_default test_prolongations__l2_global_localizable__cg_fem test_prolongations__l2_localizable__rt_pdelab test_spaces__cg__pdelab)
set_tests_properties(test_empty PROPERTIES LABELS "builder_0")
set_tests_properties(test_hyperbolic__fv_discretization__yaspgrid_laxfriedrichs_euler PROPERTIES LABELS "builder_0")
set_tests_properties( PROPERTIES LABELS "builder_0")
set_tests_properties( PROPERTIES LABELS "builder_0")
set_tests_properties( PROPERTIES LABELS "builder_0")
set_tests_properties( PROPERTIES LABELS "builder_0")
set_tests_properties(test_operators__laplace__localizable_product PROPERTIES LABELS "builder_0")
set_tests_properties(test_projections__l2__cg_pdelab PROPERTIES LABELS "builder_0")
set_tests_properties(test_projections__l2_local_localizable__rt_pdelab PROPERTIES LABELS "builder_0")
set_tests_properties(test_projections__lagrange__cg_fem PROPERTIES LABELS "builder_0")
set_tests_properties(test_prolongations__fv_default PROPERTIES LABELS "builder_0")
set_tests_properties(test_prolongations__l2_global_localizable__cg_fem PROPERTIES LABELS "builder_0")
set_tests_properties(test_prolongations__l2_localizable__rt_pdelab PROPERTIES LABELS "builder_0")
set_tests_properties(test_spaces__cg__pdelab PROPERTIES LABELS "builder_0")
add_custom_target(test_binaries_builder_1 DEPENDS headercheck__dune_gdt_operators_base.hh headercheck__dune_gdt_spaces_constraints.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations-fv-transport-2dyaspgrid.hh headercheck__dune_gdt_test_hyperbolic_problems_shallowwater.hh headercheck__dune_gdt_test_linearelliptic_discretizers_base.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_all.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-er2007-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-spe10-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_swipdg-discretization.hh headercheck__dune_gdt_test_projections_lagrange.hh headercheck__dune_gdt_test_spaces_dg.hh headercheck__dune_gdt_test_spaces_fv.hh headercheck__dune_gdt_timestepper_adaptive-rungekutta.hh test_linearelliptic__cg_discretization_AO2013TestCase_Yasp2_pdelab_istl_sparse test_linearelliptic__cg_discretization_ESV2007TestCase_Alu2_Simp_nonc_fem_istl_sparse test_linearelliptic__cg_discretization_Spe10Model1TestCase_Yasp2_pdelab_eigen_sparse test_linearelliptic__swipdg_discretization_AO2013TestCase_Yasp2_fem_eigen_sparse test_linearelliptic__swipdg_discretization_AO2013TestCase_Yasp2_fem_istl_sparse test_operators__elliptic__matrix_operator test_operators__l2__matrix_operator test_projections__dg_pdelab test_projections__l2__cg_fem test_projections__l2_localizable__dg_pdelab test_prolongations__l2_global__cg_fem test_prolongations__lagrange_localizable__cg_pdelab)
set_tests_properties( PROPERTIES LABELS "builder_1")
set_tests_properties( PROPERTIES LABELS "builder_1")
set_tests_properties( PROPERTIES LABELS "builder_1")
set_tests_properties( PROPERTIES LABELS "builder_1")
set_tests_properties( PROPERTIES LABELS "builder_1")
set_tests_properties(test_operators__elliptic__matrix_operator PROPERTIES LABELS "builder_1")
set_tests_properties(test_operators__l2__matrix_operator PROPERTIES LABELS "builder_1")
set_tests_properties(test_projections__dg_pdelab PROPERTIES LABELS "builder_1")
set_tests_properties(test_projections__l2__cg_fem PROPERTIES LABELS "builder_1")
set_tests_properties(test_projections__l2_localizable__dg_pdelab PROPERTIES LABELS "builder_1")
set_tests_properties(test_prolongations__l2_global__cg_fem PROPERTIES LABELS "builder_1")
set_tests_properties(test_prolongations__lagrange_localizable__cg_pdelab PROPERTIES LABELS "builder_1")
add_custom_target(test_binaries_builder_2 DEPENDS headercheck__dune_gdt_local_fluxes_interfaces.hh headercheck__dune_gdt_local_functionals_integrals.hh headercheck__dune_gdt_operators_laplace.hh headercheck__dune_gdt_operators_weighted-l2.hh headercheck__dune_gdt_playground_spaces_mapper_block.hh headercheck__dune_gdt_prolongations.hh headercheck__dune_gdt_spaces_interface.hh headercheck__dune_gdt_spaces_mapper_dune-fem-wrapper.hh headercheck__dune_gdt_spaces_tools.hh headercheck__dune_gdt_test_hyperbolic_problems_fokkerplanck_onebeam.hh headercheck__dune_gdt_test_hyperbolic_problems_transport.hh headercheck__dune_gdt_test_instationary-eocstudy.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-ao2013-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-esv2007-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-spe10-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-ao2013-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-mixedboundary-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_problems_ESV2007.hh headercheck__dune_gdt_test_operators_weighted-l2.hh headercheck__dune_gdt_test_projections.hh headercheck__dune_gdt_test_prolongations.hh headercheck__dune_gdt_test_spaces_dg_fem.hh headercheck__dune_gdt_test_spaces_rt.hh headercheck__dune_gdt_test_spaces_rt_pdelab.hh headercheck__dune_gdt_timestepper_explicit-rungekutta.hh headercheck__dune_gdt_timestepper_interface.hh headercheck__dune_gdt_type_traits.hh test_hyperbolic__fv_discretization__yaspgrid_godunov_adaptive_rungekutta test_hyperbolic__fv_discretization__yaspgrid_godunov_reconstruction_euler test_linearelliptic__cg_discretization_ESV2007TestCase_Alu2_Simp_nonc_pdelab_eigen_sparse test_linearelliptic__cg_discretization_Spe10Model1TestCase_Alu2_Simp_nonc_pdelab_istl_sparse test_linearelliptic__swipdg_discretization_MixedBoundaryTestCase_Yasp2_fem_eigen_sparse test_linearelliptic__swipdg_discretization_MixedBoundaryTestCase_Yasp2_fem_istl_sparse test_operators__weighted_l2__operator test_projections__l2_global_localizable__cg_fem test_projections__l2_local__dg_pdelab test_projections__l2_localizable__fv_default test_prolongations__l2__fv_default test_prolongations__l2_local__rt_pdelab test_prolongations__l2_local_localizable__dg_fem)
set_tests_properties(test_hyperbolic__fv_discretization__yaspgrid_godunov_adaptive_rungekutta PROPERTIES LABELS "builder_2")
set_tests_properties(test_hyperbolic__fv_discretization__yaspgrid_godunov_reconstruction_euler PROPERTIES LABELS "builder_2")
set_tests_properties( PROPERTIES LABELS "builder_2")
set_tests_properties( PROPERTIES LABELS "builder_2")
set_tests_properties( PROPERTIES LABELS "builder_2")
set_tests_properties( PROPERTIES LABELS "builder_2")
set_tests_properties(test_operators__weighted_l2__operator PROPERTIES LABELS "builder_2")
set_tests_properties(test_projections__l2_global_localizable__cg_fem PROPERTIES LABELS "builder_2")
set_tests_properties(test_projections__l2_local__dg_pdelab PROPERTIES LABELS "builder_2")
set_tests_properties(test_projections__l2_localizable__fv_default PROPERTIES LABELS "builder_2")
set_tests_properties(test_prolongations__l2__fv_default PROPERTIES LABELS "builder_2")
set_tests_properties(test_prolongations__l2_local__rt_pdelab PROPERTIES LABELS "builder_2")
set_tests_properties(test_prolongations__l2_local_localizable__dg_fem PROPERTIES LABELS "builder_2")
add_custom_target(test_binaries_builder_3 DEPENDS headercheck__dune_gdt_assembler_wrapper.hh headercheck__dune_gdt_local_fluxes_godunov.hh headercheck__dune_gdt_local_integrands_ESV2007.hh headercheck__dune_gdt_local_operators_interfaces.hh headercheck__dune_gdt_local_operators_lagrange-projection.hh headercheck__dune_gdt_operators_elliptic.hh headercheck__dune_gdt_playground_spaces_block.hh headercheck__dune_gdt_playground_spaces_dg_dune-fem-localfunctions-wrapper.hh headercheck__dune_gdt_playground_spaces_dg_dune-pdelab-wrapper.hh headercheck__dune_gdt_prolongations_l2.hh headercheck__dune_gdt_spaces_basefunctionset_interface.hh headercheck__dune_gdt_spaces_dg_dune-fem-wrapper.hh headercheck__dune_gdt_spaces_fv_default.hh headercheck__dune_gdt_spaces_mapper_interfaces.hh headercheck__dune_gdt_spaces_mapper_product.hh headercheck__dune_gdt_spaces_th_dune-pdelab-wrapper.hh headercheck__dune_gdt_test_hyperbolic_all_eocexpectations.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations-fv-shallowwater-1dyaspgrid.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations-fv-shocktube-1dyaspgrid.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations_base.hh headercheck__dune_gdt_test_hyperbolic_fv-discretization.hh headercheck__dune_gdt_test_hyperbolic_problems_burgers.hh headercheck__dune_gdt_test_hyperbolic_problems_default.hh headercheck__dune_gdt_test_hyperbolic_problems_fokkerplanck_sourcebeam.hh headercheck__dune_gdt_test_linearelliptic_discretizers_ipdg.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-esv2007-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-mixedboundary-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-ao2013-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-er2007-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-esv2007-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-esv2007-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_problems_spe10.hh headercheck__dune_gdt_test_projections_l2.hh headercheck__dune_gdt_test_prolongations_l2.hh headercheck__dune_gdt_test_spaces_base.hh headercheck__dune_gdt_test_spaces_cg_pdelab.hh test_linearelliptic__cg_discretization_ER2007TestCase_Alu2_Simp_nonc_fem_eigen_sparse test_linearelliptic__cg_discretization_ESV2007TestCase_Yasp2_pdelab_eigen_sparse test_linearelliptic__cg_discretization_MixedBoundaryTestCase_Alu2_Simp_nonc_pdelab_istl_sparse test_linearelliptic__cg_discretization_Spe10Model1TestCase_Yasp2_fem_eigen_sparse test_linearelliptic__swipdg_discretization_MixedBoundaryTestCase_Alu2_Simp_nonc_fem_istl_sparse test_operators__l2__localizable_product test_projections__fv_default test_projections__l2_global__cg_fem test_projections__l2_local__dg_fem test_projections__l2_localizable__cg_pdelab test_prolongations__dg_fem test_prolongations__l2__dg_pdelab test_prolongations__l2_local__dg_fem)
set_tests_properties( PROPERTIES LABELS "builder_3")
set_tests_properties( PROPERTIES LABELS "builder_3")
set_tests_properties( PROPERTIES LABELS "builder_3")
set_tests_properties( PROPERTIES LABELS "builder_3")
set_tests_properties( PROPERTIES LABELS "builder_3")
set_tests_properties(test_operators__l2__localizable_product PROPERTIES LABELS "builder_3")
set_tests_properties(test_projections__fv_default PROPERTIES LABELS "builder_3")
set_tests_properties(test_projections__l2_global__cg_fem PROPERTIES LABELS "builder_3")
set_tests_properties(test_projections__l2_local__dg_fem PROPERTIES LABELS "builder_3")
set_tests_properties(test_projections__l2_localizable__cg_pdelab PROPERTIES LABELS "builder_3")
set_tests_properties(test_prolongations__dg_fem PROPERTIES LABELS "builder_3")
set_tests_properties(test_prolongations__l2__dg_pdelab PROPERTIES LABELS "builder_3")
set_tests_properties(test_prolongations__l2_local__dg_fem PROPERTIES LABELS "builder_3")
add_custom_target(test_binaries_builder_4 DEPENDS test_linearelliptic__cg_discretization_AO2013TestCase_Alu2_Simp_nonc_fem_istl_sparse test_linearelliptic__cg_discretization_AO2013TestCase_Alu2_Simp_nonc_pdelab_istl_sparse test_linearelliptic__cg_discretization_ER2007TestCase_Yasp2_fem_eigen_sparse test_linearelliptic__cg_discretization_ESV2007TestCase_Yasp2_fem_istl_sparse test_linearelliptic__swipdg_discretization_AO2013TestCase_Alu2_Simp_nonc_fem_istl_sparse test_operators__laplace__matrix_operator test_projections__lagrange_localizable__cg_fem test_prolongations__cg_fem test_prolongations__cg_pdelab test_prolongations__l2__cg_fem test_prolongations__l2_local_localizable__rt_pdelab test_spaces__fv__default)
set_tests_properties( PROPERTIES LABELS "builder_4")
set_tests_properties( PROPERTIES LABELS "builder_4")
set_tests_properties( PROPERTIES LABELS "builder_4")
set_tests_properties( PROPERTIES LABELS "builder_4")
set_tests_properties( PROPERTIES LABELS "builder_4")
set_tests_properties(test_operators__laplace__matrix_operator PROPERTIES LABELS "builder_4")
set_tests_properties(test_projections__lagrange_localizable__cg_fem PROPERTIES LABELS "builder_4")
set_tests_properties(test_prolongations__cg_fem PROPERTIES LABELS "builder_4")
set_tests_properties(test_prolongations__cg_pdelab PROPERTIES LABELS "builder_4")
set_tests_properties(test_prolongations__l2__cg_fem PROPERTIES LABELS "builder_4")
set_tests_properties(test_prolongations__l2_local_localizable__rt_pdelab PROPERTIES LABELS "builder_4")
set_tests_properties(test_spaces__fv__default PROPERTIES LABELS "builder_4")
add_custom_target(test_binaries_builder_5 DEPENDS headercheck__dune_gdt_exists.hh headercheck__dune_gdt_local_assembler.hh headercheck__dune_gdt_local_functionals_interfaces.hh headercheck__dune_gdt_playground_timestepper_rosenbrock.hh headercheck__dune_gdt_projections_dirichlet.hh headercheck__dune_gdt_projections_lagrange.hh headercheck__dune_gdt_spaces_basefunctionset_dune-pdelab-wrapper.hh headercheck__dune_gdt_spaces_basefunctionset_fv.hh headercheck__dune_gdt_spaces_cg.hh headercheck__dune_gdt_spaces_rt.hh headercheck__dune_gdt_spaces_rt_dune-pdelab-wrapper.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations-fv-boltzmanncheckerboard-2dyaspgrid.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations-fv-sourcebeam-1dyaspgrid.hh headercheck__dune_gdt_test_hyperbolic_problems_fokkerplanck_twobeams.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_base.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-ao2013-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-spe10-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_problems_ER2007.hh headercheck__dune_gdt_test_linearelliptic_swipdg-testcases.hh headercheck__dune_gdt_test_operators_base.hh headercheck__dune_gdt_test_operators_l2.hh headercheck__dune_gdt_test_projections_base.hh headercheck__dune_gdt_timestepper_factory.hh headercheck__dune_gdt_timestepper_fractional-step.hh test_hyperbolic__fv_discretization__yaspgrid_godunov_euler test_linearelliptic__cg_discretization_ESV2007TestCase_Yasp2_pdelab_istl_sparse test_linearelliptic__cg_discretization_MixedBoundaryTestCase_Yasp2_pdelab_istl_sparse test_linearelliptic__swipdg_discretization_ESV2007TestCase_Yasp2_fem_istl_sparse test_linearelliptic__swipdg_discretization_MixedBoundaryTestCase_Alu2_Simp_nonc_fem_eigen_sparse test_operators__l2__operator test_projections__cg_fem test_projections__l2__rt_pdelab test_projections__l2_global__cg_pdelab test_projections__l2_local_localizable__dg_fem test_prolongations__l2_localizable__cg_fem test_prolongations__l2_localizable__dg_fem test_spaces__cg__fem)
set_tests_properties(test_hyperbolic__fv_discretization__yaspgrid_godunov_euler PROPERTIES LABELS "builder_5")
set_tests_properties( PROPERTIES LABELS "builder_5")
set_tests_properties( PROPERTIES LABELS "builder_5")
set_tests_properties( PROPERTIES LABELS "builder_5")
set_tests_properties( PROPERTIES LABELS "builder_5")
set_tests_properties(test_operators__l2__operator PROPERTIES LABELS "builder_5")
set_tests_properties(test_projections__cg_fem PROPERTIES LABELS "builder_5")
set_tests_properties(test_projections__l2__rt_pdelab PROPERTIES LABELS "builder_5")
set_tests_properties(test_projections__l2_global__cg_pdelab PROPERTIES LABELS "builder_5")
set_tests_properties(test_projections__l2_local_localizable__dg_fem PROPERTIES LABELS "builder_5")
set_tests_properties(test_prolongations__l2_localizable__cg_fem PROPERTIES LABELS "builder_5")
set_tests_properties(test_prolongations__l2_localizable__dg_fem PROPERTIES LABELS "builder_5")
set_tests_properties(test_spaces__cg__fem PROPERTIES LABELS "builder_5")
add_custom_target(test_binaries_builder_6 DEPENDS headercheck__dune_gdt_assembler_system.hh headercheck__dune_gdt_exceptions.hh headercheck__dune_gdt_functionals_elliptic-ipdg.hh headercheck__dune_gdt_functionals_interfaces.hh headercheck__dune_gdt_local_integrands_interfaces.hh headercheck__dune_gdt_local_integrands_product.hh headercheck__dune_gdt_local_operators_fv.hh headercheck__dune_gdt_operators_fluxreconstruction.hh headercheck__dune_gdt_operators_fv.hh headercheck__dune_gdt_playground_local_integrands_OS2014.hh headercheck__dune_gdt_playground_spaces_mapper_dune-pdelab-wrapper.hh headercheck__dune_gdt_projections.hh headercheck__dune_gdt_prolongations_lagrange.hh headercheck__dune_gdt_spaces_basefunctionset_dune-fem-localfunctions-wrapper.hh headercheck__dune_gdt_spaces_dg_interface.hh headercheck__dune_gdt_spaces_fv.hh headercheck__dune_gdt_spaces_fv_product.hh headercheck__dune_gdt_test_grids.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations.hh headercheck__dune_gdt_test_hyperbolic_eocstudy.hh headercheck__dune_gdt_test_hyperbolic_problems.hh headercheck__dune_gdt_test_hyperbolic_problems_fokkerplanck_rectangularic.hh headercheck__dune_gdt_test_linearelliptic_discretizers_cg.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-er2007-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-er2007-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-mixedboundary-2dyaspgrid.hh headercheck__dune_gdt_test_linearelliptic_estimators_swipdg-fluxreconstruction.hh headercheck__dune_gdt_test_linearelliptic_problems_AO2013.hh headercheck__dune_gdt_test_linearelliptic_swipdg-estimator-expectations.hh headercheck__dune_gdt_test_linearelliptic_swipdg-estimator-testcases.hh headercheck__dune_gdt_test_operators_elliptic.hh headercheck__dune_gdt_test_projections_l2-local.hh headercheck__dune_gdt_test_prolongations_base.hh test_linearelliptic__cg_discretization_AO2013TestCase_Alu2_Simp_nonc_pdelab_eigen_sparse test_linearelliptic__cg_discretization_ER2007TestCase_Alu2_Simp_nonc_pdelab_eigen_sparse test_linearelliptic__cg_discretization_MixedBoundaryTestCase_Alu2_Simp_nonc_fem_istl_sparse test_linearelliptic__cg_discretization_MixedBoundaryTestCase_Yasp2_pdelab_eigen_sparse test_linearelliptic__cg_discretization_Spe10Model1TestCase_Alu2_Simp_nonc_fem_eigen_sparse test_operators__elliptic__operator test_projections__l2__dg_pdelab test_projections__l2_global_localizable__cg_pdelab test_projections__l2_localizable__dg_fem test_projections__rt_pdelab test_prolongations__l2_localizable__dg_pdelab test_spaces__rt__pdelab)
set_tests_properties( PROPERTIES LABELS "builder_6")
set_tests_properties( PROPERTIES LABELS "builder_6")
set_tests_properties( PROPERTIES LABELS "builder_6")
set_tests_properties( PROPERTIES LABELS "builder_6")
set_tests_properties( PROPERTIES LABELS "builder_6")
set_tests_properties(test_operators__elliptic__operator PROPERTIES LABELS "builder_6")
set_tests_properties(test_projections__l2__dg_pdelab PROPERTIES LABELS "builder_6")
set_tests_properties(test_projections__l2_global_localizable__cg_pdelab PROPERTIES LABELS "builder_6")
set_tests_properties(test_projections__l2_localizable__dg_fem PROPERTIES LABELS "builder_6")
set_tests_properties(test_projections__rt_pdelab PROPERTIES LABELS "builder_6")
set_tests_properties(test_prolongations__l2_localizable__dg_pdelab PROPERTIES LABELS "builder_6")
set_tests_properties(test_spaces__rt__pdelab PROPERTIES LABELS "builder_6")
add_custom_target(test_binaries_builder_7 DEPENDS headercheck__dune_gdt_functionals_base.hh headercheck__dune_gdt_local_operators_integrals.hh headercheck__dune_gdt_operators_darcy.hh headercheck__dune_gdt_projections_l2-global.hh headercheck__dune_gdt_projections_l2-local.hh headercheck__dune_gdt_spaces_basefunctionset_dune-fem-wrapper.hh headercheck__dune_gdt_spaces_cg_dune-fem-wrapper.hh headercheck__dune_gdt_spaces_cg_interface.hh headercheck__dune_gdt_spaces_mapper_dune-pdelab-wrapper.hh headercheck__dune_gdt_spaces_mapper_fv.hh headercheck__dune_gdt_test_hyperbolic_discretizers_base.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations-fv-burgers-1dyaspgrid.hh headercheck__dune_gdt_test_hyperbolic_problems_2dboltzmann.hh headercheck__dune_gdt_test_linearelliptic_eocstudy.hh headercheck__dune_gdt_test_spaces_fv_default.hh test_linearelliptic__cg_discretization_MixedBoundaryTestCase_Alu2_Simp_nonc_pdelab_eigen_sparse test_linearelliptic__cg_discretization_Spe10Model1TestCase_Alu2_Simp_nonc_fem_istl_sparse test_linearelliptic__cg_discretization_Spe10Model1TestCase_Yasp2_pdelab_istl_sparse test_linearelliptic__swipdg_discretization_ESV2007TestCase_Alu2_Simp_nonc_fem_istl_sparse test_linearelliptic__swipdg_discretization_ESV2007TestCase_Yasp2_fem_eigen_sparse test_operators__elliptic__localizable_product test_projections__l2__fv_default test_projections__l2_local__rt_pdelab test_projections__l2_localizable__rt_pdelab test_projections__lagrange__cg_pdelab test_prolongations__l2_local__fv_default test_prolongations__l2_localizable__cg_pdelab)
set_tests_properties( PROPERTIES LABELS "builder_7")
set_tests_properties( PROPERTIES LABELS "builder_7")
set_tests_properties( PROPERTIES LABELS "builder_7")
set_tests_properties( PROPERTIES LABELS "builder_7")
set_tests_properties( PROPERTIES LABELS "builder_7")
set_tests_properties(test_operators__elliptic__localizable_product PROPERTIES LABELS "builder_7")
set_tests_properties(test_projections__l2__fv_default PROPERTIES LABELS "builder_7")
set_tests_properties(test_projections__l2_local__rt_pdelab PROPERTIES LABELS "builder_7")
set_tests_properties(test_projections__l2_localizable__rt_pdelab PROPERTIES LABELS "builder_7")
set_tests_properties(test_projections__lagrange__cg_pdelab PROPERTIES LABELS "builder_7")
set_tests_properties(test_prolongations__l2_local__fv_default PROPERTIES LABELS "builder_7")
set_tests_properties(test_prolongations__l2_localizable__cg_pdelab PROPERTIES LABELS "builder_7")
add_custom_target(test_binaries_builder_8 DEPENDS headercheck__dune_gdt_discretizations_default.hh headercheck__dune_gdt_local_integrands_elliptic-ipdg.hh headercheck__dune_gdt_operators_l2.hh headercheck__dune_gdt_spaces_basefunctionset_product.hh headercheck__dune_gdt_spaces_fv_interface.hh headercheck__dune_gdt_spaces_rt_interface.hh headercheck__dune_gdt_test_hyperbolic_problems_fokkerplanck_twopulses.hh headercheck__dune_gdt_test_projections_l2-global.hh headercheck__dune_gdt_test_spaces_cg.hh headercheck__dune_gdt_test_spaces_dg_pdelab.hh test_linearelliptic__cg_discretization_AO2013TestCase_Yasp2_fem_eigen_sparse test_linearelliptic__cg_discretization_ER2007TestCase_Alu2_Simp_nonc_fem_istl_sparse test_linearelliptic__cg_discretization_MixedBoundaryTestCase_Yasp2_fem_istl_sparse test_linearelliptic__swipdg_discretization_ESV2007TestCase_Alu2_Simp_nonc_fem_eigen_sparse test_linearelliptic__swipdg_estimators__alugrid_fem_eigen test_operators__darcy test_projections__dg_fem test_prolongations__l2__dg_fem test_prolongations__l2_global__cg_pdelab test_prolongations__l2_local_localizable__dg_pdelab test_prolongations__lagrange_localizable__cg_fem test_spaces__dg__pdelab)
set_tests_properties( PROPERTIES LABELS "builder_8")
set_tests_properties( PROPERTIES LABELS "builder_8")
set_tests_properties( PROPERTIES LABELS "builder_8")
set_tests_properties( PROPERTIES LABELS "builder_8")
set_tests_properties(test_linearelliptic__swipdg_estimators__alugrid_fem_eigen PROPERTIES LABELS "builder_8")
set_tests_properties(test_operators__darcy PROPERTIES LABELS "builder_8")
set_tests_properties(test_projections__dg_fem PROPERTIES LABELS "builder_8")
set_tests_properties(test_prolongations__l2__dg_fem PROPERTIES LABELS "builder_8")
set_tests_properties(test_prolongations__l2_global__cg_pdelab PROPERTIES LABELS "builder_8")
set_tests_properties(test_prolongations__l2_local_localizable__dg_pdelab PROPERTIES LABELS "builder_8")
set_tests_properties(test_prolongations__lagrange_localizable__cg_fem PROPERTIES LABELS "builder_8")
set_tests_properties(test_spaces__dg__pdelab PROPERTIES LABELS "builder_8")
add_custom_target(test_binaries_builder_9 DEPENDS headercheck__dune_gdt_discretefunction_default.hh headercheck__dune_gdt_discretefunction_reinterpret.hh headercheck__dune_gdt_discretizations_interfaces.hh headercheck__dune_gdt_local_discretefunction.hh headercheck__dune_gdt_local_dof-vector.hh headercheck__dune_gdt_local_fluxes_laxfriedrichs.hh headercheck__dune_gdt_local_fluxes_rhs.hh headercheck__dune_gdt_local_integrands_elliptic.hh headercheck__dune_gdt_local_integrands_sipdg.hh headercheck__dune_gdt_local_operators_dirichlet-projection.hh headercheck__dune_gdt_operators_elliptic-ipdg.hh headercheck__dune_gdt_operators_interfaces.hh headercheck__dune_gdt_operators_oswaldinterpolation.hh headercheck__dune_gdt_projections_l2.hh headercheck__dune_gdt_prolongations_l2-local.hh headercheck__dune_gdt_spaces_cg_dune-pdelab-wrapper.hh headercheck__dune_gdt_spaces_parallel.hh headercheck__dune_gdt_test_hyperbolic_discretizers_fv.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations-fv-burgers-2dyaspgrid.hh headercheck__dune_gdt_test_hyperbolic_eocexpectations-fv-transport-1dyaspgrid.hh headercheck__dune_gdt_test_hyperbolic_problems_interface.hh headercheck__dune_gdt_test_hyperbolic_problems_sodshocktube.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_cg-mixedboundary-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_eocexpectations_swipdg-spe10-2dalugrid.hh headercheck__dune_gdt_test_linearelliptic_problems_interface.hh headercheck__dune_gdt_test_linearelliptic_problems_mixedboundary.hh headercheck__dune_gdt_test_linearelliptic_swipdg-estimators.hh headercheck__dune_gdt_test_operators_darcy.hh headercheck__dune_gdt_test_operators_laplace.hh headercheck__dune_gdt_test_prolongations_l2-global.hh headercheck__dune_gdt_test_prolongations_l2-local.hh headercheck__dune_gdt_test_prolongations_lagrange.hh headercheck__dune_gdt_test_stationary-eocstudy.hh headercheck__dune_gdt_test_stationary-testcase.hh test_linearelliptic__cg_discretization_AO2013TestCase_Yasp2_fem_istl_sparse test_linearelliptic__cg_discretization_ER2007TestCase_Alu2_Simp_nonc_pdelab_istl_sparse test_linearelliptic__cg_discretization_ESV2007TestCase_Alu2_Simp_nonc_fem_eigen_sparse test_linearelliptic__cg_discretization_MixedBoundaryTestCase_Alu2_Simp_nonc_fem_eigen_sparse test_linearelliptic__cg_discretization_MixedBoundaryTestCase_Yasp2_fem_eigen_sparse test_operators__weighted_l2__localizable_product test_projections__l2__dg_fem test_projections__l2_local__fv_default test_prolongations__l2__cg_pdelab test_prolongations__l2_localizable__fv_default test_prolongations__lagrange__cg_fem test_prolongations__rt_pdelab)
set_tests_properties( PROPERTIES LABELS "builder_9")
set_tests_properties( PROPERTIES LABELS "builder_9")
set_tests_properties( PROPERTIES LABELS "builder_9")
set_tests_properties( PROPERTIES LABELS "builder_9")
set_tests_properties( PROPERTIES LABELS "builder_9")
set_tests_properties(test_operators__weighted_l2__localizable_product PROPERTIES LABELS "builder_9")
set_tests_properties(test_projections__l2__dg_fem PROPERTIES LABELS "builder_9")
set_tests_properties(test_projections__l2_local__fv_default PROPERTIES LABELS "builder_9")
set_tests_properties(test_prolongations__l2__cg_pdelab PROPERTIES LABELS "builder_9")
set_tests_properties(test_prolongations__l2_localizable__fv_default PROPERTIES LABELS "builder_9")
set_tests_properties(test_prolongations__lagrange__cg_fem PROPERTIES LABELS "builder_9")
set_tests_properties(test_prolongations__rt_pdelab PROPERTIES LABELS "builder_9")
add_custom_target(test_binaries_builder_10 DEPENDS test_linearelliptic__cg_discretization_AO2013TestCase_Yasp2_pdelab_eigen_sparse test_linearelliptic__cg_discretization_ER2007TestCase_Yasp2_pdelab_istl_sparse test_linearelliptic__cg_discretization_ESV2007TestCase_Alu2_Simp_nonc_pdelab_istl_sparse test_linearelliptic__swipdg_discretization_AO2013TestCase_Alu2_Simp_nonc_fem_eigen_sparse test_linearelliptic__swipdg_discretization_ER2007TestCase_Alu2_Simp_nonc_fem_istl_sparse test_operators__weighted_l2__matrix_operator test_projections__l2_local_localizable__dg_pdelab test_projections__lagrange_localizable__cg_pdelab test_prolongations__l2__rt_pdelab test_prolongations__l2_global_localizable__cg_pdelab test_prolongations__lagrange__cg_pdelab test_spaces__dg__fem)
set_tests_properties( PROPERTIES LABELS "builder_10")
set_tests_properties( PROPERTIES LABELS "builder_10")
set_tests_properties( PROPERTIES LABELS "builder_10")
set_tests_properties( PROPERTIES LABELS "builder_10")
set_tests_properties( PROPERTIES LABELS "builder_10")
set_tests_properties(test_operators__weighted_l2__matrix_operator PROPERTIES LABELS "builder_10")
set_tests_properties(test_projections__l2_local_localizable__dg_pdelab PROPERTIES LABELS "builder_10")
set_tests_properties(test_projections__lagrange_localizable__cg_pdelab PROPERTIES LABELS "builder_10")
set_tests_properties(test_prolongations__l2__rt_pdelab PROPERTIES LABELS "builder_10")
set_tests_properties(test_prolongations__l2_global_localizable__cg_pdelab PROPERTIES LABELS "builder_10")
set_tests_properties(test_prolongations__lagrange__cg_pdelab PROPERTIES LABELS "builder_10")
set_tests_properties(test_spaces__dg__fem PROPERTIES LABELS "builder_10")
add_custom_target(test_binaries_builder_11 DEPENDS headercheck__dune_gdt_local_fluxes_analytical.hh headercheck__dune_gdt_local_operators_l2-projection.hh headercheck__dune_gdt_playground_spaces_cg_dune-fem-localfunctions-wrapper.hh headercheck__dune_gdt_prolongations_l2-global.hh headercheck__dune_gdt_spaces_dg.hh headercheck__dune_gdt_spaces_product.hh headercheck__dune_gdt_test_linearelliptic_problems.hh headercheck__dune_gdt_test_linearelliptic_problems_base.hh headercheck__dune_gdt_test_spaces_cg_fem.hh test_linearelliptic__cg_discretization_ER2007TestCase_Yasp2_fem_istl_sparse test_linearelliptic__cg_discretization_ER2007TestCase_Yasp2_pdelab_eigen_sparse test_linearelliptic__cg_discretization_ESV2007TestCase_Yasp2_fem_eigen_sparse test_linearelliptic__cg_discretization_Spe10Model1TestCase_Alu2_Simp_nonc_pdelab_eigen_sparse test_linearelliptic__swipdg_discretization_ER2007TestCase_Yasp2_fem_eigen_sparse test_operators__laplace__operator test_projections__cg_pdelab test_projections__l2_local_localizable__fv_default test_projections__l2_localizable__cg_fem test_prolongations__dg_pdelab test_prolongations__l2_local__dg_pdelab test_prolongations__l2_local_localizable__fv_default)
set_tests_properties( PROPERTIES LABELS "builder_11")
set_tests_properties( PROPERTIES LABELS "builder_11")
set_tests_properties( PROPERTIES LABELS "builder_11")
set_tests_properties( PROPERTIES LABELS "builder_11")
set_tests_properties( PROPERTIES LABELS "builder_11")
set_tests_properties(test_operators__laplace__operator PROPERTIES LABELS "builder_11")
set_tests_properties(test_projections__cg_pdelab PROPERTIES LABELS "builder_11")
set_tests_properties(test_projections__l2_local_localizable__fv_default PROPERTIES LABELS "builder_11")
set_tests_properties(test_projections__l2_localizable__cg_fem PROPERTIES LABELS "builder_11")
set_tests_properties(test_prolongations__dg_pdelab PROPERTIES LABELS "builder_11")
set_tests_properties(test_prolongations__l2_local__dg_pdelab PROPERTIES LABELS "builder_11")
set_tests_properties(test_prolongations__l2_local_localizable__fv_default PROPERTIES LABELS "builder_11")
