#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412"

#include <iostream>

#include "geometry/contain.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon<double> q(N);
    std::cin >> q;
    for (int i = 0; i < N; i++) q[i] *= 1e6 / (1e6 - 1e2);
    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        Point<double> p;
        std::cin >> p;
        auto res = convex_contain(q, p);
        if (res == Contain::IN) {
            std::cout << "1\n";
        } else if (res == Contain::OUT) {
            std::cout << "0\n";
        } else {
            assert(0);
        }
    }
    return 0;
}