#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <bits/stdc++.h>

#include "geometry/monotone_chain.hpp"

int main() {
    int N;
    std::cin >> N;
    Polygon<double> P(N);
    std::cin >> P;
    auto res = monotone_chain(P, false);
    int minidx = 0;
    for (int i = 0; i < res.size(); i++) {
        if (compare_y(res[i], res[minidx])) {
            minidx = i;
        }
    }
    std::rotate(res.begin(), res.begin() + minidx, res.end());
    std::cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) std::cout << res[i].x << ' ' << res[i].y << '\n';
    return 0;
}