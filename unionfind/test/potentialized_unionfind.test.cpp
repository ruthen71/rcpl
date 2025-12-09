#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include <iostream>

#include "../../algebra/monoid/monoid_plus.hpp"
#include "../../unionfind/potentialized_unionfind.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    PotentializedUnionfind<MonoidPlus<long long>> uf(n);
    for (int i = 0; i < q; i++) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x, y;
            std::cin >> x >> y;
            long long z;
            std::cin >> z;
            uf.merge(x, y, z);
        } else {
            int x, y;
            std::cin >> x >> y;
            if (uf.same(x, y)) {
                std::cout << uf.distance(x, y) << '\n';
            } else {
                std::cout << '?' << '\n';
            }
        }
    }
    return 0;
}
