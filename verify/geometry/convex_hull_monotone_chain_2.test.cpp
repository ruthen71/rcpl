#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include <iostream>

#include "geometry/convex_hull_monotone_chain.hpp"

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        std::cin >> N;
        Polygon<long long> P(N);
        std::cin >> P;
        auto res = convex_hull_monotone_chain(P, true);
        std::cout << res.size() << '\n';
        for (int i = 0; i < res.size(); i++) std::cout << res[i].x << ' ' << res[i].y << '\n';
    }
    return 0;
}