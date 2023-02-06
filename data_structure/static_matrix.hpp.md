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
  bundledCode: "#line 2 \"data_structure/static_matrix.hpp\"\n\ntemplate <class T,\
    \ size_t n, size_t m = n> struct StaticMatrix {\n    std::array<std::array<T,\
    \ m>, n> A;\n\n    StaticMatrix() : A{{}} {}\n\n    StaticMatrix(T val) : A{{}}\
    \ {\n        for (int i = 0; i < (int)n; i++) A[i].fill(val);\n    }\n\n    size_t\
    \ size() const { return n; }\n\n    int row() const { return (int)n; }\n\n   \
    \ int col() const { return (int)m; }\n\n    inline const std::array<T, m> &operator[](int\
    \ i) const { return A[i]; }  // read\n\n    inline std::array<T, m> &operator[](int\
    \ i) { return A[i]; }  // write\n\n    static StaticMatrix E() {\n        assert(n\
    \ == m);\n        StaticMatrix ret;\n        for (int i = 0; i < (int)n; i++)\
    \ ret[i][i] = T(1);\n        return ret;\n    }\n\n    StaticMatrix &operator+=(const\
    \ StaticMatrix &B) {\n        int N = row(), M = col();\n        assert(N == B.row()\
    \ && M == B.col());\n        for (int i = 0; i < N; i++) {\n            for (int\
    \ j = 0; j < M; j++) {\n                (*this)[i][j] += B[i][j];\n          \
    \  }\n        }\n        return (*this);\n    }\n\n    StaticMatrix &operator-=(const\
    \ StaticMatrix &B) {\n        int N = row(), M = col();\n        assert(N == B.row()\
    \ && M == B.col());\n        for (int i = 0; i < N; i++) {\n            for (int\
    \ j = 0; j < M; j++) {\n                (*this)[i][j] -= B[i][j];\n          \
    \  }\n        }\n        return (*this);\n    }\n\n    StaticMatrix &operator*=(const\
    \ StaticMatrix &B) {\n        int N = row(), M = B.col(), L = B.row();\n     \
    \   assert(L == col());\n        StaticMatrix C;\n        for (int i = 0; i <\
    \ N; i++) {\n            for (int k = 0; k < L; k++) {\n                for (int\
    \ j = 0; j < M; j++) {\n                    C[i][j] += (*this)[i][k] * B[k][j];\n\
    \                }\n            }\n        }\n        A.swap(C.A);\n        return\
    \ (*this);\n    }\n\n    StaticMatrix pow(long long k) {\n        assert(row()\
    \ == col());\n        StaticMatrix B = StaticMatrix::E(), X = (*this);\n     \
    \   while (k) {\n            if (k & 1) B *= X;\n            X *= X;\n       \
    \     k >>= 1;\n        }\n        A.swap(B.A);\n        return (*this);\n   \
    \ }\n\n    StaticMatrix operator+(const StaticMatrix &B) { return ((*this) +=\
    \ B); }\n\n    StaticMatrix operator-(const StaticMatrix &B) { return ((*this)\
    \ -= B); }\n\n    StaticMatrix operator*(const StaticMatrix &B) { return ((*this)\
    \ *= B); }\n\n    friend std::ostream &operator<<(std::ostream &os, StaticMatrix\
    \ &A) {\n        int N = A.row(), M = A.col();\n        for (int i = 0; i < N;\
    \ i++) {\n            os << '[';\n            for (int j = 0; j < M; j++) os <<\
    \ A[i][j] << \" \\n\"[j == M - 1];\n        }\n        return (os);\n    }\n\n\
    \    StaticMatrix &operator+=(const T &k) {\n        int N = row(), M = col();\n\
    \        for (int i = 0; i < N; i++)\n            for (int j = 0; j < M; j++)\
    \ (*this)[i][j] += k;\n        return (*this);\n    }\n\n    StaticMatrix &operator-=(const\
    \ T &k) {\n        int N = row(), M = col();\n        for (int i = 0; i < N; i++)\n\
    \            for (int j = 0; j < M; j++) (*this)[i][j] -= k;\n        return (*this);\n\
    \    }\n\n    StaticMatrix &operator*=(const T &k) {\n        int N = row(), M\
    \ = col();\n        for (int i = 0; i < N; i++)\n            for (int j = 0; j\
    \ < M; j++) (*this)[i][j] *= k;\n        return (*this);\n    }\n\n    StaticMatrix\
    \ &operator/=(const T &k) {\n        int N = row(), M = col();\n        for (int\
    \ i = 0; i < N; i++)\n            for (int j = 0; j < M; j++) (*this)[i][j] /=\
    \ k;\n        return (*this);\n    }\n\n    StaticMatrix operator+(const T &k)\
    \ { return ((*this) += k); }\n\n    StaticMatrix operator-(const T &k) { return\
    \ ((*this) -= k); }\n\n    StaticMatrix operator*(const T &k) { return ((*this)\
    \ *= k); }\n\n    StaticMatrix operator/(const T &k) { return ((*this) /= k);\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <class T, size_t n, size_t m = n> struct StaticMatrix\
    \ {\n    std::array<std::array<T, m>, n> A;\n\n    StaticMatrix() : A{{}} {}\n\
    \n    StaticMatrix(T val) : A{{}} {\n        for (int i = 0; i < (int)n; i++)\
    \ A[i].fill(val);\n    }\n\n    size_t size() const { return n; }\n\n    int row()\
    \ const { return (int)n; }\n\n    int col() const { return (int)m; }\n\n    inline\
    \ const std::array<T, m> &operator[](int i) const { return A[i]; }  // read\n\n\
    \    inline std::array<T, m> &operator[](int i) { return A[i]; }  // write\n\n\
    \    static StaticMatrix E() {\n        assert(n == m);\n        StaticMatrix\
    \ ret;\n        for (int i = 0; i < (int)n; i++) ret[i][i] = T(1);\n        return\
    \ ret;\n    }\n\n    StaticMatrix &operator+=(const StaticMatrix &B) {\n     \
    \   int N = row(), M = col();\n        assert(N == B.row() && M == B.col());\n\
    \        for (int i = 0; i < N; i++) {\n            for (int j = 0; j < M; j++)\
    \ {\n                (*this)[i][j] += B[i][j];\n            }\n        }\n   \
    \     return (*this);\n    }\n\n    StaticMatrix &operator-=(const StaticMatrix\
    \ &B) {\n        int N = row(), M = col();\n        assert(N == B.row() && M ==\
    \ B.col());\n        for (int i = 0; i < N; i++) {\n            for (int j = 0;\
    \ j < M; j++) {\n                (*this)[i][j] -= B[i][j];\n            }\n  \
    \      }\n        return (*this);\n    }\n\n    StaticMatrix &operator*=(const\
    \ StaticMatrix &B) {\n        int N = row(), M = B.col(), L = B.row();\n     \
    \   assert(L == col());\n        StaticMatrix C;\n        for (int i = 0; i <\
    \ N; i++) {\n            for (int k = 0; k < L; k++) {\n                for (int\
    \ j = 0; j < M; j++) {\n                    C[i][j] += (*this)[i][k] * B[k][j];\n\
    \                }\n            }\n        }\n        A.swap(C.A);\n        return\
    \ (*this);\n    }\n\n    StaticMatrix pow(long long k) {\n        assert(row()\
    \ == col());\n        StaticMatrix B = StaticMatrix::E(), X = (*this);\n     \
    \   while (k) {\n            if (k & 1) B *= X;\n            X *= X;\n       \
    \     k >>= 1;\n        }\n        A.swap(B.A);\n        return (*this);\n   \
    \ }\n\n    StaticMatrix operator+(const StaticMatrix &B) { return ((*this) +=\
    \ B); }\n\n    StaticMatrix operator-(const StaticMatrix &B) { return ((*this)\
    \ -= B); }\n\n    StaticMatrix operator*(const StaticMatrix &B) { return ((*this)\
    \ *= B); }\n\n    friend std::ostream &operator<<(std::ostream &os, StaticMatrix\
    \ &A) {\n        int N = A.row(), M = A.col();\n        for (int i = 0; i < N;\
    \ i++) {\n            os << '[';\n            for (int j = 0; j < M; j++) os <<\
    \ A[i][j] << \" \\n\"[j == M - 1];\n        }\n        return (os);\n    }\n\n\
    \    StaticMatrix &operator+=(const T &k) {\n        int N = row(), M = col();\n\
    \        for (int i = 0; i < N; i++)\n            for (int j = 0; j < M; j++)\
    \ (*this)[i][j] += k;\n        return (*this);\n    }\n\n    StaticMatrix &operator-=(const\
    \ T &k) {\n        int N = row(), M = col();\n        for (int i = 0; i < N; i++)\n\
    \            for (int j = 0; j < M; j++) (*this)[i][j] -= k;\n        return (*this);\n\
    \    }\n\n    StaticMatrix &operator*=(const T &k) {\n        int N = row(), M\
    \ = col();\n        for (int i = 0; i < N; i++)\n            for (int j = 0; j\
    \ < M; j++) (*this)[i][j] *= k;\n        return (*this);\n    }\n\n    StaticMatrix\
    \ &operator/=(const T &k) {\n        int N = row(), M = col();\n        for (int\
    \ i = 0; i < N; i++)\n            for (int j = 0; j < M; j++) (*this)[i][j] /=\
    \ k;\n        return (*this);\n    }\n\n    StaticMatrix operator+(const T &k)\
    \ { return ((*this) += k); }\n\n    StaticMatrix operator-(const T &k) { return\
    \ ((*this) -= k); }\n\n    StaticMatrix operator*(const T &k) { return ((*this)\
    \ *= k); }\n\n    StaticMatrix operator/(const T &k) { return ((*this) /= k);\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/static_matrix.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/static_matrix.hpp
layout: document
title: "Static Matrix (\u884C\u5217, \u30B5\u30A4\u30BA\u56FA\u5B9A)"
---

行列のサイズが入力を受け取る前に決まっている場合、使うと速い

## 使用例

- [ABC189 E](https://atcoder.jp/contests/abc267/tasks/abc267_e)
    - 小さいサイズの行列を大量に作る場合、vector の 2 次元配列の場合、「push_back に備えて少し多めに取る」が積もりに積もってメモリ使用量が大きくなる
    - また、(おそらくメモリアクセスが連続しているかの違いにより) 実行時間にも大きな差が出る
    - [matrix 版](https://atcoder.jp/contests/abc189/submissions/35374154)
    - [static_matrix 版](https://atcoder.jp/contests/abc189/submissions/35374254)
