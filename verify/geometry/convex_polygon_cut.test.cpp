#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>

#include "geometry/convex_polygon_cut.hpp"
#include "geometry/polygon.hpp"

int main() {
    Constants<double>::set_eps(1e-8);
    int N;
    std::cin >> N;
    Polygon<double> P(N);
    std::cin >> P;
    int Q;
    std::cin >> Q;
    while (Q--) {
        Line<double> L1;
        std::cin >> L1;
        Line<double> L2(L1.b, L1.a);
        auto [rl1, rr1] = convex_polygon_cut(P, L1);
        auto [rl2, rr2] = convex_polygon_cut(P, L2);
        if (rl1.size() >= 2) {
            assert(equal(area(rl1), area(rr2)));
        }
        if (rr1.size() >= 2) {
            assert(equal(area(rl2), area(rr1)));
        }
        double ans = (rl1.size() >= 2 ? area(rl1) : 0);
        std::cout << std::fixed << std::setprecision(15) << ans << '\n';
    }
    return 0;
}