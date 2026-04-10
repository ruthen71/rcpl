#pragma once

#include <cassert>
#include <vector>

// 行列 a を掃き出し, ランクを返す
template <class T> int gauss_jordan_elimination(std::vector<std::vector<T>>& a, int pivot_end = -1) {
    assert(a.size() > 0);
    const int h = (int)(a.size()), w = (int)(a[0].size());
    int rank = 0;
    if (pivot_end == -1) pivot_end = w;

    for (int j = 0; j < pivot_end; j++) {
        // ピボットを探す
        int pivot = -1;
        for (int i = rank; i < h; i++) {
            if (a[i][j] != T(0)) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) continue;

        std::swap(a[pivot], a[rank]);

        // a[rank][j] = 1 になるように a[rank] を定数倍
        const T inv = T(1) / a[rank][j];
        for (int j2 = 0; j2 < w; j2++) a[rank][j2] *= inv;

        // a[rank] を使って他の行を掃き出す
        for (int i = 0; i < h; i++) {
            if (i != rank and a[i][j] != T(0)) {
                const T fac = a[i][j];  // a[rank] を fac 倍して a[i] から引く
                for (int j2 = 0; j2 < w; j2++) {
                    a[i][j2] -= a[rank][j2] * fac;
                }
            }
        }
        rank++;
    }
    return rank;
}