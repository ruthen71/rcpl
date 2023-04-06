---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_diameter.hpp
    title: geometry/convex_polygon_diameter.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/monotone_chain.hpp
    title: geometry/monotone_chain.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_is_convex.hpp
    title: geometry/polygon_is_convex.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/farthest_pair.hpp\"\n\n#line 2 \"geometry/monotone_chain.hpp\"\
    \n\n#line 2 \"geometry/polygon.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n// point\n\
    template <typename T> struct Point {\n    static T EPS;\n    static constexpr\
    \ T PI = 3.1415926535'8979323846'2643383279'5028841971;\n    static void set_eps(const\
    \ T &e) { EPS = e; }\n    T x, y;\n    Point(const T x = T(0), const T y = T(0))\
    \ : x(x), y(y) {}\n    Point &operator+=(const Point &p) {\n        x += p.x;\n\
    \        y += p.y;\n        return *this;\n    }\n    Point &operator-=(const\
    \ Point &p) {\n        x -= p.x;\n        y -= p.y;\n        return *this;\n \
    \   }\n    Point &operator*=(const Point &p) { return *this = Point(x * p.x -\
    \ y * p.y, x * p.y + y * p.x); }\n    Point &operator*=(const T &k) {\n      \
    \  x *= k;\n        y *= k;\n        return *this;\n    }\n    Point &operator/=(const\
    \ Point &p) { return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x\
    \ * p.x + p.y * p.y); }\n    Point &operator/=(const T &k) {\n        x /= k;\n\
    \        y /= k;\n        return *this;\n    }\n\n    Point operator+() const\
    \ { return *this; }\n    Point operator-() const { return Point(-x, -y); }\n\n\
    \    friend Point operator+(const Point &a, const Point &b) { return Point(a)\
    \ += b; }\n    friend Point operator-(const Point &a, const Point &b) { return\
    \ Point(a) -= b; }\n    friend Point operator*(const Point &a, const Point &b)\
    \ { return Point(a) *= b; }\n    friend Point operator*(const Point &p, const\
    \ T &k) { return Point(p) *= k; }\n    friend Point operator/(const Point &a,\
    \ const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
    \ Point &p, const T &k) { return Point(p) /= k; }\n    // for std::set, std::map,\
    \ compare_arg, ...\n    friend bool operator<(const Point &a, const Point &b)\
    \ { return a.x == b.x ? a.y < b.y : a.x < b.x; }\n    // I/O\n    friend std::istream\
    \ &operator>>(std::istream &is, Point &p) { return is >> p.x >> p.y; }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Point &p) { return os << '('\
    \ << p.x << ' ' << p.y << ')'; }\n};\n\n// template\ntemplate <typename T> inline\
    \ int sign(const T &x) { return x < -Point<T>::EPS ? -1 : (x > Point<T>::EPS ?\
    \ 1 : 0); }\ntemplate <typename T> inline bool equal(const T &a, const T &b) {\
    \ return sign(a - b) == 0; }\ntemplate <typename T> inline T radian_to_degree(const\
    \ T &r) { return r * 180.0 / Point<T>::PI; }\ntemplate <typename T> inline T degree_to_radian(const\
    \ T &d) { return d * Point<T>::PI / 180.0; }\n\n// contain enum\nconstexpr int\
    \ IN = 2;\nconstexpr int ON = 1;\nconstexpr int OUT = 0;\n\n// equal (point and\
    \ point)\ntemplate <typename T> inline bool equal(const Point<T> &a, const Point<T>\
    \ &b) { return equal(a.x, b.x) and equal(a.y, b.y); }\n// inner product\ntemplate\
    \ <typename T> inline T dot(const Point<T> &a, const Point<T> &b) { return a.x\
    \ * b.x + a.y * b.y; }\n// outer product\ntemplate <typename T> inline T cross(const\
    \ Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }\n// rotate\
    \ Point p counterclockwise by theta radian\ntemplate <typename T> inline Point<T>\
    \ rotate(const Point<T> &p, const T &theta) { return p * Point<T>(std::cos(theta),\
    \ std::sin(theta)); }\n// compare (x, y)\ntemplate <typename T> inline bool compare_x(const\
    \ Point<T> &a, const Point<T> &b) { return equal(a.x, b.x) ? sign(a.y - b.y) <\
    \ 0 : sign(a.x - b.x) < 0; }\n// compare (y, x)\ntemplate <typename T> inline\
    \ bool compare_y(const Point<T> &a, const Point<T> &b) { return equal(a.y, b.y)\
    \ ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }\n// compare by arg (start from\
    \ 90.0000000001~)\ntemplate <typename T> inline bool compare_arg(const Point<T>\
    \ &a, const Point<T> &b) {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n\
    \    return (Point<T>(0, 0) < a) == (Point<T>(0, 0) < b) ? a.x * b.y > a.y * b.x\
    \ : a < b;\n}\n// |p| ^ 2\ntemplate <typename T> inline T norm(const Point<T>\
    \ &p) { return p.x * p.x + p.y * p.y; }\n// |p|\ntemplate <typename T> inline\
    \ T abs(const Point<T> &p) { return std::sqrt(norm(p)); }\n// arg\ntemplate <typename\
    \ T> inline T arg(const Point<T> &p) { return std::atan2(p.y, p.x); }\n// polar\n\
    template <typename T> inline Point<T> polar(const T &rho, const T &theta = T(0))\
    \ { return rotate(Point<T>(rho, 0), theta); }\n// EPS\ntemplate <> double Point<double>::EPS\
    \ = 1e-9;\ntemplate <> long double Point<long double>::EPS = 1e-12;\ntemplate\
    \ <> long long Point<long long>::EPS = 0;\ntemplate <> __int128_t Point<__int128_t>::EPS\
    \ = 0;\n// change EPS\n// using Double = double;\n// using Pt = Point<Double>;\n\
    // Point<Double>::set_eps(new_eps);\n#line 4 \"geometry/polygon.hpp\"\n\n// polygon\n\
    template <typename T> using Polygon = std::vector<Point<T>>;\ntemplate <typename\
    \ T> std::istream &operator>>(std::istream &is, Polygon<T> &p) {\n    for (auto\
    \ &&pi : p) is >> pi;\n    return is;\n}\ntemplate <typename T> std::ostream &operator<<(std::ostream\
    \ &os, const Polygon<T> &p) {\n    for (auto &&pi : p) os << pi << \" -> \";\n\
    \    return os;\n}\n#line 2 \"geometry/ccw.hpp\"\n\n#line 4 \"geometry/ccw.hpp\"\
    \n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\ntemplate <typename T> int ccw(const\
    \ Point<T> &a, Point<T> b, Point<T> c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b,\
    \ c)) == 1) return COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return\
    \ CLOCKWISE;\n    if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (norm(b)\
    \ < norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 5 \"geometry/monotone_chain.hpp\"\
    \n\n// convex hull (Andrew's monotone chain convex hull algorithm)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    // sort (x, y) by lexicographical order, use stack, calculate upper convex hull\
    \ and lower convex hull\n// counter clockwise order\n// assume the return value\
    \ of ccw is not ONLINE_BACK or ONLINE_FRONT (lexicographical order)\n// strict\
    \ is true : points on the edges of the convex hull are not included (the number\
    \ of points is minimized)\n// complexity: O(n \\log n) (n: the number of points)\n\
    template <typename T> Polygon<T> monotone_chain(std::vector<Point<T>> &p, bool\
    \ strict = true) {\n    int n = (int)p.size();\n    if (n <= 2) return p;\n  \
    \  std::sort(p.begin(), p.end(), compare_x<T>);\n    Polygon<T> r;\n    r.reserve(n\
    \ * 2);\n    if (strict) {\n        for (int i = 0; i < n; i++) {\n          \
    \  while (r.size() >= 2 and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) != CLOCKWISE)\
    \ {\n                r.pop_back();\n            }\n            r.push_back(p[i]);\n\
    \        }\n        int t = r.size() + 1;\n        for (int i = n - 2; i >= 0;\
    \ i--) {\n            while (r.size() >= t and ccw(r[r.size() - 2], r[r.size()\
    \ - 1], p[i]) != CLOCKWISE) {\n                r.pop_back();\n            }\n\
    \            r.push_back(p[i]);\n        }\n    } else {\n        for (int i =\
    \ 0; i < n; i++) {\n            while (r.size() >= 2 and ccw(r[r.size() - 2],\
    \ r[r.size() - 1], p[i]) == COUNTER_CLOCKWISE) {\n                r.pop_back();\n\
    \            }\n            r.push_back(p[i]);\n        }\n        int t = r.size()\
    \ + 1;\n        for (int i = n - 2; i >= 0; i--) {\n            while (r.size()\
    \ >= t and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) == COUNTER_CLOCKWISE) {\n\
    \                r.pop_back();\n            }\n            r.push_back(p[i]);\n\
    \        }\n    }\n    r.pop_back();\n    std::reverse(r.begin(), r.end());\n\
    \    return r;\n}\n#line 2 \"geometry/convex_polygon_diameter.hpp\"\n\n#line 2\
    \ \"geometry/polygon_is_convex.hpp\"\n\n#line 5 \"geometry/polygon_is_convex.hpp\"\
    \n\n// check polygon is convex (not strictly, 0 <= angle <= 180 degrees)\n// angle\
    \ = 180 degrees -> ON_SEGMENT\n// angle = 0 degrees -> ONLINE_FRONT or ONLINE_BACK\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\ntemplate\
    \ <typename T> bool polygon_is_convex(const Polygon<T> &p) {\n    int n = (int)p.size();\n\
    \    assert(n >= 3);\n    bool okccw = true, okcw = true;\n    for (int i = 0;\
    \ i < n - 2; i++) {\n        int res = ccw(p[i], p[i + 1], p[i + 2]);\n      \
    \  if (res == CLOCKWISE) okccw = false;\n        if (res == COUNTER_CLOCKWISE)\
    \ okcw = false;\n        if (!okccw and !okcw) return false;\n    }\n    {\n \
    \       int res = ccw(p[n - 2], p[n - 1], p[0]);\n        if (res == CLOCKWISE)\
    \ okccw = false;\n        if (res == COUNTER_CLOCKWISE) okcw = false;\n      \
    \  if (!okccw and !okcw) return false;\n    }\n    {\n        int res = ccw(p[n\
    \ - 1], p[0], p[1]);\n        if (res == CLOCKWISE) okccw = false;\n        if\
    \ (res == COUNTER_CLOCKWISE) okcw = false;\n        if (!okccw and !okcw) return\
    \ false;\n    }\n    return true;\n}\n#line 5 \"geometry/convex_polygon_diameter.hpp\"\
    \n\n// convex polygon diameter\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\n\
    // return {index1, index2, diameter}\n// using the method of rotating calipers\
    \ (https://en.wikipedia.org/wiki/Rotating_calipers)\n// complexity: O(n)\ntemplate\
    \ <typename T> std::tuple<int, int, T> convex_polygon_diameter(const Polygon<T>\
    \ &p) {\n    assert(polygon_is_convex(p));\n    int n = (int)p.size();\n    assert(n\
    \ >= 2);\n    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n    }\n\
    \    auto [it_min, it_max] = std::minmax_element(p.begin(), p.end(), compare_x<T>);\n\
    \    int idx_min = it_min - p.begin();\n    int idx_max = it_max - p.begin();\n\
    \n    T maxdis = norm(p[idx_max] - p[idx_min]);\n    int maxi = idx_min, i = idx_min,\
    \ maxj = idx_max, j = idx_max;\n    do {\n        int ni = (i + 1 == n ? 0 : i\
    \ + 1), nj = (j + 1 == n ? 0 : j + 1);\n        if (sign(cross(p[ni] - p[i], p[nj]\
    \ - p[j])) < 0) {\n            i = ni;\n        } else {\n            j = nj;\n\
    \        }\n        if (norm(p[i] - p[j]) > maxdis) {\n            maxdis = norm(p[i]\
    \ - p[j]);\n            maxi = i;\n            maxj = j;\n        }\n    } while\
    \ (i != idx_min || j != idx_max);\n    return {maxi, maxj, abs(p[maxi] - p[maxj])};\n\
    }\n#line 5 \"geometry/farthest_pair.hpp\"\n\n// farthest pair\n// return {index1,\
    \ index2, distance}\n// using monotone chain (convex hull) and convex polygon\
    \ diameter\n// complexity: O(n \\log n) (n: the number of points)\ntemplate <typename\
    \ T> std::tuple<int, int, T> farthest_pair(const std::vector<Point<T>> &p) {\n\
    \    int n = int(p.size());\n    assert(n >= 2);\n    if (n == 2) {\n        return\
    \ {0, 1, abs(p[0] - p[1])};\n    }\n    auto q = p;\n    auto ch = monotone_chain(q);\
    \                   // O(n \\log n)\n    auto [i, j, d] = convex_polygon_diameter(ch);\
    \  // O(|ch|)\n    int resi, resj;\n    for (int k = 0; k < n; k++) {\n      \
    \  if (p[k] == ch[i]) {\n            resi = k;\n        }\n        if (p[k] ==\
    \ ch[j]) {\n            resj = k;\n        }\n    }\n    return {resi, resj, d};\n\
    }\n"
  code: "#pragma once\n\n#include \"geometry/monotone_chain.hpp\"\n#include \"geometry/convex_polygon_diameter.hpp\"\
    \n\n// farthest pair\n// return {index1, index2, distance}\n// using monotone\
    \ chain (convex hull) and convex polygon diameter\n// complexity: O(n \\log n)\
    \ (n: the number of points)\ntemplate <typename T> std::tuple<int, int, T> farthest_pair(const\
    \ std::vector<Point<T>> &p) {\n    int n = int(p.size());\n    assert(n >= 2);\n\
    \    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n    }\n    auto\
    \ q = p;\n    auto ch = monotone_chain(q);                   // O(n \\log n)\n\
    \    auto [i, j, d] = convex_polygon_diameter(ch);  // O(|ch|)\n    int resi,\
    \ resj;\n    for (int k = 0; k < n; k++) {\n        if (p[k] == ch[i]) {\n   \
    \         resi = k;\n        }\n        if (p[k] == ch[j]) {\n            resj\
    \ = k;\n        }\n    }\n    return {resi, resj, d};\n}"
  dependsOn:
  - geometry/monotone_chain.hpp
  - geometry/polygon.hpp
  - geometry/point.hpp
  - geometry/ccw.hpp
  - geometry/convex_polygon_diameter.hpp
  - geometry/polygon_is_convex.hpp
  isVerificationFile: false
  path: geometry/farthest_pair.hpp
  requiredBy:
  - geometry/all.hpp
  timestamp: '2023-04-06 10:02:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/farthest_pair.hpp
layout: document
title: "\u6700\u9060\u70B9\u5BFE"
---

## 使用例

- [ABC022 D](https://atcoder.jp/contests/abc022/submissions/39101917)