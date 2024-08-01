#pragma once

#include "geometry/point.hpp"

#include <vector>
#include <cassert>

// polygon
template <class T> using Polygon = std::vector<Point<T>>;
template <class T> std::istream& operator>>(std::istream& is, Polygon<T>& p) {
    for (auto&& pi : p) is >> pi;
    return is;
}
template <class T> std::ostream& operator<<(std::ostream& os, const Polygon<T>& p) {
    for (auto&& pi : p) os << pi << " -> ";
    return os;
}

// 多角形の面積 (符号付き)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
// return area * 2
template <class T> T polygon_area2(const Polygon<T>& p) {
    const int n = (int)(p.size());
    assert(n >= 2);
    T ret = T(0);
    for (int i = 0; i < n; i++) ret += cross(p[i], p[i + 1 == n ? 0 : i + 1]);
    // counter clockwise: ret > 0
    // clockwise: ret < 0
    return ret;
}
template <class T> T polygon_area(const Polygon<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    return polygon_area2(p) / T(2);
}

// 多角形の凸判定 (角度が 0 でも PI でも許容)
// 許容したくないときには ON_SEGMENT, ONLINE_FRONT, ONLINE_BACK が出てきたら false を返せば OK
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
template <class T> bool polygon_is_convex(const Polygon<T>& p) {
    const int n = (int)(p.size());
    assert(n >= 3);
    bool okccw = true, okcw = true;
    for (int i = 0; i < n; i++) {
        auto res = ccw(p[i], p[i + 1 >= n ? i + 1 - n : i + 1], p[i + 2 >= n ? i + 2 - n : i + 2]);
        if (res == Ccw::CLOCKWISE) okccw = false;
        if (res == Ccw::COUNTER_CLOCKWISE) okcw = false;
        if (!okccw and !okcw) return false;
    }
    return true;
}
