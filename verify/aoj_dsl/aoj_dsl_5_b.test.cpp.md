---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/cumulative_sum_2d.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"verify/aoj_dsl/aoj_dsl_5_b.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"data_structure/cumulative_sum_2d.hpp\"\n\ntemplate\
    \ <class T> struct CumulativeSum2D {\n    int h, w;\n    std::vector<std::vector<T>>\
    \ seg;\n\n    CumulativeSum2D() = default;\n\n    CumulativeSum2D(int h, int w)\
    \ : h(h), w(w), seg(h + 1, std::vector<T>(w + 1, T(0))) {}\n\n    CumulativeSum2D(std::vector<std::vector<T>>\
    \ &a) {\n        h = (int)a.size();\n        assert(h > 0);\n        w = (int)a[0].size();\n\
    \        seg.assign(h + 1, std::vector<T>(w + 1, T(0)));\n        for (int i =\
    \ 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n              \
    \  seg[i + 1][j + 1] = a[i][j];\n            }\n        }\n        for (int i\
    \ = 0; i < h + 1; i++) {\n            for (int j = 0; j < w; j++) {\n        \
    \        seg[i][j + 1] += seg[i][j];\n            }\n        }\n        for (int\
    \ i = 0; i < h; i++) {\n            for (int j = 0; j < w + 1; j++) {\n      \
    \          seg[i + 1][j] += seg[i][j];\n            }\n        }\n    }\n\n  \
    \  // [lx, rx) x [ly, ry)\n    T sum(int lx, int ly, int rx, int ry) {\n     \
    \   assert(0 <= lx and lx <= rx and rx <= h);\n        assert(0 <= ly and ly <=\
    \ ry and ry <= w);\n        return (seg[rx][ry] - seg[lx][ry] - seg[rx][ly] +\
    \ seg[lx][ly]);\n    }\n\n    // (i, j) \\in [lx, rx) x [ly, ry) seg[i][j] +=\
    \ z;\n    void imos(int lx, int ly, int rx, int ry, T z = T(1)) {\n        assert(0\
    \ <= lx and lx <= rx and rx <= h);\n        assert(0 <= ly and ly <= ry and ry\
    \ <= w);\n        seg[lx][ly] += z;\n        seg[lx][ry] -= z;\n        seg[rx][ly]\
    \ -= z;\n        seg[rx][ry] += z;\n    }\n\n    void build() {\n        for (int\
    \ i = 0; i < h + 1; i++) {\n            for (int j = 0; j < w; j++) {\n      \
    \          seg[i][j + 1] += seg[i][j];\n            }\n        }\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w + 1; j++) {\n \
    \               seg[i + 1][j] += seg[i][j];\n            }\n        }\n    }\n\
    \n    // return A[x][y]\n    T get(int x, int y) const {\n        assert(0 <=\
    \ x and x < h and 0 <= y and y < w);\n        return seg[x][y];\n    }\n\n   \
    \ // output\n    friend std::ostream &operator<<(std::ostream &os, const CumulativeSum2D\
    \ &A) {\n        os << \"h = \" << A.h << \", w = \" << A.w << \"\\n\";\n    \
    \    for (int i = 0; i <= A.h; i++) {\n            for (int j = 0; j <= A.w; j++)\
    \ {\n                os << A.seg[i][j] << \" \\n\"[j == A.w];\n            }\n\
    \        }\n        return os;\n    }\n};\n#line 6 \"verify/aoj_dsl/aoj_dsl_5_b.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    int M = 1000;\n    CumulativeSum2D<int>\
    \ rui(M, M);\n    while (N--) {\n        int x1, y1, x2, y2;\n        std::cin\
    \ >> x1 >> y1 >> x2 >> y2;\n        rui.imos(x1, y1, x2, y2);\n    }\n    rui.build();\n\
    \    int ans = 0;\n    for (int i = 0; i < M; i++) {\n        for (int j = 0;\
    \ j < M; j++) {\n            ans = std::max(ans, rui.get(i, j));\n        }\n\
    \    }\n    std::cout << ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"data_structure/cumulative_sum_2d.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    int M = 1000;\n    CumulativeSum2D<int>\
    \ rui(M, M);\n    while (N--) {\n        int x1, y1, x2, y2;\n        std::cin\
    \ >> x1 >> y1 >> x2 >> y2;\n        rui.imos(x1, y1, x2, y2);\n    }\n    rui.build();\n\
    \    int ans = 0;\n    for (int i = 0; i < M; i++) {\n        for (int j = 0;\
    \ j < M; j++) {\n            ans = std::max(ans, rui.get(i, j));\n        }\n\
    \    }\n    std::cout << ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - data_structure/cumulative_sum_2d.hpp
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_5_b.test.cpp
  requiredBy: []
  timestamp: '2023-04-16 00:50:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_5_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_5_b.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_5_b.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_5_b.test.cpp
---
