#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#include <iostream>

#include "geometry/contain.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon<long long> P(N);
    std::cin >> P;
    int Q;
    std::cin >> Q;
    while (Q--) {
        Point<long long> p;
        std::cin >> p;
        auto ans = contain(P, p);
        if (ans == Contain::IN) {
            std::cout << "2\n";
        } else if (ans == Contain::ON) {
            std::cout << "1\n";
        } else {
            std::cout << "0\n";
        }
    }
    return 0;
}