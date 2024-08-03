#pragma once

#include "geometry/point.hpp"
#include "geometry/line.hpp"
#include "geometry/circle.hpp"

// 交差判定 (直線, 線分, 円, 点)
// 直線 l1, l2 の交差判定
template <class T> bool is_intersect(const Line<T>& l1, const Line<T>& l2) {
    Point<T> base = l1.b - l1.a;
    T d12 = cross(base, l2.b - l2.a);
    T d1 = cross(base, l1.b - l2.a);
    // sign(d12) != 0 -> 平行でないので交差する
    // sign(d12) == 0 and sign(d1) == 0 -> 一致するので交差する
    return sign(d12) != 0 or sign(d1) == 0;
}
// 直線 l, 点 p の交差判定
template <class T> inline bool is_intersect(const Line<T>& l, const Point<T>& p) {
    auto res = ccw(l.a, l.b, p);
    return res == Ccw::ONLINE_BACK or res == Ccw::ONLINE_FRONT or res == Ccw::ON_SEGMENT;
}
template <class T> bool is_intersect(const Point<T>& p, const Line<T>& l) { return is_intersect(l, p); }

// 線分 s, 点 p の交差判定
template <class T> inline bool is_intersect(const Segment<T>& s, const Point<T>& p) { return ccw(s.a, s.b, p) == Ccw::ON_SEGMENT; }
template <class T> inline bool is_intersect(const Point<T>& p, const Segment<T>& s) { return ccw(s.a, s.b, p) == Ccw::ON_SEGMENT; }

// 直線 l, 線分 s の交差判定
template <class T> bool is_intersect(const Line<T>& l, const Segment<T>& s) {
    // s.a と s.b が直線 l に関して同じ側 (直線上を除き) にある場合に限り交差しない
    auto c1 = ccw(l.a, l.b, s.a);
    auto c2 = ccw(l.a, l.b, s.b);
    return !((c1 == c2) and (c1 == Ccw::CLOCKWISE or c1 == Ccw::COUNTER_CLOCKWISE));
}
template <class T> bool is_intersect(const Segment<T>& s, const Line<T>& l) { return is_intersect(l, s); }

// 線分 s1, s2 の交差判定
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
template <class T> inline bool is_intersect(const Segment<T>& s1, const Segment<T>& s2) {
    auto c1 = ccw(s1.a, s1.b, s2.a);
    auto c2 = ccw(s1.a, s1.b, s2.b);
    auto c3 = ccw(s2.a, s2.b, s1.a);
    auto c4 = ccw(s2.a, s2.b, s1.b);
    // 平行な場合: 重なるなら 1 次元で考えると必ず端点のどれかがもう一方の線分上にある
    if (c1 == Ccw::ON_SEGMENT or c2 == Ccw::ON_SEGMENT or c3 == Ccw::ON_SEGMENT or c4 == Ccw::ON_SEGMENT) return true;
    // 平行でない場合: 一方の線分の両側にもう一方の線分の端点がある, を線分を入れ替えても成立
    // 平行だが重ならない場合は以下の条件は成立しない
    bool ok1 = ((c1 == Ccw::CLOCKWISE and c2 == Ccw::COUNTER_CLOCKWISE) or (c1 == Ccw::COUNTER_CLOCKWISE and c2 == Ccw::CLOCKWISE));
    bool ok2 = ((c3 == Ccw::CLOCKWISE and c4 == Ccw::COUNTER_CLOCKWISE) or (c3 == Ccw::COUNTER_CLOCKWISE and c4 == Ccw::CLOCKWISE));
    return ok1 and ok2;
}

// 点 p1, p2 の交差判定
template <class T> inline bool is_intersect(const Point<T>& p1, const Point<T>& p2) { return equal(p1, p2); }

// 円 c1, c2 の交差判定
template <class T> inline bool is_intersect(const Circle<T>& c1, const Circle<T>& c2) {
    const int num = tangent_number(c1, c2);
    return 1 <= num and num <= 3;
}

// 円 c, 点 p の交差判定
template <class T> inline bool is_intersect(const Circle<T>& c, const Point<T>& p) { return equal(norm(p - c.o), c.r * c.r); }
template <class T> inline bool is_intersect(const Point<T>& p, const Circle<T>& c) { return equal(norm(p - c.o), c.r * c.r); }

// 円 c, 直線 l の交差判定
template <class T> inline bool is_intersect(const Circle<T>& c, const Line<T>& l) {
    static_assert(is_geometry_floating_point<T>::value == true);
    // norm(c.o - projection(l, c.o)) が直線 l と 円 c の中心 c.o の距離の 2 乗
    return sign(c.r * c.r - norm(c.o - projection(l, c.o))) >= 0;
}
template <class T> inline bool is_intersect(const Line<T>& l, const Circle<T>& c) { return is_intersect(c, l); }

// 円 c, 線分 s の交差判定
template <class T> inline bool is_intersect(const Circle<T>& c, const Segment<T>& s) {
    static_assert(is_geometry_floating_point<T>::value == true);
    if (!is_intersect(c, Line(s.a, s.b))) return false;  // 直線としても交差しない
    T d1 = abs(c.o - s.a), d2 = abs(c.o - s.b);
    if (sign(d1 - c.r) == -1 and sign(d2 - c.r) == -1) return false;  // 端点がどちらも円の内側
    if (sign(d1 - c.r) * sign(d2 - c.r) <= 0) return true;            // 円周をまたいでいる
    const Point<T> h = projection(s, c.o);
    return ccw(s.a, s.b, h) == Ccw::ON_SEGMENT;  // s.a -> h -> s.b の順で並んでいる
}
template <class T> inline bool is_intersect(const Segment<T>& s, const Circle<T>& c) { return is_intersect(c, s); }
