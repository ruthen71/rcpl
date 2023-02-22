#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#define ERROR 0.000001

#include <bits/stdc++.h>

#include "geometry/closest_pair.hpp"

int main() {
    int N;
    std::cin >> N;
    std::vector<Point> P(N);
    for (int i = 0; i < N; i++) std::cin >> P[i];
    auto [i, j, d] = closest_pair(P);
    assert(equal(d, std::abs(P[i] - P[j])));
    std::cout << std::fixed << std::setprecision(15) << std::abs(P[i] - P[j]) << '\n';
    return 0;
}