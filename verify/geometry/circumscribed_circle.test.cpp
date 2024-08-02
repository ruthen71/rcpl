#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C"
#define ERROR 0.000001
// 誤差は本来より緩め

#include <iostream>
#include <iomanip>

#include "geometry/circumscribed_circle.hpp"

int main() {
    Point<long double> a, b, c;
    std::cin >> a >> b >> c;
    auto cir = circumscribed_circle(a, b, c);
    std::cout << std::fixed << std::setprecision(15) << cir.o.x << ' ' << cir.o.y << ' ' << cir.r << '\n';
    return 0;
}