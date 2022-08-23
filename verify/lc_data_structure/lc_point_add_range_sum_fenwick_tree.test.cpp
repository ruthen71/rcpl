#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "src/data_structure/fenwick_tree.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    fenwick_tree<long long> fen(a);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            fen.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << fen.sum(l, r) << '\n';
        }
    }
    return 0;
}
