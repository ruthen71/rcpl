---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: "Point (\u70B9)"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circumscribed_circle.hpp
    title: "Circumscribed Circle (\u5916\u63A5\u5186)"
  - icon: ':heavy_check_mark:'
    path: geometry/common_area.hpp
    title: "Common Area (\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D)"
  - icon: ':heavy_check_mark:'
    path: geometry/contain.hpp
    title: "Contain (\u591A\u89D2\u5F62\u3084\u5186\u3068\u70B9\u306E\u4F4D\u7F6E\u95A2\
      \u4FC2)"
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_cut.hpp
    title: "Convex Polygon Cut (\u51F8\u591A\u89D2\u5F62\u306E\u76F4\u7DDA\u3067\u306E\
      \u5207\u65AD)"
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point.hpp
    title: "Cross Point (\u4EA4\u70B9)"
  - icon: ':heavy_check_mark:'
    path: geometry/distance.hpp
    title: "Distance (\u8DDD\u96E2)"
  - icon: ':heavy_check_mark:'
    path: geometry/incircle.hpp
    title: "Incircle (\u5185\u63A5\u5186)"
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect.hpp
    title: "Intersection (\u4EA4\u5DEE\u5224\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: "Tangent (\u63A5\u7DDA)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circumscribed_circle.test.cpp
    title: verify/geometry/circumscribed_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/common_area_cc.test.cpp
    title: verify/geometry/common_area_cc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/common_area_cp.test.cpp
    title: verify/geometry/common_area_cp.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/contain.test.cpp
    title: verify/geometry/contain.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/convex_contain.test.cpp
    title: verify/geometry/convex_contain.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/convex_polygon_cut.test.cpp
    title: verify/geometry/convex_polygon_cut.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/cross_point_cc.test.cpp
    title: verify/geometry/cross_point_cc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/cross_point_cl.test.cpp
    title: verify/geometry/cross_point_cl.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/cross_point_ss.test.cpp
    title: verify/geometry/cross_point_ss.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/distance_ss.test.cpp
    title: verify/geometry/distance_ss.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/incircle.test.cpp
    title: verify/geometry/incircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/is_intersect_ss.test.cpp
    title: verify/geometry/is_intersect_ss.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/is_orthogonal_is_parallel.test.cpp
    title: verify/geometry/is_orthogonal_is_parallel.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/projection.test.cpp
    title: verify/geometry/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/reflection.test.cpp
    title: verify/geometry/reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/tangent_cc.test.cpp
    title: verify/geometry/tangent_cc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/tangent_cp.test.cpp
    title: verify/geometry/tangent_cp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
  bundledCode: "#line 2 \"geometry/line.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n\
    #include <cassert>\n#include <cmath>\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n#include <type_traits>\n\n// Constants (EPS, PI)\n// EPS \u306E\u5909\u66F4\
    \u306F Constants<T>::set_eps(new_eps) \u3067\ntemplate <class T> struct Constants\
    \ {\n    static T EPS;\n    static void set_eps(const T e) { EPS = e; }\n    static\
    \ constexpr T PI = 3.14159'26535'89793L;\n};\n\ntemplate <> double Constants<double>::EPS\
    \ = 1e-9;\ntemplate <> long double Constants<long double>::EPS = 1e-12;\ntemplate\
    \ <> long long Constants<long long>::EPS = 0;\n\n// \u6C4E\u7528\u95A2\u6570\n\
    template <class T> inline int sign(const T x) { return x < -Constants<T>::EPS\
    \ ? -1 : (x > Constants<T>::EPS ? 1 : 0); }\ntemplate <class T> inline bool equal(const\
    \ T a, const T b) { return sign(a - b) == 0; }\ntemplate <class T> inline T radian_to_degree(const\
    \ T r) { return r * 180.0 / Constants<T>::PI; }\ntemplate <class T> inline T degree_to_radian(const\
    \ T d) { return d * Constants<T>::PI / 180.0; }\n\n// type traits\ntemplate <class\
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
    #line 4 \"geometry/line.hpp\"\n\n// \u76F4\u7DDA\ntemplate <class T> struct Line\
    \ {\n    Point<T> a, b;\n\n    Line() = default;\n    Line(const Point<T>& a,\
    \ const Point<T>& b) : a(a), b(b) {}\n\n    // Ax + By = C\n    Line(const T A,\
    \ const T B, const T C) {\n        static_assert(is_geometry_floating_point<T>::value\
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
    \ l2) {\n    return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0;\n}\n"
  code: "#pragma once\n\n#include \"../geometry/point.hpp\"\n\n// \u76F4\u7DDA\ntemplate\
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
    \ l2) {\n    return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0;\n}\n"
  dependsOn:
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: false
  path: geometry/line.hpp
  requiredBy:
  - geometry/contain.hpp
  - geometry/common_area.hpp
  - geometry/is_intersect.hpp
  - geometry/distance.hpp
  - geometry/circumscribed_circle.hpp
  - geometry/incircle.hpp
  - geometry/tangent.hpp
  - geometry/convex_polygon_cut.hpp
  - geometry/all.hpp
  - geometry/cross_point.hpp
  timestamp: '2026-01-20 04:06:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/geometry/convex_contain.test.cpp
  - verify/geometry/common_area_cc.test.cpp
  - verify/geometry/is_intersect_ss.test.cpp
  - verify/geometry/common_area_cp.test.cpp
  - verify/geometry/incircle.test.cpp
  - verify/geometry/circumscribed_circle.test.cpp
  - verify/geometry/cross_point_cl.test.cpp
  - verify/geometry/tangent_cc.test.cpp
  - verify/geometry/contain.test.cpp
  - verify/geometry/tangent_cp.test.cpp
  - verify/geometry/cross_point_cc.test.cpp
  - verify/geometry/reflection.test.cpp
  - verify/geometry/cross_point_ss.test.cpp
  - verify/geometry/projection.test.cpp
  - verify/geometry/is_orthogonal_is_parallel.test.cpp
  - verify/geometry/convex_polygon_cut.test.cpp
  - verify/geometry/distance_ss.test.cpp
documentation_of: geometry/line.hpp
layout: document
title: "Line / Segment (\u76F4\u7DDA\u30FB\u7DDA\u5206)"
---

## 使い方

```cpp
using Ln = Line<T>;
using Sg = Segment<T>;
```

## 参考文献
