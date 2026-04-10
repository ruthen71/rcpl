---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_max_index_plus.hpp
    title: algebra/acted_monoid/acted_monoid_max_index_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/acted_monoid/acted_monoid_min_index_plus.hpp
    title: algebra/acted_monoid/acted_monoid_min_index_plus.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_max_index.hpp
    title: algebra/monoid/monoid_max_index.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_min_index.hpp
    title: algebra/monoid/monoid_min_index.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
    title: segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/value_index.hpp\"\n\ntemplate <class T> struct ValueIndex\
    \ {\n    T v;\n    int i;\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const ValueIndex& x) {\n        return os << x.v;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct ValueIndex {\n    T v;\n    int\
    \ i;\n    friend std::ostream& operator<<(std::ostream& os, const ValueIndex&\
    \ x) {\n        return os << x.v;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/value_index.hpp
  requiredBy:
  - algebra/monoid/monoid_max_index.hpp
  - algebra/monoid/monoid_min_index.hpp
  - algebra/acted_monoid/acted_monoid_max_index_plus.hpp
  - algebra/acted_monoid/acted_monoid_min_index_plus.hpp
  timestamp: '2026-04-11 00:41:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - segment_tree/test/lazy_segment_tree_min_index_plus.test.cpp
documentation_of: algebra/value_index.hpp
layout: document
redirect_from:
- /library/algebra/value_index.hpp
- /library/algebra/value_index.hpp.html
title: algebra/value_index.hpp
---
