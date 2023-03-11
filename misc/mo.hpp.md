---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
    title: verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/misc/mo.hpp
    - https://snuke.hatenablog.com/entry/2016/07/01/000000
  bundledCode: "#line 2 \"misc/mo.hpp\"\n\n// Mo's Algorithm\n// https://snuke.hatenablog.com/entry/2016/07/01/000000\n\
    // complexity: O(N^2/B + QB)\n// -> O(N sqrt(Q)) (B := N / sqrt(Q))\ntemplate\
    \ <class AddLeft, class AddRight, class DelLeft, class DelRight, class Out>  //\n\
    void mo(const int &n, const std::vector<int> &l, const std::vector<int> &r,  \
    \       //\n        const AddLeft &add_left, const AddRight &add_right,      \
    \                   //\n        const DelLeft &del_left, const DelRight &del_right,\
    \ const Out &out) {\n    const int q = (int)l.size();\n    // normal\n    // const\
    \ int bucket_size = n / std::min(n, (int)sqrt(q));\n    // speed up by https://nyaannyaan.github.io/library/misc/mo.hpp\n\
    \    const int bucket_size = n / std::min(n, (int)sqrt(2.0 * q / 3.0));\n    std::vector<int>\
    \ ind(q), lbs(q);\n    // reduce the number of divisions by memoization\n    for\
    \ (int i = 0; i < q; i++) lbs[i] = l[i] / bucket_size;\n    std::iota(ind.begin(),\
    \ ind.end(), 0);\n    std::sort(ind.begin(), ind.end(), [&](int i, int j) {\n\
    \        if (lbs[i] != lbs[j]) return l[i] < l[j];\n        return (lbs[i] & 1)\
    \ ? r[i] > r[j] : r[i] < r[j];\n    });\n    int now_l = 0, now_r = 0;\n    for\
    \ (auto &&i : ind) {\n        while (now_l > l[i]) add_left(--now_l);\n      \
    \  while (now_r < r[i]) add_right(now_r++);\n        while (now_l < l[i]) del_left(now_l++);\n\
    \        while (now_r > r[i]) del_right(--now_r);\n        out(i);\n    }\n}\n\
    \ntemplate <class Add, class Del, class Out>                                 \
    \ //\nvoid mo(const int n, const std::vector<int> &l, const std::vector<int> &r,\
    \  //\n        const Add &add, const Del &del, const Out &out) {\n    mo(n, l,\
    \ r, add, add, del, del, out);\n}\n"
  code: "#pragma once\n\n// Mo's Algorithm\n// https://snuke.hatenablog.com/entry/2016/07/01/000000\n\
    // complexity: O(N^2/B + QB)\n// -> O(N sqrt(Q)) (B := N / sqrt(Q))\ntemplate\
    \ <class AddLeft, class AddRight, class DelLeft, class DelRight, class Out>  //\n\
    void mo(const int &n, const std::vector<int> &l, const std::vector<int> &r,  \
    \       //\n        const AddLeft &add_left, const AddRight &add_right,      \
    \                   //\n        const DelLeft &del_left, const DelRight &del_right,\
    \ const Out &out) {\n    const int q = (int)l.size();\n    // normal\n    // const\
    \ int bucket_size = n / std::min(n, (int)sqrt(q));\n    // speed up by https://nyaannyaan.github.io/library/misc/mo.hpp\n\
    \    const int bucket_size = n / std::min(n, (int)sqrt(2.0 * q / 3.0));\n    std::vector<int>\
    \ ind(q), lbs(q);\n    // reduce the number of divisions by memoization\n    for\
    \ (int i = 0; i < q; i++) lbs[i] = l[i] / bucket_size;\n    std::iota(ind.begin(),\
    \ ind.end(), 0);\n    std::sort(ind.begin(), ind.end(), [&](int i, int j) {\n\
    \        if (lbs[i] != lbs[j]) return l[i] < l[j];\n        return (lbs[i] & 1)\
    \ ? r[i] > r[j] : r[i] < r[j];\n    });\n    int now_l = 0, now_r = 0;\n    for\
    \ (auto &&i : ind) {\n        while (now_l > l[i]) add_left(--now_l);\n      \
    \  while (now_r < r[i]) add_right(now_r++);\n        while (now_l < l[i]) del_left(now_l++);\n\
    \        while (now_r > r[i]) del_right(--now_r);\n        out(i);\n    }\n}\n\
    \ntemplate <class Add, class Del, class Out>                                 \
    \ //\nvoid mo(const int n, const std::vector<int> &l, const std::vector<int> &r,\
    \  //\n        const Add &add, const Del &del, const Out &out) {\n    mo(n, l,\
    \ r, add, add, del, del, out);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2023-03-12 06:20:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_data_structure/lc_static_range_inversions_query.test.cpp
documentation_of: misc/mo.hpp
layout: document
title: Mo's Algorithm
---

## 使用例

- [ABC293 G](https://atcoder.jp/contests/abc293/submissions/39654125)
