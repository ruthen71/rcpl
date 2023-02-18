#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
#define ERROR 0.00000001

#include <bits/stdc++.h>

#include "geometry/polygon_area.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon P(N);
    std::cin >> P;
    std::cout << std::fixed << std::setprecision(15) << polygon_area(P) << '\n';
    return 0;
}