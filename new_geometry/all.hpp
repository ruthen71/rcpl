// #include "new_geometry/geometry_template.hpp"

#include <type_traits>

// Constants (EPS, PI)
// EPS の変更は Constants<T>::set_eps(new_eps) で
template <class T> struct Constants {
    static T EPS;
    static void set_eps(const T e) { EPS = e; }
    static constexpr T PI = 3.14159'26535'89793L;
};

template <> double Constants<double>::EPS = 1e-9;
template <> long double Constants<long double>::EPS = 1e-12;
template <> long long Constants<long long>::EPS = 0;

// base functions
template <class T> inline int sign(const T x) { return x < -Constants<T>::EPS ? -1 : (x > Constants<T>::EPS ? 1 : 0); }
template <class T> inline bool equal(const T a, const T b) { return sign(a - b) == 0; }
template <class T> inline T radian_to_degree(const T r) { return r * 180.0 / Constants<T>::PI; }
template <class T> inline T degree_to_radian(const T d) { return d * Constants<T>::PI / 180.0; }

// #include "new_geometry/point.hpp"

// point
template <class T> struct Point {
    T x, y;

    Point() = default;
    Point(const T x, const T y) : x(x), y(y) {}

    Point& operator+=(const Point& p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point& operator-=(const Point& p) {
        x -= p.x, y -= p.y;
        return *this;
    }
    Point& operator*=(const Point& p) {
        static_assert(std::is_floating_point<T>::value == true);
        return *this = Point(x * p.x - y * p.y, x * p.y + y * p.x);
    }
    Point& operator/=(const Point& p) {
        static_assert(std::is_floating_point<T>::value == true);
        return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y);
    }
    Point& operator*=(const T k) {
        x *= k, y *= k;
        return *this;
    }
    Point& operator/=(const T k) {
        static_assert(std::is_floating_point<T>::value == true);
        x /= k, y /= k;
        return *this;
    }

    Point operator+() const { return *this; }
    Point operator-() const { return Point(-x, -y); }

    friend Point operator+(const Point& a, const Point& b) { return Point(a) += b; }
    friend Point operator-(const Point& a, const Point& b) { return Point(a) -= b; }
    friend Point operator*(const Point& a, const Point& b) { return Point(a) *= b; }
    friend Point operator/(const Point& a, const Point& b) { return Point(a) /= b; }
    friend Point operator*(const Point& p, const T k) { return Point(p) *= k; }
    friend Point operator/(const Point& p, const T k) { return Point(p) /= k; }

    // 辞書式順序
    friend bool operator<(const Point& a, const Point& b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
    friend bool operator>(const Point& a, const Point& b) { return a.x == b.x ? a.y > b.y : a.x > b.x; }

    // I/O
    friend std::istream& operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) { return os << '(' << p.x << ' ' << p.y << ')'; }
};

