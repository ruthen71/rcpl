---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: "Circle (\u5186)"
  - icon: ':heavy_check_mark:'
    path: geometry/contain.hpp
    title: "Contain (\u591A\u89D2\u5F62\u3084\u5186\u3068\u70B9\u306E\u4F4D\u7F6E\u95A2\
      \u4FC2)"
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect.hpp
    title: "Intersection (\u4EA4\u5DEE\u5224\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "Line / Segment (\u76F4\u7DDA\u30FB\u7DDA\u5206)"
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: "Point (\u70B9)"
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: "Polygon (\u591A\u89D2\u5F62)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
  bundledCode: "#line 1 \"verify/geometry/contain.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C\"\
    \n\n#include <iostream>\n\n#line 2 \"geometry/contain.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#include <cassert>\n#include <cmath>\n\n\
    #line 2 \"geometry/geometry_template.hpp\"\n\n#include <type_traits>\n\n// Constants\
    \ (EPS, PI)\n// EPS \u306E\u5909\u66F4\u306F Constants<T>::set_eps(new_eps) \u3067\
    \ntemplate <class T> struct Constants {\n    static T EPS;\n    static void set_eps(const\
    \ T e) { EPS = e; }\n    static constexpr T PI = 3.14159'26535'89793L;\n};\n\n\
    template <> double Constants<double>::EPS = 1e-9;\ntemplate <> long double Constants<long\
    \ double>::EPS = 1e-12;\ntemplate <> long long Constants<long long>::EPS = 0;\n\
    \n// \u6C4E\u7528\u95A2\u6570\ntemplate <class T> inline int sign(const T x) {\
    \ return x < -Constants<T>::EPS ? -1 : (x > Constants<T>::EPS ? 1 : 0); }\ntemplate\
    \ <class T> inline bool equal(const T a, const T b) { return sign(a - b) == 0;\
    \ }\ntemplate <class T> inline T radian_to_degree(const T r) { return r * 180.0\
    \ / Constants<T>::PI; }\ntemplate <class T> inline T degree_to_radian(const T\
    \ d) { return d * Constants<T>::PI / 180.0; }\n\n// type traits\ntemplate <class\
    \ T> using is_geometry_floating_point = typename std::conditional<std::is_same<T,\
    \ double>::value || std::is_same<T, long double>::value, std::true_type, std::false_type>::type;\n\
    template <class T> using is_geometry_integer = typename std::conditional<std::is_same<T,\
    \ long long>::value, std::true_type, std::false_type>::type;\ntemplate <class\
    \ T> using is_geometry = typename std::conditional<is_geometry_floating_point<T>::value\
    \ || is_geometry_integer<T>::value, std::true_type, std::false_type>::type;\n\
    #line 7 \"geometry/point.hpp\"\n\n// \u70B9\ntemplate <class T> struct Point {\n\
    \    T x, y;\n\n    Point() = default;\n    Point(const T x, const T y) : x(x),\
    \ y(y) {}\n    template <class U> Point(const Point<U> p) : x(p.x), y(p.y) {}\n\
    \n    Point& operator+=(const Point& p) {\n        x += p.x, y += p.y;\n     \
    \   return *this;\n    }\n    Point& operator-=(const Point& p) {\n        x -=\
    \ p.x, y -= p.y;\n        return *this;\n    }\n    Point& operator*=(const Point&\
    \ p) {\n        static_assert(is_geometry_floating_point<T>::value == true);\n\
    \        return *this = Point(x * p.x - y * p.y, x * p.y + y * p.x);\n    }\n\
    \    Point& operator/=(const Point& p) {\n        static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n        return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x)\
    \ /\n                       (p.x * p.x + p.y * p.y);\n    }\n    Point& operator*=(const\
    \ T k) {\n        x *= k, y *= k;\n        return *this;\n    }\n    Point& operator/=(const\
    \ T k) {\n        static_assert(is_geometry_floating_point<T>::value == true);\n\
    \        x /= k, y /= k;\n        return *this;\n    }\n\n    Point operator+()\
    \ const { return *this; }\n    Point operator-() const { return Point(-x, -y);\
    \ }\n\n    friend Point operator+(const Point& a, const Point& b) {\n        return\
    \ Point(a) += b;\n    }\n    friend Point operator-(const Point& a, const Point&\
    \ b) {\n        return Point(a) -= b;\n    }\n    friend Point operator*(const\
    \ Point& a, const Point& b) {\n        return Point(a) *= b;\n    }\n    friend\
    \ Point operator/(const Point& a, const Point& b) {\n        return Point(a) /=\
    \ b;\n    }\n    friend Point operator*(const Point& p, const T k) { return Point(p)\
    \ *= k; }\n    friend Point operator/(const Point& p, const T k) { return Point(p)\
    \ /= k; }\n\n    // \u8F9E\u66F8\u5F0F\u9806\u5E8F\n    friend bool operator<(const\
    \ Point& a, const Point& b) {\n        return a.x == b.x ? a.y < b.y : a.x < b.x;\n\
    \    }\n    friend bool operator>(const Point& a, const Point& b) {\n        return\
    \ a.x == b.x ? a.y > b.y : a.x > b.x;\n    }\n    friend bool operator==(const\
    \ Point& a, const Point& b) {\n        return a.x == b.x and a.y == b.y;\n   \
    \ }\n\n    // I/O\n    friend std::istream& operator>>(std::istream& is, Point&\
    \ p) {\n        return is >> p.x >> p.y;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Point& p) {\n        return os << '(' << p.x << ' ' << p.y << ')';\n\
    \    }\n};\n\n// \u6C4E\u7528\u95A2\u6570\n// \u70B9\u306E\u4E00\u81F4\u5224\u5B9A\
    \ntemplate <class T> inline bool equal(const Point<T>& a, const Point<T>& b) {\n\
    \    return equal(a.x, b.x) and equal(a.y, b.y);\n}\n// \u5185\u7A4D\ntemplate\
    \ <class T> inline T dot(const Point<T>& a, const Point<T>& b) {\n    return a.x\
    \ * b.x + a.y * b.y;\n}\n// \u5916\u7A4D\ntemplate <class T> inline T cross(const\
    \ Point<T>& a, const Point<T>& b) {\n    return a.x * b.y - a.y * b.x;\n}\n//\
    \ rad \u30E9\u30B8\u30A2\u30F3\u3060\u3051\u53CD\u6642\u8A08\u56DE\u308A\u306B\
    \u56DE\u8EE2\ntemplate <class T> inline Point<T> rotate(const Point<T>& p, const\
    \ T theta) {\n    static_assert(is_geometry_floating_point<T>::value == true);\n\
    \    return p * Point<T>(std::cos(theta), std::sin(theta));\n}\n// (x, y) \u306E\
    \u8F9E\u66F8\u5F0F\u9806\u5E8F (\u8AA4\u5DEE\u8A31\u5BB9)\ntemplate <class T>\
    \ inline bool compare_x(const Point<T>& a, const Point<T>& b) {\n    return equal(a.x,\
    \ b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0;\n}\n// (y, x) \u306E\u8F9E\
    \u66F8\u5F0F\u9806\u5E8F (\u8AA4\u5DEE\u8A31\u5BB9)\ntemplate <class T> inline\
    \ bool compare_y(const Point<T>& a, const Point<T>& b) {\n    return equal(a.y,\
    \ b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0;\n}\n// \u6574\u6570\u306E\u307E\
    \u307E\u884C\u3046\u504F\u89D2\u30BD\u30FC\u30C8\n// \u7121\u9650\u306E\u7CBE\u5EA6\
    \u3092\u3082\u3064 arg(p) = atan2(y, x) \u3067\u6BD4\u8F03\u3057, \u540C\u3058\
    \u5834\u5408\u306F norm(p) \u3067\u6BD4\u8F03\n// (atan2(0, 0) = 0 \u3068\u3059\
    \u308B) \u57FA\u672C\u7684\u306B (-PI, PI] \u3067\u30BD\u30FC\u30C8\u3055\u308C\
    , \u70B9 (0, 0) \u306F (-PI,\n// 0) \u3068 [0, PI] \u306E\u9593\u306B\u5165\u308B\
    \n// https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n// https://judge.yosupo.jp/problem/sort_points_by_argument\n\
    template <class T>\ninline bool compare_atan2(const Point<T>& a, const Point<T>&\
    \ b) {\n    static_assert(is_geometry_integer<T>::value == true);\n    if ((Point<T>(a.y,\
    \ -a.x) > Point<T>(0, 0)) ==\n        (Point<T>(b.y, -b.x) >\n         Point<T>(0,\
    \ 0))) {  // a, b in (-PI, 0] or a, b in (0, PI]\n        if (a.x * b.y != a.y\
    \ * b.x)\n            return a.x * b.y > a.y * b.x;  // cross(a, b) != 0\n   \
    \     return a == Point<T>(0, 0)\n                   ? b.x > 0 and b.y == 0\n\
    \                   : (b == Point<T>(0, 0) ? a.y < 0 : norm(a) < norm(b));\n \
    \   }\n    return Point<T>(a.y, -a.x) < Point<T>(b.y, -b.x);\n}\n// \u7D76\u5BFE\
    \u5024\u306E 2 \u4E57\ntemplate <class T> inline T norm(const Point<T>& p) {\n\
    \    return p.x * p.x + p.y * p.y;\n}\n// \u7D76\u5BFE\u5024\ntemplate <class\
    \ T> inline T abs(const Point<T>& p) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    return std::sqrt(norm(p));\n}\n// \u504F\u89D2\ntemplate <class\
    \ T> inline T arg(const Point<T>& p) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    return std::atan2(p.y, p.x);  // (-PI, PI]\n}\n// \u5171\u5F79\
    \u8907\u7D20\u6570 (x \u8EF8\u306B\u3064\u3044\u3066\u5BFE\u8C61\u306A\u70B9)\n\
    template <class T> inline Point<T> conj(const Point<T>& p) {\n    return Point(p.x,\
    \ -p.y);\n}\n// \u6975\u5EA7\u6A19\u7CFB -> \u76F4\u4EA4\u5EA7\u6A19\u7CFB (\u7D76\
    \u5BFE\u5024\u304C rho \u3067\u504F\u89D2\u304C theta \u30E9\u30B8\u30A2\u30F3\
    )\ntemplate <class T> inline Point<T> polar(const T rho, const T theta = T(0))\
    \ {\n    static_assert(is_geometry_floating_point<T>::value == true);\n    assert(sign(rho)\
    \ >= 0);\n    return Point<T>(std::cos(theta), std::sin(theta)) * rho;\n}\n//\
    \ ccw \u306E\u623B\u308A\u5024\nenum class Ccw {\n    COUNTER_CLOCKWISE = 1, \
    \ // a->b->c \u53CD\u6642\u8A08\u56DE\u308A\n    CLOCKWISE = -1,         // a->b->c\
    \ \u6642\u8A08\u56DE\u308A\n    ONLINE_BACK = 2,        // c->a->b \u76F4\u7DDA\
    \n    ONLINE_FRONT = -2,      // a->b->c \u76F4\u7DDA\n    ON_SEGMENT = 0    \
    \      // a->c->b \u76F4\u7DDA\n};\n// \u70B9 a, b, c \u306E\u4F4D\u7F6E\u95A2\
    \u4FC2\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    template <class T>\nCcw ccw(const Point<T>& a, const Point<T>& b, const Point<T>&\
    \ c) {\n    Point<T> ab = b - a;\n    Point<T> ac = c - a;\n    if (sign(cross(ab,\
    \ ac)) == 1) return Ccw::COUNTER_CLOCKWISE;\n    if (sign(cross(ab, ac)) == -1)\
    \ return Ccw::CLOCKWISE;\n    if (sign(dot(ab, ac)) == -1) return Ccw::ONLINE_BACK;\n\
    \    if (sign(norm(ab) - norm(ac)) == -1) return Ccw::ONLINE_FRONT;\n    return\
    \ Ccw::ON_SEGMENT;\n}\n// \u7DDA\u5206 a -> b \u304B\u3089 \u7DDA\u5206 a -> c\
    \ \u307E\u3067\u306E\u89D2\u5EA6 (\u30E9\u30B8\u30A2\u30F3\u3067 -PI \u3088\u308A\
    \u5927\u304D\u304F PI \u4EE5\u4E0B)\ntemplate <class T>\nT get_angle(const Point<T>&\
    \ a, const Point<T>& b, const Point<T>& c) {\n    Point<T> ab = b - a;\n    Point<T>\
    \ ac = c - a;\n    // a-b\u304C x \u8EF8\u306B\u306A\u308B\u3088\u3046\u306B\u56DE\
    \u8EE2\n    ac *= conj(ab) / norm(ab);\n    return arg(ac);  // (-PI, PI]\n}\n\
    #line 4 \"geometry/polygon.hpp\"\n\n#include <vector>\n#line 7 \"geometry/polygon.hpp\"\
    \n\n// \u591A\u89D2\u5F62\ntemplate <class T> using Polygon = std::vector<Point<T>>;\n\
    template <class T> std::istream& operator>>(std::istream& is, Polygon<T>& p) {\n\
    \    for (auto&& pi : p) is >> pi;\n    return is;\n}\ntemplate <class T> std::ostream&\
    \ operator<<(std::ostream& os, const Polygon<T>& p) {\n    for (auto&& pi : p)\
    \ os << pi << \" -> \";\n    return os;\n}\n\n// \u591A\u89D2\u5F62\u306E\u9762\
    \u7A4D (\u7B26\u53F7\u4ED8\u304D)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    // return area * 2\ntemplate <class T> T area2(const Polygon<T>& p) {\n    const\
    \ int n = (int)(p.size());\n    assert(n >= 2);\n    T res = T(0);\n    for (int\
    \ i = 0; i < n; i++) res += cross(p[i], p[i + 1 == n ? 0 : i + 1]);\n    // counter\
    \ clockwise: res > 0\n    // clockwise: res < 0\n    return res;\n}\ntemplate\
    \ <class T> T area(const Polygon<T>& p) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    return area2(p) / T(2);\n}\n\n// \u591A\u89D2\u5F62\u306E\u51F8\
    \u5224\u5B9A (\u89D2\u5EA6\u304C 0 \u3067\u3082 PI \u3067\u3082\u8A31\u5BB9)\n\
    // \u8A31\u5BB9\u3057\u305F\u304F\u306A\u3044\u3068\u304D\u306B\u306F ON_SEGMENT,\
    \ ONLINE_FRONT, ONLINE_BACK \u304C\u51FA\u3066\u304D\u305F\u3089 false \u3092\u8FD4\
    \u305B\u3070 OK\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\n\
    template <class T> bool is_convex(const Polygon<T>& p) {\n    const int n = (int)(p.size());\n\
    \    assert(n >= 3);\n    bool okccw = true, okcw = true;\n    for (int i = 0;\
    \ i < n; i++) {\n        auto res = ccw(p[i], p[i + 1 >= n ? i + 1 - n : i + 1],\
    \ p[i + 2 >= n ? i + 2 - n : i + 2]);\n        if (res == Ccw::CLOCKWISE) okccw\
    \ = false;\n        if (res == Ccw::COUNTER_CLOCKWISE) okcw = false;\n       \
    \ if (!okccw and !okcw) return false;\n    }\n    return true;\n}\n#line 2 \"\
    geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\n// \u76F4\u7DDA\ntemplate\
    \ <class T> struct Line {\n    Point<T> a, b;\n\n    Line() = default;\n    Line(const\
    \ Point<T>& a, const Point<T>& b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(const\
    \ T A, const T B, const T C) {\n        static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n        assert(!(equal(A, T(0)) and equal(B, T(0))));\n        if\
    \ (equal(A, T(0))) {\n            a = Point<T>(T(0), C / B), b = Point<T>(T(1),\
    \ C / B);\n        } else if (equal(B, T(0))) {\n            a = Point<T>(C /\
    \ A, T(0)), b = Point<T>(C / A, T(1));\n        } else if (equal(C, T(0))) {\n\
    \            a = Point<T>(T(0), T(0)), b = Point<T>(T(1), -A / B);\n        }\
    \ else {\n            a = Point<T>(T(0), C / B), b = Point<T>(C / A, T(0));\n\
    \        }\n    }\n\n    friend std::istream& operator>>(std::istream& is, Line&\
    \ p) {\n        return is >> p.a >> p.b;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Line& p) {\n        return os << p.a << \"->\" << p.b;\n    }\n};\n\
    \n// \u7DDA\u5206\ntemplate <class T> struct Segment : Line<T> {\n    Segment()\
    \ = default;\n\n    Segment(const Point<T>& a, const Point<T>& b) : Line<T>(a,\
    \ b) {}\n};\n\n// \u70B9 p \u304B\u3089\u76F4\u7DDA l \u306B\u4E0B\u308D\u3057\
    \u305F\u5782\u7DDA\u3068\u76F4\u7DDA l \u306E\u4EA4\u70B9\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    template <class T> Point<T> projection(const Line<T>& l, const Point<T>& p) {\n\
    \    static_assert(is_geometry_floating_point<T>::value == true);\n    T t = dot(p\
    \ - l.a, l.b - l.a) / norm(l.b - l.a);\n    return l.a + (l.b - l.a) * t;\n}\n\
    \n// \u76F4\u7DDA l \u306B\u95A2\u3057\u3066\u70B9 p \u3068\u5BFE\u8C61\u306A\u4F4D\
    \u7F6E\u306B\u3042\u308B\u70B9\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\n\
    template <class T> Point<T> reflection(const Line<T>& l, const Point<T>& p) {\n\
    \    static_assert(is_geometry_floating_point<T>::value == true);\n    return\
    \ p + (projection(l, p) - p) * T(2);\n}\n\n// \u76F4\u7DDA l1, l2 \u306E\u5782\
    \u76F4\u5224\u5B9A\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    template <class T>\ninline bool is_orthogonal(const Line<T>& l1, const Line<T>&\
    \ l2) {\n    return sign(dot(l1.b - l1.a, l2.b - l2.a)) == 0;\n}\n\n// \u76F4\u7DDA\
    \ l1, l2 \u306E\u5E73\u884C\u5224\u5B9A\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    template <class T>\ninline bool is_parallel(const Line<T>& l1, const Line<T>&\
    \ l2) {\n    return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0;\n}\n#line 2 \"\
    geometry/is_intersect.hpp\"\n\n#line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\
    \n\n// \u5186\ntemplate <class T> struct Circle {\n    Point<T> o;\n    T r;\n\
    \n    Circle() = default;\n    Circle(const Point<T>& o, const T r) : o(o), r(r)\
    \ {}\n\n    friend std::istream& operator>>(std::istream& is, Circle& c) {\n \
    \       return is >> c.o >> c.r;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Circle& c) {\n        return os << c.o << \", \" << c.r;\n    }\n\
    };\n\n// \u5171\u901A\u63A5\u7DDA\u306E\u672C\u6570\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    template <class T> int tangent_number(Circle<T> c1, Circle<T> c2) {\n    if (c1.r\
    \ < c2.r) std::swap(c1, c2);\n    const T d2 = norm(c1.o - c2.o);\n    if (sign(d2\
    \ - (c1.r + c2.r) * (c1.r + c2.r)) == 1)\n        return 4;  // d > c1.r + c2.r\
    \ and c1.r + c2.r >= 0 <=> d ^ 2 > (c1.r +\n                   // c2.r) ^ 2\n\
    \    if (sign(d2 - (c1.r + c2.r) * (c1.r + c2.r)) == 0)\n        return 3;  //\
    \ d = c1.r + c2.r and c1.r + c2.r >= 0 <=> d ^ 2 = (c1.r +\n                 \
    \  // c2.r) ^ 2\n    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 1)\n    \
    \    return 2;  // d > c1.r - c2.r and c1.r - c2.r >= 0 <=> d ^ 2 > (c1.r -\n\
    \                   // c2.r) ^ 2\n    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r))\
    \ == 0)\n        return 1;  // d = c1.r - c2.r and c1.r - c2.r >= 0 <=> d ^ 2\
    \ = (c1.r -\n                   // c2.r) ^ 2\n    return 0;\n}\n#line 6 \"geometry/is_intersect.hpp\"\
    \n\n// \u4EA4\u5DEE\u5224\u5B9A (\u76F4\u7DDA, \u7DDA\u5206, \u5186, \u70B9)\n\
    // \u76F4\u7DDA l1, l2 \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate <class T> bool\
    \ is_intersect(const Line<T>& l1, const Line<T>& l2) {\n    Point<T> base = l1.b\
    \ - l1.a;\n    T d12 = cross(base, l2.b - l2.a);\n    T d1 = cross(base, l1.b\
    \ - l2.a);\n    // sign(d12) != 0 -> \u5E73\u884C\u3067\u306A\u3044\u306E\u3067\
    \u4EA4\u5DEE\u3059\u308B\n    // sign(d12) == 0 and sign(d1) == 0 -> \u4E00\u81F4\
    \u3059\u308B\u306E\u3067\u4EA4\u5DEE\u3059\u308B\n    return sign(d12) != 0 or\
    \ sign(d1) == 0;\n}\n// \u76F4\u7DDA l, \u70B9 p \u306E\u4EA4\u5DEE\u5224\u5B9A\
    \ntemplate <class T>\ninline bool is_intersect(const Line<T>& l, const Point<T>&\
    \ p) {\n    auto res = ccw(l.a, l.b, p);\n    return res == Ccw::ONLINE_BACK or\
    \ res == Ccw::ONLINE_FRONT or\n           res == Ccw::ON_SEGMENT;\n}\ntemplate\
    \ <class T> bool is_intersect(const Point<T>& p, const Line<T>& l) {\n    return\
    \ is_intersect(l, p);\n}\n\n// \u7DDA\u5206 s, \u70B9 p \u306E\u4EA4\u5DEE\u5224\
    \u5B9A\ntemplate <class T>\ninline bool is_intersect(const Segment<T>& s, const\
    \ Point<T>& p) {\n    return ccw(s.a, s.b, p) == Ccw::ON_SEGMENT;\n}\ntemplate\
    \ <class T>\ninline bool is_intersect(const Point<T>& p, const Segment<T>& s)\
    \ {\n    return ccw(s.a, s.b, p) == Ccw::ON_SEGMENT;\n}\n\n// \u76F4\u7DDA l,\
    \ \u7DDA\u5206 s \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate <class T> bool is_intersect(const\
    \ Line<T>& l, const Segment<T>& s) {\n    // s.a \u3068 s.b \u304C\u76F4\u7DDA\
    \ l \u306B\u95A2\u3057\u3066\u540C\u3058\u5074 (\u76F4\u7DDA\u4E0A\u3092\u9664\
    \u304D)\n    // \u306B\u3042\u308B\u5834\u5408\u306B\u9650\u308A\u4EA4\u5DEE\u3057\
    \u306A\u3044\n    auto c1 = ccw(l.a, l.b, s.a);\n    auto c2 = ccw(l.a, l.b, s.b);\n\
    \    return !((c1 == c2) and\n             (c1 == Ccw::CLOCKWISE or c1 == Ccw::COUNTER_CLOCKWISE));\n\
    }\ntemplate <class T> bool is_intersect(const Segment<T>& s, const Line<T>& l)\
    \ {\n    return is_intersect(l, s);\n}\n\n// \u7DDA\u5206 s1, s2 \u306E\u4EA4\u5DEE\
    \u5224\u5B9A\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\n\
    template <class T>\ninline bool is_intersect(const Segment<T>& s1, const Segment<T>&\
    \ s2) {\n    auto c1 = ccw(s1.a, s1.b, s2.a);\n    auto c2 = ccw(s1.a, s1.b, s2.b);\n\
    \    auto c3 = ccw(s2.a, s2.b, s1.a);\n    auto c4 = ccw(s2.a, s2.b, s1.b);\n\
    \    // \u5E73\u884C\u306A\u5834\u5408: \u91CD\u306A\u308B\u306A\u3089 1\n   \
    \ // \u6B21\u5143\u3067\u8003\u3048\u308B\u3068\u5FC5\u305A\u7AEF\u70B9\u306E\u3069\
    \u308C\u304B\u304C\u3082\u3046\u4E00\u65B9\u306E\u7DDA\u5206\u4E0A\u306B\u3042\
    \u308B\n    if (c1 == Ccw::ON_SEGMENT or c2 == Ccw::ON_SEGMENT or\n        c3\
    \ == Ccw::ON_SEGMENT or c4 == Ccw::ON_SEGMENT)\n        return true;\n    // \u5E73\
    \u884C\u3067\u306A\u3044\u5834\u5408: \u4E00\u65B9\u306E\u7DDA\u5206\u306E\u4E21\
    \u5074\u306B\u3082\u3046\u4E00\u65B9\u306E\u7DDA\u5206\u306E\u7AEF\u70B9\u304C\
    \u3042\u308B,\n    // \u3092\u7DDA\u5206\u3092\u5165\u308C\u66FF\u3048\u3066\u3082\
    \u6210\u7ACB \u5E73\u884C\u3060\u304C\u91CD\u306A\u3089\u306A\u3044\u5834\u5408\
    \u306F\u4EE5\u4E0B\u306E\u6761\u4EF6\u306F\u6210\u7ACB\u3057\u306A\u3044\n   \
    \ bool ok1 = ((c1 == Ccw::CLOCKWISE and c2 == Ccw::COUNTER_CLOCKWISE) or\n   \
    \             (c1 == Ccw::COUNTER_CLOCKWISE and c2 == Ccw::CLOCKWISE));\n    bool\
    \ ok2 = ((c3 == Ccw::CLOCKWISE and c4 == Ccw::COUNTER_CLOCKWISE) or\n        \
    \        (c3 == Ccw::COUNTER_CLOCKWISE and c4 == Ccw::CLOCKWISE));\n    return\
    \ ok1 and ok2;\n}\n\n// \u70B9 p1, p2 \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate\
    \ <class T>\ninline bool is_intersect(const Point<T>& p1, const Point<T>& p2)\
    \ {\n    return equal(p1, p2);\n}\n\n// \u5186 c1, c2 \u306E\u4EA4\u5DEE\u5224\
    \u5B9A\ntemplate <class T>\ninline bool is_intersect(const Circle<T>& c1, const\
    \ Circle<T>& c2) {\n    const int num = tangent_number(c1, c2);\n    return 1\
    \ <= num and num <= 3;\n}\n\n// \u5186 c, \u70B9 p \u306E\u4EA4\u5DEE\u5224\u5B9A\
    \ntemplate <class T>\ninline bool is_intersect(const Circle<T>& c, const Point<T>&\
    \ p) {\n    return equal(norm(p - c.o), c.r * c.r);\n}\ntemplate <class T>\ninline\
    \ bool is_intersect(const Point<T>& p, const Circle<T>& c) {\n    return equal(norm(p\
    \ - c.o), c.r * c.r);\n}\n\n// \u5186 c, \u76F4\u7DDA l \u306E\u4EA4\u5DEE\u5224\
    \u5B9A\ntemplate <class T>\ninline bool is_intersect(const Circle<T>& c, const\
    \ Line<T>& l) {\n    static_assert(is_geometry_floating_point<T>::value == true);\n\
    \    // norm(c.o - projection(l, c.o)) \u304C\u76F4\u7DDA l \u3068 \u5186 c \u306E\
    \u4E2D\u5FC3 c.o \u306E\u8DDD\u96E2\u306E 2 \u4E57\n    return sign(c.r * c.r\
    \ - norm(c.o - projection(l, c.o))) >= 0;\n}\ntemplate <class T>\ninline bool\
    \ is_intersect(const Line<T>& l, const Circle<T>& c) {\n    return is_intersect(c,\
    \ l);\n}\n\n// \u5186 c, \u7DDA\u5206 s \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate\
    \ <class T>\ninline bool is_intersect(const Circle<T>& c, const Segment<T>& s)\
    \ {\n    static_assert(is_geometry_floating_point<T>::value == true);\n    if\
    \ (!is_intersect(c, Line(s.a, s.b)))\n        return false;  // \u76F4\u7DDA\u3068\
    \u3057\u3066\u3082\u4EA4\u5DEE\u3057\u306A\u3044\n    T d1 = abs(c.o - s.a), d2\
    \ = abs(c.o - s.b);\n    if (sign(d1 - c.r) == -1 and sign(d2 - c.r) == -1)\n\
    \        return false;  // \u7AEF\u70B9\u304C\u3069\u3061\u3089\u3082\u5186\u306E\
    \u5185\u5074\n    if (sign(d1 - c.r) * sign(d2 - c.r) <= 0)\n        return true;\
    \  // \u5186\u5468\u3092\u307E\u305F\u3044\u3067\u3044\u308B\n    const Point<T>\
    \ h = projection(s, c.o);\n    return ccw(s.a, s.b, h) ==\n           Ccw::ON_SEGMENT;\
    \  // s.a -> h -> s.b \u306E\u9806\u3067\u4E26\u3093\u3067\u3044\u308B\n}\ntemplate\
    \ <class T>\ninline bool is_intersect(const Segment<T>& s, const Circle<T>& c)\
    \ {\n    return is_intersect(c, s);\n}\n#line 6 \"geometry/contain.hpp\"\n\nenum\
    \ class Contain { IN, ON, OUT };\n\n// \u5186 c \u3068\u70B9 p \u306E\u4F4D\u7F6E\
    \u95A2\u4FC2\ntemplate <class T> Contain contain(const Circle<T>& c, const Point<T>&\
    \ p) {\n    int sgn = sign(norm(p - c.o) - c.r * c.r);\n    return sgn == 1 ?\
    \ Contain::OUT : (sgn == 0 ? Contain::ON : Contain::IN);\n}\n\n// \u591A\u89D2\
    \u5F62 (\u51F8\u3068\u306F\u9650\u3089\u306A\u3044) q \u3068\u70B9 p \u306E\u4F4D\
    \u7F6E\u95A2\u4FC2\n// \u9802\u70B9\u306F\u53CD\u6642\u8A08\u56DE\u308A\u306B\u4E26\
    \u3093\u3067\u3044\u308B\n// O(n)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C\n\
    template <class T> Contain contain(const Polygon<T>& q, const Point<T>& p) {\n\
    \    const int n = (int)(q.size());\n    assert(n >= 3);\n    bool x = false;\n\
    \    for (int i = 0; i < n; i++) {\n        if (is_intersect(Segment(q[i], q[(i\
    \ + 1) % n]), p)) return Contain::ON;\n        Point a = q[i] - p, b = q[(i +\
    \ 1) % n] - p;\n        if (a.y > b.y) std::swap(a, b);\n        // a.y < b.y\n\
    \        // check each point's y is 0 at most 1 times\n        if (sign(a.y) <=\
    \ 0 and sign(b.y) > 0 and sign(cross(a, b)) > 0) x = !x;\n    }\n    return (x\
    \ ? Contain::IN : Contain::OUT);\n}\n\n// \u51F8\u591A\u89D2\u5F62 (\u3059\u3079\
    \u3066\u306E\u5185\u89D2\u304C 180\xB0 \u672A\u6E80) q \u3068\u70B9 p \u306E\u4F4D\
    \u7F6E\u95A2\u4FC2\n// \u9802\u70B9\u306F\u53CD\u6642\u8A08\u56DE\u308A\u306B\u4E26\
    \u3093\u3067\u3044\u308B\n// O(log n)\n// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412\n\
    // https://atcoder.jp/contests/abc296/tasks/abc296_g\ntemplate <class T> Contain\
    \ convex_contain(const Polygon<T>& q, const Point<T>& p) {\n    const int n =\
    \ (int)(q.size());\n    assert(n >= 3);\n    auto c1 = ccw(q[0], q[1], p);\n \
    \   auto c2 = ccw(q[0], q[n - 1], p);\n    if (c1 == Ccw::CLOCKWISE or c2 == Ccw::COUNTER_CLOCKWISE)\
    \ return Contain::OUT;\n    if (c1 == Ccw::ON_SEGMENT or c2 == Ccw::ON_SEGMENT)\
    \ return Contain::ON;\n    if (c1 == Ccw::ONLINE_FRONT or c2 == Ccw::ONLINE_FRONT)\
    \ return Contain::OUT;\n    // \u4E8C\u5206\u63A2\u7D22 (q[0] -> q[i] -> p \u304C\
    \u53CD\u6642\u8A08\u56DE\u308A\u306B\u306A\u308B\u3088\u3046\u306A\u6700\u5927\
    \u306E i)\n    int ok = 1, ng = n - 1;\n    while (ng - ok > 1) {\n        int\
    \ md = (ok + ng) / 2;\n        if (ccw(q[0], q[md], p) == Ccw::COUNTER_CLOCKWISE)\
    \ {\n            ok = md;\n        } else {\n            ng = md;\n        }\n\
    \    }\n    // \u76F4\u7DDA q[ok] -> q[ok + 1] \u3092\u57FA\u6E96\u306B\u8003\u3048\
    \u308B\n    auto c3 = ccw(q[ok], q[ok + 1], p);\n    assert(c3 != Ccw::ONLINE_FRONT);\n\
    \    assert(c3 != Ccw::ONLINE_BACK);\n    return c3 == Ccw::ON_SEGMENT ? Contain::ON\
    \ : (c3 == Ccw::COUNTER_CLOCKWISE ? Contain::IN : Contain::OUT);\n}\n#line 6 \"\
    verify/geometry/contain.test.cpp\"\n\nint main() {\n    int N;\n    std::cin >>\
    \ N;\n    Polygon<long long> P(N);\n    std::cin >> P;\n    int Q;\n    std::cin\
    \ >> Q;\n    while (Q--) {\n        Point<long long> p;\n        std::cin >> p;\n\
    \        auto ans = contain(P, p);\n        if (ans == Contain::IN) {\n      \
    \      std::cout << \"2\\n\";\n        } else if (ans == Contain::ON) {\n    \
    \        std::cout << \"1\\n\";\n        } else {\n            std::cout << \"\
    0\\n\";\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C\"\
    \n\n#include <iostream>\n\n#include \"geometry/contain.hpp\"\n\nint main() {\n\
    \    int N;\n    std::cin >> N;\n    Polygon<long long> P(N);\n    std::cin >>\
    \ P;\n    int Q;\n    std::cin >> Q;\n    while (Q--) {\n        Point<long long>\
    \ p;\n        std::cin >> p;\n        auto ans = contain(P, p);\n        if (ans\
    \ == Contain::IN) {\n            std::cout << \"2\\n\";\n        } else if (ans\
    \ == Contain::ON) {\n            std::cout << \"1\\n\";\n        } else {\n  \
    \          std::cout << \"0\\n\";\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - geometry/contain.hpp
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/line.hpp
  - geometry/is_intersect.hpp
  - geometry/circle.hpp
  isVerificationFile: true
  path: verify/geometry/contain.test.cpp
  requiredBy: []
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/contain.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/contain.test.cpp
- /verify/verify/geometry/contain.test.cpp.html
title: verify/geometry/contain.test.cpp
---
