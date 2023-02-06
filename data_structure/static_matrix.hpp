#pragma once

template <class T, size_t n, size_t m = n> struct StaticMatrix {
    std::array<std::array<T, m>, n> A;

    StaticMatrix() : A{{}} {}

    StaticMatrix(T val) : A{{}} {
        for (int i = 0; i < (int)n; i++) A[i].fill(val);
    }

    size_t size() const { return n; }

    int row() const { return (int)n; }

    int col() const { return (int)m; }

    inline const std::array<T, m> &operator[](int i) const { return A[i]; }  // read

    inline std::array<T, m> &operator[](int i) { return A[i]; }  // write

    static StaticMatrix E() {
        assert(n == m);
        StaticMatrix ret;
        for (int i = 0; i < (int)n; i++) ret[i][i] = T(1);
        return ret;
    }

    StaticMatrix &operator+=(const StaticMatrix &B) {
        int N = row(), M = col();
        assert(N == B.row() && M == B.col());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return (*this);
    }

    StaticMatrix &operator-=(const StaticMatrix &B) {
        int N = row(), M = col();
        assert(N == B.row() && M == B.col());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return (*this);
    }

    StaticMatrix &operator*=(const StaticMatrix &B) {
        int N = row(), M = B.col(), L = B.row();
        assert(L == col());
        StaticMatrix C;
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

    StaticMatrix pow(long long k) {
        assert(row() == col());
        StaticMatrix B = StaticMatrix::E(), X = (*this);
        while (k) {
            if (k & 1) B *= X;
            X *= X;
            k >>= 1;
        }
        A.swap(B.A);
        return (*this);
    }

    StaticMatrix operator+(const StaticMatrix &B) { return ((*this) += B); }

    StaticMatrix operator-(const StaticMatrix &B) { return ((*this) -= B); }

    StaticMatrix operator*(const StaticMatrix &B) { return ((*this) *= B); }

    friend std::ostream &operator<<(std::ostream &os, StaticMatrix &A) {
        int N = A.row(), M = A.col();
        for (int i = 0; i < N; i++) {
            os << '[';
            for (int j = 0; j < M; j++) os << A[i][j] << " \n"[j == M - 1];
        }
        return (os);
    }

    StaticMatrix &operator+=(const T &k) {
        int N = row(), M = col();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) (*this)[i][j] += k;
        return (*this);
    }

    StaticMatrix &operator-=(const T &k) {
        int N = row(), M = col();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) (*this)[i][j] -= k;
        return (*this);
    }

    StaticMatrix &operator*=(const T &k) {
        int N = row(), M = col();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) (*this)[i][j] *= k;
        return (*this);
    }

    StaticMatrix &operator/=(const T &k) {
        int N = row(), M = col();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) (*this)[i][j] /= k;
        return (*this);
    }

    StaticMatrix operator+(const T &k) { return ((*this) += k); }

    StaticMatrix operator-(const T &k) { return ((*this) -= k); }

    StaticMatrix operator*(const T &k) { return ((*this) *= k); }

    StaticMatrix operator/(const T &k) { return ((*this) /= k); }
};