// point base functions
// 点の一致判定
template <class T> inline bool equal(const Point<T>& a, const Point<T>& b) { return equal(a.x, b.x) and equal(a.y, b.y); }
// 内積
template <class T> inline T dot(const Point<T>& a, const Point<T>& b) { return a.x * b.x + a.y * b.y; }
// 外積
template <class T> inline T cross(const Point<T>& a, const Point<T>& b) { return a.x * b.y - a.y * b.x; }
// rad ラジアンだけ反時計回りに回転
template <class T> inline Point<T> rotate(const Point<T>& p, const T theta) {
    static_assert(std::is_floating_point<T>::value == true);
    return p * Point<T>(std::cos(theta), std::sin(theta));
}
// x, y の順で比較
template <class T> inline bool compare_x(const Point<T>& a, const Point<T>& b) { return equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }
// y, x の順で比較
template <class T> inline bool compare_y(const Point<T>& a, const Point<T>& b) { return equal(a.y, b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }
// arg(p), norm(p) の順で比較, arg(p) は [0, 2 * PI) で並ぶ
// 整数の範囲で比較可能
template <class T> inline bool compare_arg(const Point<T>& a, const Point<T>& b) {
    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103
    assert(!equal(a, Point<T>(0, 0)));
    assert(!equal(b, Point<T>(0, 0)));
    if ((Point<T>(0, 0) < Point<T>(a.y, a.x)) == (Point<T>(0, 0) < Point<T>(b.y, b.x))) {
        return (a.x * b.y == a.y * b.x) ? norm(a) < norm(b) : a.x * b.y > a.y * b.x;
    } else {
        return Point<T>(a.y, a.x) > Point<T>(b.y, b.x);
    }
}
// 絶対値の 2 乗
template <class T> inline T norm(const Point<T>& p) { return p.x * p.x + p.y * p.y; }
// 絶対値
template <class T> inline T abs(const Point<T>& p) {
    static_assert(std::is_floating_point<T>::value == true);
    return std::sqrtl(norm(p));
}
// 偏角
template <class T> inline T arg(const Point<T>& p) {
    static_assert(std::is_floating_point<T>::value == true);
    return std::atan2l(p.y, p.x);
}
// 共役複素数 (x 軸について対象な点)
template <class T> inline Point<T> conj(const Point<T>& p) { return Point(p.x, -p.y); }
// 極座標系 -> 直交座標系 (絶対値が rho で偏角が theta ラジアン)
template <class T> inline Point<T> polar(const T rho, const T theta = T(0)) {
    static_assert(std::is_floating_point<T>::value == true);
    assert(sign(rho) >= 0);
    return Point<T>(std::cos(theta), std::sin(theta)) * rho;
}

// ccw の戻り値
enum class Ccw {
    COUNTER_CLOCKWISE = 1,  // a->b->c 反時計回り
    CLOCKWISE = -1,         // a->b->c 時計回り
    ONLINE_BACK = 2,        // c->a->b 直線
    ONLINE_FRONT = -2,      // a->b->c 直線
    ON_SEGMENT = 0          // a->c->b 直線
};
// 点 a, b, c の位置関係
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
template <class T> Ccw ccw(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    Point<T> ab = b - a;
    Point<T> ac = c - a;
    if (sign(cross(ab, ac)) == 1) return Ccw::COUNTER_CLOCKWISE;
    if (sign(cross(ab, ac)) == -1) return Ccw::CLOCKWISE;
    if (sign(dot(ab, ac)) == -1) return Ccw::ONLINE_BACK;
    if (sign(norm(ab) - norm(ac))) return Ccw::ONLINE_FRONT;
    return Ccw::ON_SEGMENT;
}

// #include "new_geometry/line.hpp"

// line
template <class T> struct Line {
    Point<T> a, b;

    Line() = default;
    Line(const Point<T>& a, const Point<T>& b) : a(a), b(b) {}

    // Ax + By = C
    Line(const T A, const T B, const T C) {
        static_assert(std::is_floating_point<T>::value == true);
        assert(!(equal(A, T(0)) and equal(B, T(0))));
        if (equal(A, T(0))) {
            a = Point<T>(T(0), C / B), b = Point<T>(T(1), C / B);
        } else if (equal(B, T(0))) {
            a = Point<T>(C / A, T(0)), b = Point<T>(C / A, T(1));
        } else if (equal(C, T(0))) {
            a = Point<T>(T(0), T(0)), b = Point<T>(T(1), -A / B);
        } else {
            a = Point<T>(T(0), C / B), b = Point<T>(C / A, T(0));
        }
    }

    friend std::istream& operator>>(std::istream& is, Line& p) { return is >> p.a >> p.b; }
    friend std::ostream& operator<<(std::ostream& os, const Line& p) { return os << p.a << "->" << p.b; }
};

// #include "new_geometry/segment.hpp"

// segment
template <class T> struct Segment : Line<T> {
    Segment() = default;

    Segment(const Point<T>& a, const Point<T>& b) : Line<T>(a, b) {}
};

// circle
template <class T> struct Circle {
    Point<T> o;
    T r;

    Circle() = default;
    Circle(const Point<T>& o, const T r) : o(o), r(r) {}

    friend std::istream& operator>>(std::istream& is, Circle& c) { return is >> c.o >> c.r; }
    friend std::ostream& operator<<(std::ostream& os, const Circle& c) { return os << c.o << ", " << c.r; }
};

// polygon
#include <vector>
template <class T> using Polygon = std::vector<Point<T>>;
template <class T> std::istream& operator>>(std::istream& is, Polygon<T>& p) {
    for (auto&& pi : p) is >> pi;
    return is;
}
template <class T> std::ostream& operator<<(std::ostream& os, const Polygon<T>& p) {
    for (auto&& pi : p) os << pi << " -> ";
    return os;
}

// 点 p から直線 l に下ろした垂線と直線 l の交点
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
template <class T> Point<T> projection(const Line<T>& l, const Point<T>& p) {
    static_assert(std::is_floating_point<T>::value == true);
    T t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return l.a + (l.b - l.a) * t;
}

// 直線 l に関して点 p と対象な位置にある点
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
template <class T> Point<T> reflection(const Line<T>& l, const Point<T>& p) {
    static_assert(std::is_floating_point<T>::value == true);
    return p + (projection(l, p) - p) * T(2);
}

// 直線 l1, l2 の垂直判定
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
template <class T> inline bool is_orthogonal(const Line<T>& l1, const Line<T>& l2) { return sign(dot(l1.b - l1.a, l2.b - l2.a)) == 0; }

// 直線 l1, l2 の平行判定
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
template <class T> inline bool is_parallel(const Line<T>& l1, const Line<T>& l2) { return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0; }

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
    // 線分が平行なケースは 1 次元的に考えると必ず端点のどれかがもう一方の線分上にある
    if (c1 == Ccw::ON_SEGMENT or c2 == Ccw::ON_SEGMENT or c3 == Ccw::ON_SEGMENT or c4 == Ccw::ON_SEGMENT) {
        return true;
    }
    // 平行でない場合: 一方の線分の両側にもう一方の線分の端点がある, を線分を入れ替えても成立
    bool ok1 = ((c1 == Ccw::CLOCKWISE and c2 == Ccw::COUNTER_CLOCKWISE) or (c1 == Ccw::COUNTER_CLOCKWISE and c2 == Ccw::CLOCKWISE));
    bool ok2 = ((c3 == Ccw::CLOCKWISE and c4 == Ccw::COUNTER_CLOCKWISE) or (c3 == Ccw::COUNTER_CLOCKWISE and c4 == Ccw::CLOCKWISE));
    return ok1 and ok2;
}

