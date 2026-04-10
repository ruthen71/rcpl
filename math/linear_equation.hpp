#pragma once

#include "math/gauss_jordan_elimination.hpp"

#include <cassert>
#include <utility>
#include <vector>

// 線形方程式 Ax = b を解く
// {rank, x} を返す
template <class T> std::pair<int, std::vector<T>> linear_equation(const std::vector<std::vector<T>>& A, const std::vector<T>& b) {
    assert(A.size() > 0);
    const int m = (int)(A.size()), n = (int)(A[0].size());
    std::vector M(m, std::vector<T>(n + 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = A[i][j];
        }
        M[i][n] = b[i];
    }
    int rank = gauss_jordan_elimination(M, n);
    show(M);

    // 解が存在しない場合, rank = -1 を返す
    for (int i = rank; i < m; i++) {
        if (M[i][n] != T(0)) {
            return {-1, {}};
        }
    }
    std::vector<T> x(n);
    for (int i = 0; i < rank; i++) x[i] = M[i][n];
    return {rank, x};
}