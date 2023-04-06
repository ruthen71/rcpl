---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':x:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':x:'
    path: geometry/circumscribed_circle.hpp
    title: geometry/circumscribed_circle.hpp
  - icon: ':x:'
    path: geometry/closest_pair.hpp
    title: "\u6700\u8FD1\u70B9\u5BFE"
  - icon: ':x:'
    path: geometry/convex_polygon_cut.hpp
    title: geometry/convex_polygon_cut.hpp
  - icon: ':x:'
    path: geometry/convex_polygon_diameter.hpp
    title: geometry/convex_polygon_diameter.hpp
  - icon: ':x:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':x:'
    path: geometry/cross_point_cl.hpp
    title: geometry/cross_point_cl.hpp
  - icon: ':x:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':x:'
    path: geometry/cross_point_ss.hpp
    title: geometry/cross_point_ss.hpp
  - icon: ':x:'
    path: geometry/distance_lp.hpp
    title: geometry/distance_lp.hpp
  - icon: ':x:'
    path: geometry/distance_sp.hpp
    title: geometry/distance_sp.hpp
  - icon: ':x:'
    path: geometry/distance_ss.hpp
    title: geometry/distance_ss.hpp
  - icon: ':warning:'
    path: geometry/farthest_pair.hpp
    title: "\u6700\u9060\u70B9\u5BFE"
  - icon: ':x:'
    path: geometry/incircle.hpp
    title: geometry/incircle.hpp
  - icon: ':x:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':x:'
    path: geometry/is_intersect_cl.hpp
    title: geometry/is_intersect_cl.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_cp.hpp
    title: geometry/is_intersect_cp.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_ll.hpp
    title: geometry/is_intersect_ll.hpp
  - icon: ':warning:'
    path: geometry/is_intersect_lp.hpp
    title: geometry/is_intersect_lp.hpp
  - icon: ':x:'
    path: geometry/is_intersect_sp.hpp
    title: geometry/is_intersect_sp.hpp
  - icon: ':x:'
    path: geometry/is_intersect_ss.hpp
    title: geometry/is_intersect_ss.hpp
  - icon: ':x:'
    path: geometry/is_orthogonal.hpp
    title: geometry/is_orthogonal.hpp
  - icon: ':x:'
    path: geometry/is_parallel.hpp
    title: geometry/is_parallel.hpp
  - icon: ':x:'
    path: geometry/line.hpp
    title: geometry/line.hpp
  - icon: ':x:'
    path: geometry/monotone_chain.hpp
    title: geometry/monotone_chain.hpp
  - icon: ':x:'
    path: geometry/point.hpp
    title: geometry/point.hpp
  - icon: ':x:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':x:'
    path: geometry/polygon_area.hpp
    title: geometry/polygon_area.hpp
  - icon: ':x:'
    path: geometry/polygon_contain.hpp
    title: geometry/polygon_contain.hpp
  - icon: ':x:'
    path: geometry/polygon_is_convex.hpp
    title: geometry/polygon_is_convex.hpp
  - icon: ':x:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':x:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
  - icon: ':x:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  - icon: ':x:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  - icon: ':x:'
    path: geometry/tangent_point_cp.hpp
    title: geometry/tangent_point_cp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/all.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n\
    // point\ntemplate <typename T> struct Point {\n    static T EPS;\n    static\
    \ const T PI = std::acos(T(-1));\n    static void set_eps(const T &e) { EPS =\
    \ e; }\n    T x, y;\n    Point(const T x = T(0), const T y = T(0)) : x(x), y(y)\
    \ {}\n    Point &operator+=(const Point &p) {\n        x += p.x;\n        y +=\
    \ p.y;\n        return *this;\n    }\n    Point &operator-=(const Point &p) {\n\
    \        x -= p.x;\n        y -= p.y;\n        return *this;\n    }\n    Point\
    \ &operator*=(const Point &p) { return *this = Point(x * p.x - y * p.y, x * p.y\
    \ + y * p.x); }\n    Point &operator*=(const T &k) {\n        x *= k;\n      \
    \  y *= k;\n        return *this;\n    }\n    Point &operator/=(const Point &p)\
    \ { return *this = Point(x * p.x + y * p.y, -x * p.y + y * p.x) / (p.x * p.x +\
    \ p.y * p.y); }\n    Point &operator/=(const T &k) {\n        x /= k;\n      \
    \  y /= k;\n        return *this;\n    }\n\n    Point operator+() const { return\
    \ *this; }\n    Point operator-() const { return Point(-x, -y); }\n\n    friend\
    \ Point operator+(const Point &a, const Point &b) { return Point(a) += b; }\n\
    \    friend Point operator-(const Point &a, const Point &b) { return Point(a)\
    \ -= b; }\n    friend Point operator*(const Point &a, const Point &b) { return\
    \ Point(a) *= b; }\n    friend Point operator*(const Point &p, const T &k) { return\
    \ Point(p) *= k; }\n    friend Point operator/(const Point &a, const Point &b)\
    \ { return Point(a) /= b; }\n    friend Point operator/(const Point &p, const\
    \ T &k) { return Point(p) /= k; }\n    // for std::set, std::map, compare_arg,\
    \ ...\n    friend bool operator<(const Point &a, const Point &b) { return a.x\
    \ == b.x ? a.y < b.y : a.x < b.x; }\n    // I/O\n    friend std::istream &operator>>(std::istream\
    \ &is, Point &p) { return is >> p.x >> p.y; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Point &p) { return os << '(' << p.x << ' ' << p.y << ')'; }\n};\n\
    \n// template\ntemplate <typename T> inline int sign(const T &x) { return x <\
    \ -Point<T>::EPS ? -1 : (x > Point<T>::EPS ? 1 : 0); }\ntemplate <typename T>\
    \ inline bool equal(const T &a, const T &b) { return sign(a - b) == 0; }\ntemplate\
    \ <typename T> inline T radian_to_degree(const T &r) { return r * 180.0 / Point<T>::PI;\
    \ }\ntemplate <typename T> inline T degree_to_radian(const T &d) { return d *\
    \ Point<T>::PI / 180.0; }\n\n// contain enum\nconstexpr int IN = 2;\nconstexpr\
    \ int ON = 1;\nconstexpr int OUT = 0;\n\n// equal (point and point)\ntemplate\
    \ <typename T> inline bool equal(const Point<T> &a, const Point<T> &b) { return\
    \ equal(a.x, b.x) and equal(a.y, b.y); }\n// inner product\ntemplate <typename\
    \ T> inline T dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y\
    \ * b.y; }\n// outer product\ntemplate <typename T> inline T cross(const Point<T>\
    \ &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }\n// rotate Point p\
    \ counterclockwise by theta radian\ntemplate <typename T> inline Point<T> rotate(const\
    \ Point<T> &p, const T &theta) { return p * Point<T>(std::cos(theta), std::sin(theta));\
    \ }\n// compare (x, y)\ntemplate <typename T> inline bool compare_x(const Point<T>\
    \ &a, const Point<T> &b) { return equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x\
    \ - b.x) < 0; }\n// compare (y, x)\ntemplate <typename T> inline bool compare_y(const\
    \ Point<T> &a, const Point<T> &b) { return equal(a.y, b.y) ? sign(a.x - b.x) <\
    \ 0 : sign(a.y - b.y) < 0; }\n// compare by arg (start from 90.0000000001~)\n\
    template <typename T> inline bool compare_arg(const Point<T> &a, const Point<T>\
    \ &b) {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n    return\
    \ (Point<T>(0, 0) < a) == (Point<T>(0, 0) < b) ? a.x * b.y > a.y * b.x : a < b;\n\
    }\n// |p| ^ 2\ntemplate <typename T> inline T norm(const Point<T> &p) { return\
    \ p.x * p.x + p.y * p.y; }\n// |p|\ntemplate <typename T> inline T abs(const Point<T>\
    \ &p) { return std::sqrt(norm(p)); }\n// arg\ntemplate <typename T> inline T arg(const\
    \ Point<T> &p) { return std::atan2(p.y, p.x); }\n// polar\ntemplate <typename\
    \ T> inline Point<T> polar(const T &rho, const T &theta = T(0)) { return rotate(Point<T>(rho,\
    \ 0), theta); }\n// EPS\ntemplate <> double Point<double>::EPS = 1e-9;\ntemplate\
    \ <> long double Point<long double>::EPS = 1e-12;\ntemplate <> long long Point<long\
    \ long>::EPS = 0;\ntemplate <> __int128_t Point<__int128_t>::EPS = 0;\n// change\
    \ EPS\n// using Double = double;\n// using Pt = Point<Double>;\n// Point<Double>::set_eps(new_eps);\n\
    #line 2 \"geometry/line.hpp\"\n\n#line 4 \"geometry/line.hpp\"\n\n// line\ntemplate\
    \ <typename T> struct Line {\n    Point<T> a, b;\n\n    Line() = default;\n\n\
    \    Line(const Point<T> &a, const Point<T> &b) : a(a), b(b) {}\n\n    // Ax +\
    \ By = C\n    Line(const T &A, const T &B, const T &C) {\n        assert(equal(A,\
    \ 0) and equal(B, 0));\n        if (equal(A, 0)) {\n            a = Point<T>(0,\
    \ C / B), b = Point<T>(1, C / B);\n        } else if (equal(B, 0)) {\n       \
    \     a = Point<T>(C / A, 0), b = Point<T>(C / A, 1);\n        } else if (equal(C,\
    \ 0)) {\n            a = Point<T>(0, 0), b = Point<T>(1, B / A);\n        } else\
    \ {\n            a = Point<T>(0, C / B), b = Point<T>(C / A, 0);\n        }\n\
    \    }\n\n    friend std::istream &operator>>(std::istream &is, Line &p) { return\
    \ is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 2 \"geometry/segment.hpp\"\
    \n\n#line 4 \"geometry/segment.hpp\"\n\n// segment\ntemplate <typename T> struct\
    \ Segment : Line<T> {\n    Segment() = default;\n\n    Segment(const Point<T>\
    \ &a, const Point<T> &b) : Line<T>(a, b) {}\n};\n#line 2 \"geometry/circle.hpp\"\
    \n\n#line 4 \"geometry/circle.hpp\"\n\n// circle\ntemplate <typename T> struct\
    \ Circle {\n    Point<T> o;\n    T r;\n\n    Circle() = default;\n\n    Circle(const\
    \ Point<T> &o, const T &r) : o(o), r(r) {}\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Circle &c) { return is >> c.o >> c.r; }  // format : x y r\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Circle &c) { return os << c.o\
    \ << ' ' << c.r; }\n};\n#line 2 \"geometry/polygon.hpp\"\n\n#line 4 \"geometry/polygon.hpp\"\
    \n\n// polygon\ntemplate <typename T> using Polygon = std::vector<Point<T>>;\n\
    template <typename T> std::istream &operator>>(std::istream &is, Polygon<T> &p)\
    \ {\n    for (auto &&pi : p) is >> pi;\n    return is;\n}\ntemplate <typename\
    \ T> std::ostream &operator<<(std::ostream &os, const Polygon<T> &p) {\n    for\
    \ (auto &&pi : p) os << pi << \" -> \";\n    return os;\n}\n#line 8 \"geometry/all.hpp\"\
    \n\n#line 2 \"geometry/projection.hpp\"\n\n#line 5 \"geometry/projection.hpp\"\
    \n\n// projection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\n\
    template <typename T> Point<T> projection(const Line<T> &l, const Point<T> &p)\
    \ {\n    T t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n    return l.a + t\
    \ * (l.b - l.a);\n}\n#line 2 \"geometry/reflection.hpp\"\n\n#line 6 \"geometry/reflection.hpp\"\
    \n\n// reflection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\n\
    template <typename T> Point<T> reflection(const Line<T> &l, const Point<T> &p)\
    \ { return p + (projection(l, p) - p) * T(2); }\n#line 2 \"geometry/ccw.hpp\"\n\
    \n#line 4 \"geometry/ccw.hpp\"\n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\ntemplate <typename T> int ccw(const\
    \ Point<T> &a, Point<T> b, Point<T> c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b,\
    \ c)) == 1) return COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return\
    \ CLOCKWISE;\n    if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (norm(b)\
    \ < norm(c)) return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 2 \"geometry/is_orthogonal.hpp\"\
    \n\n#line 4 \"geometry/is_orthogonal.hpp\"\n\n// orthogonal\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    template <typename T> inline bool is_orthogonal(const Line<T> &l1, const Line<T>\
    \ &l2) { return sign(dot(l1.b - l1.a, l2.b - l2.a)) == 0; }\n#line 2 \"geometry/is_parallel.hpp\"\
    \n\n#line 4 \"geometry/is_parallel.hpp\"\n\n// parallel\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    template <typename T> inline bool is_parallel(const Line<T> &l1, const Line<T>\
    \ &l2) { return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0; }\n#line 14 \"geometry/all.hpp\"\
    \n\n#line 2 \"geometry/is_intersect_ll.hpp\"\n\n#line 4 \"geometry/is_intersect_ll.hpp\"\
    \n\n// intersection (line and line)\ntemplate <typename T> bool is_intersect_ll(const\
    \ Line<T> &l1, const Line<T> &l2) {\n    Point<T> base = l1.b - l1.a;\n    T d12\
    \ = cross(base, l2.b - l2.a);\n    T d1 = cross(base, l1.b - l2.a);\n    if (sign(d12)\
    \ == 0) {\n        // parallel\n        if (sign(d1) == 0) {\n            // cross\n\
    \            return true;\n        } else {\n            // not cross\n      \
    \      return false;\n        }\n    }\n    return true;\n}\n#line 2 \"geometry/is_intersect_lp.hpp\"\
    \n\n#line 5 \"geometry/is_intersect_lp.hpp\"\n\n// intersection (line and point)\n\
    // ccw(a, b, c) == ON_SEGMENT or ONLINE_BACK or ONLINE_FRONT\ntemplate <typename\
    \ T> inline bool is_intersect_lp(const Line<T> &l, const Point<T> &p) {\n    int\
    \ res = ccw(l.a, l.b, p);\n    return (res == ONLINE_BACK or res == ONLINE_FRONT\
    \ or res == ON_SEGMENT);\n}\n#line 2 \"geometry/is_intersect_ss.hpp\"\n\n#line\
    \ 5 \"geometry/is_intersect_ss.hpp\"\n\n// intersection (segment and segment)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\ntemplate\
    \ <typename T> inline bool is_intersect_ss(const Segment<T> &s1, const Segment<T>\
    \ &s2) { return (ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and ccw(s2.a,\
    \ s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0); }\n#line 2 \"geometry/is_intersect_sp.hpp\"\
    \n\n#line 5 \"geometry/is_intersect_sp.hpp\"\n\n// intersection (segment and point)\n\
    // ccw(a, b, c) == ON_SEGMENT -> a - c - b\ntemplate <typename T> inline bool\
    \ is_intersect_sp(const Segment<T> &s, const Point<T> &p) { return ccw(s.a, s.b,\
    \ p) == ON_SEGMENT or sign(norm(s.a - p)) == 0 or sign(norm(s.b - p)) == 0; }\n\
    #line 3 \"geometry/tangent_number_cc.hpp\"\n\n// return the number of tangent\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\ntemplate\
    \ <typename T> int tangent_number_cc(Circle<T> c1, Circle<T> c2) {\n    if (c1.r\
    \ < c2.r) std::swap(c1, c2);\n    const T d2 = norm(c1.o - c2.o);\n    if (sign(d2\
    \ - (c1.r + c2.r) * (c1.r + c2.r)) == 1) return 4;  // d > c1.r + c2.r and c1.r\
    \ + c2.r >= 0 <=> d * d > (c1.r + c2.r) * (c1.r + c2.r)\n    if (sign(d2 - (c1.r\
    \ + c2.r) * (c1.r + c2.r)) == 0) return 3;  // d = c1.r + c2.r and c1.r + c2.r\
    \ >= 0 <=> d * d = (c1.r + c2.r) * (c1.r + c2.r)\n    if (sign(d2 - (c1.r - c2.r)\
    \ * (c1.r - c2.r)) == 1) return 2;  // d > c1.r - c2.r and c1.r - c2.r >= 0 <=>\
    \ d * d > (c1.r - c2.r) * (c1.r - c2.r)\n    if (sign(d2 - (c1.r - c2.r) * (c1.r\
    \ - c2.r)) == 0) return 1;  // d = c1.r - c2.r and c1.r - c2.r >= 0 <=> d * d\
    \ = (c1.r - c2.r) * (c1.r - c2.r)\n    return 0;\n}\n#line 2 \"geometry/is_intersect_cc.hpp\"\
    \n\n#line 5 \"geometry/is_intersect_cc.hpp\"\n\n// intersection (circle and circle)\n\
    // intersect = number of tangent is 1, 2, 3\ntemplate <typename T> inline bool\
    \ is_intersect_cc(const Circle<T> &c1, const Circle<T> &c2) {\n    int num = tangent_number_cc(c1,\
    \ c2);\n    return 1 <= num and num <= 3;\n}\n#line 2 \"geometry/is_intersect_cp.hpp\"\
    \n\n#line 5 \"geometry/is_intersect_cp.hpp\"\n// intersection (circle and point)\n\
    template <typename T> inline bool is_intersect_cp(const Circle<T> &c, const Point<T>\
    \ &p) { return equal(norm(p - c.o), c.r * c.r); }\n#line 2 \"geometry/is_intersect_cl.hpp\"\
    \n\n#line 2 \"geometry/distance_lp.hpp\"\n\n#line 6 \"geometry/distance_lp.hpp\"\
    \n\n// distance (line and point) (Double = double or long)\ntemplate <typename\
    \ T> T distance_lp(const Line<T> &l, const Point<T> &p) { return abs(p - projection(l,\
    \ p)); }\ntemplate <typename T> T distance2_lp(const Line<T> &l, const Point<T>\
    \ &p) { return norm(p - projection(l, p)); }\n#line 5 \"geometry/is_intersect_cl.hpp\"\
    \n\n// intersection (circle and line)\ntemplate <typename T> inline bool is_intersect_cl(const\
    \ Circle<T> &c, const Line<T> &l) { return sign(c.r * c.r - distance2_lp(l, c.o))\
    \ >= 0; }\n#line 23 \"geometry/all.hpp\"\n\n#line 2 \"geometry/cross_point_ll.hpp\"\
    \n\n#line 4 \"geometry/cross_point_ll.hpp\"\n\n// cross point (line and line)\n\
    template <typename T> Point<T> cross_point_ll(const Line<T> &l1, const Line<T>\
    \ &l2) {\n    Point<T> base = l1.b - l1.a;\n    T d12 = cross(base, l2.b - l2.a);\n\
    \    T d1 = cross(base, l1.b - l2.a);\n    if (sign(d12) == 0) {\n        // parallel\n\
    \        if (sign(d1) == 0) {\n            // cross\n            return l2.a;\n\
    \        } else {\n            // not cross\n            assert(false);\n    \
    \    }\n    }\n    return l2.a + (l2.b - l2.a) * (d1 / d12);\n}\n#line 2 \"geometry/cross_point_ss.hpp\"\
    \n\n#line 6 \"geometry/cross_point_ss.hpp\"\n\n// cross point (segment and segment)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\ntemplate\
    \ <typename T> Point<T> cross_point_ss(const Segment<T> &s1, const Segment<T>\
    \ &s2) {\n    // check intersection s1 and s2\n    assert(is_intersect_ss(s1,\
    \ s2));\n    Point<T> base = s1.b - s1.a;\n    T d12 = cross(base, s2.b - s2.a);\n\
    \    T d1 = cross(base, s1.b - s2.a);\n    if (sign(d12) == 0) {\n        // parallel\n\
    \        if (sign(d1) == 0) {\n            // equal\n            if (is_intersect_sp(s1,\
    \ s2.a)) return s2.a;\n            if (is_intersect_sp(s1, s2.b)) return s2.b;\n\
    \            if (is_intersect_sp(s2, s1.a)) return s1.a;\n            assert(is_intersect_sp(s2,\
    \ s1.b));\n            return s1.b;\n        } else {\n            // excepted\
    \ by is_intersect_ss(s1, s2)\n            assert(0);\n        }\n    }\n    return\
    \ s2.a + (s2.b - s2.a) * (d1 / d12);\n}\n#line 2 \"geometry/cross_point_cl.hpp\"\
    \n\n#line 5 \"geometry/cross_point_cl.hpp\"\n\n// cross point (circle and line)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\ntemplate\
    \ <typename T> std::vector<Point<T>> cross_point_cl(const Circle<T> &c, const\
    \ Line<T> &l) {\n    assert(is_intersect_cl(c, l));\n    auto pr = projection(l,\
    \ c.o);\n    if (equal(norm(pr - c.o), c.r * c.r)) return {pr};\n    Point<T>\
    \ e = (l.b - l.a) * (T(1) / abs(l.b - l.a));\n    auto k = sqrt(c.r * c.r - norm(pr\
    \ - c.o));\n    return {pr - e * k, pr + e * k};\n}\n#line 2 \"geometry/cross_point_cc.hpp\"\
    \n\n#line 4 \"geometry/cross_point_cc.hpp\"\n\n// cross point (circle and circle)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\ntemplate\
    \ <typename T> std::vector<Point<T>> cross_point_cc(const Circle<T> &c1, const\
    \ Circle<T> &c2) {\n    if (!is_intersect_cc(c1, c2)) return {};\n    T d = abs(c1.o\
    \ - c2.o);\n    T a = std::acos((c1.r * c1.r - c2.r * c2.r + d * d) / (T(2) *\
    \ c1.r * d));\n    T t = arg(c2.o - c1.o);\n    Point<T> p = c1.o + polar(c1.r,\
    \ t + a);\n    Point<T> q = c1.o + polar(c1.r, t - a);\n    if (equal(p.x, q.x)\
    \ and equal(p.y, q.y)) return {p};\n    return {p, q};\n}\n#line 28 \"geometry/all.hpp\"\
    \n\n#line 2 \"geometry/distance_sp.hpp\"\n\n#line 7 \"geometry/distance_sp.hpp\"\
    \n\n// distance (segment and point)\ntemplate <typename T> T distance_sp(const\
    \ Segment<T> &s, const Point<T> &p) {\n    Point<T> r = projection(s, p);\n  \
    \  if (is_intersect_sp(s, r)) {\n        return abs(r - p);\n    }\n    return\
    \ std::min(abs(s.a - p), abs(s.b - p));\n}\n#line 2 \"geometry/distance_ss.hpp\"\
    \n\n#line 6 \"geometry/distance_ss.hpp\"\n\n// distance (segment and segment)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\ntemplate\
    \ <typename T> T distance_ss(const Segment<T> &s1, const Segment<T> &s2) {\n \
    \   if (is_intersect_ss(s1, s2)) return T(0);\n    return std::min({distance_sp(s1,\
    \ s2.a), distance_sp(s1, s2.b), distance_sp(s2, s1.a), distance_sp(s2, s1.b)});\n\
    }\n#line 32 \"geometry/all.hpp\"\n\n#line 2 \"geometry/tangent_point_cp.hpp\"\n\
    \n#line 4 \"geometry/tangent_point_cp.hpp\"\n\n// tangent point (circle and point)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\ntemplate\
    \ <typename T> std::pair<Point<T>, Point<T>> tangent_point_cp(const Circle<T>\
    \ &c, const Point<T> &p) {\n    assert(sign(abs(c.o - p) - c.r) == 1);\n    auto\
    \ res = cross_point_cc(c, Circle(p, sqrt(norm(c.o - p) - c.r * c.r)));\n    return\
    \ {res[0], res[1]};\n}\n#line 2 \"geometry/incircle.hpp\"\n\n#line 6 \"geometry/incircle.hpp\"\
    \n\n// incircle of a triangle\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B\n\
    // https://drken1215.hatenablog.com/entry/2020/10/16/073700\ntemplate <typename\
    \ T> Circle<T> incircle(const Point<T> &a, const Point<T> &b, const Point<T> &c)\
    \ {\n    T A = arg((c - a) / (b - a)), B = arg((a - b) / (c - b));\n    Line l1(a,\
    \ a + rotate(b - a, A / 2)), l2(b, b + rotate(c - b, B / 2));\n    auto o = cross_point_ll(l1,\
    \ l2);\n    auto r = distance_lp(Line(a, b), o);\n    return Circle(o, r);\n}\n\
    #line 2 \"geometry/circumscribed_circle.hpp\"\n\n#line 5 \"geometry/circumscribed_circle.hpp\"\
    \n\n// circumscribed circle of a triangle\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C\n\
    // https://drken1215.hatenablog.com/entry/2020/10/16/074400\ntemplate <typename\
    \ T> Circle<T> circumscribed_circle(const Point<T> &a, const Point<T> &b, const\
    \ Point<T> &c) {\n    Line l1((a + b) / 2, (a + b) / 2 + rotate(b - a, Point<T>::PI\
    \ / 2)), l2((b + c) / 2, (b + c) / 2 + rotate(c - b, Point<T>::PI / 2));\n   \
    \ auto o = cross_point_ll(l1, l2);\n    auto r = abs(o - a);\n    return Circle(o,\
    \ r);\n}\n#line 36 \"geometry/all.hpp\"\n\n#line 2 \"geometry/polygon_area.hpp\"\
    \n\n#line 4 \"geometry/polygon_area.hpp\"\n\n// area of polygon\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    // return area * 2\ntemplate <typename T> T polygon_area2(const Polygon<T> &p)\
    \ {\n    int n = (int)p.size();\n    assert(n >= 2);\n    T ret = T(0);\n    for\
    \ (int i = 0; i < n - 1; i++) {\n        ret += cross(p[i], p[i + 1]);\n    }\n\
    \    ret += cross(p[n - 1], p[0]);\n    // counter clockwise: ret > 0\n    //\
    \ clockwise: ret < 0\n    return ret;\n}\ntemplate <typename T> T polygon_area(const\
    \ Polygon<T> &p) { return polygon_area2(p) / T(2); }\n#line 2 \"geometry/polygon_is_convex.hpp\"\
    \n\n#line 5 \"geometry/polygon_is_convex.hpp\"\n\n// check polygon is convex (not\
    \ strictly, 0 <= angle <= 180 degrees)\n// angle = 180 degrees -> ON_SEGMENT\n\
    // angle = 0 degrees -> ONLINE_FRONT or ONLINE_BACK\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\n\
    template <typename T> bool polygon_is_convex(const Polygon<T> &p) {\n    int n\
    \ = (int)p.size();\n    assert(n >= 3);\n    bool okccw = true, okcw = true;\n\
    \    for (int i = 0; i < n - 2; i++) {\n        int res = ccw(p[i], p[i + 1],\
    \ p[i + 2]);\n        if (res == CLOCKWISE) okccw = false;\n        if (res ==\
    \ COUNTER_CLOCKWISE) okcw = false;\n        if (!okccw and !okcw) return false;\n\
    \    }\n    {\n        int res = ccw(p[n - 2], p[n - 1], p[0]);\n        if (res\
    \ == CLOCKWISE) okccw = false;\n        if (res == COUNTER_CLOCKWISE) okcw = false;\n\
    \        if (!okccw and !okcw) return false;\n    }\n    {\n        int res =\
    \ ccw(p[n - 1], p[0], p[1]);\n        if (res == CLOCKWISE) okccw = false;\n \
    \       if (res == COUNTER_CLOCKWISE) okcw = false;\n        if (!okccw and !okcw)\
    \ return false;\n    }\n    return true;\n}\n#line 2 \"geometry/polygon_contain.hpp\"\
    \n\n#line 5 \"geometry/polygon_contain.hpp\"\n\n// polygon contain point -> 2\
    \ (IN)\n// polygon cross point -> 1 (ON)\n// otherwise -> 0 (OUT)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C\n\
    template <typename T> int polygon_contain(const Polygon<T> &q, const Point<T>\
    \ &p) {\n    bool x = false;\n    int n = (int)q.size();\n    for (int i = 0;\
    \ i < n - 1; i++) {\n        if (is_intersect_sp(Segment(q[i], q[i + 1]), p))\
    \ return ON;\n        Point a = q[i] - p, b = q[i + 1] - p;\n        if (a.y >\
    \ b.y) std::swap(a, b);\n        // a.y < b.y\n        // check each point's y\
    \ is 0 at most 1 times\n        if (sign(a.y) <= 0 and sign(b.y) > 0 and sign(cross(a,\
    \ b)) > 0) x = !x;\n    }\n    {\n        if (is_intersect_sp(Segment(q[n - 1],\
    \ q[0]), p)) return ON;\n        Point a = q[n - 1] - p, b = q[0] - p;\n     \
    \   if (a.y > b.y) std::swap(a, b);\n        if (sign(a.y) <= 0 and sign(b.y)\
    \ > 0 and sign(cross(a, b)) > 0) x = !x;\n    }\n    return (x ? IN : OUT);\n\
    }\n#line 2 \"geometry/monotone_chain.hpp\"\n\n#line 5 \"geometry/monotone_chain.hpp\"\
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
    \    return r;\n}\n#line 2 \"geometry/convex_polygon_diameter.hpp\"\n\n#line 5\
    \ \"geometry/convex_polygon_diameter.hpp\"\n\n// convex polygon diameter\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\n\
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
    }\n#line 2 \"geometry/convex_polygon_cut.hpp\"\n\n#line 5 \"geometry/convex_polygon_cut.hpp\"\
    \n\n// cut convex polygon p by line l\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\n\
    // return {left polygon, right polygon}\n// whether each point is included is\
    \ determined by the sign of the outer product of the two vectors to the endpoints\
    \ of the line\ntemplate <typename T> std::pair<Polygon<T>, Polygon<T>> convex_polygon_cut(const\
    \ Polygon<T> &p, const Line<T> &l) {\n    int n = (int)p.size();\n    assert(n\
    \ >= 3);\n    Polygon<T> pl, pr;\n    for (int i = 0; i < n; i++) {\n        int\
    \ s1 = sign(cross(l.a - p[i], l.b - p[i]));\n        int s2 = sign(cross(l.a -\
    \ p[i + 1 == n ? 0 : i + 1], l.b - p[i + 1 == n ? 0 : i + 1]));\n        if (s1\
    \ >= 0) {\n            pl.push_back(p[i]);\n        }\n        if (s1 <= 0) {\n\
    \            pr.push_back(p[i]);\n        }\n        if (s1 * s2 < 0) {\n    \
    \        // don't use \"<=\", use \"<\" to exclude endpoints\n            auto\
    \ pc = cross_point_ll(Line(p[i], p[i + 1 == n ? 0 : i + 1]), l);\n           \
    \ pl.push_back(pc);\n            pr.push_back(pc);\n        }\n    }\n    return\
    \ {pl, pr};\n}\n#line 43 \"geometry/all.hpp\"\n\n#line 2 \"geometry/closest_pair.hpp\"\
    \n\n#line 4 \"geometry/closest_pair.hpp\"\n\n// closest pair\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\n\
    // return {index1, index2, distance}\n// using divide-and-conquer algorithm\n\
    // complexity: O(n \\log n) (n: the number of points)\ntemplate <typename T> std::tuple<int,\
    \ int, T> closest_pair(const std::vector<Point<T>> &p) {\n    int n = int(p.size());\n\
    \    assert(n >= 2);\n    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n\
    \    }\n    // may not be efficient due to indirect references ...\n    std::vector<int>\
    \ ind(n);\n    std::iota(ind.begin(), ind.end(), 0);\n    std::sort(ind.begin(),\
    \ ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });\n    auto divide_and_conquer\
    \ = [&](auto f, int l, int r) -> std::tuple<int, int, T> {\n        if (r - l\
    \ <= 1) return {-1, -1, std::numeric_limits<T>::max()};\n        int md = (l +\
    \ r) / 2;\n        T x = p[ind[md]].x;\n        // divide and conquer\n      \
    \  auto [i1l, i2l, dl] = f(f, l, md);\n        auto [i1r, i2r, dr] = f(f, md,\
    \ r);\n        int i1, i2;\n        T d;\n        if (dl < dr) {\n           \
    \ d = dl, i1 = i1l, i2 = i2l;\n        } else {\n            d = dr, i1 = i1r,\
    \ i2 = i2r;\n        }\n        std::inplace_merge(ind.begin() + l, ind.begin()\
    \ + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i], p[j]); });\n\
    \        // ind are sorted by y\n        std::vector<int> near_x;  // index of\
    \ vertices whose distance from the line x is less than d\n        for (int i =\
    \ l; i < r; i++) {\n            if (sign(std::abs(p[ind[i]].x - x) - d) >= 0)\
    \ continue;  // std::abs(p[ind[i]].x - x) >= d\n            int sz = int(near_x.size());\n\
    \            // iterate from the end until the distance in y-coordinates is greater\
    \ than or equal to d\n            for (int j = sz - 1; j >= 0; j--) {\n      \
    \          Point cp = p[ind[i]] - p[near_x[j]];\n                if (sign(cp.y\
    \ - d) >= 0) break;  // cp.y >= d\n                T cd = abs(cp);\n         \
    \       if (cd < d) {\n                    d = cd, i1 = ind[i], i2 = near_x[j];\n\
    \                }\n            }\n            near_x.push_back(ind[i]);\n   \
    \     }\n        return {i1, i2, d};\n    };\n    return divide_and_conquer(divide_and_conquer,\
    \ 0, n);\n}\n#line 2 \"geometry/farthest_pair.hpp\"\n\n#line 5 \"geometry/farthest_pair.hpp\"\
    \n\n// farthest pair\n// return {index1, index2, distance}\n// using monotone\
    \ chain (convex hull) and convex polygon diameter\n// complexity: O(n \\log n)\
    \ (n: the number of points)\ntemplate <typename T> std::tuple<int, int, T> farthest_pair(const\
    \ std::vector<Point<T>> &p) {\n    int n = int(p.size());\n    assert(n >= 2);\n\
    \    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n    }\n    auto\
    \ q = p;\n    auto ch = monotone_chain(q);                   // O(n \\log n)\n\
    \    auto [i, j, d] = convex_polygon_diameter(ch);  // O(|ch|)\n    int resi,\
    \ resj;\n    for (int k = 0; k < n; k++) {\n        if (p[k] == ch[i]) {\n   \
    \         resi = k;\n        }\n        if (p[k] == ch[j]) {\n            resj\
    \ = k;\n        }\n    }\n    return {resi, resj, d};\n}\n#line 46 \"geometry/all.hpp\"\
    \n"
  code: '#pragma once


    #include "geometry/point.hpp"

    #include "geometry/line.hpp"

    #include "geometry/segment.hpp"

    #include "geometry/circle.hpp"

    #include "geometry/polygon.hpp"


    #include "geometry/projection.hpp"

    #include "geometry/reflection.hpp"

    #include "geometry/ccw.hpp"

    #include "geometry/is_orthogonal.hpp"

    #include "geometry/is_parallel.hpp"


    #include "geometry/is_intersect_ll.hpp"

    #include "geometry/is_intersect_lp.hpp"

    #include "geometry/is_intersect_ss.hpp"

    #include "geometry/is_intersect_sp.hpp"

    #include "geometry/tangent_number_cc.hpp"

    #include "geometry/is_intersect_cc.hpp"

    #include "geometry/is_intersect_cp.hpp"

    #include "geometry/is_intersect_cl.hpp"


    #include "geometry/cross_point_ll.hpp"

    #include "geometry/cross_point_ss.hpp"

    #include "geometry/cross_point_cl.hpp"

    #include "geometry/cross_point_cc.hpp"


    #include "geometry/distance_lp.hpp"

    #include "geometry/distance_sp.hpp"

    #include "geometry/distance_ss.hpp"


    #include "geometry/tangent_point_cp.hpp"

    #include "geometry/incircle.hpp"

    #include "geometry/circumscribed_circle.hpp"


    #include "geometry/polygon_area.hpp"

    #include "geometry/polygon_is_convex.hpp"

    #include "geometry/polygon_contain.hpp"

    #include "geometry/monotone_chain.hpp"

    #include "geometry/convex_polygon_diameter.hpp"

    #include "geometry/convex_polygon_cut.hpp"


    #include "geometry/closest_pair.hpp"

    #include "geometry/farthest_pair.hpp"

    '
  dependsOn:
  - geometry/point.hpp
  - geometry/line.hpp
  - geometry/segment.hpp
  - geometry/circle.hpp
  - geometry/polygon.hpp
  - geometry/projection.hpp
  - geometry/reflection.hpp
  - geometry/ccw.hpp
  - geometry/is_orthogonal.hpp
  - geometry/is_parallel.hpp
  - geometry/is_intersect_ll.hpp
  - geometry/is_intersect_lp.hpp
  - geometry/is_intersect_ss.hpp
  - geometry/is_intersect_sp.hpp
  - geometry/tangent_number_cc.hpp
  - geometry/is_intersect_cc.hpp
  - geometry/is_intersect_cp.hpp
  - geometry/is_intersect_cl.hpp
  - geometry/distance_lp.hpp
  - geometry/cross_point_ll.hpp
  - geometry/cross_point_ss.hpp
  - geometry/cross_point_cl.hpp
  - geometry/cross_point_cc.hpp
  - geometry/distance_sp.hpp
  - geometry/distance_ss.hpp
  - geometry/tangent_point_cp.hpp
  - geometry/incircle.hpp
  - geometry/circumscribed_circle.hpp
  - geometry/polygon_area.hpp
  - geometry/polygon_is_convex.hpp
  - geometry/polygon_contain.hpp
  - geometry/monotone_chain.hpp
  - geometry/convex_polygon_diameter.hpp
  - geometry/convex_polygon_cut.hpp
  - geometry/closest_pair.hpp
  - geometry/farthest_pair.hpp
  isVerificationFile: false
  path: geometry/all.hpp
  requiredBy: []
  timestamp: '2023-04-06 09:06:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/all.hpp
layout: document
redirect_from:
- /library/geometry/all.hpp
- /library/geometry/all.hpp.html
title: geometry/all.hpp
---
