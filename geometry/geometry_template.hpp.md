---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':warning:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
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
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
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
  - geometry/is_orthogonal.hpp
  - geometry/reflection.hpp
  - geometry/projection.hpp
  - geometry/circle.hpp
  - geometry/ccw.hpp
  - geometry/is_parallel.hpp
  timestamp: '2023-02-11 12:18:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_cgl/aoj_cgl_2_a.test.cpp
  - verify/aoj_cgl/aoj_cgl_1_c.test.cpp
  - verify/aoj_cgl/aoj_cgl_1_b.test.cpp
  - verify/aoj_cgl/aoj_cgl_1_a.test.cpp
documentation_of: geometry/geometry_template.hpp
layout: document
redirect_from:
- /library/geometry/geometry_template.hpp
- /library/geometry/geometry_template.hpp.html
title: geometry/geometry_template.hpp
---
