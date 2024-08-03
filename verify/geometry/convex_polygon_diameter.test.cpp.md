---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_diameter.hpp
    title: "Convex Polygon Diameter (\u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84)"
  - icon: ':question:'
    path: geometry/geometry_template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: geometry/point.hpp
    title: "Point (\u70B9)"
  - icon: ':question:'
    path: geometry/polygon.hpp
    title: "Polygon (\u591A\u89D2\u5F62)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
  bundledCode: "#line 1 \"verify/geometry/convex_polygon_diameter.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\"\
    \n#define ERROR 0.000001\n\n#include <iostream>\n#include <iomanip>\n\n#line 2\
    \ \"geometry/convex_polygon_diameter.hpp\"\n\n#line 2 \"geometry/polygon.hpp\"\
    \n\n#line 2 \"geometry/point.hpp\"\n\n#line 2 \"geometry/geometry_template.hpp\"\
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
    \ p) { return os << '(' << p.x << ' ' << p.y << ')'; }\n};\n\n// \u6C4E\u7528\u95A2\
    \u6570\n// \u70B9\u306E\u4E00\u81F4\u5224\u5B9A\ntemplate <class T> inline bool\
    \ equal(const Point<T>& a, const Point<T>& b) { return equal(a.x, b.x) and equal(a.y,\
    \ b.y); }\n// \u5185\u7A4D\ntemplate <class T> inline T dot(const Point<T>& a,\
    \ const Point<T>& b) { return a.x * b.x + a.y * b.y; }\n// \u5916\u7A4D\ntemplate\
    \ <class T> inline T cross(const Point<T>& a, const Point<T>& b) { return a.x\
    \ * b.y - a.y * b.x; }\n// rad \u30E9\u30B8\u30A2\u30F3\u3060\u3051\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B\u56DE\u8EE2\ntemplate <class T> inline Point<T> rotate(const\
    \ Point<T>& p, const T theta) {\n    static_assert(is_geometry_floating_point<T>::value\
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
    \ == true);\n    return std::sqrt(norm(p));\n}\n// \u504F\u89D2 (-PI, PI]\ntemplate\
    \ <class T> inline T arg(const Point<T>& p) {\n    static_assert(is_geometry_floating_point<T>::value\
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
    \ Ccw::ON_SEGMENT;\n}\n\n// \u7DDA\u5206 a->b \u304B\u3089 \u7DDA\u5206 a->c \u307E\
    \u3067\u306E\u89D2\u5EA6 (\u30E9\u30B8\u30A2\u30F3, \u7B26\u53F7\u4ED8\u304D)\n\
    template <class T> T get_angle(const Point<T>& a, const Point<T>& b, const Point<T>&\
    \ c) {\n    Point<T> ab = b - a;\n    Point<T> ac = c - a;\n    ac *= conj(ab)\
    \ / norm(ab);  // a-b\u304C x \u8EF8\u306B\u306A\u308B\u3088\u3046\u306B\u56DE\
    \u8EE2\n    return arg(ac);\n}\n#line 4 \"geometry/polygon.hpp\"\n\n#include <vector>\n\
    #line 7 \"geometry/polygon.hpp\"\n\n// \u591A\u89D2\u5F62\ntemplate <class T>\
    \ using Polygon = std::vector<Point<T>>;\ntemplate <class T> std::istream& operator>>(std::istream&\
    \ is, Polygon<T>& p) {\n    for (auto&& pi : p) is >> pi;\n    return is;\n}\n\
    template <class T> std::ostream& operator<<(std::ostream& os, const Polygon<T>&\
    \ p) {\n    for (auto&& pi : p) os << pi << \" -> \";\n    return os;\n}\n\n//\
    \ \u591A\u89D2\u5F62\u306E\u9762\u7A4D (\u7B26\u53F7\u4ED8\u304D)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    // return area * 2\ntemplate <class T> T polygon_area2(const Polygon<T>& p) {\n\
    \    const int n = (int)(p.size());\n    assert(n >= 2);\n    T res = T(0);\n\
    \    for (int i = 0; i < n; i++) res += cross(p[i], p[i + 1 == n ? 0 : i + 1]);\n\
    \    // counter clockwise: res > 0\n    // clockwise: res < 0\n    return res;\n\
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
    }\n#line 4 \"geometry/convex_polygon_diameter.hpp\"\n\n#include <tuple>\n#include\
    \ <algorithm>\n\n// \u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84 (rotating calipers)\n\
    // https://en.wikipedia.org/wiki/Rotating_calipers\n// O(n)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\n\
    // return {index1, index2, diameter}\ntemplate <class T> std::tuple<int, int,\
    \ T> convex_polygon_diameter(const Polygon<T>& p) {\n    assert(polygon_is_convex(p));\n\
    \    const int n = (int)(p.size());\n    assert(n >= 2);\n    if (n == 2) {\n\
    \        return {0, 1, abs(p[0] - p[1])};\n    }\n    auto [it_min, it_max] =\
    \ std::minmax_element(p.begin(), p.end(), compare_x<T>);\n    int idx_min = it_min\
    \ - p.begin();\n    int idx_max = it_max - p.begin();\n\n    T maxdis = norm(p[idx_max]\
    \ - p[idx_min]);\n    int maxi = idx_min, i = idx_min, maxj = idx_max, j = idx_max;\n\
    \    do {\n        int ni = (i + 1 == n ? 0 : i + 1), nj = (j + 1 == n ? 0 : j\
    \ + 1);\n        if (sign(cross(p[ni] - p[i], p[nj] - p[j])) < 0) {\n        \
    \    i = ni;\n        } else {\n            j = nj;\n        }\n        if (norm(p[i]\
    \ - p[j]) > maxdis) {\n            maxdis = norm(p[i] - p[j]);\n            maxi\
    \ = i;\n            maxj = j;\n        }\n    } while (i != idx_min or j != idx_max);\n\
    \    return {maxi, maxj, abs(p[maxi] - p[maxj])};\n}\n#line 8 \"verify/geometry/convex_polygon_diameter.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    Polygon<double> P(N);\n\
    \    std::cin >> P;\n    auto [i, j, d] = convex_polygon_diameter(P);\n    std::cout\
    \ << std::fixed << std::setprecision(15) << d << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\"\
    \n#define ERROR 0.000001\n\n#include <iostream>\n#include <iomanip>\n\n#include\
    \ \"geometry/convex_polygon_diameter.hpp\"\n\nint main() {\n    int N;\n    std::cin\
    \ >> N;\n    Polygon<double> P(N);\n    std::cin >> P;\n    auto [i, j, d] = convex_polygon_diameter(P);\n\
    \    std::cout << std::fixed << std::setprecision(15) << d << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - geometry/convex_polygon_diameter.hpp
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/geometry_template.hpp
  isVerificationFile: true
  path: verify/geometry/convex_polygon_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-08-03 20:33:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/geometry/convex_polygon_diameter.test.cpp
layout: document
redirect_from:
- /verify/verify/geometry/convex_polygon_diameter.test.cpp
- /verify/verify/geometry/convex_polygon_diameter.test.cpp.html
title: verify/geometry/convex_polygon_diameter.test.cpp
---