// 点 p1, p2 の交差判定
template <class T> inline bool is_intersect(const Point<T>& p1, const Point<T>& p2) { return equal(p1, p2); }

// 共通接線の本数
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
template <class T> int tangent_number(Circle<T> c1, Circle<T> c2) {
    if (c1.r < c2.r) std::swap(c1, c2);
    const T d2 = norm(c1.o - c2.o);
    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 1) return 4;  // d > c1.r + c2.r and c1.r + c2.r >= 0 <=> d ^ 2 > (c1.r + c2.r) ^ 2
    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 0) return 3;  // d = c1.r + c2.r and c1.r + c2.r >= 0 <=> d ^ 2 = (c1.r + c2.r) ^ 2
    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 1) return 2;  // d > c1.r - c2.r and c1.r - c2.r >= 0 <=> d ^ 2 > (c1.r - c2.r) ^ 2
    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 0) return 1;  // d = c1.r - c2.r and c1.r - c2.r >= 0 <=> d ^ 2 = (c1.r - c2.r) ^ 2
    return 0;
}

// 円 c1, c2 の交差判定
template <class T> inline bool is_intersect(const Circle<T>& c1, const Circle<T>& c2) {
    int num = tangent_number(c1, c2);
    return 1 <= num and num <= 3;
}

// 円 c, 点 p の交差判定
template <class T> inline bool is_intersect(const Circle<T>& c, const Point<T>& p) { return equal(norm(p - c.o), c.r * c.r); }
template <class T> inline bool is_intersect(const Point<T>& p, const Circle<T>& c) { return equal(norm(p - c.o), c.r * c.r); }

