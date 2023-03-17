---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj_dsl/aoj_dsl_5_b.test.cpp
    title: verify/aoj_dsl/aoj_dsl_5_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/cumulative_sum_2d.hpp\"\n\ntemplate <class\
    \ T> struct CumulativeSum2D {\n    int h, w;\n    std::vector<std::vector<T>>\
    \ seg;\n\n    CumulativeSum2D() = default;\n\n    CumulativeSum2D(int h, int w)\
    \ : h(h), w(w), seg(h + 1, std::vector<T>(w + 1, T(0))) {}\n\n    CumulativeSum2D(std::vector<std::vector<T>>\
    \ &a) {\n        h = (int)a.size();\n        assert(h > 0);\n        w = (int)a[0].size();\n\
    \        seg.assign(h + 1, std::vector<T>(w + 1, T(0)));\n        for (int i =\
    \ 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n              \
    \  seg[i + 1][j + 1] = a[i][j];\n            }\n        }\n        for (int i\
    \ = 0; i < h + 1; i++) {\n            for (int j = 0; j < w; j++) {\n        \
    \        seg[i][j + 1] += seg[i][j];\n            }\n        }\n        for (int\
    \ i = 0; i < h; i++) {\n            for (int j = 0; j < w + 1; j++) {\n      \
    \          seg[i + 1][j] += seg[i][j];\n            }\n        }\n    }\n\n  \
    \  // [lx, ly) x [rx, ry)\n    T sum(int lx, int ly, int rx, int ry) {\n     \
    \   assert(0 <= lx and lx <= rx and rx <= h);\n        assert(0 <= ly and ly <=\
    \ ry and ry <= w);\n        return (seg[rx][ry] - seg[lx][ry] - seg[rx][ly] +\
    \ seg[lx][ly]);\n    }\n\n    // (i, j) \\in [lx, ly) x [rx, ry) seg[i][j] +=\
    \ z;\n    void imos(int lx, int ly, int rx, int ry, T z = T(1)) {\n        assert(0\
    \ <= lx and lx <= rx and rx <= h);\n        assert(0 <= ly and ly <= ry and ry\
    \ <= w);\n        seg[lx][ly] += z;\n        seg[lx][ry] -= z;\n        seg[rx][ly]\
    \ -= z;\n        seg[rx][ry] += z;\n    }\n\n    void build() {\n        for (int\
    \ i = 0; i < h + 1; i++) {\n            for (int j = 0; j < w; j++) {\n      \
    \          seg[i][j + 1] += seg[i][j];\n            }\n        }\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w + 1; j++) {\n \
    \               seg[i + 1][j] += seg[i][j];\n            }\n        }\n    }\n\
    \n    // return A[x][y]\n    T get(int x, int y) const {\n        assert(0 <=\
    \ x and x < h and 0 <= y and y < w);\n        return seg[x][y];\n    }\n\n   \
    \ // output\n    friend std::ostream &operator<<(std::ostream &os, const CumulativeSum2D\
    \ &A) {\n        os << \"h = \" << A.h << \", w = \" << A.w << \"\\n\";\n    \
    \    for (int i = 0; i <= A.h; i++) {\n            for (int j = 0; j <= A.w; j++)\
    \ {\n                os << A.seg[i][j] << \" \\n\"[j == A.w];\n            }\n\
    \        }\n        return os;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct CumulativeSum2D {\n    int h, w;\n\
    \    std::vector<std::vector<T>> seg;\n\n    CumulativeSum2D() = default;\n\n\
    \    CumulativeSum2D(int h, int w) : h(h), w(w), seg(h + 1, std::vector<T>(w +\
    \ 1, T(0))) {}\n\n    CumulativeSum2D(std::vector<std::vector<T>> &a) {\n    \
    \    h = (int)a.size();\n        assert(h > 0);\n        w = (int)a[0].size();\n\
    \        seg.assign(h + 1, std::vector<T>(w + 1, T(0)));\n        for (int i =\
    \ 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n              \
    \  seg[i + 1][j + 1] = a[i][j];\n            }\n        }\n        for (int i\
    \ = 0; i < h + 1; i++) {\n            for (int j = 0; j < w; j++) {\n        \
    \        seg[i][j + 1] += seg[i][j];\n            }\n        }\n        for (int\
    \ i = 0; i < h; i++) {\n            for (int j = 0; j < w + 1; j++) {\n      \
    \          seg[i + 1][j] += seg[i][j];\n            }\n        }\n    }\n\n  \
    \  // [lx, ly) x [rx, ry)\n    T sum(int lx, int ly, int rx, int ry) {\n     \
    \   assert(0 <= lx and lx <= rx and rx <= h);\n        assert(0 <= ly and ly <=\
    \ ry and ry <= w);\n        return (seg[rx][ry] - seg[lx][ry] - seg[rx][ly] +\
    \ seg[lx][ly]);\n    }\n\n    // (i, j) \\in [lx, ly) x [rx, ry) seg[i][j] +=\
    \ z;\n    void imos(int lx, int ly, int rx, int ry, T z = T(1)) {\n        assert(0\
    \ <= lx and lx <= rx and rx <= h);\n        assert(0 <= ly and ly <= ry and ry\
    \ <= w);\n        seg[lx][ly] += z;\n        seg[lx][ry] -= z;\n        seg[rx][ly]\
    \ -= z;\n        seg[rx][ry] += z;\n    }\n\n    void build() {\n        for (int\
    \ i = 0; i < h + 1; i++) {\n            for (int j = 0; j < w; j++) {\n      \
    \          seg[i][j + 1] += seg[i][j];\n            }\n        }\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w + 1; j++) {\n \
    \               seg[i + 1][j] += seg[i][j];\n            }\n        }\n    }\n\
    \n    // return A[x][y]\n    T get(int x, int y) const {\n        assert(0 <=\
    \ x and x < h and 0 <= y and y < w);\n        return seg[x][y];\n    }\n\n   \
    \ // output\n    friend std::ostream &operator<<(std::ostream &os, const CumulativeSum2D\
    \ &A) {\n        os << \"h = \" << A.h << \", w = \" << A.w << \"\\n\";\n    \
    \    for (int i = 0; i <= A.h; i++) {\n            for (int j = 0; j <= A.w; j++)\
    \ {\n                os << A.seg[i][j] << \" \\n\"[j == A.w];\n            }\n\
    \        }\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cumulative_sum_2d.hpp
  requiredBy: []
  timestamp: '2023-03-17 17:11:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_5_b.test.cpp
documentation_of: data_structure/cumulative_sum_2d.hpp
layout: document
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---

使い方
1. ある2次元配列の矩形和を求める場合
    - コンストラクタ引数に2次元配列を入力
    - `sum(lx, ly, rx, ry)`で $ [lx, rx) \times [ly, ry) $ の和を返す
1. 2次元imos法のように使う場合
    - コンストラクタ引数に入力した値を`h, w`とすると、$[0, h) \times [0, w)$ への加算ができる(加算しうる半開区間の右端の値を入力する)
    - `imos(lx, ly, rx, ry, z)`で $ [lx, rx) \times [ly, ry) $ に $ z $ を加算
    - `build()`で構築
    - `rui.get(x, y)`でアクセス
