#pragma once
#include <vector>

// find s that sum s[i] * a[i] = x (s[i] = 1 or -1)
// O(n 2 ^ n) (n: size of a)
template <class T> std::vector<int> meet_in_the_middle(const std::vector<T>& a, T x) {
    const int n = int(a.size());
    const int n1 = n / 2, n2 = n - n1;
    std::unordered_map<T, int> mp;
    std::vector<int> res(n, 0);
    for (int bit = 0; bit < (1 << n1); bit++) {
        T c = T(0);
        for (int i = 0; i < n1; i++) {
            if (bit >> i & 1) {
                c += a[i];
            } else {
                c -= a[i];
            }
        }
        mp[c] = bit;
    }
    for (int bit = 0; bit < (1 << n2); bit++) {
        T d = T(0);
        for (int i = 0; i < n2; i++) {
            if (bit >> i & 1) {
                d += a[i + n1];
            } else {
                d -= a[i + n1];
            }
        }
        if (mp.count(x - d)) {
            for (int i = 0; i < n1; i++) res[i] = (mp[x - d] >> i & 1) * 2 - 1;
            for (int i = 0; i < n2; i++) res[i + n1] = (bit >> i & 1) * 2 - 1;
            return res;
        }
    }
    return res;
}

// calculate all possible sorted { sum s[i] * a[i], bit } (using std::inplace_merge)
template <class T> std::vector<std::pair<T, int>> calc_half(const std::vector<T>& a) {
    int n = int(a.size());
    std::vector<std::pair<T, int>> half(1 << n);
    int size = 1;
    half[0] = {T(0), 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size; j++) {
            half[j + size] = {half[j].first + a[i], half[j].second | (1 << i)};
        }
        for (int j = 0; j < size; j++) {
            half[j].first -= a[i];
        }
        std::inplace_merge(half.begin(), half.begin() + size, half.begin() + size * 2);
        size <<= 1;
    }
    return half;
}

// O(2 ^ n) (using std::inplace_merge, Two Pointer Approach)
template <class T> std::vector<int> meet_in_the_middle_faster(const std::vector<T>& a, T x) {
    const int n = int(a.size());
    const int n1 = n / 2, n2 = n - n1;

    std::vector<T> a1(n1), a2(n2);
    for (int i = 0; i < n1; i++) a1[i] = a[i];
    for (int i = 0; i < n2; i++) a2[i] = a[i + n1];

    auto half1 = calc_half(a1);
    auto half2 = calc_half(a2);

    int r = (1 << n2) - 1;
    std::vector<int> res(n, 0);
    for (int i = 0; i < (1 << n1); i++) {
        while (r > 0 and half1[i].first + half2[r].first > x) r--;
        if (half1[i].first + half2[r].first == x) {
            for (int j = 0; j < n1; j++) res[j] = (half1[i].second >> j & 1) * 2 - 1;
            for (int j = 0; j < n2; j++) res[j + n1] = (half2[r].second >> j & 1) * 2 - 1;
            return res;
        }
    }
    return res;
}