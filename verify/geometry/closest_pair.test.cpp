#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <numeric>

#include "geometry/closest_pair.hpp"

int main() {
    int N;
    std::cin >> N;
    std::vector<Point<double>> P(N);
    for (int i = 0; i < N; i++) std::cin >> P[i];
    auto [i, j, d] = closest_pair(P);
    assert(equal(d, abs(P[i] - P[j])));
    std::cout << std::fixed << std::setprecision(15) << d << '\n';
    return 0;
}