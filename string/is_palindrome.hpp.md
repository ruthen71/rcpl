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
  bundledCode: "#line 2 \"string/is_palindrome.hpp\"\n\n#include <string>\n#include\
    \ <vector>\n\ntemplate <class T> bool is_palindrome(const std::vector<T>& s) {\n\
    \    const int n = (int)(s.size());\n    bool res = true;\n    for (int i = 0;\
    \ i < n / 2; i++) res &= s[i] == s[n - 1 - i];\n    return res;\n}\n\nbool is_palindrome(const\
    \ std::string& s) {\n    const int n = (int)(s.size());\n    std::vector<int>\
    \ s2(n);\n    for (int i = 0; i < n; i++) s2[i] = s[i];\n    return is_palindrome(s2);\n\
    }\n"
  code: "#pragma once\n\n#include <string>\n#include <vector>\n\ntemplate <class T>\
    \ bool is_palindrome(const std::vector<T>& s) {\n    const int n = (int)(s.size());\n\
    \    bool res = true;\n    for (int i = 0; i < n / 2; i++) res &= s[i] == s[n\
    \ - 1 - i];\n    return res;\n}\n\nbool is_palindrome(const std::string& s) {\n\
    \    const int n = (int)(s.size());\n    std::vector<int> s2(n);\n    for (int\
    \ i = 0; i < n; i++) s2[i] = s[i];\n    return is_palindrome(s2);\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/is_palindrome.hpp
  requiredBy: []
  timestamp: '2024-08-27 02:16:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/is_palindrome.hpp
layout: document
title: "\u56DE\u6587\u5224\u5B9A"
---

## 使い方

```cpp
std::string s;
auto res = is_palindrome(s);
```

## 参考文献
