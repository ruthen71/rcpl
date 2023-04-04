---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/ccw.hpp
    title: geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: geometry/circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circumscribed_circle.hpp
    title: geometry/circumscribed_circle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/closest_pair.hpp
    title: "\u6700\u8FD1\u70B9\u5BFE"
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_cut.hpp
    title: geometry/convex_polygon_cut.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_diameter.hpp
    title: geometry/convex_polygon_diameter.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cc.hpp
    title: geometry/cross_point_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_cl.hpp
    title: geometry/cross_point_cl.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ll.hpp
    title: geometry/cross_point_ll.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point_ss.hpp
    title: geometry/cross_point_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_lp.hpp
    title: geometry/distance_lp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_sp.hpp
    title: geometry/distance_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/distance_ss.hpp
    title: geometry/distance_ss.hpp
  - icon: ':warning:'
    path: geometry/farthest_pair.hpp
    title: "\u6700\u9060\u70B9\u5BFE"
  - icon: ':heavy_check_mark:'
    path: geometry/geometry_template.hpp
    title: geometry/geometry_template.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/incircle.hpp
    title: geometry/incircle.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_cc.hpp
    title: geometry/is_intersect_cc.hpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_sp.hpp
    title: geometry/is_intersect_sp.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect_ss.hpp
    title: geometry/is_intersect_ss.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_orthogonal.hpp
    title: geometry/is_orthogonal.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/is_parallel.hpp
    title: geometry/is_parallel.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: geometry/line.hpp
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
    path: geometry/polygon_area.hpp
    title: geometry/polygon_area.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_contain.hpp
    title: geometry/polygon_contain.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_is_convex.hpp
    title: geometry/polygon_is_convex.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/projection.hpp
    title: geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/reflection.hpp
    title: geometry/reflection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/segment.hpp
    title: geometry/segment.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_number_cc.hpp
    title: geometry/tangent_number_cc.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent_point_cp.hpp
    title: geometry/tangent_point_cp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/geometry_template.hpp\"\n\n// template\nusing Double\
    \ = double;\nconst Double EPS = 1e-8;\n// using Double = long double;\n// const\
    \ Double EPS = 1e-10;\n// using Double = long long;\n// const Double EPS = 0;\n\
    // using Double = __int128_t;\n// const Double EPS = 0;\nconst Double PI = std::acos(Double(-1));\n\
    inline int sign(const Double &x) { return x < -EPS ? -1 : (x > EPS ? 1 : 0); }\n\
    inline bool equal(const Double &a, const Double &b) { return sign(a - b) == 0;\
    \ }\ninline Double radian_to_degree(const Double &r) { return r * 180.0 / PI;\
    \ }\ninline Double degree_to_radian(const Double &d) { return d * PI / 180.0;\
    \ }\nconstexpr int IN = 2;\nconstexpr int ON = 1;\nconstexpr int OUT = 0;\n#line\
    \ 3 \"geometry/all.hpp\"\n\n#line 2 \"geometry/point.hpp\"\n\n#line 4 \"geometry/point.hpp\"\
    \n\n// point\nstruct Point {\n    Double x, y;\n    Point(const Double x = Double(0),\
    \ const Double y = Double(0)) : x(x), y(y) {}\n    Point &operator+=(const Point\
    \ &p) {\n        x += p.x;\n        y += p.y;\n        return *this;\n    }\n\
    \    Point &operator-=(const Point &p) {\n        x -= p.x;\n        y -= p.y;\n\
    \        return *this;\n    }\n    Point &operator*=(const Point &p) { return\
    \ *this = Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n    Point &operator*=(const\
    \ Double &k) {\n        x *= k;\n        y *= k;\n        return *this;\n    }\n\
    \    Point &operator/=(const Point &p) { return *this = Point(x * p.x + y * p.y,\
    \ -x * p.y + y * p.x) / (p.x * p.x + p.y * p.y); }\n    Point &operator/=(const\
    \ Double &k) {\n        x /= k;\n        y /= k;\n        return *this;\n    }\n\
    \n    Point operator+() const { return *this; }\n    Point operator-() const {\
    \ return Point(-x, -y); }\n\n    friend Point operator+(const Point &a, const\
    \ Point &b) { return Point(a) += b; }\n    friend Point operator-(const Point\
    \ &a, const Point &b) { return Point(a) -= b; }\n    friend Point operator*(const\
    \ Point &a, const Point &b) { return Point(a) *= b; }\n    friend Point operator*(const\
    \ Point &p, const Double &k) { return Point(p) *= k; }\n    friend Point operator/(const\
    \ Point &a, const Point &b) { return Point(a) /= b; }\n    friend Point operator/(const\
    \ Point &p, const Double &k) { return Point(p) /= k; }\n    // for std::set, std::map,\
    \ compare_arg, ...\n    friend bool operator<(const Point &a, const Point &b)\
    \ { return a.x == b.x ? a.y < b.y : a.x < b.x; }\n};\n\n// using Point = std::complex<Double>;\n\
    std::istream &operator>>(std::istream &is, Point &p) { return is >> p.x >> p.y;\
    \ }\nstd::ostream &operator<<(std::ostream &os, const Point &p) { return os <<\
    \ std::fixed << std::setprecision(15) << p.x << ' ' << p.y; }\n\n// equal (point\
    \ and point)\ninline bool equal(const Point &a, const Point &b) { return equal(a.x,\
    \ b.x) and equal(a.y, b.y); }\n// inner product\ninline Double dot(const Point\
    \ &a, const Point &b) { return a.x * b.x + a.y * b.y; }\n// outer product\ninline\
    \ Double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x;\
    \ }\n// rotate Point p counterclockwise by theta radian\ninline Point rotate(const\
    \ Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }\n\
    // compare (x, y)\ninline bool compare_x(const Point &a, const Point &b) { return\
    \ equal(a.x, b.x) ? sign(a.y - b.y) < 0 : sign(a.x - b.x) < 0; }\n// compare (y,\
    \ x)\ninline bool compare_y(const Point &a, const Point &b) { return equal(a.y,\
    \ b.y) ? sign(a.x - b.x) < 0 : sign(a.y - b.y) < 0; }\n// compare by arg (start\
    \ from 90.0000000001~)\ninline bool compare_arg(const Point &a, const Point &b)\
    \ {\n    // https://ngtkana.hatenablog.com/entry/2021/11/13/202103\n    return\
    \ (Point(0, 0) < a) == (Point(0, 0) < b) ? a.x * b.y > a.y * b.x : a < b;\n}\n\
    // |p| ^ 2\ninline Double norm(const Point &p) { return p.x * p.x + p.y * p.y;\
    \ }\n// |p|\ninline Double abs(const Point &p) { return sqrt(norm(p)); }\n// arg\n\
    inline Double arg(const Point &p) { return std::atan2(p.y, p.x); }\n// polar\n\
    inline Point polar(const Double &rho, const Double &theta = Double(0)) { return\
    \ rotate(Point(rho, 0), theta); }\n#line 2 \"geometry/line.hpp\"\n\n#line 4 \"\
    geometry/line.hpp\"\n\n// line\nstruct Line {\n    Point a, b;\n\n    Line() =\
    \ default;\n\n    Line(const Point &a, const Point &b) : a(a), b(b) {}\n\n   \
    \ // Ax + By = C\n    Line(const Double &A, const Double &B, const Double &C)\
    \ {\n        assert(equal(A, 0) and equal(B, 0));\n        if (equal(A, 0)) {\n\
    \            a = Point(0, C / B), b = Point(1, C / B);\n        } else if (equal(B,\
    \ 0)) {\n            a = Point(C / A, 0), b = Point(C / A, 1);\n        } else\
    \ if (equal(C, 0)) {\n            a = Point(0, 0), b = Point(1, B / A);\n    \
    \    } else {\n            a = Point(0, C / B), b = Point(C / A, 0);\n       \
    \ }\n    }\n\n    friend std::istream &operator>>(std::istream &is, Line &p) {\
    \ return is >> p.a >> p.b; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &p) { return os << p.a << \"->\" << p.b; }\n};\n#line 2 \"geometry/segment.hpp\"\
    \n\n#line 4 \"geometry/segment.hpp\"\n\n// segment\nstruct Segment : Line {\n\
    \    Segment() = default;\n\n    Segment(const Point &a, const Point &b) : Line(a,\
    \ b) {}\n};\n#line 2 \"geometry/circle.hpp\"\n\n#line 4 \"geometry/circle.hpp\"\
    \n\n// circle\nstruct Circle {\n    Point o;\n    Double r;\n\n    Circle() =\
    \ default;\n\n    Circle(const Point &o, const Double &r) : o(o), r(r) {}\n\n\
    \    friend std::ostream &operator<<(std::ostream &os, const Circle &c) { return\
    \ os << c.o << ' ' << c.r; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Circle &c) { return is >> c.o >> c.r; }  // format : x y r\n};\n#line 2\
    \ \"geometry/polygon.hpp\"\n\n#line 4 \"geometry/polygon.hpp\"\n\n// polygon\n\
    using Polygon = std::vector<Point>;\nstd::istream &operator>>(std::istream &is,\
    \ Polygon &p) {\n    for (auto &&pi : p) is >> pi;\n    return is;\n}\nstd::ostream\
    \ &operator<<(std::ostream &os, const Polygon &p) {\n    for (auto &&pi : p) os\
    \ << pi << \" -> \";\n    return os;\n}\n#line 9 \"geometry/all.hpp\"\n\n#line\
    \ 2 \"geometry/projection.hpp\"\n\n#line 5 \"geometry/projection.hpp\"\n\n// projection\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A\nPoint projection(const\
    \ Line &l, const Point &p) {\n    Double t = dot(p - l.a, l.b - l.a) / norm(l.b\
    \ - l.a);\n    return l.a + t * (l.b - l.a);\n}\n#line 2 \"geometry/reflection.hpp\"\
    \n\n#line 6 \"geometry/reflection.hpp\"\n\n// reflection\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\n\
    Point reflection(const Line &l, const Point &p) { return p + (projection(l, p)\
    \ - p) * Double(2); }\n#line 2 \"geometry/ccw.hpp\"\n\n#line 4 \"geometry/ccw.hpp\"\
    \n\n// counter clockwise\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\n\
    constexpr int COUNTER_CLOCKWISE = 1;  // a-b-c counter clockwise\nconstexpr int\
    \ CLOCKWISE = -1;         // a-b-c clockwise\nconstexpr int ONLINE_BACK = 2; \
    \       // c-a-b line\nconstexpr int ONLINE_FRONT = -2;      // a-b-c line\nconstexpr\
    \ int ON_SEGMENT = 0;         // a-c-b line\nint ccw(const Point &a, Point b,\
    \ Point c) {\n    b = b - a, c = c - a;\n    if (sign(cross(b, c)) == 1) return\
    \ COUNTER_CLOCKWISE;\n    if (sign(cross(b, c)) == -1) return CLOCKWISE;\n   \
    \ if (sign(dot(b, c)) == -1) return ONLINE_BACK;\n    if (norm(b) < norm(c)) return\
    \ ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n#line 2 \"geometry/is_orthogonal.hpp\"\
    \n\n#line 4 \"geometry/is_orthogonal.hpp\"\n\n// orthogonal\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    inline bool is_orthogonal(const Line &l1, const Line &l2) { return sign(dot(l1.b\
    \ - l1.a, l2.b - l2.a)) == 0; }\n#line 2 \"geometry/is_parallel.hpp\"\n\n#line\
    \ 4 \"geometry/is_parallel.hpp\"\n\n// parallel\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A\n\
    inline bool is_parallel(const Line &l1, const Line &l2) { return sign(cross(l1.b\
    \ - l1.a, l2.b - l2.a)) == 0; }\n#line 15 \"geometry/all.hpp\"\n\n#line 2 \"geometry/is_intersect_ll.hpp\"\
    \n\n#line 4 \"geometry/is_intersect_ll.hpp\"\n\n// intersection (line and line)\n\
    bool is_intersect_ll(const Line &l1, const Line &l2) {\n    Point base = l1.b\
    \ - l1.a;\n    Double d12 = cross(base, l2.b - l2.a);\n    Double d1 = cross(base,\
    \ l1.b - l2.a);\n    if (sign(d12) == 0) {\n        // parallel\n        if (sign(d1)\
    \ == 0) {\n            // cross\n            return true;\n        } else {\n\
    \            // not cross\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n#line 2 \"geometry/is_intersect_lp.hpp\"\n\n#line 5 \"geometry/is_intersect_lp.hpp\"\
    \n\n// intersection (line and point)\n// ccw(a, b, c) == ON_SEGMENT or ONLINE_BACK\
    \ or ONLINE_FRONT\ninline bool is_intersect_lp(const Line &l, const Point &p)\
    \ {\n    int res = ccw(l.a, l.b, p);\n    return (res == ONLINE_BACK or res ==\
    \ ONLINE_FRONT or res == ON_SEGMENT);\n}\n#line 2 \"geometry/is_intersect_ss.hpp\"\
    \n\n#line 5 \"geometry/is_intersect_ss.hpp\"\n\n// intersection (segment and segment)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\ninline bool\
    \ is_intersect_ss(const Segment &s1, const Segment &s2) { return (ccw(s1.a, s1.b,\
    \ s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 and ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b,\
    \ s1.b) <= 0); }\n#line 2 \"geometry/is_intersect_sp.hpp\"\n\n#line 5 \"geometry/is_intersect_sp.hpp\"\
    \n\n// intersection (segment and point)\n// ccw(a, b, c) == ON_SEGMENT -> a -\
    \ c - b\ninline bool is_intersect_sp(const Segment &s, const Point &p) { return\
    \ ccw(s.a, s.b, p) == ON_SEGMENT or sign(norm(s.a - p)) == 0 or sign(norm(s.b\
    \ - p)) == 0; }\n#line 3 \"geometry/tangent_number_cc.hpp\"\n\n// return the number\
    \ of tangent\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\n\
    int tangent_number_cc(Circle c1, Circle c2) {\n    if (c1.r < c2.r) std::swap(c1,\
    \ c2);\n    const Double d2 = norm(c1.o - c2.o);\n    if (sign(d2 - (c1.r + c2.r)\
    \ * (c1.r + c2.r)) == 1) return 4;  // d > c1.r + c2.r and c1.r + c2.r >= 0 <=>\
    \ d * d > (c1.r + c2.r) * (c1.r + c2.r)\n    if (sign(d2 - (c1.r + c2.r) * (c1.r\
    \ + c2.r)) == 0) return 3;  // d = c1.r + c2.r and c1.r + c2.r >= 0 <=> d * d\
    \ = (c1.r + c2.r) * (c1.r + c2.r)\n    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r))\
    \ == 1) return 2;  // d > c1.r - c2.r and c1.r - c2.r >= 0 <=> d * d > (c1.r -\
    \ c2.r) * (c1.r - c2.r)\n    if (sign(d2 - (c1.r - c2.r) * (c1.r - c2.r)) == 0)\
    \ return 1;  // d = c1.r - c2.r and c1.r - c2.r >= 0 <=> d * d = (c1.r - c2.r)\
    \ * (c1.r - c2.r)\n    return 0;\n}\n#line 2 \"geometry/is_intersect_cc.hpp\"\n\
    \n#line 5 \"geometry/is_intersect_cc.hpp\"\n\n// intersection (circle and circle)\n\
    // intersect = number of tangent is 1, 2, 3\ninline bool is_intersect_cc(const\
    \ Circle &c1, const Circle &c2) {\n    int num = tangent_number_cc(c1, c2);\n\
    \    return 1 <= num and num <= 3;\n}\n#line 2 \"geometry/is_intersect_cp.hpp\"\
    \n\n#line 5 \"geometry/is_intersect_cp.hpp\"\n// intersection (circle and point)\n\
    inline bool is_intersect_cp(const Circle &c, const Point &p) { return equal(norm(p\
    \ - c.o), c.r * c.r); }\n#line 2 \"geometry/is_intersect_cl.hpp\"\n\n#line 2 \"\
    geometry/distance_lp.hpp\"\n\n#line 6 \"geometry/distance_lp.hpp\"\n\n// distance\
    \ (line and point) (Double = double or long)\nDouble distance_lp(const Line &l,\
    \ const Point &p) { return abs(p - projection(l, p)); }\nDouble distance2_lp(const\
    \ Line &l, const Point &p) { return norm(p - projection(l, p)); }\n#line 5 \"\
    geometry/is_intersect_cl.hpp\"\n\n// intersection (circle and line)\ninline bool\
    \ is_intersect_cl(const Circle &c, const Line &l) { return sign(c.r * c.r - distance2_lp(l,\
    \ c.o)) >= 0; }\n#line 24 \"geometry/all.hpp\"\n\n#line 2 \"geometry/cross_point_ll.hpp\"\
    \n\n#line 4 \"geometry/cross_point_ll.hpp\"\n\n// cross point (line and line)\n\
    Point cross_point_ll(const Line &l1, const Line &l2) {\n    Point base = l1.b\
    \ - l1.a;\n    Double d12 = cross(base, l2.b - l2.a);\n    Double d1 = cross(base,\
    \ l1.b - l2.a);\n    if (sign(d12) == 0) {\n        // parallel\n        if (sign(d1)\
    \ == 0) {\n            // cross\n            return l2.a;\n        } else {\n\
    \            // not cross\n            assert(false);\n        }\n    }\n    return\
    \ l2.a + (l2.b - l2.a) * (d1 / d12);\n}\n#line 2 \"geometry/cross_point_ss.hpp\"\
    \n\n#line 6 \"geometry/cross_point_ss.hpp\"\n\n// cross point (segment and segment)\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\nPoint cross_point_ss(const\
    \ Segment &s1, const Segment &s2) {\n    // check intersection s1 and s2\n   \
    \ assert(is_intersect_ss(s1, s2));\n    Point base = s1.b - s1.a;\n    Double\
    \ d12 = cross(base, s2.b - s2.a);\n    Double d1 = cross(base, s1.b - s2.a);\n\
    \    if (sign(d12) == 0) {\n        // parallel\n        if (sign(d1) == 0) {\n\
    \            // equal\n            if (is_intersect_sp(s1, s2.a)) return s2.a;\n\
    \            if (is_intersect_sp(s1, s2.b)) return s2.b;\n            if (is_intersect_sp(s2,\
    \ s1.a)) return s1.a;\n            assert(is_intersect_sp(s2, s1.b));\n      \
    \      return s1.b;\n        } else {\n            // excepted by is_intersect_ss(s1,\
    \ s2)\n            assert(0);\n        }\n    }\n    return s2.a + (s2.b - s2.a)\
    \ * (d1 / d12);\n}\n#line 2 \"geometry/cross_point_cl.hpp\"\n\n#line 5 \"geometry/cross_point_cl.hpp\"\
    \n\n// cross point (circle and line)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\n\
    std::vector<Point> cross_point_cl(const Circle &c, const Line &l) {\n    assert(is_intersect_cl(c,\
    \ l));\n    auto pr = projection(l, c.o);\n    if (equal(norm(pr - c.o), c.r *\
    \ c.r)) return {pr};\n    Point e = (l.b - l.a) * (Double(1) / abs(l.b - l.a));\n\
    \    auto k = sqrt(norm(c.r) - norm(pr - c.o));\n    return {pr - e * k, pr +\
    \ e * k};\n}\n#line 2 \"geometry/cross_point_cc.hpp\"\n\n#line 4 \"geometry/cross_point_cc.hpp\"\
    \n\n// cross point (circle and circle)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\n\
    std::vector<Point> cross_point_cc(const Circle &c1, const Circle &c2) {\n    if\
    \ (!is_intersect_cc(c1, c2)) return {};\n    Double d = abs(c1.o - c2.o);\n  \
    \  Double a = std::acos((norm(c1.r) - norm(c2.r) + norm(d)) / (Double(2) * c1.r\
    \ * d));\n    Double t = arg(c2.o - c1.o);\n    Point p = c1.o + polar(c1.r, t\
    \ + a);\n    Point q = c1.o + polar(c1.r, t - a);\n    if (equal(p.x, q.x) and\
    \ equal(p.y, q.y)) return {p};\n    return {p, q};\n}\n#line 29 \"geometry/all.hpp\"\
    \n\n#line 2 \"geometry/distance_sp.hpp\"\n\n#line 7 \"geometry/distance_sp.hpp\"\
    \n\n// distance (segment and point)\nDouble distance_sp(const Segment &s, const\
    \ Point &p) {\n    Point r = projection(s, p);\n    if (is_intersect_sp(s, r))\
    \ {\n        return abs(r - p);\n    }\n    return std::min(abs(s.a - p), abs(s.b\
    \ - p));\n}\n#line 2 \"geometry/distance_ss.hpp\"\n\n#line 6 \"geometry/distance_ss.hpp\"\
    \n\n// distance (segment and segment)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\n\
    Double distance_ss(const Segment &s1, const Segment &s2) {\n    if (is_intersect_ss(s1,\
    \ s2)) return Double(0);\n    return std::min({distance_sp(s1, s2.a), distance_sp(s1,\
    \ s2.b), distance_sp(s2, s1.a), distance_sp(s2, s1.b)});\n}\n#line 33 \"geometry/all.hpp\"\
    \n\n#line 2 \"geometry/tangent_point_cp.hpp\"\n\n#line 4 \"geometry/tangent_point_cp.hpp\"\
    \n\n// tangent point (circle and point)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F\n\
    std::pair<Point, Point> tangent_point_cp(const Circle &c, const Point &p) {\n\
    \    assert(sign(abs(c.o - p) - c.r) == 1);\n    auto res = cross_point_cc(c,\
    \ Circle(p, sqrt(norm(c.o - p) - norm(c.r))));\n    return {res[0], res[1]};\n\
    }\n#line 2 \"geometry/incircle.hpp\"\n\n#line 6 \"geometry/incircle.hpp\"\n\n\
    // incircle of a triangle\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B\n\
    // https://drken1215.hatenablog.com/entry/2020/10/16/073700\nCircle incircle(const\
    \ Point &a, const Point &b, const Point &c) {\n    Double A = arg((c - a) / (b\
    \ - a)), B = arg((a - b) / (c - b));\n    Line l1(a, a + rotate(b - a, A / 2)),\
    \ l2(b, b + rotate(c - b, B / 2));\n    auto o = cross_point_ll(l1, l2);\n   \
    \ auto r = distance_lp(Line(a, b), o);\n    return Circle(o, r);\n}\n#line 2 \"\
    geometry/circumscribed_circle.hpp\"\n\n#line 5 \"geometry/circumscribed_circle.hpp\"\
    \n\n// circumscribed circle of a triangle\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C\n\
    // https://drken1215.hatenablog.com/entry/2020/10/16/074400\nCircle circumscribed_circle(const\
    \ Point &a, const Point &b, const Point &c) {\n    Line l1((a + b) / 2, (a + b)\
    \ / 2 + rotate(b - a, PI / 2)), l2((b + c) / 2, (b + c) / 2 + rotate(c - b, PI\
    \ / 2));\n    auto o = cross_point_ll(l1, l2);\n    auto r = abs(o - a);\n   \
    \ return Circle(o, r);\n}\n#line 37 \"geometry/all.hpp\"\n\n#line 2 \"geometry/polygon_area.hpp\"\
    \n\n#line 4 \"geometry/polygon_area.hpp\"\n\n// area of polygon\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\n\
    // return area * 2\nDouble polygon_area2(const Polygon &p) {\n    int n = (int)p.size();\n\
    \    assert(n >= 2);\n    Double ret = Double(0);\n    for (int i = 0; i < n -\
    \ 1; i++) {\n        ret += cross(p[i], p[i + 1]);\n    }\n    ret += cross(p[n\
    \ - 1], p[0]);\n    // counter clockwise: ret > 0\n    // clockwise: ret < 0\n\
    \    return std::abs(ret);\n}\nDouble polygon_area(const Polygon &p) { return\
    \ polygon_area2(p) / Double(2); }\n#line 2 \"geometry/polygon_is_convex.hpp\"\n\
    \n#line 5 \"geometry/polygon_is_convex.hpp\"\n\n// check polygon is convex (not\
    \ strictly, 0 <= angle <= 180 degrees)\n// angle = 180 degrees -> ON_SEGMENT\n\
    // angle = 0 degrees -> ONLINE_FRONT or ONLINE_BACK\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B\n\
    bool polygon_is_convex(const Polygon &p) {\n    int n = (int)p.size();\n    assert(n\
    \ >= 3);\n    bool okccw = true, okcw = true;\n    for (int i = 0; i < n - 2;\
    \ i++) {\n        int res = ccw(p[i], p[i + 1], p[i + 2]);\n        if (res ==\
    \ CLOCKWISE) okccw = false;\n        if (res == COUNTER_CLOCKWISE) okcw = false;\n\
    \        if (!okccw and !okcw) return false;\n    }\n    {\n        int res =\
    \ ccw(p[n - 2], p[n - 1], p[0]);\n        if (res == CLOCKWISE) okccw = false;\n\
    \        if (res == COUNTER_CLOCKWISE) okcw = false;\n        if (!okccw and !okcw)\
    \ return false;\n    }\n    {\n        int res = ccw(p[n - 1], p[0], p[1]);\n\
    \        if (res == CLOCKWISE) okccw = false;\n        if (res == COUNTER_CLOCKWISE)\
    \ okcw = false;\n        if (!okccw and !okcw) return false;\n    }\n    return\
    \ true;\n}\n#line 2 \"geometry/polygon_contain.hpp\"\n\n#line 5 \"geometry/polygon_contain.hpp\"\
    \n\n// polygon contain point -> 2 (IN)\n// polygon cross point -> 1 (ON)\n// otherwise\
    \ -> 0 (OUT)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C\n\
    int polygon_contain(const Polygon &q, const Point &p) {\n    bool x = false;\n\
    \    int n = (int)q.size();\n    for (int i = 0; i < n - 1; i++) {\n        if\
    \ (is_intersect_sp(Segment(q[i], q[i + 1]), p)) return ON;\n        Point a =\
    \ q[i] - p, b = q[i + 1] - p;\n        if (a.y > b.y) std::swap(a, b);\n     \
    \   // a.y < b.y\n        // check each point's y is 0 at most 1 times\n     \
    \   if (sign(a.y) <= 0 and sign(b.y) > 0 and sign(cross(a, b)) > 0) x = !x;\n\
    \    }\n    {\n        if (is_intersect_sp(Segment(q[n - 1], q[0]), p)) return\
    \ ON;\n        Point a = q[n - 1] - p, b = q[0] - p;\n        if (a.y > b.y) std::swap(a,\
    \ b);\n        if (sign(a.y) <= 0 and sign(b.y) > 0 and sign(cross(a, b)) > 0)\
    \ x = !x;\n    }\n    return (x ? IN : OUT);\n}\n#line 2 \"geometry/monotone_chain.hpp\"\
    \n\n#line 5 \"geometry/monotone_chain.hpp\"\n\n// convex hull (Andrew's monotone\
    \ chain convex hull algorithm)\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    // sort (x, y) by lexicographical order, use stack, calculate upper convex hull\
    \ and lower convex hull\n// counter clockwise order\n// assume the return value\
    \ of ccw is not ONLINE_BACK or ONLINE_FRONT (lexicographical order)\n// strict\
    \ is true : points on the edges of the convex hull are not included (the number\
    \ of points is minimized)\n// complexity: O(n \\log n) (n: the number of points)\n\
    Polygon monotone_chain(std::vector<Point> &p, bool strict = true) {\n    int n\
    \ = (int)p.size();\n    if (n <= 2) return p;\n    std::sort(p.begin(), p.end(),\
    \ compare_x);\n    Polygon r;\n    r.reserve(n * 2);\n    if (strict) {\n    \
    \    for (int i = 0; i < n; i++) {\n            while (r.size() >= 2 and ccw(r[r.size()\
    \ - 2], r[r.size() - 1], p[i]) != CLOCKWISE) {\n                r.pop_back();\n\
    \            }\n            r.push_back(p[i]);\n        }\n        int t = r.size()\
    \ + 1;\n        for (int i = n - 2; i >= 0; i--) {\n            while (r.size()\
    \ >= t and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) != CLOCKWISE) {\n     \
    \           r.pop_back();\n            }\n            r.push_back(p[i]);\n   \
    \     }\n    } else {\n        for (int i = 0; i < n; i++) {\n            while\
    \ (r.size() >= 2 and ccw(r[r.size() - 2], r[r.size() - 1], p[i]) == COUNTER_CLOCKWISE)\
    \ {\n                r.pop_back();\n            }\n            r.push_back(p[i]);\n\
    \        }\n        int t = r.size() + 1;\n        for (int i = n - 2; i >= 0;\
    \ i--) {\n            while (r.size() >= t and ccw(r[r.size() - 2], r[r.size()\
    \ - 1], p[i]) == COUNTER_CLOCKWISE) {\n                r.pop_back();\n       \
    \     }\n            r.push_back(p[i]);\n        }\n    }\n    r.pop_back();\n\
    \    std::reverse(r.begin(), r.end());\n    return r;\n}\n#line 2 \"geometry/convex_polygon_diameter.hpp\"\
    \n\n#line 5 \"geometry/convex_polygon_diameter.hpp\"\n\n// convex polygon diameter\n\
    // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\n// return\
    \ {index1, index2, diameter}\n// using the method of rotating calipers (https://en.wikipedia.org/wiki/Rotating_calipers)\n\
    // complexity: O(n)\nstd::tuple<int, int, Double> convex_polygon_diameter(const\
    \ Polygon &p) {\n    assert(polygon_is_convex(p));\n    int n = (int)p.size();\n\
    \    assert(n >= 2);\n    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n\
    \    }\n    auto [it_min, it_max] = std::minmax_element(p.begin(), p.end(), compare_x);\n\
    \    int idx_min = it_min - p.begin();\n    int idx_max = it_max - p.begin();\n\
    \n    Double maxdis = norm(p[idx_max] - p[idx_min]);\n    int maxi = idx_min,\
    \ i = idx_min, maxj = idx_max, j = idx_max;\n    do {\n        int ni = (i + 1\
    \ == n ? 0 : i + 1), nj = (j + 1 == n ? 0 : j + 1);\n        if (sign(cross(p[ni]\
    \ - p[i], p[nj] - p[j])) < 0) {\n            i = ni;\n        } else {\n     \
    \       j = nj;\n        }\n        if (norm(p[i] - p[j]) > maxdis) {\n      \
    \      maxdis = norm(p[i] - p[j]);\n            maxi = i;\n            maxj =\
    \ j;\n        }\n    } while (i != idx_min || j != idx_max);\n    return {maxi,\
    \ maxj, abs(p[maxi] - p[maxj])};\n}\n#line 2 \"geometry/convex_polygon_cut.hpp\"\
    \n\n#line 5 \"geometry/convex_polygon_cut.hpp\"\n\n// cut convex polygon p by\
    \ line l\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\n\
    // return {left polygon, right polygon}\n// whether each point is included is\
    \ determined by the sign of the outer product of the two vectors to the endpoints\
    \ of the line\nstd::pair<Polygon, Polygon> convex_polygon_cut(const Polygon &p,\
    \ const Line &l) {\n    int n = (int)p.size();\n    assert(n >= 3);\n    Polygon\
    \ pl, pr;\n    for (int i = 0; i < n - 1; i++) {\n        int s1 = sign(cross(l.a\
    \ - p[i], l.b - p[i]));\n        int s2 = sign(cross(l.a - p[i + 1], l.b - p[i\
    \ + 1]));\n        if (s1 >= 0) {\n            pl.push_back(p[i]);\n        }\n\
    \        if (s1 <= 0) {\n            pr.push_back(p[i]);\n        }\n        if\
    \ (s1 * s2 < 0) {\n            // don't use \"<=\", use \"<\" to exclude endpoints\n\
    \            auto pc = cross_point_ll(Line(p[i], p[i + 1]), l);\n            pl.push_back(pc);\n\
    \            pr.push_back(pc);\n        }\n    }\n    {\n        int s1 = sign(cross(l.a\
    \ - p[n - 1], l.b - p[n - 1]));\n        int s2 = sign(cross(l.a - p[0], l.b -\
    \ p[0]));\n        if (s1 >= 0) {\n            pl.push_back(p[n - 1]);\n     \
    \   }\n        if (s1 <= 0) {\n            pr.push_back(p[n - 1]);\n        }\n\
    \        if (s1 * s2 < 0) {\n            // don't use \"<=\", use \"<\" to exclude\
    \ endpoints\n            auto pc = cross_point_ll(Line(p[n - 1], p[0]), l);\n\
    \            pl.push_back(pc);\n            pr.push_back(pc);\n        }\n   \
    \ }\n    return {pl, pr};\n}\n#line 44 \"geometry/all.hpp\"\n\n#line 2 \"geometry/closest_pair.hpp\"\
    \n\n#line 4 \"geometry/closest_pair.hpp\"\n\n// closest pair\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\n\
    // return {index1, index2, distance}\n// using divide-and-conquer algorithm\n\
    // complexity: O(n \\log n) (n: the number of points)\nstd::tuple<int, int, Double>\
    \ closest_pair(const std::vector<Point> &p) {\n    int n = int(p.size());\n  \
    \  assert(n >= 2);\n    if (n == 2) {\n        return {0, 1, abs(p[0] - p[1])};\n\
    \    }\n    // may not be efficient due to indirect references ...\n    std::vector<int>\
    \ ind(n);\n    std::iota(ind.begin(), ind.end(), 0);\n    std::sort(ind.begin(),\
    \ ind.end(), [&](int i, int j) { return compare_x(p[i], p[j]); });\n    auto divide_and_conquer\
    \ = [&](auto f, int l, int r) -> std::tuple<int, int, Double> {\n        if (r\
    \ - l <= 1) return {-1, -1, std::numeric_limits<Double>::max()};\n        int\
    \ md = (l + r) / 2;\n        Double x = p[ind[md]].x;\n        // divide and conquer\n\
    \        auto [i1l, i2l, dl] = f(f, l, md);\n        auto [i1r, i2r, dr] = f(f,\
    \ md, r);\n        int i1, i2;\n        Double d;\n        if (dl < dr) {\n  \
    \          d = dl, i1 = i1l, i2 = i2l;\n        } else {\n            d = dr,\
    \ i1 = i1r, i2 = i2r;\n        }\n        std::inplace_merge(ind.begin() + l,\
    \ ind.begin() + md, ind.begin() + r, [&](int i, int j) { return compare_y(p[i],\
    \ p[j]); });\n        // ind are sorted by y\n        std::vector<int> near_x;\
    \  // index of vertices whose distance from the line x is less than d\n      \
    \  for (int i = l; i < r; i++) {\n            if (sign(std::abs(p[ind[i]].x -\
    \ x) - d) >= 0) continue;  // std::abs(p[ind[i]].x - x) >= d\n            int\
    \ sz = int(near_x.size());\n            // iterate from the end until the distance\
    \ in y-coordinates is greater than or equal to d\n            for (int j = sz\
    \ - 1; j >= 0; j--) {\n                Point cp = p[ind[i]] - p[near_x[j]];\n\
    \                if (sign(cp.y - d) >= 0) break;  // cp.y >= d\n             \
    \   Double cd = abs(cp);\n                if (cd < d) {\n                    d\
    \ = cd, i1 = ind[i], i2 = near_x[j];\n                }\n            }\n     \
    \       near_x.push_back(ind[i]);\n        }\n        return {i1, i2, d};\n  \
    \  };\n    return divide_and_conquer(divide_and_conquer, 0, n);\n}\n#line 2 \"\
    geometry/farthest_pair.hpp\"\n\n#line 5 \"geometry/farthest_pair.hpp\"\n\n// farthest\
    \ pair\n// return {index1, index2, distance}\n// using monotone chain (convex\
    \ hull) and convex polygon diameter\n// complexity: O(n \\log n) (n: the number\
    \ of points)\nstd::tuple<int, int, Double> farthest_pair(const std::vector<Point>\
    \ &p) {\n    int n = int(p.size());\n    assert(n >= 2);\n    if (n == 2) {\n\
    \        return {0, 1, std::abs(p[0] - p[1])};\n    }\n    auto q = p;\n    auto\
    \ ch = monotone_chain(q);                   // O(n \\log n)\n    auto [i, j, d]\
    \ = convex_polygon_diameter(ch);  // O(|ch|)\n    int resi, resj;\n    for (int\
    \ k = 0; k < n; k++) {\n        if (p[k] == ch[i]) {\n            resi = k;\n\
    \        }\n        if (p[k] == ch[j]) {\n            resj = k;\n        }\n \
    \   }\n    return {resi, resj, d};\n}\n#line 47 \"geometry/all.hpp\"\n"
  code: '#pragma once

    #include "geometry/geometry_template.hpp"


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
  - geometry/geometry_template.hpp
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
  timestamp: '2023-04-04 19:34:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/all.hpp
layout: document
redirect_from:
- /library/geometry/all.hpp
- /library/geometry/all.hpp.html
title: geometry/all.hpp
---
