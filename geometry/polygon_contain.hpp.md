---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: "Circle (\u5186)"
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/geometry/polygon_contain.test.cpp
    title: verify/geometry/polygon_contain.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
  bundledCode: "#line 2 \"geometry/polygon_contain.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
    \n\n#include <type_traits>\n\n// Constants (EPS, PI)\n// EPS \u306E\u5909\u66F4\
    \u306F Constants<T>::set_eps(new_eps) \u3067\ntemplate <class T> struct Constants\
    \ {\n    static T EPS;\n    static void set_eps(const T e) { EPS = e; }\n    static\
    \ constexpr T PI = 3.14159'26535'89793L;\n};\n\ntemplate <> double Constants<double>::EPS\
    \ = 1e-9;\ntemplate <> long double Constants<long double>::EPS = 1e-12;\ntemplate\
    \ <> long long Constants<long long>::EPS = 0;\n\n// base functions\ntemplate <class\
    \ T> inline int sign(const T x) { return x < -Constants<T>::EPS ? -1 : (x > Constants<T>::EPS\
    \ ? 1 : 0); }\ntemplate <class T> inline bool equal(const T a, const T b) { return\
    \ sign(a - b) == 0; }\ntemplate <class T> inline T radian_to_degree(const T r)\
    \ { return r * 180.0 / Constants<T>::PI; }\ntemplate <class T> inline T degree_to_radian(const\
    \ T d) { return d * Constants<T>::PI / 180.0; }\n\n// type traits\ntemplate <class\
    \ T> using is_geometry_floating_point = typename std::conditional<std::is_same<T,\
    \ double>::value || std::is_same<T, long double>::value, std::true_type, std::false_type>::type;\n\
    template <class T> using is_geometry_integer = typename std::conditional<std::is_same<T,\
    \ long long>::value, std::true_type, std::false_type>::type;\ntemplate <class\
    \ T> using is_geometry = typename std::conditional<is_geometry_floating_point<T>::value\
    \ || is_geometry_integer<T>::value, std::true_type, std::false_type>::type;\n\
    #line 4 \"geometry/point.hpp\"\n\n#include <cmath>\n#include <cassert>\n\n// \u70B9\
    \ntemplate <class T> struct Point {\n    T x, y;\n\n    Point() = default;\n \
    \   Point(const T x, const T y) : x(x), y(y) {}\n\n    Point& operator+=(const\
    \ Point& p) {\n        x += p.x, y += p.y;\n        return *this;\n    }\n   \
    \ Point& operator-=(const Point& p) {\n        x -= p.x, y -= p.y;\n        return\
    \ *this;\n    }\n    Point& operator*=(const Point& p) {\n        static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n        return *this = Point(x * p.x - y * p.y, x * p.y + y * p.x);\n\
    \    }\n    Point& operator/=(const Point& p) {\n        static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n        return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x)\
    \ / (p.x * p.x + p.y * p.y);\n    }\n    Point& operator*=(const T k) {\n    \
    \    x *= k, y *= k;\n        return *this;\n    }\n    Point& operator/=(const\
    \ T k) {\n        static_assert(is_geometry_floating_point<T>::value == true);\n\
    \        x /= k, y /= k;\n        return *this;\n    }\n\n    Point operator+()\
    \ const { return *this; }\n    Point operator-() const { return Point(-x, -y);\
    \ }\n\n    friend Point operator+(const Point& a, const Point& b) { return Point(a)\
    \ += b; }\n    friend Point operator-(const Point& a, const Point& b) { return\
    \ Point(a) -= b; }\n    friend Point operator*(const Point& a, const Point& b)\
    \ { return Point(a) *= b; }\n    friend Point operator/(const Point& a, const\
    \ Point& b) { return Point(a) /= b; }\n    friend Point operator*(const Point&\
    \ p, const T k) { return Point(p) *= k; }\n    friend Point operator/(const Point&\
    \ p, const T k) { return Point(p) /= k; }\n\n    // \u8F9E\u66F8\u5F0F\u9806\u5E8F\
    \n    friend bool operator<(const Point& a, const Point& b) { return a.x == b.x\
    \ ? a.y < b.y : a.x < b.x; }\n    friend bool operator>(const Point& a, const\
    \ Point& b) { return a.x == b.x ? a.y > b.y : a.x > b.x; }\n    friend bool operator==(const\
    \ Point& a, const Point& b) { return a.x == b.x and a.y == b.y; }\n\n    // I/O\n\
    \    friend std::istream& operator>>(std::istream& is, Point& p) { return is >>\
    \ p.x >> p.y; }\n    friend std::ostream& operator<<(std::ostream& os, const Point&\
    \ p) { return os << '(' << p.x << ' ' << p.y << ')'; }\n};\n\n// point base functions\n\
    // \u70B9\u306E\u4E00\u81F4\u5224\u5B9A\ntemplate <class T> inline bool equal(const\
    \ Point<T>& a, const Point<T>& b) { return equal(a.x, b.x) and equal(a.y, b.y);\
    \ }\n// \u5185\u7A4D\ntemplate <class T> inline T dot(const Point<T>& a, const\
    \ Point<T>& b) { return a.x * b.x + a.y * b.y; }\n// \u5916\u7A4D\ntemplate <class\
    \ T> inline T cross(const Point<T>& a, const Point<T>& b) { return a.x * b.y -\
    \ a.y * b.x; }\n// rad \u30E9\u30B8\u30A2\u30F3\u3060\u3051\u53CD\u6642\u8A08\u56DE\
    \u308A\u306B\u56DE\u8EE2\ntemplate <class T> inline Point<T> rotate(const Point<T>&\
    \ p, const T theta) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    return p * Point<T>(std::cos(theta), std::sin(theta));\n}\n//\
    \ (x, y) \u306E\u8F9E\u66F8\u5F0F\u9806\u5E8F (\u8AA4\u5DEE\u8A31\u5BB9)\ntemplate\
    \ <class T> inline bool compare_x(const Point<T>& a, const Point<T>& b) { return\
    \ equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }\n// (y, x) \u306E\
    \u8F9E\u66F8\u5F0F\u9806\u5E8F (\u8AA4\u5DEE\u8A31\u5BB9)\ntemplate <class T>\
    \ inline bool compare_y(const Point<T>& a, const Point<T>& b) { return equal(a.y,\
    \ b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }\n// \u6574\u6570\u306E\u307E\
    \u307E\u884C\u3046\u504F\u89D2\u30BD\u30FC\u30C8\n// \u7121\u9650\u306E\u7CBE\u5EA6\
    \u3092\u3082\u3064 arg(p) = atan2(y, x) \u3067\u6BD4\u8F03\u3057, \u540C\u3058\
    \u5834\u5408\u306F norm(p) \u3067\u6BD4\u8F03 (atan2(0, 0) = 0 \u3068\u3059\u308B\
    )\n// \u57FA\u672C\u7684\u306B (-PI, PI] \u3067\u30BD\u30FC\u30C8\u3055\u308C\
    , \u70B9 (0, 0) \u306F (-PI, 0) \u3068 [0, PI] \u306E\u9593\u306B\u5165\u308B\n\
    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n// https://judge.yosupo.jp/problem/sort_points_by_argument\n\
    template <class T> inline bool compare_atan2(const Point<T>& a, const Point<T>&\
    \ b) {\n    static_assert(is_geometry_integer<T>::value == true);\n    if ((Point<T>(a.y,\
    \ -a.x) > Point<T>(0, 0)) == (Point<T>(b.y, -b.x) > Point<T>(0, 0))) {  // a,\
    \ b in (-PI, 0] or a, b in (0, PI]\n        if (a.x * b.y != a.y * b.x) return\
    \ a.x * b.y > a.y * b.x;                            // cross(a, b) != 0\n    \
    \    return a == Point<T>(0, 0) ? b.x > 0 and b.y == 0 : (b == Point<T>(0, 0)\
    \ ? a.y < 0 : norm(a) < norm(b));\n    }\n    return Point<T>(a.y, -a.x) < Point<T>(b.y,\
    \ -b.x);\n}\n// \u7D76\u5BFE\u5024\u306E 2 \u4E57\ntemplate <class T> inline T\
    \ norm(const Point<T>& p) { return p.x * p.x + p.y * p.y; }\n// \u7D76\u5BFE\u5024\
    \ntemplate <class T> inline T abs(const Point<T>& p) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    return std::sqrt(norm(p));\n}\n// \u504F\u89D2\ntemplate <class\
    \ T> inline T arg(const Point<T>& p) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    return std::atan2(p.y, p.x);\n}\n// \u5171\u5F79\u8907\u7D20\u6570\
    \ (x \u8EF8\u306B\u3064\u3044\u3066\u5BFE\u8C61\u306A\u70B9)\ntemplate <class\
    \ T> inline Point<T> conj(const Point<T>& p) { return Point(p.x, -p.y); }\n//\
    \ \u6975\u5EA7\u6A19\u7CFB -> \u76F4\u4EA4\u5EA7\u6A19\u7CFB (\u7D76\u5BFE\u5024\
    \u304C rho \u3067\u504F\u89D2\u304C theta \u30E9\u30B8\u30A2\u30F3)\ntemplate\
    \ <class T> inline Point<T> polar(const T rho, const T theta = T(0)) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    assert(sign(rho) >= 0);\n    return Point<T>(std::cos(theta),\
    \ std::sin(theta)) * rho;\n}\n\n// ccw \u306E\u623B\u308A\u5024\nenum class Ccw\
    \ {\n    COUNTER_CLOCKWISE = 1,  // a->b->c \u53CD\u6642\u8A08\u56DE\u308A\n \
    \   CLOCKWISE = -1,         // a->b->c \u6642\u8A08\u56DE\u308A\n    ONLINE_BACK\
    \ = 2,        // c->a->b \u76F4\u7DDA\n    ONLINE_FRONT = -2,      // a->b->c\
    \ \u76F4\u7DDA\n    ON_SEGMENT = 0          // a->c->b \u76F4\u7DDA\n};\n// \u70B9\
    \ a, b, c \u306E\u4F4D\u7F6E\u95A2\u4FC2\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    template <class T> Ccw ccw(const Point<T>& a, const Point<T>& b, const Point<T>&\
    \ c) {\n    Point<T> ab = b - a;\n    Point<T> ac = c - a;\n    if (sign(cross(ab,\
    \ ac)) == 1) return Ccw::COUNTER_CLOCKWISE;\n    if (sign(cross(ab, ac)) == -1)\
    \ return Ccw::CLOCKWISE;\n    if (sign(dot(ab, ac)) == -1) return Ccw::ONLINE_BACK;\n\
    \    if (sign(norm(ab) - norm(ac)) == -1) return Ccw::ONLINE_FRONT;\n    return\
    \ Ccw::ON_SEGMENT;\n}\n#line 4 \"geometry/polygon.hpp\"\n\n#include <vector>\n\
    #line 7 \"geometry/polygon.hpp\"\n\n// polygon\ntemplate <class T> using Polygon\
    \ = std::vector<Point<T>>;\ntemplate <class T> std::istream& operator>>(std::istream&\
    \ is, Polygon<T>& p) {\n    for (auto&& pi : p) is >> pi;\n    return is;\n}\n\
    template <class T> std::ostream& operator<<(std::ostream& os, const Polygon<T>&\
    \ p) {\n    for (auto&& pi : p) os << pi << \" -> \";\n    return os;\n}\n\n//\
    \ \u591A\u89D2\u5F62\u306E\u9762\u7A4D (\u7B26\u53F7\u4ED8\u304D)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    // return area * 2\ntemplate <class T> T polygon_area2(const Polygon<T>& p) {\n\
    \    const int n = (int)(p.size());\n    assert(n >= 2);\n    T ret = T(0);\n\
    \    for (int i = 0; i < n; i++) ret += cross(p[i], p[i + 1 == n ? 0 : i + 1]);\n\
    \    // counter clockwise: ret > 0\n    // clockwise: ret < 0\n    return ret;\n\
    }\ntemplate <class T> T polygon_area(const Polygon<T>& p) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    return polygon_area2(p) / T(2);\n}\n\n// \u591A\u89D2\u5F62\u306E\
    \u51F8\u5224\u5B9A (\u89D2\u5EA6\u304C 0 \u3067\u3082 PI \u3067\u3082\u8A31\u5BB9\
    )\n// \u8A31\u5BB9\u3057\u305F\u304F\u306A\u3044\u3068\u304D\u306B\u306F ON_SEGMENT,\
    \ ONLINE_FRONT, ONLINE_BACK \u304C\u51FA\u3066\u304D\u305F\u3089 false \u3092\u8FD4\
    \u305B\u3070 OK\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\n\
    template <class T> bool polygon_is_convex(const Polygon<T>& p) {\n    const int\
    \ n = (int)(p.size());\n    assert(n >= 3);\n    bool okccw = true, okcw = true;\n\
    \    for (int i = 0; i < n; i++) {\n        auto res = ccw(p[i], p[i + 1 >= n\
    \ ? i + 1 - n : i + 1], p[i + 2 >= n ? i + 2 - n : i + 2]);\n        if (res ==\
    \ Ccw::CLOCKWISE) okccw = false;\n        if (res == Ccw::COUNTER_CLOCKWISE) okcw\
    \ = false;\n        if (!okccw and !okcw) return false;\n    }\n    return true;\n\
    }\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\n// line\n\
    template <class T> struct Line {\n    Point<T> a, b;\n\n    Line() = default;\n\
    \    Line(const Point<T>& a, const Point<T>& b) : a(a), b(b) {}\n\n    // Ax +\
    \ By = C\n    Line(const T A, const T B, const T C) {\n        static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n        assert(!(equal(A, T(0)) and equal(B, T(0))));\n        if\
    \ (equal(A, T(0))) {\n            a = Point<T>(T(0), C / B), b = Point<T>(T(1),\
    \ C / B);\n        } else if (equal(B, T(0))) {\n            a = Point<T>(C /\
    \ A, T(0)), b = Point<T>(C / A, T(1));\n        } else if (equal(C, T(0))) {\n\
    \            a = Point<T>(T(0), T(0)), b = Point<T>(T(1), -A / B);\n        }\
    \ else {\n            a = Point<T>(T(0), C / B), b = Point<T>(C / A, T(0));\n\
    \        }\n    }\n\n    friend std::istream& operator>>(std::istream& is, Line&\
    \ p) { return is >> p.a >> p.b; }\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Line& p) { return os << p.a << \"->\" << p.b; }\n};\n\n// segment\n\
    template <class T> struct Segment : Line<T> {\n    Segment() = default;\n\n  \
    \  Segment(const Point<T>& a, const Point<T>& b) : Line<T>(a, b) {}\n};\n\n//\
    \ \u70B9 p \u304B\u3089\u76F4\u7DDA l \u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\
    \u3068\u76F4\u7DDA l \u306E\u4EA4\u70B9\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    template <class T> Point<T> projection(const Line<T>& l, const Point<T>& p) {\n\
    \    static_assert(is_geometry_floating_point<T>::value == true);\n    T t = dot(p\
    \ - l.a, l.b - l.a) / norm(l.b - l.a);\n    return l.a + (l.b - l.a) * t;\n}\n\
    \n// \u76F4\u7DDA l \u306B\u95A2\u3057\u3066\u70B9 p \u3068\u5BFE\u8C61\u306A\u4F4D\
    \u7F6E\u306B\u3042\u308B\u70B9\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\n\
    template <class T> Point<T> reflection(const Line<T>& l, const Point<T>& p) {\n\
    \    static_assert(is_geometry_floating_point<T>::value == true);\n    return\
    \ p + (projection(l, p) - p) * T(2);\n}\n\n// \u76F4\u7DDA l1, l2 \u306E\u5782\
    \u76F4\u5224\u5B9A\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    template <class T> inline bool is_orthogonal(const Line<T>& l1, const Line<T>&\
    \ l2) { return sign(dot(l1.b - l1.a, l2.b - l2.a)) == 0; }\n\n// \u76F4\u7DDA\
    \ l1, l2 \u306E\u5E73\u884C\u5224\u5B9A\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    template <class T> inline bool is_parallel(const Line<T>& l1, const Line<T>& l2)\
    \ { return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0; }\n#line 2 \"geometry/is_intersect.hpp\"\
    \n\n#line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\n\n// circle\n\
    template <class T> struct Circle {\n    Point<T> o;\n    T r;\n\n    Circle()\
    \ = default;\n    Circle(const Point<T>& o, const T r) : o(o), r(r) {}\n\n   \
    \ friend std::istream& operator>>(std::istream& is, Circle& c) { return is >>\
    \ c.o >> c.r; }\n    friend std::ostream& operator<<(std::ostream& os, const Circle&\
    \ c) { return os << c.o << \", \" << c.r; }\n};\n\n// \u5171\u901A\u63A5\u7DDA\
    \u306E\u672C\u6570\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    template <class T> int tangent_number(Circle<T> c1, Circle<T> c2) {\n    if (c1.r\
    \ < c2.r) std::swap(c1, c2);\n    const T d2 = norm(c1.o - c2.o);\n    if (sign(d2\
    \ - (c1.r + c2.r) * (c1.r + c2.r)) == 1) return 4;  // d > c1.r + c2.r and c1.r\
    \ + c2.r >= 0 <=> d ^ 2 > (c1.r + c2.r) ^ 2\n    if (sign(d2 - (c1.r + c2.r) *\
    \ (c1.r + c2.r)) == 0) return 3;  // d = c1.r + c2.r and c1.r + c2.r >= 0 <=>\
    \ d ^ 2 = (c1.r + c2.r) ^ 2\n    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r))\
    \ == 1) return 2;  // d > c1.r - c2.r and c1.r - c2.r >= 0 <=> d ^ 2 > (c1.r -\
    \ c2.r) ^ 2\n    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 0) return 1;\
    \  // d = c1.r - c2.r and c1.r - c2.r >= 0 <=> d ^ 2 = (c1.r - c2.r) ^ 2\n   \
    \ return 0;\n}\n#line 6 \"geometry/is_intersect.hpp\"\n\n// \u4EA4\u5DEE\u5224\
    \u5B9A (\u76F4\u7DDA, \u7DDA\u5206, \u5186, \u70B9)\n// \u76F4\u7DDA l1, l2 \u306E\
    \u4EA4\u5DEE\u5224\u5B9A\ntemplate <class T> bool is_intersect(const Line<T>&\
    \ l1, const Line<T>& l2) {\n    Point<T> base = l1.b - l1.a;\n    T d12 = cross(base,\
    \ l2.b - l2.a);\n    T d1 = cross(base, l1.b - l2.a);\n    // sign(d12) != 0 ->\
    \ \u5E73\u884C\u3067\u306A\u3044\u306E\u3067\u4EA4\u5DEE\u3059\u308B\n    // sign(d12)\
    \ == 0 and sign(d1) == 0 -> \u4E00\u81F4\u3059\u308B\u306E\u3067\u4EA4\u5DEE\u3059\
    \u308B\n    return sign(d12) != 0 or sign(d1) == 0;\n}\n// \u76F4\u7DDA l, \u70B9\
    \ p \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate <class T> inline bool is_intersect(const\
    \ Line<T>& l, const Point<T>& p) {\n    auto res = ccw(l.a, l.b, p);\n    return\
    \ res == Ccw::ONLINE_BACK or res == Ccw::ONLINE_FRONT or res == Ccw::ON_SEGMENT;\n\
    }\ntemplate <class T> bool is_intersect(const Point<T>& p, const Line<T>& l) {\
    \ return is_intersect(l, p); }\n\n// \u7DDA\u5206 s, \u70B9 p \u306E\u4EA4\u5DEE\
    \u5224\u5B9A\ntemplate <class T> inline bool is_intersect(const Segment<T>& s,\
    \ const Point<T>& p) { return ccw(s.a, s.b, p) == Ccw::ON_SEGMENT; }\ntemplate\
    \ <class T> inline bool is_intersect(const Point<T>& p, const Segment<T>& s) {\
    \ return ccw(s.a, s.b, p) == Ccw::ON_SEGMENT; }\n\n// \u76F4\u7DDA l, \u7DDA\u5206\
    \ s \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate <class T> bool is_intersect(const\
    \ Line<T>& l, const Segment<T>& s) {\n    // s.a \u3068 s.b \u304C\u76F4\u7DDA\
    \ l \u306B\u95A2\u3057\u3066\u540C\u3058\u5074 (\u76F4\u7DDA\u4E0A\u3092\u9664\
    \u304D) \u306B\u3042\u308B\u5834\u5408\u306B\u9650\u308A\u4EA4\u5DEE\u3057\u306A\
    \u3044\n    auto c1 = ccw(l.a, l.b, s.a);\n    auto c2 = ccw(l.a, l.b, s.b);\n\
    \    return !((c1 == c2) and (c1 == Ccw::CLOCKWISE or c1 == Ccw::COUNTER_CLOCKWISE));\n\
    }\ntemplate <class T> bool is_intersect(const Segment<T>& s, const Line<T>& l)\
    \ { return is_intersect(l, s); }\n\n// \u7DDA\u5206 s1, s2 \u306E\u4EA4\u5DEE\u5224\
    \u5B9A\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\n\
    template <class T> inline bool is_intersect(const Segment<T>& s1, const Segment<T>&\
    \ s2) {\n    auto c1 = ccw(s1.a, s1.b, s2.a);\n    auto c2 = ccw(s1.a, s1.b, s2.b);\n\
    \    auto c3 = ccw(s2.a, s2.b, s1.a);\n    auto c4 = ccw(s2.a, s2.b, s1.b);\n\
    \    // \u7DDA\u5206\u304C\u5E73\u884C\u306A\u30B1\u30FC\u30B9\u306F 1 \u6B21\u5143\
    \u7684\u306B\u8003\u3048\u308B\u3068\u5FC5\u305A\u7AEF\u70B9\u306E\u3069\u308C\
    \u304B\u304C\u3082\u3046\u4E00\u65B9\u306E\u7DDA\u5206\u4E0A\u306B\u3042\u308B\
    \n    if (c1 == Ccw::ON_SEGMENT or c2 == Ccw::ON_SEGMENT or c3 == Ccw::ON_SEGMENT\
    \ or c4 == Ccw::ON_SEGMENT) {\n        return true;\n    }\n    // \u5E73\u884C\
    \u3067\u306A\u3044\u5834\u5408: \u4E00\u65B9\u306E\u7DDA\u5206\u306E\u4E21\u5074\
    \u306B\u3082\u3046\u4E00\u65B9\u306E\u7DDA\u5206\u306E\u7AEF\u70B9\u304C\u3042\
    \u308B, \u3092\u7DDA\u5206\u3092\u5165\u308C\u66FF\u3048\u3066\u3082\u6210\u7ACB\
    \n    bool ok1 = ((c1 == Ccw::CLOCKWISE and c2 == Ccw::COUNTER_CLOCKWISE) or (c1\
    \ == Ccw::COUNTER_CLOCKWISE and c2 == Ccw::CLOCKWISE));\n    bool ok2 = ((c3 ==\
    \ Ccw::CLOCKWISE and c4 == Ccw::COUNTER_CLOCKWISE) or (c3 == Ccw::COUNTER_CLOCKWISE\
    \ and c4 == Ccw::CLOCKWISE));\n    return ok1 and ok2;\n}\n\n// \u70B9 p1, p2\
    \ \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate <class T> inline bool is_intersect(const\
    \ Point<T>& p1, const Point<T>& p2) { return equal(p1, p2); }\n\n// \u5186 c1,\
    \ c2 \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate <class T> inline bool is_intersect(const\
    \ Circle<T>& c1, const Circle<T>& c2) {\n    int num = tangent_number(c1, c2);\n\
    \    return 1 <= num and num <= 3;\n}\n\n// \u5186 c, \u70B9 p \u306E\u4EA4\u5DEE\
    \u5224\u5B9A\ntemplate <class T> inline bool is_intersect(const Circle<T>& c,\
    \ const Point<T>& p) { return equal(norm(p - c.o), c.r * c.r); }\ntemplate <class\
    \ T> inline bool is_intersect(const Point<T>& p, const Circle<T>& c) { return\
    \ equal(norm(p - c.o), c.r * c.r); }\n\n// \u5186 c, \u76F4\u7DDA l \u306E\u4EA4\
    \u5DEE\u5224\u5B9A\ntemplate <class T> inline bool is_intersect(const Circle<T>&\
    \ c, const Line<T>& l) {\n    static_assert(is_geometry_floating_point<T>::value\
    \ == true);\n    // norm(c.o - projection(l, c.o)) \u304C\u76F4\u7DDA l \u3068\
    \ \u5186 c \u306E\u4E2D\u5FC3 c.o \u306E\u8DDD\u96E2\u306E 2 \u4E57\n    return\
    \ sign(c.r * c.r - norm(c.o - projection(l, c.o))) >= 0;\n}\ntemplate <class T>\
    \ inline bool is_intersect(const Line<T>& l, const Circle<T>& c) { return is_intersect(c,\
    \ l); }\n\n// \u5186 c, \u7DDA\u5206 s \u306E\u4EA4\u5DEE\u5224\u5B9A\ntemplate\
    \ <class T> inline bool is_intersect(const Circle<T>& c, const Segment<T>& s)\
    \ {\n    static_assert(is_geometry_floating_point<T>::value == true);\n    if\
    \ (!is_intersect(c, Line(s.a, s.b))) return false;  // \u76F4\u7DDA\u3068\u3057\
    \u3066\u3082\u4EA4\u5DEE\u3057\u306A\u3044\n    T d1 = abs(c.o - s.a), d2 = abs(c.o\
    \ - s.b);\n    if (sign(d1 - c.r) == -1 and sign(d2 - c.r) == -1) return false;\
    \  // \u7AEF\u70B9\u304C\u3069\u3061\u3089\u3082\u5186\u306E\u5185\u5074\n   \
    \ if (sign(d1 - c.r) * sign(d2 - c.r) <= 0) return true;            // \u5186\u5468\
    \u3092\u307E\u305F\u3044\u3067\u3044\u308B\n    const Point<T> h = projection(s,\
    \ c.o);\n    return ccw(s.a, s.b, h) == Ccw::ON_SEGMENT;  // s.a -> h -> s.b \u306E\
    \u9806\u3067\u4E26\u3093\u3067\u3044\u308B\n}\ntemplate <class T> inline bool\
    \ is_intersect(const Segment<T>& s, const Circle<T>& c) { return is_intersect(c,\
    \ s); }\n#line 6 \"geometry/polygon_contain.hpp\"\n\nenum class Contain { IN,\
    \ ON, OUT };\n\n// \u591A\u89D2\u5F62\u304C\u70B9\u3092\u5305\u542B\u3059\u308B\
    \u304B\u5224\u5B9A\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C\n\
    template <class T> Contain polygon_contain(const Polygon<T>& q, const Point<T>&\
    \ p) {\n    bool x = false;\n    const int n = (int)(q.size());\n    for (int\
    \ i = 0; i < n; i++) {\n        int ni = i + 1 == n ? 0 : i + 1;\n        if (is_intersect(Segment(q[i],\
    \ q[ni]), p)) return Contain::ON;\n        Point a = q[i] - p, b = q[ni] - p;\n\
    \        if (a.y > b.y) std::swap(a, b);\n        // a.y < b.y\n        // check\
    \ each point's y is 0 at most 1 times\n        if (sign(a.y) <= 0 and sign(b.y)\
    \ > 0 and sign(cross(a, b)) > 0) x = !x;\n    }\n    return (x ? Contain::IN :\
    \ Contain::OUT);\n}\n"
  code: "#pragma once\n\n#include \"geometry/polygon.hpp\"\n#include \"geometry/line.hpp\"\
    \n#include \"geometry/is_intersect.hpp\"\n\nenum class Contain { IN, ON, OUT };\n\
    \n// \u591A\u89D2\u5F62\u304C\u70B9\u3092\u5305\u542B\u3059\u308B\u304B\u5224\u5B9A\
    \n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C\ntemplate\
    \ <class T> Contain polygon_contain(const Polygon<T>& q, const Point<T>& p) {\n\
    \    bool x = false;\n    const int n = (int)(q.size());\n    for (int i = 0;\
    \ i < n; i++) {\n        int ni = i + 1 == n ? 0 : i + 1;\n        if (is_intersect(Segment(q[i],\
    \ q[ni]), p)) return Contain::ON;\n        Point a = q[i] - p, b = q[ni] - p;\n\
    \        if (a.y > b.y) std::swap(a, b);\n        // a.y < b.y\n        // check\
    \ each point's y is 0 at most 1 times\n        if (sign(a.y) <= 0 and sign(b.y)\
    \ > 0 and sign(cross(a, b)) > 0) x = !x;\n    }\n    return (x ? Contain::IN :\
    \ Contain::OUT);\n}"
  dependsOn:
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  - geometry/line.hpp
  - geometry/is_intersect.hpp
  - geometry/circle.hpp
  isVerificationFile: false
  path: geometry/polygon_contain.hpp
  requiredBy: []
  timestamp: '2024-08-02 21:55:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/geometry/polygon_contain.test.cpp
documentation_of: geometry/polygon_contain.hpp
layout: document
title: "Polygon Contain (\u591A\u89D2\u5F62\u3068\u70B9\u306E\u4EA4\u5DEE\u5224\u5B9A\
  )"
---

## 使い方

```cpp
Polygon<T> P;
Point<T> p;
// ans は Contain::IN, Contain::ON, Contain::OUT のいずれか
auto ans = polygon_contain(P, p);
```

## 参考文献

- [Wikipedia, Rotating calipers](https://en.wikipedia.org/wiki/Rotating_calipers)
