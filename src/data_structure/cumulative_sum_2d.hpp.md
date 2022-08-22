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
    _deprecated_at_docs: docs/data_structure/cumulative_sum_2d.md
    document_title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"src/data_structure/cumulative_sum_2d.hpp\"\n\ntemplate <class\
    \ T> struct cumulative_sum_2d {\n    std::vector<std::vector<T>> cum;\n    int\
    \ H, W;\n\n    cumulative_sum_2d(int W, int H) : H(H), W(W), cum(W + 1, std::vector<T>(H\
    \ + 1, 0)) {}\n\n    cumulative_sum_2d(std::vector<std::vector<T>> &A) {\n   \
    \     H = (int)A.size(), W = (int)A[0].size();\n        cum.assign(H + 1, std::vector<T>(W\
    \ + 1, 0));\n        for (int i = 0; i < H; i++) {\n            for (int j = 0;\
    \ j < W; j++) {\n                cum[i + 1][j + 1] = A[i][j];\n            }\n\
    \        }\n        for (int i = 0; i < H + 1; i++) {\n            for (int j\
    \ = 0; j < W; j++) {\n                cum[i][j + 1] += cum[i][j];\n          \
    \  }\n        }\n        for (int i = 0; i < H; i++) {\n            for (int j\
    \ = 0; j < W + 1; j) {\n                cum[i + 1][j] += cum[i][j];\n        \
    \    }\n        }\n    }\n\n    // [lx, ly) x [rx, ry)\n    T query(int lx, int\
    \ ly, int rx, int ry) { return (cum[rx][ry] - cum[lx][ry] - cum[rx][ly] + cum[lx][ly]);\
    \ }\n\n    // A[x][y] = z\n    void set(int x, int y, T z) { cum[x + 1][y + 1]\
    \ = z; }\n\n    // A[x][y] += z\n    void add(int x, int y, T z) { cum[x + 1][y\
    \ + 1] += z; }\n\n    // (i, j) \\in [lx, ly) x [rx, ry) cum[i][j] += z;\n   \
    \ void imos(int lx, int ly, int rx, int ry, T z = 1) {\n        add(lx, ly, z);\n\
    \        add(lx, ry, -z);\n        add(rx, ly, -z);\n        add(rx, ry, z);\n\
    \    }\n\n    void build() {\n        for (int i = 0; i < H + 1; i++) {\n    \
    \        for (int j = 0; j < W; j++) {\n                cum[i][j + 1] += cum[i][j];\n\
    \            }\n        }\n        for (int i = 0; i < H; i++) {\n           \
    \ for (int j = 0; j < W + 1; j++) {\n                cum[i + 1][j] += cum[i][j];\n\
    \            }\n        }\n    }\n\n    T get(int x, int y) { return cum[x + 1][y\
    \ + 1]; }\n\n    // output\n    friend ostream &operator<<(ostream &os, const\
    \ cumulative_sum_2d &A) {\n        for (int i = 0; i < (int)A.size(); i++) {\n\
    \            for (int j = 0; j < (int)A[i].size(); j++) {\n                os\
    \ << A[i][j] << \" \\n\"[j == (int)A[i].size() - 1];\n            }\n        }\n\
    \        return os;\n    }\n};\n\n/**\n * @brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\
    \n * @docs docs/data_structure/cumulative_sum_2d.md\n */\n"
  code: "#pragma once\n\ntemplate <class T> struct cumulative_sum_2d {\n    std::vector<std::vector<T>>\
    \ cum;\n    int H, W;\n\n    cumulative_sum_2d(int W, int H) : H(H), W(W), cum(W\
    \ + 1, std::vector<T>(H + 1, 0)) {}\n\n    cumulative_sum_2d(std::vector<std::vector<T>>\
    \ &A) {\n        H = (int)A.size(), W = (int)A[0].size();\n        cum.assign(H\
    \ + 1, std::vector<T>(W + 1, 0));\n        for (int i = 0; i < H; i++) {\n   \
    \         for (int j = 0; j < W; j++) {\n                cum[i + 1][j + 1] = A[i][j];\n\
    \            }\n        }\n        for (int i = 0; i < H + 1; i++) {\n       \
    \     for (int j = 0; j < W; j++) {\n                cum[i][j + 1] += cum[i][j];\n\
    \            }\n        }\n        for (int i = 0; i < H; i++) {\n           \
    \ for (int j = 0; j < W + 1; j) {\n                cum[i + 1][j] += cum[i][j];\n\
    \            }\n        }\n    }\n\n    // [lx, ly) x [rx, ry)\n    T query(int\
    \ lx, int ly, int rx, int ry) { return (cum[rx][ry] - cum[lx][ry] - cum[rx][ly]\
    \ + cum[lx][ly]); }\n\n    // A[x][y] = z\n    void set(int x, int y, T z) { cum[x\
    \ + 1][y + 1] = z; }\n\n    // A[x][y] += z\n    void add(int x, int y, T z) {\
    \ cum[x + 1][y + 1] += z; }\n\n    // (i, j) \\in [lx, ly) x [rx, ry) cum[i][j]\
    \ += z;\n    void imos(int lx, int ly, int rx, int ry, T z = 1) {\n        add(lx,\
    \ ly, z);\n        add(lx, ry, -z);\n        add(rx, ly, -z);\n        add(rx,\
    \ ry, z);\n    }\n\n    void build() {\n        for (int i = 0; i < H + 1; i++)\
    \ {\n            for (int j = 0; j < W; j++) {\n                cum[i][j + 1]\
    \ += cum[i][j];\n            }\n        }\n        for (int i = 0; i < H; i++)\
    \ {\n            for (int j = 0; j < W + 1; j++) {\n                cum[i + 1][j]\
    \ += cum[i][j];\n            }\n        }\n    }\n\n    T get(int x, int y) {\
    \ return cum[x + 1][y + 1]; }\n\n    // output\n    friend ostream &operator<<(ostream\
    \ &os, const cumulative_sum_2d &A) {\n        for (int i = 0; i < (int)A.size();\
    \ i++) {\n            for (int j = 0; j < (int)A[i].size(); j++) {\n         \
    \       os << A[i][j] << \" \\n\"[j == (int)A[i].size() - 1];\n            }\n\
    \        }\n        return os;\n    }\n};\n\n/**\n * @brief 2\u6B21\u5143\u7D2F\
    \u7A4D\u548C\n * @docs docs/data_structure/cumulative_sum_2d.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/cumulative_sum_2d.hpp
  requiredBy: []
  timestamp: '2022-08-23 00:34:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj_dsl/aoj_dsl_5_b.test.cpp
documentation_of: src/data_structure/cumulative_sum_2d.hpp
layout: document
redirect_from:
- /library/src/data_structure/cumulative_sum_2d.hpp
- /library/src/data_structure/cumulative_sum_2d.hpp.html
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
# 2次元累積和

## 概要
2つの使い方が想定される
1. ある2次元配列を入力し、さまざまな矩形和を求める場合
    - コンストラクタ引数にその2次元配列を直接取ると、勝手に構築する
    - `query(lx, ly, rx, ry)`で $ [lx, rx) \times [ly, ry) $ の和を返す
1. 2次元imos法のように使いたい場合
    - コンストラクタ引数には配列のサイズを入力する
    - このとき、配列サイズは行列ともに1大きくする
        - 1次元imos法をするときに、長さ $ N $ の配列に区間加算する場合も配列自体は右端を考慮して長さを $ N+1 $ にするのと同じイメージ
    - `imos(lx, ly, rx, ry, z)`で $ [lx, rx) \times [ly, ry) $ に $ z $ を加算する
    - `build()`で構築
    - `get(x, y)`でimos法をする前での配列`A`の`A[x][y]`にアクセスできる
