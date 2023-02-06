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
  bundledCode: "#line 2 \"string/run_length_encoding.hpp\"\n\nstd::vector<std::pair<char,\
    \ int>> run_length_encoding(std::string &S) {\n    assert(S.size() > 0);\n   \
    \ std::vector<std::pair<char, int>> res = {{S.front(), 0}};\n    for (auto &si\
    \ : S) {\n        if (si != res.back().first) {\n            res.push_back({si,\
    \ 0});\n        }\n        res.back().second++;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nstd::vector<std::pair<char, int>> run_length_encoding(std::string\
    \ &S) {\n    assert(S.size() > 0);\n    std::vector<std::pair<char, int>> res\
    \ = {{S.front(), 0}};\n    for (auto &si : S) {\n        if (si != res.back().first)\
    \ {\n            res.push_back({si, 0});\n        }\n        res.back().second++;\n\
    \    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2023-02-06 23:29:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run_length_encoding.hpp
layout: document
title: "Run Length Encoding (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E)"
---