// 円 c, 直線 l の交差判定
template <class T> inline bool is_intersect(const Circle<T>& c, const Line<T>& l) {
    static_assert(std::is_floating_point<T>::value == true);
    // norm(c.o - projection(l, c.o)) が直線 l と 円 c の中心 c.o の距離の 2 乗
    return sign(c.r * c.r - norm(c.o - projection(l, c.o))) >= 0;
}
template <class T> inline bool is_intersect(const Line<T>& l, const Circle<T>& c) { return is_intersect(c, l); }

// 円 c, 線分 s の交差判定
template <class T> inline bool is_intersect(const Circle<T>& c, const Segment<T>& s) {
    static_assert(std::is_floating_point<T>::value == true);
    if (!is_intersect(c, Line(s.a, s.b))) return false;  // 直線としても交差しない
    T d1 = abs(c.o - s.a), d2 = abs(c.o - s.b);
    if (sign(d1 - c.r) == -1 and sign(d2 - c.r) == -1) return false;  // 端点がどちらも円の内側
    if (sign(d1 - c.r) * sign(d2 - c.r) <= 0) return true;            // 円周をまたいでいる
    const Point<T> h = projection(s, c.o);
    return ccw(s.a, s.b, h) == Ccw::ON_SEGMENT;  // s.a -> h -> s.b の順で並んでいる
}
template <class T> inline bool is_intersect(const Segment<T>& s, const Circle<T>& c) { return is_intersect(c, s); }

// 交点 (直線, 線分, 円)
// 交点を持たない場合の挙動は未定義
// 直線 l1, l2 の交点 1 つ
template <class T> Point<T> cross_point(const Line<T>& l1, const Line<T>& l2) {
    static_assert(std::is_floating_point<T>::value == true);
    Point<T> base = l1.b - l1.a;
    T d12 = cross(base, l2.b - l2.a);
    T d1 = cross(base, l1.b - l2.a);
    if (sign(d12) == 0) {
        assert(sign(d1) == 0);  // 平行かつ一致しない
        return l2.a;
    }
    return l2.a + (l2.b - l2.a) * (d1 / d12);
}

// 線分 s1, s2 の交点 1 つ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
template <class T> Point<T> cross_point(const Segment<T>& s1, const Segment<T>& s2) {
    static_assert(std::is_floating_point<T>::value == true);
    Point<T> base = s1.b - s1.a;
    T d12 = cross(base, s2.b - s2.a);
    T d1 = cross(base, s1.b - s2.a);
    if (sign(d12) == 0) {
        assert(sign(d1) == 0);  // 平行かつ一致しない
        // 端点のどれかを返す
        if (is_intersect(s1, s2.a)) return s2.a;
        if (is_intersect(s1, s2.b)) return s2.b;
        if (is_intersect(s2, s1.a)) return s1.a;
        assert(is_intersect(s2, s1.b));
        return s1.b;
    }
    return s2.a + (s2.b - s2.a) * (d1 / d12);
}

// 直線 l, 線分 s の交点 1 つ
template <class T> Point<T> cross_point(const Line<T>& l, const Segment<T>& s) {
    // cross_point(l1, l2) は重なるとき l2.a を返すので OK
    return cross_point(l, Line<T>(s.a, s.b));
}
template <class T> Point<T> cross_point(const Segment<T>& s, const Line<T>& l) { return cross_point(l, s); }

// 円 c, 直線 l の交点 1 or 2 つ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
template <class T> std::vector<Point<T>> cross_point(const Circle<T>& c, const Line<T>& l) {
    static_assert(std::is_floating_point<T>::value == true);
    auto pr = projection(l, c.o);
    if (equal(norm(pr - c.o), c.r * c.r)) return {pr};
    Point<T> e = (l.b - l.a) / abs(l.b - l.a);
    auto k = sqrtl(c.r * c.r - norm(pr - c.o));
    return {pr - e * k, pr + e * k};
}
template <class T> std::vector<Point<T>> cross_point(const Line<T>& l, const Circle<T>& c) { return cross_point(c, l); }

