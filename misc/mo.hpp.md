---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/misc/mo.test.cpp
    title: verify/misc/mo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://nyaannyaan.github.io/library/misc/mo.hpp
    - https://snuke.hatenablog.com/entry/2016/07/01/000000
  bundledCode: "#line 2 \"misc/mo.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    #include <numeric>\n\n// Mo's Algorithm\n// https://snuke.hatenablog.com/entry/2016/07/01/000000\n\
    // complexity: O(N * N / B + Q * B)\n// -> O(N sqrt(Q)) (B := N / sqrt(Q))\ntemplate\
    \ <class AddLeft, class AddRight, class DelLeft, class DelRight, class Out>\n\
    void mo(const int n, const std::vector<int> l, const std::vector<int> r, const\
    \ AddLeft &add_left,\n        const AddRight &add_right, const DelLeft &del_left,\
    \ const DelRight &del_right,\n        const Out &out, const int bucket_size_value\
    \ = -1) {\n    const int q = (int)(l.size());\n    if (q == 0) return;\n    //\
    \ determine bucket size\n    auto calculate_bucket_size = [&]() {\n        //\
    \ const int bucket_size = std::max(1.0, n / std::max(1.0, sqrt(q)));\n       \
    \ // speed up by https://nyaannyaan.github.io/library/misc/mo.hpp\n        const\
    \ int bucket_size = std::max(1.0, n / std::max(1.0, sqrt(2.0 * q / 3.0)));\n \
    \       return bucket_size;\n    };\n    const int bucket_size = bucket_size_value\
    \ == -1 ? calculate_bucket_size() : bucket_size_value;\n    std::vector<int> ind(q),\
    \ lbs(q);\n    // reduce the number of divisions by memoization\n    for (int\
    \ i = 0; i < q; i++) lbs[i] = l[i] / bucket_size;\n    std::iota(ind.begin(),\
    \ ind.end(), 0);\n    std::sort(ind.begin(), ind.end(), [&](int i, int j) {\n\
    \        if (lbs[i] != lbs[j]) return l[i] < l[j];\n        return (lbs[i] & 1)\
    \ ? r[i] > r[j] : r[i] < r[j];\n    });\n    // \u4EE5\u524D\u306F now_l = now_r\
    \ = l[ind.front()] \u3068\u3057\u3066\u3044\u305F\u304C, \u3053\u308C\u306F [now_l,\
    \ now_r) \u306B\u5BFE\u3059\u308B\u7B54\u3048\u304C\n    // [0, 0) \u3068\u540C\
    \u3058\u3067\u306A\u3044\u3068\u58CA\u308C\u308B\n    int now_l = 0, now_r = 0;\n\
    \    for (auto &&i : ind) {\n        while (now_l > l[i]) add_left(--now_l);\n\
    \        while (now_r < r[i]) add_right(now_r++);\n        while (now_l < l[i])\
    \ del_left(now_l++);\n        while (now_r > r[i]) del_right(--now_r);\n     \
    \   out(i);\n    }\n}\ntemplate <class Add, class Del, class Out>            \
    \                      //\nvoid mo(const int n, const std::vector<int> &l, const\
    \ std::vector<int> &r,  //\n        const Add &add, const Del &del, const Out\
    \ &out, const int bucket_size_value = -1) {\n    mo(n, l, r, add, add, del, del,\
    \ out, bucket_size_value);\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n#include <numeric>\n\
    \n// Mo's Algorithm\n// https://snuke.hatenablog.com/entry/2016/07/01/000000\n\
    // complexity: O(N * N / B + Q * B)\n// -> O(N sqrt(Q)) (B := N / sqrt(Q))\ntemplate\
    \ <class AddLeft, class AddRight, class DelLeft, class DelRight, class Out>\n\
    void mo(const int n, const std::vector<int> l, const std::vector<int> r, const\
    \ AddLeft &add_left,\n        const AddRight &add_right, const DelLeft &del_left,\
    \ const DelRight &del_right,\n        const Out &out, const int bucket_size_value\
    \ = -1) {\n    const int q = (int)(l.size());\n    if (q == 0) return;\n    //\
    \ determine bucket size\n    auto calculate_bucket_size = [&]() {\n        //\
    \ const int bucket_size = std::max(1.0, n / std::max(1.0, sqrt(q)));\n       \
    \ // speed up by https://nyaannyaan.github.io/library/misc/mo.hpp\n        const\
    \ int bucket_size = std::max(1.0, n / std::max(1.0, sqrt(2.0 * q / 3.0)));\n \
    \       return bucket_size;\n    };\n    const int bucket_size = bucket_size_value\
    \ == -1 ? calculate_bucket_size() : bucket_size_value;\n    std::vector<int> ind(q),\
    \ lbs(q);\n    // reduce the number of divisions by memoization\n    for (int\
    \ i = 0; i < q; i++) lbs[i] = l[i] / bucket_size;\n    std::iota(ind.begin(),\
    \ ind.end(), 0);\n    std::sort(ind.begin(), ind.end(), [&](int i, int j) {\n\
    \        if (lbs[i] != lbs[j]) return l[i] < l[j];\n        return (lbs[i] & 1)\
    \ ? r[i] > r[j] : r[i] < r[j];\n    });\n    // \u4EE5\u524D\u306F now_l = now_r\
    \ = l[ind.front()] \u3068\u3057\u3066\u3044\u305F\u304C, \u3053\u308C\u306F [now_l,\
    \ now_r) \u306B\u5BFE\u3059\u308B\u7B54\u3048\u304C\n    // [0, 0) \u3068\u540C\
    \u3058\u3067\u306A\u3044\u3068\u58CA\u308C\u308B\n    int now_l = 0, now_r = 0;\n\
    \    for (auto &&i : ind) {\n        while (now_l > l[i]) add_left(--now_l);\n\
    \        while (now_r < r[i]) add_right(now_r++);\n        while (now_l < l[i])\
    \ del_left(now_l++);\n        while (now_r > r[i]) del_right(--now_r);\n     \
    \   out(i);\n    }\n}\ntemplate <class Add, class Del, class Out>            \
    \                      //\nvoid mo(const int n, const std::vector<int> &l, const\
    \ std::vector<int> &r,  //\n        const Add &add, const Del &del, const Out\
    \ &out, const int bucket_size_value = -1) {\n    mo(n, l, r, add, add, del, del,\
    \ out, bucket_size_value);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2024-12-17 21:01:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/misc/mo.test.cpp
documentation_of: misc/mo.hpp
layout: document
title: Mo's Algorithm
---

## 使用例

- [AtCoder Beginner Contest 384 G - Abs Sum](https://atcoder.jp/contests/abc384/tasks/abc384_g)
    - 区間 $ [l, r) $ に対するクエリではなく, 区間 $ [0, l) $ と区間 $ [0, r) $ に対するクエリと考えると, `add_left` と `del_left` の渡し方を逆にすれば良い
    - [提出例](https://atcoder.jp/contests/abc384/submissions/60852613)
- [AtCoder Beginner Contest 293 G - Triple Index](https://atcoder.jp/contests/abc293/tasks/abc293_g)
- [AtCoder Beginner Contest 238 G - Cubic?](https://atcoder.jp/contests/abc238/tasks/abc238_g)
