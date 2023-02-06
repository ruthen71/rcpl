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
    \ <class T> struct CumulativeSum2D {\n    std::vector<std::vector<T>> cum;\n \
    \   int H, W;\n\n    CumulativeSum2D(int W, int H) : H(H), W(W), cum(W + 1, std::vector<T>(H\
    \ + 1, 0)) {}\n\n    CumulativeSum2D(std::vector<std::vector<T>> &A) {\n     \
    \   H = (int)A.size(), W = (int)A[0].size();\n        cum.assign(H + 1, std::vector<T>(W\
    \ + 1, 0));\n        for (int i = 0; i < H; i++) {\n            for (int j = 0;\
    \ j < W; j++) {\n                cum[i + 1][j + 1] = A[i][j];\n            }\n\
    \        }\n        for (int i = 0; i < H + 1; i++) {\n            for (int j\
    \ = 0; j < W; j++) {\n                cum[i][j + 1] += cum[i][j];\n          \
    \  }\n        }\n        for (int i = 0; i < H; i++) {\n            for (int j\
    \ = 0; j < W + 1; j++) {\n                cum[i + 1][j] += cum[i][j];\n      \
    \      }\n        }\n    }\n\n    // [lx, ly) x [rx, ry)\n    T sum(int lx, int\
    \ ly, int rx, int ry) {\n        assert(0 <= lx and lx <= rx and rx <= H);\n \
    \       assert(0 <= ly and ly <= ry and ry <= W);\n        return (cum[rx][ry]\
    \ - cum[lx][ry] - cum[rx][ly] + cum[lx][ly]);\n    }\n\n    // A[x][y] = z\n \
    \   void set(int x, int y, T z) {\n        assert(0 <= x and x < H);\n       \
    \ assert(0 <= y and y < W);\n        cum[x + 1][y + 1] = z;\n    }\n\n    // A[x][y]\
    \ += z\n    void add(int x, int y, T z) {\n        assert(0 <= x and x < H);\n\
    \        assert(0 <= y and y < W);\n        cum[x + 1][y + 1] += z;\n    }\n\n\
    \    // (i, j) \\in [lx, ly) x [rx, ry) cum[i][j] += z;\n    void imos(int lx,\
    \ int ly, int rx, int ry, T z = 1) {\n        add(lx, ly, z);\n        add(lx,\
    \ ry, -z);\n        add(rx, ly, -z);\n        add(rx, ry, z);\n    }\n\n    void\
    \ build() {\n        for (int i = 0; i < H + 1; i++) {\n            for (int j\
    \ = 0; j < W; j++) {\n                cum[i][j + 1] += cum[i][j];\n          \
    \  }\n        }\n        for (int i = 0; i < H; i++) {\n            for (int j\
    \ = 0; j < W + 1; j++) {\n                cum[i + 1][j] += cum[i][j];\n      \
    \      }\n        }\n    }\n\n    T operator()(int x, int y) {\n        assert(0\
    \ <= x and x < H and 0 <= y and y < W);\n        return cum[x + 1][y + 1];\n \
    \   }\n\n    // output\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const CumulativeSum2D &A) {\n        for (int i = 0; i < (int)A.cum.size();\
    \ i++) {\n            for (int j = 0; j < (int)A.cum[i].size(); j++) {\n     \
    \           os << A.cum[i][j] << \" \\n\"[j == (int)A.cum[i].size() - 1];\n  \
    \          }\n        }\n        return os;\n    }\n};\n#line 6 \"verify/aoj_dsl/aoj_dsl_5_b.test.cpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    int M = 1000;\n    CumulativeSum2D<int>\
    \ rui(M + 1, M + 1);\n    while (N--) {\n        int x1, y1, x2, y2;\n       \
    \ std::cin >> x1 >> y1 >> x2 >> y2;\n        rui.imos(x1, y1, x2, y2);\n    }\n\
    \    rui.build();\n    int ans = 0;\n    for (int i = 0; i < M; i++)\n       \
    \ for (int j = 0; j < M; j++) ans = std::max(ans, rui(i, j));\n    std::cout <<\
    \ ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"data_structure/cumulative_sum_2d.hpp\"\
    \n\nint main() {\n    int N;\n    std::cin >> N;\n    int M = 1000;\n    CumulativeSum2D<int>\
    \ rui(M + 1, M + 1);\n    while (N--) {\n        int x1, y1, x2, y2;\n       \
    \ std::cin >> x1 >> y1 >> x2 >> y2;\n        rui.imos(x1, y1, x2, y2);\n    }\n\
    \    rui.build();\n    int ans = 0;\n    for (int i = 0; i < M; i++)\n       \
    \ for (int j = 0; j < M; j++) ans = std::max(ans, rui(i, j));\n    std::cout <<\
    \ ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - data_structure/cumulative_sum_2d.hpp
  isVerificationFile: true
  path: verify/aoj_dsl/aoj_dsl_5_b.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 23:39:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj_dsl/aoj_dsl_5_b.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj_dsl/aoj_dsl_5_b.test.cpp
- /verify/verify/aoj_dsl/aoj_dsl_5_b.test.cpp.html
title: verify/aoj_dsl/aoj_dsl_5_b.test.cpp
---