// 円 c, 線分 s の交点 1 or 2 つ
template <class T> std::vector<Point<T>> cross_point(const Circle<T>& c, const Segment<T>& s) {
    assert(is_intersect(c, s));
    auto ps = cross_point(c, Line<T>(s.a, s.b));
    std::vector<Point<T>> res;
    for (auto&& p : ps)
        if (ccw(s.a, s.b, p) == Ccw::ON_SEGMENT) res.emplace_back(p);
    return res;
}
template <class T> std::vector<Point<T>> cross_point(const Segment<T>& s, const Circle<T>& c) { return cross_point(c, s); }

// 円 c1, c2 の交点 1 or 2 つ
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
template <class T> std::vector<Point<T>> cross_point(const Circle<T>& c1, const Circle<T>& c2) {
    static_assert(std::is_floating_point<T>::value == true);
    assert(is_intersect(c1, c2));
    T d = abs(c1.o - c2.o);
    T a = std::acosl((c1.r * c1.r - c2.r * c2.r + d * d) / (T(2) * c1.r * d));
    T t = arg(c2.o - c1.o);
    Point<T> p = c1.o + polar(c1.r, t + a);
    Point<T> q = c1.o + polar(c1.r, t - a);
    if (equal(p, q)) return {p};
    return {p, q};
}

// 距離 (直線, 線分, 点)
// 点 p1, p2 の距離
template <class T> T distance(const Point<T>& p1, const Point<T>& p2) { return abs(p1 - p2); }

// 直線 l, 点 p の距離
template <class T> T distance(const Line<T>& l, const Point<T>& p) {
    static_assert(std::is_floating_point<T>::value == true);
    return abs(p - projection(l, p));
}
template <class T> T distance(const Point<T>& p, const Line<T>& l) { return distance(l, p); }

// 線分 s, 点 p の距離
template <class T> T distance(const Segment<T>& s, const Point<T>& p) {
    static_assert(std::is_floating_point<T>::value == true);
    Point<T> r = projection(s, p);
    if (is_intersect(s, r)) return abs(r - p);
    return std::min(abs(s.a - p), abs(s.b - p));
}
template <class T> T distance(const Point<T>& p, const Segment<T>& s) { return distance(s, p); }

// 直線 l1, l2 の距離
template <class T> T distance(const Line<T>& l1, const Line<T>& l2) {
    static_assert(std::is_floating_point<T>::value == true);
    if (is_intersect(l1, l2)) return 0;
    return distance(l1, l2.a);
}

#include <algorithm>

// 直線 l, 線分 s の距離
template <class T> T distance(const Line<T>& l, const Segment<T>& s) {
    static_assert(std::is_floating_point<T>::value == true);
    if (is_intersect(l, s)) return 0;
    return std::min(distance(l, s.a), distance(l, s.b));
}
template <class T> T distance(const Segment<T>& s, const Line<T>& l) { return distance(l, s); }

// 線分 s1, s2 の距離
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
template <class T> T distance(const Segment<T>& s1, const Segment<T>& s2) {
    static_assert(std::is_floating_point<T>::value == true);
    if (is_intersect(s1, s2)) return 0;
    return std::min({distance(s1, s2.a), distance(s1, s2.b), distance(s2, s1.a), distance(s2, s1.b)});
}

// 円の接点 (円の外側の点に対する円の接線の円との交点)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
template <class T> std::vector<Point<T>> tangent_point(const Circle<T>& c, const Point<T>& p) {
    static_assert(std::is_floating_point<T>::value == true);
    assert(sign(abs(c.o - p) - c.r) == 1);
    return cross_point(c, Circle(p, sqrtl(norm(c.o - p) - c.r * c.r)));
}

// 三角形の内接円
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B
// https://drken1215.hatenablog.com/entry/2020/10/16/073700
template <class T> Circle<T> incircle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    static_assert(std::is_floating_point<T>::value == true);
    T A = arg((c - a) / (b - a)), B = arg((a - b) / (c - b));
    Line l1(a, a + rotate(b - a, A / 2)), l2(b, b + rotate(c - b, B / 2));
    auto o = cross_point(l1, l2);
    auto r = distance(Line(a, b), o);
    return Circle(o, r);
}

