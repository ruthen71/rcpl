#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 0.000001

#include <bits/stdc++.h>

#include "geometry/cross_point_cl.hpp"

int main() {
    Circle C;
    std::cin >> C;
    int Q;
    std::cin >> Q;
    while (Q--) {
        Line L;
        std::cin >> L;
        auto res = cross_point_cl(C, L);
        std::sort(res.begin(), res.end());
        if (res.size() == 1) res.push_back(res[0]);
        std::cout << res[0] << ' ' << res[1] << '\n';
    }
    return 0;
}