#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <iostream>

#include "geometry/point.hpp"

int main() {
    Point<long long> P1, P2;
    int Q;
    std::cin >> P1 >> P2 >> Q;
    while (Q--) {
        Point<long long> P3;
        std::cin >> P3;
        auto ans = ccw(P1, P2, P3);
        if (ans == Ccw::COUNTER_CLOCKWISE) {
            std::cout << "COUNTER_CLOCKWISE\n";
        } else if (ans == Ccw::CLOCKWISE) {
            std::cout << "CLOCKWISE\n";
        } else if (ans == Ccw::ONLINE_BACK) {
            std::cout << "ONLINE_BACK\n";
        } else if (ans == Ccw::ONLINE_FRONT) {
            std::cout << "ONLINE_FRONT\n";
        } else {
            std::cout << "ON_SEGMENT\n";
        }
    }
    return 0;
}