// 三角形の外接円
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C
// https://drken1215.hatenablog.com/entry/2020/10/16/074400
template <class T> Circle<T> circumscribed_circle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    static_assert(std::is_floating_point<T>::value == true);
    Line<T> l1((a + b) / 2, (a + b) / 2 + rotate(b - a, Constants<T>::PI / 2));
    Line<T> l2((b + c) / 2, (b + c) / 2 + rotate(c - b, Constants<T>::PI / 2));
    auto o = cross_point(l1, l2);
    auto r = abs(o - a);
    return Circle(o, r);
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
    static_assert(std::is_floating_point<T>::value == true);
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

enum class Contain { IN, ON, OUT };

// 多角形が点を包含するか判定
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
template <class T> Contain polygon_contain(const Polygon<T>& q, const Point<T>& p) {
    bool x = false;
    const int n = (int)(q.size());
    for (int i = 0; i < n; i++) {
        if (is_intersect(Segment(q[i], q[i + 1 == n ? 0 : i + 1]), p)) return Contain::ON;
        Point a = q[i] - p, b = q[i + 1] - p;
        if (a.y > b.y) std::swap(a, b);
        // a.y < b.y
        // check each point's y is 0 at most 1 times
        if (sign(a.y) <= 0 and sign(b.y) > 0 and sign(cross(a, b)) > 0) x = !x;
    }
    return (x ? Contain::IN : Contain::OUT);
}

// 凸包 (Andrew's Monotone Chain algorithm)
// O(n log n)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
// (x, y) を辞書式順序でソートし, スタックを使って上側凸包と下側凸包を求める
// 反時計回り
// strict を true にすると凸包の辺上に並ぶ頂点は含めない (頂点数が最小になる)
template <class T> Polygon<T> convex_hull_monotone_chain(std::vector<Point<T>>& p, bool strict = true) {
    const int n = (int)(p.size());
    if (n <= 2) return p;
    std::sort(p.begin(), p.end(), compare_x<T>);
    Polygon<T> r;
    r.reserve(n * 2);
    auto f = [&strict](Ccw ccwres) -> bool { return strict ? ccwres != Ccw::CLOCKWISE : ccwres == Ccw::COUNTER_CLOCKWISE; };
    for (int i = 0; i < n; i++) {
        while (r.size() >= 2 and f(ccw(r[r.size() - 2], r[r.size() - 1], p[i]))) {
            r.pop_back();
        }
        r.push_back(p[i]);
    }
    int t = r.size() + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (r.size() >= t and f(ccw(r[r.size() - 2], r[r.size() - 1], p[i]))) {
            r.pop_back();
        }
        r.push_back(p[i]);
    }
    r.pop_back();
    std::reverse(r.begin(), r.end());
    return r;
}

// 凸多角形の直径 (rotating calipers)
// https://en.wikipedia.org/wiki/Rotating_calipers
// O(n)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
// return {index1, index2, diameter}
template <class T> std::tuple<int, int, T> convex_polygon_diameter(const Polygon<T>& p) {
    assert(polygon_is_convex(p));
    const int n = (int)(p.size());
    assert(n >= 2);
    if (n == 2) {
        return {0, 1, abs(p[0] - p[1])};
    }
    auto [it_min, it_max] = std::minmax_element(p.begin(), p.end(), compare_x);
    int idx_min = it_min - p.begin();
    int idx_max = it_max - p.begin();

    T maxdis = norm(p[idx_max] - p[idx_min]);
    int maxi = idx_min, i = idx_min, maxj = idx_max, j = idx_max;
    do {
        int ni = (i + 1 == n ? 0 : i + 1), nj = (j + 1 == n ? 0 : j + 1);
        if (sign(cross(p[ni] - p[i], p[nj] - p[j])) < 0) {
            i = ni;
        } else {
            j = nj;
        }
        if (norm(p[i] - p[j]) > maxdis) {
            maxdis = norm(p[i] - p[j]);
            maxi = i;
            maxj = j;
        }
    } while (i != idx_min or j != idx_max);
    return {maxi, maxj, abs(p[maxi] - p[maxj])};
}

