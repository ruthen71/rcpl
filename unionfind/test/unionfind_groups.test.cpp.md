---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: unionfind/unionfind.hpp
    title: Unionfind
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
  bundledCode: "#line 1 \"unionfind/test/unionfind_groups.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\n#line 2\
    \ \"unionfind/unionfind.hpp\"\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <vector>\n\n// Unionfind\nstruct Unionfind {\n    int n;\n    std::vector<int>\
    \ parent;\n\n    Unionfind() = default;\n\n    explicit Unionfind(int n) : n(n),\
    \ parent(n, -1) {}\n\n    int leader(int x) {\n        assert(0 <= x and x < n);\n\
    \        if (parent[x] < 0) {\n            return x;\n        } else {\n     \
    \       return parent[x] = leader(parent[x]);\n        }\n    }\n\n    int merge(int\
    \ x, int y) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and y\
    \ < n);\n        x = leader(x);\n        y = leader(y);\n        if (x == y) {\n\
    \            return x;\n        }\n        if (-parent[x] < -parent[y]) {\n  \
    \          std::swap(x, y);\n        }\n        parent[x] += parent[y];\n    \
    \    parent[y] = x;\n        return x;\n    }\n\n    bool same(int x, int y) {\n\
    \        assert(0 <= x and x < n);\n        assert(0 <= y and y < n);\n      \
    \  return leader(x) == leader(y);\n    }\n\n    int size(int x) {\n        assert(0\
    \ <= x and x < n);\n        return -parent[leader(x)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(n), group_size(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            leader_buf[i] = leader(i);\n    \
    \        group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(n);\n        for (int i = 0; i < n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(std::remove_if(\n                         result.begin(),\
    \ result.end(),\n                         [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n                     result.end());\n        return result;\n\
    \    }\n};\n#line 6 \"unionfind/test/unionfind_groups.test.cpp\"\n\nvoid test1_zero()\
    \ {\n    Unionfind uf(0);\n    assert(uf.groups() == std::vector<std::vector<int>>());\n\
    }\n\nvoid test2_empty() {\n    Unionfind uf;\n    assert(uf.groups() == std::vector<std::vector<int>>());\n\
    }\n\nvoid test3_assign() {\n    Unionfind uf;\n    uf = Unionfind(10);\n}\n\n\
    void test4_simple() {\n    Unionfind uf(2);\n    assert(uf.same(0, 1) == false);\n\
    \    int x = uf.merge(0, 1);\n    assert(uf.leader(0) == x);\n    assert(uf.leader(1)\
    \ == x);\n    assert(uf.same(0, 1) == true);\n    assert(uf.size(0) == 2);\n}\n\
    \nvoid test5_line() {\n    int n = 500000;\n    Unionfind uf(n);\n    for (int\
    \ i = 0; i < n - 1; i++) {\n        uf.merge(i, i + 1);\n    }\n    assert(uf.size(0)\
    \ == n);\n    assert(uf.groups().size() == 1);\n}\n\nvoid test6_line_reverse()\
    \ {\n    int n = 500000;\n    Unionfind uf(n);\n    for (int i = n - 2; i >= 0;\
    \ i--) {\n        uf.merge(i, i + 1);\n    }\n    assert(uf.size(0) == n);\n \
    \   assert(uf.groups().size() == 1);\n}\n\nvoid test7_groups() {\n    int n =\
    \ 5;\n    Unionfind uf(n);\n    uf.merge(0, 1);\n    uf.merge(2, 3);\n    uf.merge(2,\
    \ 4);\n    auto gp = uf.groups();\n    for (auto&& v : gp) std::sort(v.begin(),\
    \ v.end());\n    std::sort(gp.begin(), gp.end());\n    std::vector<std::vector<int>>\
    \ gp_sorted = {{0, 1}, {2, 3, 4}};\n    assert(gp == gp_sorted);\n}\n\nint main()\
    \ {\n    test1_zero();\n    test2_empty();\n    test3_assign();\n    test4_simple();\n\
    \    test5_line();\n    test6_line_reverse();\n    test7_groups();\n    int a,\
    \ b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#include \"../../unionfind/unionfind.hpp\"\n\nvoid test1_zero() {\n    Unionfind\
    \ uf(0);\n    assert(uf.groups() == std::vector<std::vector<int>>());\n}\n\nvoid\
    \ test2_empty() {\n    Unionfind uf;\n    assert(uf.groups() == std::vector<std::vector<int>>());\n\
    }\n\nvoid test3_assign() {\n    Unionfind uf;\n    uf = Unionfind(10);\n}\n\n\
    void test4_simple() {\n    Unionfind uf(2);\n    assert(uf.same(0, 1) == false);\n\
    \    int x = uf.merge(0, 1);\n    assert(uf.leader(0) == x);\n    assert(uf.leader(1)\
    \ == x);\n    assert(uf.same(0, 1) == true);\n    assert(uf.size(0) == 2);\n}\n\
    \nvoid test5_line() {\n    int n = 500000;\n    Unionfind uf(n);\n    for (int\
    \ i = 0; i < n - 1; i++) {\n        uf.merge(i, i + 1);\n    }\n    assert(uf.size(0)\
    \ == n);\n    assert(uf.groups().size() == 1);\n}\n\nvoid test6_line_reverse()\
    \ {\n    int n = 500000;\n    Unionfind uf(n);\n    for (int i = n - 2; i >= 0;\
    \ i--) {\n        uf.merge(i, i + 1);\n    }\n    assert(uf.size(0) == n);\n \
    \   assert(uf.groups().size() == 1);\n}\n\nvoid test7_groups() {\n    int n =\
    \ 5;\n    Unionfind uf(n);\n    uf.merge(0, 1);\n    uf.merge(2, 3);\n    uf.merge(2,\
    \ 4);\n    auto gp = uf.groups();\n    for (auto&& v : gp) std::sort(v.begin(),\
    \ v.end());\n    std::sort(gp.begin(), gp.end());\n    std::vector<std::vector<int>>\
    \ gp_sorted = {{0, 1}, {2, 3, 4}};\n    assert(gp == gp_sorted);\n}\n\nint main()\
    \ {\n    test1_zero();\n    test2_empty();\n    test3_assign();\n    test4_simple();\n\
    \    test5_line();\n    test6_line_reverse();\n    test7_groups();\n    int a,\
    \ b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n\
    }\n"
  dependsOn:
  - unionfind/unionfind.hpp
  isVerificationFile: true
  path: unionfind/test/unionfind_groups.test.cpp
  requiredBy: []
  timestamp: '2025-12-10 04:21:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: unionfind/test/unionfind_groups.test.cpp
layout: document
redirect_from:
- /verify/unionfind/test/unionfind_groups.test.cpp
- /verify/unionfind/test/unionfind_groups.test.cpp.html
title: unionfind/test/unionfind_groups.test.cpp
---
