---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: enumerate/enumerate_product.hpp
    title: "$ 0 \\leq p_{i} < a_{i} $ \u3092\u6E80\u305F\u3059\u6574\u6570\u5217 $p$\
      \ \u306E\u5217\u6319"
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
  bundledCode: "#line 1 \"enumerate/test/enumerate_product.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\n#line 2\
    \ \"enumerate/enumerate_product.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n// enumerate product\n// enumerate p (0 <= p[i] < a[i])\ntemplate <class F>\
    \ void enumerate_product(std::vector<int> a, F f) {\n    const int n = (int)(a.size());\n\
    \    std::vector<int> p;\n    auto dfs = [&](auto g, int i) -> void {\n      \
    \  if (i == n) {\n            f(p);\n            return;\n        }\n        for\
    \ (int x = 0; x < a[i]; x++) {\n            p.push_back(x);\n            g(g,\
    \ i + 1);\n            p.pop_back();\n        }\n    };\n    dfs(dfs, 0);\n  \
    \  return;\n}\n#line 6 \"enumerate/test/enumerate_product.test.cpp\"\n\nvoid test1_simple()\
    \ {\n    std::vector<int> a = {1, 2, 3};\n    std::vector<std::vector<int>> ps;\n\
    \    auto f = [&](std::vector<int> p) -> void {\n        ps.push_back(p);\n  \
    \      return;\n    };\n    enumerate_product(a, f);\n    std::vector<std::vector<int>>\
    \ ps2 = {{0, 0, 0}, {0, 0, 1}, {0, 0, 2},\n                                  \
    \       {0, 1, 0}, {0, 1, 1}, {0, 1, 2}};\n    assert(ps == ps2);\n}\n\nvoid test2_zero()\
    \ {\n    // \u4E00\u5EA6 0 \u4EE5\u4E0B\u306E\u6574\u6570\u304C\u51FA\u73FE\u3057\
    \u305F\u5834\u5408\n    // \u305D\u308C\u4EE5\u964D\u306E\u6574\u6570\u306E\u5024\
    \u306B\u3088\u3089\u305A p \u306F\u5217\u6319\u3055\u308C\u306A\u3044\n    std::vector<int>\
    \ a = {1, 0, 1000000000, 1000000000};\n    std::vector<std::vector<int>> ps;\n\
    \    auto f = [&](std::vector<int> p) -> void {\n        ps.push_back(p);\n  \
    \      return;\n    };\n    enumerate_product(a, f);\n    assert(ps.size() ==\
    \ 0);\n}\n\nint main() {\n    test1_simple();\n    test2_zero();\n    int a, b;\n\
    \    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <iostream>\n\
    \n#include \"../../enumerate/enumerate_product.hpp\"\n\nvoid test1_simple() {\n\
    \    std::vector<int> a = {1, 2, 3};\n    std::vector<std::vector<int>> ps;\n\
    \    auto f = [&](std::vector<int> p) -> void {\n        ps.push_back(p);\n  \
    \      return;\n    };\n    enumerate_product(a, f);\n    std::vector<std::vector<int>>\
    \ ps2 = {{0, 0, 0}, {0, 0, 1}, {0, 0, 2},\n                                  \
    \       {0, 1, 0}, {0, 1, 1}, {0, 1, 2}};\n    assert(ps == ps2);\n}\n\nvoid test2_zero()\
    \ {\n    // \u4E00\u5EA6 0 \u4EE5\u4E0B\u306E\u6574\u6570\u304C\u51FA\u73FE\u3057\
    \u305F\u5834\u5408\n    // \u305D\u308C\u4EE5\u964D\u306E\u6574\u6570\u306E\u5024\
    \u306B\u3088\u3089\u305A p \u306F\u5217\u6319\u3055\u308C\u306A\u3044\n    std::vector<int>\
    \ a = {1, 0, 1000000000, 1000000000};\n    std::vector<std::vector<int>> ps;\n\
    \    auto f = [&](std::vector<int> p) -> void {\n        ps.push_back(p);\n  \
    \      return;\n    };\n    enumerate_product(a, f);\n    assert(ps.size() ==\
    \ 0);\n}\n\nint main() {\n    test1_simple();\n    test2_zero();\n    int a, b;\n\
    \    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - enumerate/enumerate_product.hpp
  isVerificationFile: true
  path: enumerate/test/enumerate_product.test.cpp
  requiredBy: []
  timestamp: '2026-04-11 01:00:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: enumerate/test/enumerate_product.test.cpp
layout: document
redirect_from:
- /verify/enumerate/test/enumerate_product.test.cpp
- /verify/enumerate/test/enumerate_product.test.cpp.html
title: enumerate/test/enumerate_product.test.cpp
---
