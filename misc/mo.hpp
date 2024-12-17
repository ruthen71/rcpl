#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

// Mo's Algorithm
// https://snuke.hatenablog.com/entry/2016/07/01/000000
// complexity: O(N * N / B + Q * B)
// -> O(N sqrt(Q)) (B := N / sqrt(Q))
template <class AddLeft, class AddRight, class DelLeft, class DelRight, class Out>
void mo(const int n, const std::vector<int> l, const std::vector<int> r, const AddLeft &add_left,
        const AddRight &add_right, const DelLeft &del_left, const DelRight &del_right,
        const Out &out, const int bucket_size_value = -1) {
    const int q = (int)(l.size());
    if (q == 0) return;
    // determine bucket size
    auto calculate_bucket_size = [&]() {
        // const int bucket_size = std::max(1.0, n / std::max(1.0, sqrt(q)));
        // speed up by https://nyaannyaan.github.io/library/misc/mo.hpp
        const int bucket_size = std::max(1.0, n / std::max(1.0, sqrt(2.0 * q / 3.0)));
        return bucket_size;
    };
    const int bucket_size = bucket_size_value == -1 ? calculate_bucket_size() : bucket_size_value;
    std::vector<int> ind(q), lbs(q);
    // reduce the number of divisions by memoization
    for (int i = 0; i < q; i++) lbs[i] = l[i] / bucket_size;
    std::iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&](int i, int j) {
        if (lbs[i] != lbs[j]) return l[i] < l[j];
        return (lbs[i] & 1) ? r[i] > r[j] : r[i] < r[j];
    });
    // 以前は now_l = now_r = l[ind.front()] としていたが, これは [now_l, now_r) に対する答えが
    // [0, 0) と同じでないと壊れる
    int now_l = 0, now_r = 0;
    for (auto &&i : ind) {
        while (now_l > l[i]) add_left(--now_l);
        while (now_r < r[i]) add_right(now_r++);
        while (now_l < l[i]) del_left(now_l++);
        while (now_r > r[i]) del_right(--now_r);
        out(i);
    }
}
template <class Add, class Del, class Out>                                  //
void mo(const int n, const std::vector<int> &l, const std::vector<int> &r,  //
        const Add &add, const Del &del, const Out &out, const int bucket_size_value = -1) {
    mo(n, l, r, add, add, del, del, out, bucket_size_value);
}