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
  bundledCode: "#line 2 \"string/element_next_index.hpp\"\n\n#include <string>\n#include\
    \ <vector>\n\n// element next index\n// res[i][c] = s[i, n) \u306B\u304A\u3044\
    \u3066\u6B21\u306E c \u306E\u767B\u5834\u4F4D\u7F6E\u3092\u8FD4\u3059\ntemplate\
    \ <class T> std::vector<std::vector<int>> element_next_index(const std::vector<T>&\
    \ s) {\n    const int n = (int)(s.size());\n    T lb = std::numeric_limits<T>::max(),\
    \ ub = std::numeric_limits<T>::min();\n    for (int i = 0; i < n; i++) {\n   \
    \     if (lb > s[i]) lb = s[i];\n        if (ub < s[i]) ub = s[i];\n    }\n  \
    \  const int sigma = ub - lb + 1;\n    std::vector res(n + 1, std::vector<int>(sigma,\
    \ -1));\n    for (int i = n - 1; i >= 0; i--) {\n        res[i] = res[i + 1];\n\
    \        res[i][s[i] - lb] = i;\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>>\
    \ element_next_index(const std::string& s) {\n    const int n = (int)(s.size());\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) s2[i] = s[i];\n\
    \    return element_next_index(s2);\n}\n"
  code: "#pragma once\n\n#include <string>\n#include <vector>\n\n// element next index\n\
    // res[i][c] = s[i, n) \u306B\u304A\u3044\u3066\u6B21\u306E c \u306E\u767B\u5834\
    \u4F4D\u7F6E\u3092\u8FD4\u3059\ntemplate <class T> std::vector<std::vector<int>>\
    \ element_next_index(const std::vector<T>& s) {\n    const int n = (int)(s.size());\n\
    \    T lb = std::numeric_limits<T>::max(), ub = std::numeric_limits<T>::min();\n\
    \    for (int i = 0; i < n; i++) {\n        if (lb > s[i]) lb = s[i];\n      \
    \  if (ub < s[i]) ub = s[i];\n    }\n    const int sigma = ub - lb + 1;\n    std::vector\
    \ res(n + 1, std::vector<int>(sigma, -1));\n    for (int i = n - 1; i >= 0; i--)\
    \ {\n        res[i] = res[i + 1];\n        res[i][s[i] - lb] = i;\n    }\n   \
    \ return res;\n}\n\nstd::vector<std::vector<int>> element_next_index(const std::string&\
    \ s) {\n    const int n = (int)(s.size());\n    std::vector<int> s2(n);\n    for\
    \ (int i = 0; i < n; i++) s2[i] = s[i];\n    return element_next_index(s2);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: string/element_next_index.hpp
  requiredBy: []
  timestamp: '2024-08-27 03:21:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/element_next_index.hpp
layout: document
title: "Element Next Index (\u8981\u7D20\u306E\u6B21\u306E\u767B\u5834\u4F4D\u7F6E\
  )"
---

## 使い方

```cpp
std::string s;
auto res = element_next_index(s);
```

`res[i][c]` は $i = 0, 1, ... , n$ について, $ s[i, n) $ において次の `c` の登場位置を返す

`c` は与えられた配列の要素の最小値を基準としたときの差分である（`a - z` なら `a` が $0$, `b` が $1$, ... , `z` が $26$ となる）

## 参考文献