// 凸多角形 p を 直線 l で切断
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
// return {left polygon, right polygon}
template <class T> std::pair<Polygon<T>, Polygon<T>> convex_polygon_cut(const Polygon<T>& p, const Line<T>& l) {
    static_assert(std::is_floating_point<T>::value == true);
    const int n = (int)(p.size());
    assert(n >= 3);
    Polygon<T> pl, pr;
    for (int i = 0; i < n; i++) {
        int ni = i + 1 == n ? 0 : i + 1;
        const int s1 = sign(cross(l.a - p[i], l.b - p[i]));
        const int s2 = sign(cross(l.a - p[ni], l.b - p[ni]));
        if (s1 >= 0) {
            pl.push_back(p[i]);
        }
        if (s1 <= 0) {
            pr.push_back(p[i]);
        }
        if (s1 * s2 < 0) {
            auto pc = cross_point(Line(p[i], p[ni]), l);
            pl.push_back(pc);
            pr.push_back(pc);
        }
    }
    return {pl, pr};
}

// 最近点対 (分割統治法)
// O(n log n)
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
// return {index1, index2, distance}
template <class T> std::tuple<int, int, T> closest_pair(const std::vector<Point<T>>& p) {
    const int n = (int)(p.size());

    assert(n >= 2);
    if (n == 2) {
        return {0, 1, abs(p[0] - p[1])};
    }
    // may not be efficient due to indirect references ...
    std::vector<int> ind(n);
    std::iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });
    auto dfs = [&](auto f, int l, int r) -> std::tuple<int, int, T> {
        if (r - l <= 1) return {-1, -1, std::numeric_limits<T>::max()};
        const int md = (l + r) / 2;
        T x = p[ind[md]].x;
        // 分割統治法
        auto [i1l, i2l, dl] = f(f, l, md);
        auto [i1r, i2r, dr] = f(f, md, r);
        int i1 = i1r, i2 = i2r;
        T d = dr;
        if (dl < dr) {
            d = dl, i1 = i1l, i2 = i2l;
        }
        std::inplace_merge(ind.begin() + l, ind.begin() + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i], p[j]); });
        // ind は y でソートされる
        std::vector<int> near_x;  // 直線 x からの距離が d 未満の頂点のインデックス
        for (int i = l; i < r; i++) {
            if (sign(std::abs(p[ind[i]].x - x) - d) >= 0) continue;  // |p[ind[i]].x - x| >= d
            const int sz = (int)(near_x.size());
            // y座標との距離が d 以上になるまで繰り返す
            for (int j = sz - 1; j >= 0; j--) {
                Point cp = p[ind[i]] - p[near_x[j]];
                if (sign(cp.y - d) >= 0) break;  // cp.y >= d
                T cd = abs(cp);
                if (cd < d) {
                    d = cd, i1 = ind[i], i2 = near_x[j];
                }
            }
            near_x.push_back(ind[i]);
        }
        return {i1, i2, d};
    };
    return dfs(dfs, 0, n);
}

// 最遠点対
// return {index1, index2, distance}
// 凸包を求めてから凸多角形の直径を求めている
// O(n log n)
template <class T> std::tuple<int, int, T> farthest_pair(const std::vector<Point<T>>& p) {
    const int n = (int)(p.size());
    assert(n >= 2);
    if (n == 2) {
        return {0, 1, abs(p[0] - p[1])};
    }
    auto q = p;
    auto ch = monotone_chain(q);                   // O(n log n)
    auto [i, j, d] = convex_polygon_diameter(ch);  // O(|ch|)
    int resi, resj;
    for (int k = 0; k < n; k++) {
        if (p[k] == ch[i]) {
            resi = k;
        }
        if (p[k] == ch[j]) {
            resj = k;
        }
    }
    return {resi, resj, d};
}