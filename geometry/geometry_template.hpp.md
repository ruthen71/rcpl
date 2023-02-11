---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  requiredBy: []
  timestamp: '2023-02-11 12:18:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry_template.hpp
layout: document
redirect_from:
- /library/geometry/geometry_template.hpp
- /library/geometry/geometry_template.hpp.html
title: geometry/geometry_template.hpp
---
