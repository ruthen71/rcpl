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
  bundledCode: "#line 2 \"data_structure/matrix.hpp\"\n\ntemplate <class T> struct\
    \ Matrix {\n    std::vector<std::vector<T>> A;\n\n    Matrix(int N) : A(N, std::vector<T>(N,\
    \ T(0))) {}\n    Matrix(int N, int M, T val = T(0)) : A(N, std::vector<T>(M, val))\
    \ {}\n\n    size_t size() const { return A.size(); }\n\n    int row() const {\
    \ return (int)A.size(); }\n\n    int col() const { return (int)A[0].size(); }\n\
    \n    inline const std::vector<T> &operator[](int i) const { return A[i]; }  //\
    \ read\n\n    inline std::vector<T> &operator[](int i) { return A[i]; }  // write\n\
    \n    static Matrix E(int N) {\n        Matrix ret(N);\n        for (int i = 0;\
    \ i < N; i++) ret[i][i] = T(1);\n        return ret;\n    }\n\n    Matrix &operator+=(const\
    \ Matrix &B) {\n        int N = row(), M = col();\n        assert(N == B.row()\
    \ && M == B.col());\n        for (int i = 0; i < N; i++) {\n            for (int\
    \ j = 0; j < M; j++) {\n                (*this)[i][j] += B[i][j];\n          \
    \  }\n        }\n        return (*this);\n    }\n\n    Matrix &operator-=(const\
    \ Matrix &B) {\n        int N = row(), M = col();\n        assert(N == B.row()\
    \ && M == B.col());\n        for (int i = 0; i < N; i++) {\n            for (int\
    \ j = 0; j < M; j++) {\n                (*this)[i][j] -= B[i][j];\n          \
    \  }\n        }\n        return (*this);\n    }\n\n    Matrix &operator*=(const\
    \ Matrix &B) {\n        int N = row(), M = B.col(), L = B.row();\n        assert(L\
    \ == col());\n        Matrix C(N, M);\n        for (int i = 0; i < N; i++) {\n\
    \            for (int k = 0; k < L; k++) {\n                for (int j = 0; j\
    \ < M; j++) {\n                    C[i][j] += (*this)[i][k] * B[k][j];\n     \
    \           }\n            }\n        }\n        A.swap(C.A);\n        return\
    \ (*this);\n    }\n\n    Matrix pow(long long n) {\n        assert(row() == col());\n\
    \        Matrix B = Matrix::E(row()), X = (*this);\n        while (n) {\n    \
    \        if (n & 1) B *= X;\n            X *= X;\n            n >>= 1;\n     \
    \   }\n        A.swap(B.A);\n        return (*this);\n    }\n\n    Matrix operator+(const\
    \ Matrix &B) { return ((*this) += B); }\n\n    Matrix operator-(const Matrix &B)\
    \ { return ((*this) -= B); }\n\n    Matrix operator*(const Matrix &B) { return\
    \ ((*this) *= B); }\n\n    friend std::ostream &operator<<(std::ostream &os, Matrix\
    \ &A) {\n        int N = A.row(), M = A.col();\n        for (int i = 0; i < N;\
    \ i++) {\n            os << '[';\n            for (int j = 0; j < M; j++) os <<\
    \ A[i][j] << \" \\n\"[j == M - 1];\n        }\n        return (os);\n    }\n\n\
    \    Matrix &operator+=(const T &k) {\n        int N = row(), M = col();\n   \
    \     for (int i = 0; i < N; i++)\n            for (int j = 0; j < M; j++) (*this)[i][j]\
    \ += k;\n        return (*this);\n    }\n\n    Matrix &operator-=(const T &k)\
    \ {\n        int N = row(), M = col();\n        for (int i = 0; i < N; i++)\n\
    \            for (int j = 0; j < M; j++) (*this)[i][j] -= k;\n        return (*this);\n\
    \    }\n\n    Matrix &operator*=(const T &k) {\n        int N = row(), M = col();\n\
    \        for (int i = 0; i < N; i++)\n            for (int j = 0; j < M; j++)\
    \ (*this)[i][j] *= k;\n        return (*this);\n    }\n\n    Matrix &operator/=(const\
    \ T &k) {\n        int N = row(), M = col();\n        for (int i = 0; i < N; i++)\n\
    \            for (int j = 0; j < M; j++) (*this)[i][j] /= k;\n        return (*this);\n\
    \    }\n\n    Matrix operator+(const T &k) { return ((*this) += k); }\n\n    Matrix\
    \ operator-(const T &k) { return ((*this) -= k); }\n\n    Matrix operator*(const\
    \ T &k) { return ((*this) *= k); }\n\n    Matrix operator/(const T &k) { return\
    \ ((*this) /= k); }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct Matrix {\n    std::vector<std::vector<T>>\
    \ A;\n\n    Matrix(int N) : A(N, std::vector<T>(N, T(0))) {}\n    Matrix(int N,\
    \ int M, T val = T(0)) : A(N, std::vector<T>(M, val)) {}\n\n    size_t size()\
    \ const { return A.size(); }\n\n    int row() const { return (int)A.size(); }\n\
    \n    int col() const { return (int)A[0].size(); }\n\n    inline const std::vector<T>\
    \ &operator[](int i) const { return A[i]; }  // read\n\n    inline std::vector<T>\
    \ &operator[](int i) { return A[i]; }  // write\n\n    static Matrix E(int N)\
    \ {\n        Matrix ret(N);\n        for (int i = 0; i < N; i++) ret[i][i] = T(1);\n\
    \        return ret;\n    }\n\n    Matrix &operator+=(const Matrix &B) {\n   \
    \     int N = row(), M = col();\n        assert(N == B.row() && M == B.col());\n\
    \        for (int i = 0; i < N; i++) {\n            for (int j = 0; j < M; j++)\
    \ {\n                (*this)[i][j] += B[i][j];\n            }\n        }\n   \
    \     return (*this);\n    }\n\n    Matrix &operator-=(const Matrix &B) {\n  \
    \      int N = row(), M = col();\n        assert(N == B.row() && M == B.col());\n\
    \        for (int i = 0; i < N; i++) {\n            for (int j = 0; j < M; j++)\
    \ {\n                (*this)[i][j] -= B[i][j];\n            }\n        }\n   \
    \     return (*this);\n    }\n\n    Matrix &operator*=(const Matrix &B) {\n  \
    \      int N = row(), M = B.col(), L = B.row();\n        assert(L == col());\n\
    \        Matrix C(N, M);\n        for (int i = 0; i < N; i++) {\n            for\
    \ (int k = 0; k < L; k++) {\n                for (int j = 0; j < M; j++) {\n \
    \                   C[i][j] += (*this)[i][k] * B[k][j];\n                }\n \
    \           }\n        }\n        A.swap(C.A);\n        return (*this);\n    }\n\
    \n    Matrix pow(long long n) {\n        assert(row() == col());\n        Matrix\
    \ B = Matrix::E(row()), X = (*this);\n        while (n) {\n            if (n &\
    \ 1) B *= X;\n            X *= X;\n            n >>= 1;\n        }\n        A.swap(B.A);\n\
    \        return (*this);\n    }\n\n    Matrix operator+(const Matrix &B) { return\
    \ ((*this) += B); }\n\n    Matrix operator-(const Matrix &B) { return ((*this)\
    \ -= B); }\n\n    Matrix operator*(const Matrix &B) { return ((*this) *= B); }\n\
    \n    friend std::ostream &operator<<(std::ostream &os, Matrix &A) {\n       \
    \ int N = A.row(), M = A.col();\n        for (int i = 0; i < N; i++) {\n     \
    \       os << '[';\n            for (int j = 0; j < M; j++) os << A[i][j] << \"\
    \ \\n\"[j == M - 1];\n        }\n        return (os);\n    }\n\n    Matrix &operator+=(const\
    \ T &k) {\n        int N = row(), M = col();\n        for (int i = 0; i < N; i++)\n\
    \            for (int j = 0; j < M; j++) (*this)[i][j] += k;\n        return (*this);\n\
    \    }\n\n    Matrix &operator-=(const T &k) {\n        int N = row(), M = col();\n\
    \        for (int i = 0; i < N; i++)\n            for (int j = 0; j < M; j++)\
    \ (*this)[i][j] -= k;\n        return (*this);\n    }\n\n    Matrix &operator*=(const\
    \ T &k) {\n        int N = row(), M = col();\n        for (int i = 0; i < N; i++)\n\
    \            for (int j = 0; j < M; j++) (*this)[i][j] *= k;\n        return (*this);\n\
    \    }\n\n    Matrix &operator/=(const T &k) {\n        int N = row(), M = col();\n\
    \        for (int i = 0; i < N; i++)\n            for (int j = 0; j < M; j++)\
    \ (*this)[i][j] /= k;\n        return (*this);\n    }\n\n    Matrix operator+(const\
    \ T &k) { return ((*this) += k); }\n\n    Matrix operator-(const T &k) { return\
    \ ((*this) -= k); }\n\n    Matrix operator*(const T &k) { return ((*this) *= k);\
    \ }\n\n    Matrix operator/(const T &k) { return ((*this) /= k); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/matrix.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:12:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/matrix.hpp
layout: document
title: "Matrix (\u884C\u5217)"
---
