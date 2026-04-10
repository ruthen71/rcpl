---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/top_two.hpp
    title: TopTwo
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
  bundledCode: "#line 1 \"misc/test/top_two.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#include <array>\n#include <cassert>\n#include <iostream>\n\n#line 2 \"misc/top_two.hpp\"\
    \n\ntemplate <class T, T inf> struct TopTwo {\n    T a, b;\n    TopTwo() {\n \
    \       a = -inf;\n        b = -inf;\n    }\n    TopTwo(T a, T b) : a(a), b(b)\
    \ {\n        if (a < b) {\n            std::swap(this->a, this->b);\n        }\n\
    \    }\n    bool add(T x) {\n        if (a < x) {\n            b = a;\n      \
    \      a = x;\n            return true;\n        } else if (b < x) {\n       \
    \     b = x;\n            return true;\n        }\n        return false;\n   \
    \ }\n};\n#line 8 \"misc/test/top_two.test.cpp\"\n\nvoid test1_top_two_add() {\n\
    \    TopTwo<int, 1000> t;\n    {\n        // (1, -inf)\n        bool f = t.add(1);\n\
    \        assert(f == true and t.a == 1 and t.b == -1000);\n    }\n    {\n    \
    \    // (1, 1)\n        bool f = t.add(1);\n        assert(f == true and t.a ==\
    \ 1 and t.b == 1);\n    }\n    {\n        // (1, 1)\n        bool f = t.add(0);\n\
    \        assert(f == false and t.a == 1 and t.b == 1);\n    }\n    {\n       \
    \ // (1, 1)\n        bool f = t.add(1);\n        assert(f == false and t.a ==\
    \ 1 and t.b == 1);\n    }\n    {\n        // (2, 1)\n        bool f = t.add(2);\n\
    \        assert(f == true and t.a == 2 and t.b == 1);\n    }\n    {\n        //\
    \ (4, 2)\n        bool f = t.add(4);\n        assert(f == true and t.a == 4 and\
    \ t.b == 2);\n    }\n    {\n        // (4, 3)\n        bool f = t.add(3);\n  \
    \      assert(f == true and t.a == 4 and t.b == 3);\n    }\n    {\n        //\
    \ (4, 3)\n        bool f = t.add(3);\n        assert(f == false and t.a == 4 and\
    \ t.b == 3);\n    }\n}\n\nvoid test2_top_two_swap() {\n    TopTwo<int, 1000> t(0,\
    \ 1);\n    assert(t.a == 1 and t.b == 0);\n}\n\nint main() {\n    test1_top_two_add();\n\
    \    test2_top_two_swap();\n    int a, b;\n    std::cin >> a >> b;\n    std::cout\
    \ << a + b << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <array>\n\
    #include <cassert>\n#include <iostream>\n\n#include \"../top_two.hpp\"\n\nvoid\
    \ test1_top_two_add() {\n    TopTwo<int, 1000> t;\n    {\n        // (1, -inf)\n\
    \        bool f = t.add(1);\n        assert(f == true and t.a == 1 and t.b ==\
    \ -1000);\n    }\n    {\n        // (1, 1)\n        bool f = t.add(1);\n     \
    \   assert(f == true and t.a == 1 and t.b == 1);\n    }\n    {\n        // (1,\
    \ 1)\n        bool f = t.add(0);\n        assert(f == false and t.a == 1 and t.b\
    \ == 1);\n    }\n    {\n        // (1, 1)\n        bool f = t.add(1);\n      \
    \  assert(f == false and t.a == 1 and t.b == 1);\n    }\n    {\n        // (2,\
    \ 1)\n        bool f = t.add(2);\n        assert(f == true and t.a == 2 and t.b\
    \ == 1);\n    }\n    {\n        // (4, 2)\n        bool f = t.add(4);\n      \
    \  assert(f == true and t.a == 4 and t.b == 2);\n    }\n    {\n        // (4,\
    \ 3)\n        bool f = t.add(3);\n        assert(f == true and t.a == 4 and t.b\
    \ == 3);\n    }\n    {\n        // (4, 3)\n        bool f = t.add(3);\n      \
    \  assert(f == false and t.a == 4 and t.b == 3);\n    }\n}\n\nvoid test2_top_two_swap()\
    \ {\n    TopTwo<int, 1000> t(0, 1);\n    assert(t.a == 1 and t.b == 0);\n}\n\n\
    int main() {\n    test1_top_two_add();\n    test2_top_two_swap();\n    int a,\
    \ b;\n    std::cin >> a >> b;\n    std::cout << a + b << '\\n';\n    return 0;\n\
    }\n"
  dependsOn:
  - misc/top_two.hpp
  isVerificationFile: true
  path: misc/test/top_two.test.cpp
  requiredBy: []
  timestamp: '2026-02-15 05:06:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: misc/test/top_two.test.cpp
layout: document
redirect_from:
- /verify/misc/test/top_two.test.cpp
- /verify/misc/test/top_two.test.cpp.html
title: misc/test/top_two.test.cpp
---
