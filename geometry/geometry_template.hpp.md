---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/area.hpp
    title: geometry/area.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/contain.hpp
    title: geometry/contain.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cl.hpp
    title: geometry/cross_point_cl.hpp
  - icon: ':warning:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ss.hpp
    title: geometry/cross_point_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_lp.hpp
    title: geometry/distance_lp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_sp.hpp
    title: geometry/distance_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_ss.hpp
    title: geometry/distance_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_convex.hpp
    title: geometry/is_convex.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cl.hpp
    title: geometry/is_intersect_cl.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_cp.hpp
    title: geometry/is_intersect_cp.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_ll.hpp
    title: geometry/is_intersect_ll.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_lp.hpp
    title: geometry/is_intersect_lp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_sp.hpp
    title: geometry/is_intersect_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_ss.hpp
    title: geometry/is_intersect_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_orthogonal.hpp
    title: geometry/is_orthogonal.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_parallel.hpp
    title: geometry/is_parallel.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_1_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_1_b.test.cpp
    title: verify/aoj_cgl/aoj_cgl_1_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_1_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_1_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_2_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_2_b.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_2_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
    title: verify/aoj_cgl/aoj_cgl_2_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_3_b.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_b.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_3_c.test.cpp
    title: verify/aoj_cgl/aoj_cgl_3_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj_cgl/aoj_cgl_7_e.test.cpp
    title: verify/aoj_cgl/aoj_cgl_7_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "geometry/geometry_template.hpp"


    // template

    using Double = double;

    const Double EPS = 1e-8;

    const Double PI = std::acos(-1);

    inline int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0);
    }

    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;
    }

    Double radian_to_degree(const Double &r) { return r * 180.0 / PI; }

    Double degree_to_radian(const Double &d) { return d * PI / 180.0; }

    '
  code: '#pragma once


    // template

    using Double = double;

    const Double EPS = 1e-8;

    const Double PI = std::acos(-1);

    inline int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0);
    }

    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;
    }

    Double radian_to_degree(const Double &r) { return r * 180.0 / PI; }

    Double degree_to_radian(const Double &d) { return d * PI / 180.0; }'
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry_template.hpp
  requiredBy:
  - geometry/line.hpp
  - geometry/point.hpp
  - geometry/area.hpp
  - geometry/cross_point_ss.hpp
  - geometry/is_orthogonal.hpp
  - geometry/segment.hpp
  - geometry/cross_point_cc.hpp
  - geometry/distance_sp.hpp
  - geometry/is_intersect_cc.hpp
  - geometry/tangent_number_cc.hpp
  - geometry/reflection.hpp
  - geometry/projection.hpp
  - geometry/cross_point_ll.hpp
  - geometry/is_intersect_ll.hpp
  - geometry/is_convex.hpp
  - geometry/is_intersect_ss.hpp
  - geometry/is_intersect_cl.hpp
  - geometry/circle.hpp
  - geometry/is_intersect_lp.hpp
  - geometry/is_intersect_sp.hpp
  - geometry/polygon.hpp
  - geometry/cross_point_cl.hpp
  - geometry/distance_ss.hpp
  - geometry/ccw.hpp
  - geometry/distance_lp.hpp
  - geometry/contain.hpp
  - geometry/is_intersect_cp.hpp
  - geometry/all.hpp
  - geometry/is_parallel.hpp
  timestamp: '2023-02-11 12:18:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_3_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_2_d.test.cpp
  - verify/aoj_cgl/aoj_cgl_2_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_e.test.cpp
  - verify/aoj_cgl/aoj_cgl_3_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_1_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_1_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_2_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_3_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_7_d.test.cpp
  - verify/aoj_cgl/aoj_cgl_2_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_1_a.test.cpp
documentation_of: geometry/geometry_template.hpp
layout: document
redirect_from:
- /library/geometry/geometry_template.hpp
- /library/geometry/geometry_template.hpp.html
title: geometry/geometry_template.hpp
---
