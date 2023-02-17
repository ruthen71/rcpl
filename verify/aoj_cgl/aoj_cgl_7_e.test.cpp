#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR 0.000001

#include <bits/stdc++.h>

#include "geometry/cross_point_cc.hpp"

int main() {
    Circle C1, C2;
    std::cin >> C1 >> C2;
    auto res = cross_point_cc(C1, C2);
    std::sort(res.begin(), res.end());
    if (res.size() == 1) res.push_back(res[0]);
    std::cout << res[0] << ' ' << res[1] << '\n';
    return 0;
}