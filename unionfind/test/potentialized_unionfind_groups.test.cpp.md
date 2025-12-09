---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/monoid/monoid_plus.hpp
    title: algebra/monoid/monoid_plus.hpp
  - icon: ':heavy_check_mark:'
    path: unionfind/potentialized_unionfind.hpp
    title: "Potentialized Unionfind\uFF08\u91CD\u307F\u4ED8\u304D Unionfind\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"unionfind/test/potentialized_unionfind_groups.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#line 2 \"algebra/monoid/monoid_plus.hpp\"\n\ntemplate <class T> struct MonoidPlus\
    \ {\n    using value_type = T;\n    static constexpr T operation(const T& a, const\
    \ T& b) noexcept {\n        return a + b;\n    }\n    static constexpr T identity()\
    \ noexcept { return T(0); }\n    static constexpr T inverse(const T& a) noexcept\
    \ { return -a; }\n    static constexpr bool commutative = true;\n};\n#line 2 \"\
    unionfind/potentialized_unionfind.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\n// Potentialized Unionfind\ntemplate <class G> struct PotentializedUnionfind\
    \ {\n    static_assert(G::commutative == true);\n\n    using T = typename G::value_type;\n\
    \n    int n;\n    std::vector<int> parent;\n    std::vector<T> value;\n\n    PotentializedUnionfind()\
    \ = default;\n\n    explicit PotentializedUnionfind(int n)\n        : n(n), parent(n,\
    \ -1), value(n, G::identity()) {}\n\n    int leader(int x) {\n        assert(0\
    \ <= x and x < n);\n        if (parent[x] < 0) {\n            return x;\n    \
    \    } else {\n            int r = leader(parent[x]);\n            value[x] =\
    \ G::operation(value[x], value[parent[x]]);\n            return parent[x] = r;\n\
    \        }\n    }\n\n    T potential(int x) {\n        assert(0 <= x and x < n);\n\
    \        leader(x);\n        return value[x];\n    }\n\n    int merge(int x, int\
    \ y, T d) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and y <\
    \ n);\n        // d \u306F y \u306E x \u304B\u3089\u306E\u30DD\u30C6\u30F3\u30B7\
    \u30E3\u30EB\u306E\u5DEE\u5206\n        // d \u3092 leader(y) \u306E leader(x)\
    \ \u304B\u3089\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u5DEE\u5206\u306B\
    \u4FEE\u6B63\n        d = G::operation(G::operation(d, potential(x)),\n      \
    \                   G::inverse(potential(y)));\n        x = leader(x);\n     \
    \   y = leader(y);\n        if (x == y) {\n            if (d == G::identity())\
    \ {\n                return x;\n            } else {\n                return -1;\n\
    \            }\n        }\n        if (-parent[x] < -parent[y]) {\n          \
    \  std::swap(x, y);\n            d = G::inverse(d);\n        }\n        parent[x]\
    \ += parent[y];\n        parent[y] = x;\n        value[y] = d;\n        return\
    \ x;\n    }\n\n    T distance(int x, int y) {\n        assert(0 <= x and x < n);\n\
    \        assert(0 <= y and y < n);\n        assert(same(x, y));\n        return\
    \ G::operation(potential(y), G::inverse(potential(x)));\n    }\n\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and y\
    \ < n);\n        return leader(x) == leader(y);\n    }\n\n    int size(int x)\
    \ {\n        assert(0 <= x and x < n);\n        return -parent[leader(x)];\n \
    \   }\n\n    std::vector<std::vector<std::pair<int, T>>> groups() {\n        std::vector<int>\
    \ leader_buf(n), group_size(n);\n        for (int i = 0; i < n; i++) {\n     \
    \       leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<std::pair<int, T>>> result(n);\n \
    \       for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].emplace_back(i,\
    \ potential(i));\n        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<std::pair<int,\
    \ T>>& v) {\n                               return v.empty();\n              \
    \             }),\n            result.end());\n        return result;\n    }\n\
    };\n#line 7 \"unionfind/test/potentialized_unionfind_groups.test.cpp\"\n\nvoid\
    \ test1_zero() {\n    PotentializedUnionfind<MonoidPlus<int>> uf(0);\n    assert(uf.groups()\
    \ == (std::vector<std::vector<std::pair<int, int>>>()));\n}\n\nvoid test2_empty()\
    \ {\n    PotentializedUnionfind<MonoidPlus<int>> uf;\n    assert(uf.groups() ==\
    \ (std::vector<std::vector<std::pair<int, int>>>()));\n}\n\nvoid test3_assign()\
    \ {\n    PotentializedUnionfind<MonoidPlus<int>> uf;\n    uf = PotentializedUnionfind<MonoidPlus<int>>(10);\n\
    }\n\nvoid test4_simple() {\n    PotentializedUnionfind<MonoidPlus<int>> uf(2);\n\
    \    assert(uf.same(0, 1) == false);\n    int x = uf.merge(0, 1, 2);\n    assert(uf.leader(0)\
    \ == x);\n    assert(uf.leader(1) == x);\n    assert(uf.same(0, 1) == true);\n\
    \    assert(uf.size(0) == 2);\n    assert(uf.distance(0, 1) == 2);\n}\n\nvoid\
    \ test5_line() {\n    int n = 500000;\n    PotentializedUnionfind<MonoidPlus<int>>\
    \ uf(n);\n    for (int i = 0; i < n - 1; i++) {\n        uf.merge(i, i + 1, 1);\n\
    \    }\n    assert(uf.size(0) == n);\n    assert(uf.groups().size() == 1);\n \
    \   assert(uf.distance(0, n - 1) == n - 1);\n}\n\nvoid test6_line_reverse() {\n\
    \    int n = 500000;\n    PotentializedUnionfind<MonoidPlus<int>> uf(n);\n   \
    \ for (int i = n - 2; i >= 0; i--) {\n        uf.merge(i, i + 1, 1);\n    }\n\
    \    assert(uf.size(0) == n);\n    assert(uf.groups().size() == 1);\n    assert(uf.distance(0,\
    \ n - 1) == n - 1);\n}\n\nvoid test7_groups() {\n    int n = 5;\n    PotentializedUnionfind<MonoidPlus<int>>\
    \ uf(n);\n    uf.merge(0, 1, 1);\n    uf.merge(2, 3, 2);\n    uf.merge(2, 4, 6);\n\
    \    auto gp = uf.groups();\n    for (auto&& v : gp) {\n        std::sort(v.begin(),\
    \ v.end());\n        int v0 = v[0].second;\n        for (auto&& vi : v) {\n  \
    \          vi.second -= v0;\n        }\n    }\n    std::sort(gp.begin(), gp.end());\n\
    \    std::vector<std::vector<std::pair<int, int>>> gp_sorted = {\n        {{0,\
    \ 0}, {1, 1}}, {{2, 0}, {3, 2}, {4, 6}}};\n    assert(gp == gp_sorted);\n}\n\n\
    int main() {\n    test1_zero();\n    test2_empty();\n    test3_assign();\n   \
    \ test4_simple();\n    test5_line();\n    test6_line_reverse();\n    test7_groups();\n\
    \    int a, b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#include \"../../algebra/monoid/monoid_plus.hpp\"\n#include \"../../unionfind/potentialized_unionfind.hpp\"\
    \n\nvoid test1_zero() {\n    PotentializedUnionfind<MonoidPlus<int>> uf(0);\n\
    \    assert(uf.groups() == (std::vector<std::vector<std::pair<int, int>>>()));\n\
    }\n\nvoid test2_empty() {\n    PotentializedUnionfind<MonoidPlus<int>> uf;\n \
    \   assert(uf.groups() == (std::vector<std::vector<std::pair<int, int>>>()));\n\
    }\n\nvoid test3_assign() {\n    PotentializedUnionfind<MonoidPlus<int>> uf;\n\
    \    uf = PotentializedUnionfind<MonoidPlus<int>>(10);\n}\n\nvoid test4_simple()\
    \ {\n    PotentializedUnionfind<MonoidPlus<int>> uf(2);\n    assert(uf.same(0,\
    \ 1) == false);\n    int x = uf.merge(0, 1, 2);\n    assert(uf.leader(0) == x);\n\
    \    assert(uf.leader(1) == x);\n    assert(uf.same(0, 1) == true);\n    assert(uf.size(0)\
    \ == 2);\n    assert(uf.distance(0, 1) == 2);\n}\n\nvoid test5_line() {\n    int\
    \ n = 500000;\n    PotentializedUnionfind<MonoidPlus<int>> uf(n);\n    for (int\
    \ i = 0; i < n - 1; i++) {\n        uf.merge(i, i + 1, 1);\n    }\n    assert(uf.size(0)\
    \ == n);\n    assert(uf.groups().size() == 1);\n    assert(uf.distance(0, n -\
    \ 1) == n - 1);\n}\n\nvoid test6_line_reverse() {\n    int n = 500000;\n    PotentializedUnionfind<MonoidPlus<int>>\
    \ uf(n);\n    for (int i = n - 2; i >= 0; i--) {\n        uf.merge(i, i + 1, 1);\n\
    \    }\n    assert(uf.size(0) == n);\n    assert(uf.groups().size() == 1);\n \
    \   assert(uf.distance(0, n - 1) == n - 1);\n}\n\nvoid test7_groups() {\n    int\
    \ n = 5;\n    PotentializedUnionfind<MonoidPlus<int>> uf(n);\n    uf.merge(0,\
    \ 1, 1);\n    uf.merge(2, 3, 2);\n    uf.merge(2, 4, 6);\n    auto gp = uf.groups();\n\
    \    for (auto&& v : gp) {\n        std::sort(v.begin(), v.end());\n        int\
    \ v0 = v[0].second;\n        for (auto&& vi : v) {\n            vi.second -= v0;\n\
    \        }\n    }\n    std::sort(gp.begin(), gp.end());\n    std::vector<std::vector<std::pair<int,\
    \ int>>> gp_sorted = {\n        {{0, 0}, {1, 1}}, {{2, 0}, {3, 2}, {4, 6}}};\n\
    \    assert(gp == gp_sorted);\n}\n\nint main() {\n    test1_zero();\n    test2_empty();\n\
    \    test3_assign();\n    test4_simple();\n    test5_line();\n    test6_line_reverse();\n\
    \    test7_groups();\n    int a, b;\n    std::cin >> a >> b;\n    std::cout <<\
    \ a + b << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - algebra/monoid/monoid_plus.hpp
  - unionfind/potentialized_unionfind.hpp
  isVerificationFile: true
  path: unionfind/test/potentialized_unionfind_groups.test.cpp
  requiredBy: []
  timestamp: '2025-12-10 04:21:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unionfind/test/potentialized_unionfind_groups.test.cpp
layout: document
redirect_from:
- /verify/unionfind/test/potentialized_unionfind_groups.test.cpp
- /verify/unionfind/test/potentialized_unionfind_groups.test.cpp.html
title: unionfind/test/potentialized_unionfind_groups.test.cpp
---
