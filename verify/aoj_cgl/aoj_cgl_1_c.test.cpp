#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include <bits/stdc++.h>

#include "geometry/ccw.hpp"

int main() {
    Point<double> P1, P2;
    std::cin >> P1 >> P2;
    int Q;
    std::cin >> Q;
    while (Q--) {
        Point<double> P3;
        std::cin >> P3;
        auto ans = ccw(P1, P2, P3);
        if (ans == COUNTER_CLOCKWISE) {
            std::cout << "COUNTER_CLOCKWISE\n";
        } else if (ans == CLOCKWISE) {
            std::cout << "CLOCKWISE\n";
        } else if (ans == ONLINE_BACK) {
            std::cout << "ONLINE_BACK\n";
        } else if (ans == ONLINE_FRONT) {
            std::cout << "ONLINE_FRONT\n";
        } else {
            std::cout << "ON_SEGMENT\n";
        }
    }
    return 0;
}