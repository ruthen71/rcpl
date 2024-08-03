#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include <iostream>

#include "geometry/polygon.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon<long long> P(N);
    std::cin >> P;
    long long s = area2(P);
    if (s % 2 == 0) {
        std::cout << s / 2 << ".0\n";
    } else {
        std::cout << s / 2 << ".5\n";
    }
    return 0;
}