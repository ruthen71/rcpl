#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

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
        int minidx = 0;
        for (int i = 0; i < res.size(); i++) {
            if (compare_y(res[i], res[minidx])) {
                minidx = i;
            }
        }
        std::rotate(res.begin(), res.begin() + minidx, res.end());
        std::cout << res.size() << '\n';
        for (int i = 0; i < res.size(); i++) std::cout << res[i].x << ' ' << res[i].y << '\n';
    }
    return 0;
}