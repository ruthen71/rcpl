#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_I"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>

#include "geometry/common_area.hpp"

int main() {
    Circle<double> c1, c2;
    std::cin >> c1 >> c2;
    std::cout << std::fixed << std::setprecision(15) << common_area(c1, c2) << '\n';
    return 0;
}