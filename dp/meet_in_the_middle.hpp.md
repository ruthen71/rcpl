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
  bundledCode: "#line 2 \"dp/meet_in_the_middle.hpp\"\n#include <vector>\n\n// find\
    \ s that sum s[i] * a[i] = x (s[i] = 1 or -1)\n// O(n 2 ^ n) (n: size of a)\n\
    template <class T> std::vector<int> meet_in_the_middle(const std::vector<T>& a,\
    \ T x) {\n    const int n = int(a.size());\n    const int n1 = n / 2, n2 = n -\
    \ n1;\n    std::unordered_map<T, int> mp;\n    std::vector<int> res(n, 0);\n \
    \   for (int bit = 0; bit < (1 << n1); bit++) {\n        T c = T(0);\n       \
    \ for (int i = 0; i < n1; i++) {\n            if (bit >> i & 1) {\n          \
    \      c += a[i];\n            } else {\n                c -= a[i];\n        \
    \    }\n        }\n        mp[c] = bit;\n    }\n    for (int bit = 0; bit < (1\
    \ << n2); bit++) {\n        T d = T(0);\n        for (int i = 0; i < n2; i++)\
    \ {\n            if (bit >> i & 1) {\n                d += a[i + n1];\n      \
    \      } else {\n                d -= a[i + n1];\n            }\n        }\n \
    \       if (mp.count(x - d)) {\n            for (int i = 0; i < n1; i++) res[i]\
    \ = (mp[x - d] >> i & 1) * 2 - 1;\n            for (int i = 0; i < n2; i++) res[i\
    \ + n1] = (bit >> i & 1) * 2 - 1;\n            return res;\n        }\n    }\n\
    \    return res;\n}\n\n// calculate all possible sorted { sum s[i] * a[i], bit\
    \ } (using std::inplace_merge)\ntemplate <class T> std::vector<std::pair<T, int>>\
    \ calc_half(const std::vector<T>& a) {\n    int n = int(a.size());\n    std::vector<std::pair<T,\
    \ int>> half(1 << n);\n    int size = 1;\n    half[0] = {T(0), 0};\n    for (int\
    \ i = 0; i < n; i++) {\n        for (int j = 0; j < size; j++) {\n           \
    \ half[j + size] = {half[j].first + a[i], half[j].second | (1 << i)};\n      \
    \  }\n        for (int j = 0; j < size; j++) {\n            half[j].first -= a[i];\n\
    \        }\n        std::inplace_merge(half.begin(), half.begin() + size, half.begin()\
    \ + size * 2);\n        size <<= 1;\n    }\n    return half;\n}\n\n// O(2 ^ n)\
    \ (using std::inplace_merge, Two Pointer Approach)\ntemplate <class T> std::vector<int>\
    \ meet_in_the_middle_faster(const std::vector<T>& a, T x) {\n    const int n =\
    \ int(a.size());\n    const int n1 = n / 2, n2 = n - n1;\n\n    std::vector<T>\
    \ a1(n1), a2(n2);\n    for (int i = 0; i < n1; i++) a1[i] = a[i];\n    for (int\
    \ i = 0; i < n2; i++) a2[i] = a[i + n1];\n\n    auto half1 = calc_half(a1);\n\
    \    auto half2 = calc_half(a2);\n\n    int r = (1 << n2) - 1;\n    std::vector<int>\
    \ res(n, 0);\n    for (int i = 0; i < (1 << n1); i++) {\n        while (r > 0\
    \ and half1[i].first + half2[r].first > x) r--;\n        if (half1[i].first +\
    \ half2[r].first == x) {\n            for (int j = 0; j < n1; j++) res[j] = (half1[i].second\
    \ >> j & 1) * 2 - 1;\n            for (int j = 0; j < n2; j++) res[j + n1] = (half2[r].second\
    \ >> j & 1) * 2 - 1;\n            return res;\n        }\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\n// find s that sum s[i] * a[i] = x (s[i]\
    \ = 1 or -1)\n// O(n 2 ^ n) (n: size of a)\ntemplate <class T> std::vector<int>\
    \ meet_in_the_middle(const std::vector<T>& a, T x) {\n    const int n = int(a.size());\n\
    \    const int n1 = n / 2, n2 = n - n1;\n    std::unordered_map<T, int> mp;\n\
    \    std::vector<int> res(n, 0);\n    for (int bit = 0; bit < (1 << n1); bit++)\
    \ {\n        T c = T(0);\n        for (int i = 0; i < n1; i++) {\n           \
    \ if (bit >> i & 1) {\n                c += a[i];\n            } else {\n    \
    \            c -= a[i];\n            }\n        }\n        mp[c] = bit;\n    }\n\
    \    for (int bit = 0; bit < (1 << n2); bit++) {\n        T d = T(0);\n      \
    \  for (int i = 0; i < n2; i++) {\n            if (bit >> i & 1) {\n         \
    \       d += a[i + n1];\n            } else {\n                d -= a[i + n1];\n\
    \            }\n        }\n        if (mp.count(x - d)) {\n            for (int\
    \ i = 0; i < n1; i++) res[i] = (mp[x - d] >> i & 1) * 2 - 1;\n            for\
    \ (int i = 0; i < n2; i++) res[i + n1] = (bit >> i & 1) * 2 - 1;\n           \
    \ return res;\n        }\n    }\n    return res;\n}\n\n// calculate all possible\
    \ sorted { sum s[i] * a[i], bit } (using std::inplace_merge)\ntemplate <class\
    \ T> std::vector<std::pair<T, int>> calc_half(const std::vector<T>& a) {\n   \
    \ int n = int(a.size());\n    std::vector<std::pair<T, int>> half(1 << n);\n \
    \   int size = 1;\n    half[0] = {T(0), 0};\n    for (int i = 0; i < n; i++) {\n\
    \        for (int j = 0; j < size; j++) {\n            half[j + size] = {half[j].first\
    \ + a[i], half[j].second | (1 << i)};\n        }\n        for (int j = 0; j <\
    \ size; j++) {\n            half[j].first -= a[i];\n        }\n        std::inplace_merge(half.begin(),\
    \ half.begin() + size, half.begin() + size * 2);\n        size <<= 1;\n    }\n\
    \    return half;\n}\n\n// O(2 ^ n) (using std::inplace_merge, Two Pointer Approach)\n\
    template <class T> std::vector<int> meet_in_the_middle_faster(const std::vector<T>&\
    \ a, T x) {\n    const int n = int(a.size());\n    const int n1 = n / 2, n2 =\
    \ n - n1;\n\n    std::vector<T> a1(n1), a2(n2);\n    for (int i = 0; i < n1; i++)\
    \ a1[i] = a[i];\n    for (int i = 0; i < n2; i++) a2[i] = a[i + n1];\n\n    auto\
    \ half1 = calc_half(a1);\n    auto half2 = calc_half(a2);\n\n    int r = (1 <<\
    \ n2) - 1;\n    std::vector<int> res(n, 0);\n    for (int i = 0; i < (1 << n1);\
    \ i++) {\n        while (r > 0 and half1[i].first + half2[r].first > x) r--;\n\
    \        if (half1[i].first + half2[r].first == x) {\n            for (int j =\
    \ 0; j < n1; j++) res[j] = (half1[i].second >> j & 1) * 2 - 1;\n            for\
    \ (int j = 0; j < n2; j++) res[j + n1] = (half2[r].second >> j & 1) * 2 - 1;\n\
    \            return res;\n        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/meet_in_the_middle.hpp
  requiredBy: []
  timestamp: '2024-01-20 13:41:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/meet_in_the_middle.hpp
layout: document
title: "Meet in the middle (\u534A\u5206\u5168\u5217\u6319)"
---

- 数列 $ a $ と整数 $ x $ が与えられたとき、$ \sum s_{i} a_{i} = x $ となるような数列 $ s $ ($ s_{i} $ は $1$ または $-1$) が存在するかを半分全列挙で判定する

- `meet_in_the_middle_faster` はソート済み要素の列挙をマージソート(`std::inplace_merge`)で、存在判定を尺取法で行うことで計算量を $ O(n 2^{n})$ から $ O(2^{n}) $ に落としている

## 使用例

- [ABC326 F](https://atcoder.jp/contests/abc326/submissions/49422940)
