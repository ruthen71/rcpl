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
  bundledCode: "#line 2 \"string/run_length_encoding.hpp\"\n\n#include <cassert>\n\
    #include <string>\n#include <utility>\n#include <vector>\n\ntemplate <class T>\
    \ std::vector<std::pair<T, int>> run_length_encoding(const std::vector<T>& s)\
    \ {\n    assert((int)(s.size()) > 0);\n    std::vector<std::pair<T, int>> res\
    \ = {{s.front(), 0}};\n    for (auto&& si : s) {\n        if (si != res.back().first)\
    \ {\n            res.emplace_back(si, 0);\n        }\n        res.back().second++;\n\
    \    }\n    return res;\n}\n\nstd::vector<std::pair<char, int>> run_length_encoding(const\
    \ std::string& s) {\n    const int n = (int)(s.size());\n    std::vector<char>\
    \ s2(n);\n    for (int i = 0; i < n; i++) s2[i] = s[i];\n    return run_length_encoding(s2);\n\
    }\n"
  code: "#pragma once\n\n#include <cassert>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\ntemplate <class T> std::vector<std::pair<T, int>> run_length_encoding(const\
    \ std::vector<T>& s) {\n    assert((int)(s.size()) > 0);\n    std::vector<std::pair<T,\
    \ int>> res = {{s.front(), 0}};\n    for (auto&& si : s) {\n        if (si !=\
    \ res.back().first) {\n            res.emplace_back(si, 0);\n        }\n     \
    \   res.back().second++;\n    }\n    return res;\n}\n\nstd::vector<std::pair<char,\
    \ int>> run_length_encoding(const std::string& s) {\n    const int n = (int)(s.size());\n\
    \    std::vector<char> s2(n);\n    for (int i = 0; i < n; i++) s2[i] = s[i];\n\
    \    return run_length_encoding(s2);\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2024-08-27 02:17:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run_length_encoding.hpp
layout: document
title: "Run Length Encoding (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E)"
---

## 使い方

```cpp
std::string s;
auto res = run_length_encoding(s);
```

## 参考文献
