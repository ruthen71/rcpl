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
  bundledCode: "#line 2 \"string/z_algorithm.hpp\"\n\n#include <string>\n#include\
    \ <vector>\n\n// z[i] = LCP(s[0...n), s[i...n)) (LCP: Longest Common Prefix)\n\
    // |z| = |s|\ntemplate <class T> std::vector<int> z_algorithm(const std::vector<T>&\
    \ s) {\n    const int n = (int)(s.size());\n    if (n == 0) return {};\n    std::vector<int>\
    \ z(n);\n    z[0] = 0;\n    for (int i = 1, j = 0; i < n; i++) {\n        int&\
    \ k = z[i];\n        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n\
    \        while (i + k < n && s[k] == s[i + k]) k++;\n        if (j + z[j] < i\
    \ + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n    const int n = (int)(s.size());\n    std::vector<int>\
    \ s2(n);\n    for (int i = 0; i < n; i++) s2[i] = s[i];\n    return z_algorithm(s2);\n\
    }\n"
  code: "#pragma once\n\n#include <string>\n#include <vector>\n\n// z[i] = LCP(s[0...n),\
    \ s[i...n)) (LCP: Longest Common Prefix)\n// |z| = |s|\ntemplate <class T> std::vector<int>\
    \ z_algorithm(const std::vector<T>& s) {\n    const int n = (int)(s.size());\n\
    \    if (n == 0) return {};\n    std::vector<int> z(n);\n    z[0] = 0;\n    for\
    \ (int i = 1, j = 0; i < n; i++) {\n        int& k = z[i];\n        k = (j + z[j]\
    \ <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n        while (i + k < n && s[k]\
    \ == s[i + k]) k++;\n        if (j + z[j] < i + z[i]) j = i;\n    }\n    z[0]\
    \ = n;\n    return z;\n}\n\nstd::vector<int> z_algorithm(const std::string& s)\
    \ {\n    const int n = (int)(s.size());\n    std::vector<int> s2(n);\n    for\
    \ (int i = 0; i < n; i++) s2[i] = s[i];\n    return z_algorithm(s2);\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2026-04-11 01:01:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
