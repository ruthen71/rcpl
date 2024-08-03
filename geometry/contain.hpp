#pragma once

#include "geometry/polygon.hpp"
#include "geometry/line.hpp"
#include "geometry/is_intersect.hpp"

enum class Contain { IN, ON, OUT };

// 円 c と点 p の位置関係
template <class T> Contain contain(const Circle<T>& c, const Point<T>& p) {
    int sgn = sign(norm(p - c.o) - c.r * c.r);
    return sgn == 1 ? Contain::OUT : (sgn == 0 ? Contain::ON : Contain::IN);
}

// 多角形 (凸とは限らない) q と点 p の位置関係
// 頂点は反時計回りに並んでいる
// O(n)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
template <class T> Contain contain(const Polygon<T>& q, const Point<T>& p) {
    const int n = (int)(q.size());
    assert(n >= 3);
    bool x = false;
    for (int i = 0; i < n; i++) {
        if (is_intersect(Segment(q[i], q[(i + 1) % n]), p)) return Contain::ON;
        Point a = q[i] - p, b = q[(i + 1) % n] - p;
        if (a.y > b.y) std::swap(a, b);
        // a.y < b.y
        // check each point's y is 0 at most 1 times
        if (sign(a.y) <= 0 and sign(b.y) > 0 and sign(cross(a, b)) > 0) x = !x;
    }
    return (x ? Contain::IN : Contain::OUT);
}

// 凸多角形 (すべての内角が 180° 未満) q と点 p の位置関係
// 頂点は反時計回りに並んでいる
// O(log n)
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412
// https://atcoder.jp/contests/abc296/tasks/abc296_g
template <class T> Contain convex_contain(const Polygon<T>& q, const Point<T>& p) {
    const int n = (int)(q.size());
    assert(n >= 3);
    auto c1 = ccw(q[0], q[1], p);
    auto c2 = ccw(q[0], q[n - 1], p);
    if (c1 == Ccw::CLOCKWISE or c2 == Ccw::COUNTER_CLOCKWISE) return Contain::OUT;
    if (c1 == Ccw::ON_SEGMENT or c2 == Ccw::ON_SEGMENT) return Contain::ON;
    if (c1 == Ccw::ONLINE_FRONT or c2 == Ccw::ONLINE_FRONT) return Contain::OUT;
    // 二分探索 (q[0] -> q[i] -> p が反時計回りになるような最大の i)
    int ok = 1, ng = n - 1;
    while (ng - ok > 1) {
        int md = (ok + ng) / 2;
        if (ccw(q[0], q[md], p) == Ccw::COUNTER_CLOCKWISE) {
            ok = md;
        } else {
            ng = md;
        }
    }
    // 直線 q[ok] -> q[ok + 1] を基準に考える
    auto c3 = ccw(q[ok], q[ok + 1], p);
    assert(c3 != Ccw::ONLINE_FRONT);
    assert(c3 != Ccw::ONLINE_BACK);
    return c3 == Ccw::ON_SEGMENT ? Contain::ON : (c3 == Ccw::COUNTER_CLOCKWISE ? Contain::IN : Contain::OUT);
}