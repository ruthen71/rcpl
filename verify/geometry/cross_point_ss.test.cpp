#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#define ERROR 0.00000001

#include <iostream>
#include <iomanip>

#include "geometry/cross_point.hpp"

int main() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        // 1 点で交わることが保証されているため直線と線分のどの組合せに対しても同じ答えとなる
        Line<double> L1, L2;
        std::cin >> L1 >> L2;
        Segment<double> S1(L1.a, L1.b), S2(L2.a, L2.b);
        auto pll = cross_point(L1, L2);
        auto pls = cross_point(L1, S2);
        auto psl = cross_point(S1, L2);
        auto pss = cross_point(S1, S2);
        std::vector<Point<double>> ps = {pll, pls, psl, pss};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                assert(equal(ps[i], ps[j]));
            }
        }
        std::cout << std::fixed << std::setprecision(15) << p.x << ' ' << p.y << '\n';
    }
    return 0;
}