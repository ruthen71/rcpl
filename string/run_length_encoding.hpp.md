---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Run Length Encoding (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
      \u7E2E)"
    links: []
  bundledCode: "#line 2 \"string/run_length_encoding.hpp\"\n\nstd::vector<std::pair<char,\
    \ int>> run_length_encoding(std::string &S) {\n    assert(S.size() > 0);\n   \
    \ std::vector<std::pair<char, int>> res = {{S.front(), 0}};\n    for (auto &si\
    \ : S) {\n        if (si != res.back().first) {\n            res.push_back({si,\
    \ 0});\n        }\n        res.back().second++;\n    }\n    return res;\n}\n\n\
    /**\n * @brief Run Length Encoding (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
    \u7E2E)\n */\n"
  code: "#pragma once\n\nstd::vector<std::pair<char, int>> run_length_encoding(std::string\
    \ &S) {\n    assert(S.size() > 0);\n    std::vector<std::pair<char, int>> res\
    \ = {{S.front(), 0}};\n    for (auto &si : S) {\n        if (si != res.back().first)\
    \ {\n            res.push_back({si, 0});\n        }\n        res.back().second++;\n\
    \    }\n    return res;\n}\n\n/**\n * @brief Run Length Encoding (\u30E9\u30F3\
    \u30EC\u30F3\u30B0\u30B9\u5727\u7E2E)\n */"
  dependsOn: []
  isVerificationFile: false
  path: string/run_length_encoding.hpp
  requiredBy: []
  timestamp: '2023-02-06 17:52:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run_length_encoding.hpp
layout: document
redirect_from:
- /library/string/run_length_encoding.hpp
- /library/string/run_length_encoding.hpp.html
title: "Run Length Encoding (\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E)"
---
