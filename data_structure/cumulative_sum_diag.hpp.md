---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/cumulative_sum_diag.hpp\"\n\ntemplate <class\
    \ T, int delta = 1> struct cumulative_sum_diag {\n    std::vector<std::vector<T>>\
    \ cum;\n    int H, W;\n\n    cumulative_sum_diag(std::vector<std::vector<T>> &A)\
    \ {\n        assert(A.size() > 0);\n        H = (int)A.size(), W = (int)A[0].size();\n\
    \        cum.assign(H + W, std::vector<T>(W + 1, 0));\n        if (delta == 1)\
    \ {\n            for (int i = 0; i < H; i++) {\n                for (int j = 0;\
    \ j < W; j++) {\n                    cum[i + W - 1 - j][j + 1] = A[i][j];\n  \
    \              }\n            }\n            for (int i = 0; i < H + W; i++) {\n\
    \                for (int j = 0; j < W; j++) {\n                    cum[i][j +\
    \ 1] += cum[i][j];\n                }\n            }\n        } else {\n     \
    \       assert(delta == -1);\n            for (int i = 0; i < H; i++) {\n    \
    \            for (int j = 0; j < W; j++) {\n                    cum[i + j][j +\
    \ 1] = A[i][j];\n                }\n            }\n            for (int i = 0;\
    \ i < H + W; i++) {\n                for (int j = 0; j < W; j++) {\n         \
    \           cum[i][j + 1] += cum[i][j];\n                }\n            }\n  \
    \      }\n    }\n\n    T sum(int x1, int y1, int x2, int y2) {\n        assert(0\
    \ <= x1 and x1 < H and 0 <= y1 and y1 < W);\n        assert(0 <= x2 and x2 < H\
    \ and 0 <= y2 and y2 < W);\n        assert(y1 <= y2);\n        if (delta == 1)\
    \ {\n            // sum of (x1, y1), (x1 + 1, y1 + 1), ... , (x2, y2)\n      \
    \      assert(x1 - y1 == x2 - y2);\n            return cum[x1 + W - 1 - y1][y2\
    \ + 1] - cum[x1 + W - 1 - y1][y1];\n        } else {\n            // sum of (x1,\
    \ y1), (x1 - 1, y1 + 1), ... , (x2, y2)\n            assert(x1 + y1 == x2 + y2);\n\
    \            return cum[x1 + y1][y2 + 1] - cum[x1 + y1][y1];\n        }\n    }\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T, int delta = 1> struct cumulative_sum_diag\
    \ {\n    std::vector<std::vector<T>> cum;\n    int H, W;\n\n    cumulative_sum_diag(std::vector<std::vector<T>>\
    \ &A) {\n        assert(A.size() > 0);\n        H = (int)A.size(), W = (int)A[0].size();\n\
    \        cum.assign(H + W, std::vector<T>(W + 1, 0));\n        if (delta == 1)\
    \ {\n            for (int i = 0; i < H; i++) {\n                for (int j = 0;\
    \ j < W; j++) {\n                    cum[i + W - 1 - j][j + 1] = A[i][j];\n  \
    \              }\n            }\n            for (int i = 0; i < H + W; i++) {\n\
    \                for (int j = 0; j < W; j++) {\n                    cum[i][j +\
    \ 1] += cum[i][j];\n                }\n            }\n        } else {\n     \
    \       assert(delta == -1);\n            for (int i = 0; i < H; i++) {\n    \
    \            for (int j = 0; j < W; j++) {\n                    cum[i + j][j +\
    \ 1] = A[i][j];\n                }\n            }\n            for (int i = 0;\
    \ i < H + W; i++) {\n                for (int j = 0; j < W; j++) {\n         \
    \           cum[i][j + 1] += cum[i][j];\n                }\n            }\n  \
    \      }\n    }\n\n    T sum(int x1, int y1, int x2, int y2) {\n        assert(0\
    \ <= x1 and x1 < H and 0 <= y1 and y1 < W);\n        assert(0 <= x2 and x2 < H\
    \ and 0 <= y2 and y2 < W);\n        assert(y1 <= y2);\n        if (delta == 1)\
    \ {\n            // sum of (x1, y1), (x1 + 1, y1 + 1), ... , (x2, y2)\n      \
    \      assert(x1 - y1 == x2 - y2);\n            return cum[x1 + W - 1 - y1][y2\
    \ + 1] - cum[x1 + W - 1 - y1][y1];\n        } else {\n            // sum of (x1,\
    \ y1), (x1 - 1, y1 + 1), ... , (x2, y2)\n            assert(x1 + y1 == x2 + y2);\n\
    \            return cum[x1 + y1][y2 + 1] - cum[x1 + y1][y1];\n        }\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cumulative_sum_diag.hpp
  requiredBy: []
  timestamp: '2023-02-06 19:13:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/cumulative_sum_diag.hpp
layout: document
title: "\u659C\u3081\u7D2F\u7A4D\u548C"
---

- 閉区間なので注意
- [使用例1](https://atcoder.jp/contests/abc265/submissions/36930250)
