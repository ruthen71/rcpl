#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../../src/data_structure/unionfind.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    unionfind uf(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.merge(u, v);
        } else {
            cout << uf.same(u, v) << '\n';
        }
    }
    return 0;
}
