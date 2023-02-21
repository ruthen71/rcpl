#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C"
#define ERROR 0.00001
// The original ERROR is 0.000001

#include <bits/stdc++.h>

#include "geometry/circumscribed_circle.hpp"

int main() {
    Point a, b, c;
    std::cin >> a >> b >> c;
    auto [p, r] = circumscribed_circle(a, b, c);
    std::cout << p << ' ' << r << '\n';
    return 0;
}