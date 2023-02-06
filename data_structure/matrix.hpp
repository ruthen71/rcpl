#pragma once

template <class T> struct Matrix {
    std::vector<std::vector<T>> A;

    Matrix(int N) : A(N, std::vector<T>(N, T(0))) {}
    Matrix(int N, int M, T val = T(0)) : A(N, std::vector<T>(M, val)) {}

    size_t size() const { return A.size(); }

    int row() const { return (int)A.size(); }

    int col() const { return (int)A[0].size(); }

    inline const std::vector<T> &operator[](int i) const { return A[i]; }  // read

    inline std::vector<T> &operator[](int i) { return A[i]; }  // write

    static Matrix E(int N) {
        Matrix ret(N);
        for (int i = 0; i < N; i++) ret[i][i] = T(1);
        return ret;
    }

    Matrix &operator+=(const Matrix &B) {
        int N = row(), M = col();
        assert(N == B.row() && M == B.col());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return (*this);
    }

    Matrix &operator-=(const Matrix &B) {
        int N = row(), M = col();
        assert(N == B.row() && M == B.col());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return (*this);
    }

    Matrix &operator*=(const Matrix &B) {
        int N = row(), M = B.col(), L = B.row();
        assert(L == col());
        Matrix C(N, M);
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < L; k++) {
                for (int j = 0; j < M; j++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        A.swap(C.A);
        return (*this);
    }

    Matrix pow(long long n) {
        assert(row() == col());
        Matrix B = Matrix::E(row()), X = (*this);
        while (n) {
            if (n & 1) B *= X;
            X *= X;
            n >>= 1;
        }
        A.swap(B.A);
        return (*this);
    }

    Matrix operator+(const Matrix &B) { return ((*this) += B); }

    Matrix operator-(const Matrix &B) { return ((*this) -= B); }

    Matrix operator*(const Matrix &B) { return ((*this) *= B); }

    friend std::ostream &operator<<(std::ostream &os, Matrix &A) {
        int N = A.row(), M = A.col();
        for (int i = 0; i < N; i++) {
            os << '[';
            for (int j = 0; j < M; j++) os << A[i][j] << " \n"[j == M - 1];
        }
        return (os);
    }

    Matrix &operator+=(const T &k) {
        int N = row(), M = col();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) (*this)[i][j] += k;
        return (*this);
    }

    Matrix &operator-=(const T &k) {
        int N = row(), M = col();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) (*this)[i][j] -= k;
        return (*this);
    }

    Matrix &operator*=(const T &k) {
        int N = row(), M = col();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) (*this)[i][j] *= k;
        return (*this);
    }

    Matrix &operator/=(const T &k) {
        int N = row(), M = col();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) (*this)[i][j] /= k;
        return (*this);
    }

    Matrix operator+(const T &k) { return ((*this) += k); }

    Matrix operator-(const T &k) { return ((*this) -= k); }

    Matrix operator*(const T &k) { return ((*this) *= k); }

    Matrix operator/(const T &k) { return ((*this) /= k); }
};