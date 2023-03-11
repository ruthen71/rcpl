#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <bits/stdc++.h>

#include "misc/mo.hpp"
#include "data_structure/fenwick_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    std::vector<int> L(Q), R(Q);
    for (int i = 0; i < Q; i++) std::cin >> L[i] >> R[i];

    auto B = A;
    std::sort(B.begin(), B.end());
    B.erase(std::unique(B.begin(), B.end()), B.end());
    for (auto &&e : A) e = std::lower_bound(B.begin(), B.end(), e) - B.begin();

    const int M = (int)B.size();
    FenwickTree<long long> fen(M);
    std::vector<long long> ans(Q);
    long long cur = 0;
    auto add_left = [&](int i) {
        cur += fen.sum(A[i]);
        fen.add(A[i], 1);
    };
    auto add_right = [&](int i) {
        cur += fen.sum(A[i] + 1, M);
        fen.add(A[i], 1);
    };
    auto del_left = [&](int i) {
        cur -= fen.sum(A[i]);
        fen.add(A[i], -1);
    };
    auto del_right = [&](int i) {
        cur -= fen.sum(A[i] + 1, M);
        fen.add(A[i], -1);
    };
    auto out = [&](int i) { ans[i] = cur; };
    mo(N, L, R, add_left, add_right, del_left, del_right, out);
    for (int i = 0; i < Q; i++) std::cout << ans[i] << '\n';
    return 0;
}