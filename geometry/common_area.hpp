#pragma once

#include "geometry/circle.hpp"
#include "geometry/line.hpp"
#include "geometry/polygon.hpp"
#include "geometry/cross_point.hpp"

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
// https://drken1215.hatenablog.com/entry/2020/02/02/091000
// 円 c の中心 o, 線分 s のなす三角形と円 c の共通部分の面積
template <class T> T common_area(Circle<T> c, Segment<T> s) {
    // c.o を原点と見て平行移動
    s.a -= c.o;
    s.b -= c.o;
    c.o -= c.o;
    // c.o, s.a, s.b が一直線に並ぶ場合
    if (sign(norm(s.a - s.b)) == 0) return 0;
    bool a_in_c = sign(norm(s.a) - c.r * c.r) == -1;
    bool b_in_c = sign(norm(s.b) - c.r * c.r) == -1;
    // s.a, s.b がともに円 c の内部にある場合 -> 三角形
    if (a_in_c and b_in_c) return cross(s.a, s.b) / 2;
    // s.a, s.b がともに円 c の外部にある場合 -> 扇形
    if (!is_intersect(c, s)) return c.r * c.r * get_angle(c.o, s.a, s.b) / 2;
    auto cp = cross_point(c, s);
    // 交点を cp1, cp2 とする (1 つの場合は cp1 == cp2)
    auto cp1 = cp.front(), cp2 = cp.back();
    // 線分 s.a -> cp1, cp1 -> cp2, cp2 -> s.b について, 扇形か三角形か場合分けしながら求めていく
    T res = 0;
    // s.a -> cp1
    if (a_in_c) {
        res += cross(s.a, cp1) / 2;
    } else {
        res += c.r * c.r * get_angle(c.o, s.a, cp1) / 2;
    }
    // cp1 -> cp2
    res += cross(cp1, cp2) / 2;
    // cp2 -> s.b
    if (b_in_c) {
        res += cross(cp2, s.b) / 2;
    } else {
        res += c.r * c.r * get_angle(c.o, cp2, s.b) / 2;
    }
    return res;
}

// 円 c, 多角形 p の共通部分の面積 (符号付き)
template <class T> T common_area(const Circle<T>& c, const Polygon<T>& p) {
    static_assert(is_geometry_floating_point<T>::value == true);
    const int n = (int)(p.size());
    assert(n >= 2);
    T res = T(0);
    for (int i = 0; i < n; i++) res += common_area(c, Segment(p[i], p[(i + 1) % n]));
    // counter clockwise: res > 0
    // clockwise: res < 0
    return res;
}
template <class T> T common_area(const Polygon<T>& p, const Circle<T>& c) { return common_area(c, p); }
