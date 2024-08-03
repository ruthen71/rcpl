---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/all.hpp
    title: geometry/all.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/circle.hpp
    title: "Circle (\u5186)"
  - icon: ':heavy_check_mark:'
    path: geometry/circumscribed_circle.hpp
    title: "Circumscribed Circle (\u5916\u63A5\u5186)"
  - icon: ':heavy_check_mark:'
    path: geometry/closest_pair.hpp
    title: "Closest Pair (\u6700\u8FD1\u70B9\u5BFE)"
  - icon: ':question:'
    path: geometry/convex_hull_monotone_chain.hpp
    title: "Convex Hull (\u51F8\u5305)"
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_cut.hpp
    title: "Convex Polygon Cut (\u51F8\u591A\u89D2\u5F62\u306E\u76F4\u7DDA\u3067\u306E\
      \u5207\u65AD)"
  - icon: ':heavy_check_mark:'
    path: geometry/convex_polygon_diameter.hpp
    title: "Convex Polygon Diameter (\u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84)"
  - icon: ':heavy_check_mark:'
    path: geometry/cross_point.hpp
    title: "Cross Point (\u4EA4\u70B9)"
  - icon: ':heavy_check_mark:'
    path: geometry/distance.hpp
    title: "Distance (\u8DDD\u96E2)"
  - icon: ':warning:'
    path: geometry/farthest_pair.hpp
    title: "Farthest Pair (\u6700\u9060\u70B9\u5BFE)"
  - icon: ':heavy_check_mark:'
    path: geometry/incircle.hpp
    title: "Incircle (\u5185\u63A5\u5186)"
  - icon: ':heavy_check_mark:'
    path: geometry/is_intersect.hpp
    title: "Intersection (\u4EA4\u5DEE\u5224\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: geometry/line.hpp
    title: "Line / Segment (\u76F4\u7DDA\u30FB\u7DDA\u5206)"
  - icon: ':question:'
    path: geometry/point.hpp
    title: "Point (\u70B9)"
  - icon: ':question:'
    path: geometry/polygon.hpp
    title: "Polygon (\u591A\u89D2\u5F62)"
  - icon: ':heavy_check_mark:'
    path: geometry/polygon_contain.hpp
    title: "Polygon Contain (\u591A\u89D2\u5F62\u3068\u70B9\u306E\u4EA4\u5DEE\u5224\
      \u5B9A)"
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: "Tangent (\u63A5\u7DDA)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/geometry/ccw.test.cpp
    title: verify/geometry/ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/circumscribed_circle.test.cpp
    title: verify/geometry/circumscribed_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/closest_pair.test.cpp
    title: verify/geometry/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/compare_atan2.test.cpp
    title: verify/geometry/compare_atan2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/convex_hull_monotone_chain_1.test.cpp
    title: verify/geometry/convex_hull_monotone_chain_1.test.cpp
  - icon: ':x:'
    path: verify/geometry/convex_hull_monotone_chain_2.test.cpp
    title: verify/geometry/convex_hull_monotone_chain_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/convex_polygon_cut.test.cpp
    title: verify/geometry/convex_polygon_cut.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/convex_polygon_diameter.test.cpp
    title: verify/geometry/convex_polygon_diameter.test.cpp
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
    path: verify/geometry/polygon_area.test.cpp
    title: verify/geometry/polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/polygon_contain.test.cpp
    title: verify/geometry/polygon_contain.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/geometry/polygon_is_convex.test.cpp
    title: verify/geometry/polygon_is_convex.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: verify/geometry/tangent_number.test.cpp
    title: verify/geometry/tangent_number.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/geometry_template.hpp\"\n\n#include <type_traits>\n\
    \n// Constants (EPS, PI)\n// EPS \u306E\u5909\u66F4\u306F Constants<T>::set_eps(new_eps)\
    \ \u3067\ntemplate <class T> struct Constants {\n    static T EPS;\n    static\
    \ void set_eps(const T e) { EPS = e; }\n    static constexpr T PI = 3.14159'26535'89793L;\n\
    };\n\ntemplate <> double Constants<double>::EPS = 1e-9;\ntemplate <> long double\
    \ Constants<long double>::EPS = 1e-12;\ntemplate <> long long Constants<long long>::EPS\
    \ = 0;\n\n// \u6C4E\u7528\u95A2\u6570\ntemplate <class T> inline int sign(const\
    \ T x) { return x < -Constants<T>::EPS ? -1 : (x > Constants<T>::EPS ? 1 : 0);\
    \ }\ntemplate <class T> inline bool equal(const T a, const T b) { return sign(a\
    \ - b) == 0; }\ntemplate <class T> inline T radian_to_degree(const T r) { return\
    \ r * 180.0 / Constants<T>::PI; }\ntemplate <class T> inline T degree_to_radian(const\
    \ T d) { return d * Constants<T>::PI / 180.0; }\n\n// type traits\ntemplate <class\
    \ T> using is_geometry_floating_point = typename std::conditional<std::is_same<T,\
    \ double>::value || std::is_same<T, long double>::value, std::true_type, std::false_type>::type;\n\
    template <class T> using is_geometry_integer = typename std::conditional<std::is_same<T,\
    \ long long>::value, std::true_type, std::false_type>::type;\ntemplate <class\
    \ T> using is_geometry = typename std::conditional<is_geometry_floating_point<T>::value\
    \ || is_geometry_integer<T>::value, std::true_type, std::false_type>::type;\n"
  code: "#pragma once\n\n#include <type_traits>\n\n// Constants (EPS, PI)\n// EPS\
    \ \u306E\u5909\u66F4\u306F Constants<T>::set_eps(new_eps) \u3067\ntemplate <class\
    \ T> struct Constants {\n    static T EPS;\n    static void set_eps(const T e)\
    \ { EPS = e; }\n    static constexpr T PI = 3.14159'26535'89793L;\n};\n\ntemplate\
    \ <> double Constants<double>::EPS = 1e-9;\ntemplate <> long double Constants<long\
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
    \ || is_geometry_integer<T>::value, std::true_type, std::false_type>::type;\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry_template.hpp
  requiredBy:
  - geometry/farthest_pair.hpp
  - geometry/distance.hpp
  - geometry/closest_pair.hpp
  - geometry/circumscribed_circle.hpp
  - geometry/point.hpp
  - geometry/is_intersect.hpp
  - geometry/convex_polygon_diameter.hpp
  - geometry/line.hpp
  - geometry/incircle.hpp
  - geometry/circle.hpp
  - geometry/cross_point.hpp
  - geometry/all.hpp
  - geometry/convex_polygon_cut.hpp
  - geometry/polygon_contain.hpp
  - geometry/tangent.hpp
  - geometry/convex_hull_monotone_chain.hpp
  - geometry/polygon.hpp
  timestamp: '2024-08-03 15:34:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/geometry/convex_polygon_diameter.test.cpp
  - verify/geometry/cross_point_ss.test.cpp
  - verify/geometry/polygon_contain.test.cpp
  - verify/geometry/convex_hull_monotone_chain_1.test.cpp
  - verify/geometry/cross_point_cl.test.cpp
  - verify/geometry/cross_point_cc.test.cpp
  - verify/geometry/incircle.test.cpp
  - verify/geometry/ccw.test.cpp
  - verify/geometry/tangent_number.test.cpp
  - verify/geometry/reflection.test.cpp
  - verify/geometry/projection.test.cpp
  - verify/geometry/polygon_is_convex.test.cpp
  - verify/geometry/convex_hull_monotone_chain_2.test.cpp
  - verify/geometry/compare_atan2.test.cpp
  - verify/geometry/is_intersect_ss.test.cpp
  - verify/geometry/closest_pair.test.cpp
  - verify/geometry/polygon_area.test.cpp
  - verify/geometry/tangent_cc.test.cpp
  - verify/geometry/is_orthogonal_is_parallel.test.cpp
  - verify/geometry/distance_ss.test.cpp
  - verify/geometry/convex_polygon_cut.test.cpp
  - verify/geometry/tangent_cp.test.cpp
  - verify/geometry/circumscribed_circle.test.cpp
documentation_of: geometry/geometry_template.hpp
layout: document
title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---

## 使い方

```cpp
// EPS 取得
Constants::<T>::EPS
// PI 取得
Constants::<T>::PI
// T の誤差を 1e-8 に変更
Constants<T>::set_eps(1e-8);
```

`double`, `long double`, `long long` 以外は動かない

関数によっては整数型でのみ, あるいは浮動小数点数型でのみ動作するものもあり, 想定していない使われ方に対しては `static_assert` で CE を吐くようにしている

## 参考文献
- [cpprefjp - C++日本語レファレンス, type_traits](https://cpprefjp.github.io/reference/type_traits.html)