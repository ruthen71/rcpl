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
  bundledCode: "#line 2 \"debug.hpp\"\n\n#include <iomanip>\n#define show(x) std::cerr\
    \ << std::setprecision(15) << __LINE__ << \" : \" << #x << \" = \" << (x) << std::endl\n\
    \n#include <utility>\ntemplate <class OStream, class T, class U> OStream &operator<<(OStream\
    \ &os, const std::pair<T, U> &pir) { return os << \"(\" << pir.first << \", \"\
    \ << pir.second << \")\"; }\n\n#include <tuple>\ntemplate <class OStream, class...\
    \ T> OStream &operator<<(OStream &os, const std::tuple<T...> &tpl) {\n    os <<\
    \ \"(\";\n    std::apply([&os](auto &&...args) { ((os << args << \", \"), ...);\
    \ }, tpl);\n    return os << \")\";\n}\n\n#include <array>\ntemplate <class OStream,\
    \ class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz>\
    \ &arr) {\n    os << \"[ \";\n    for (auto v : arr) os << v << \" \";\n    return\
    \ os << \"]\";\n}\n\n#include <vector>\ntemplate <class OStream, class T> OStream\
    \ &operator<<(OStream &os, const std::vector<T> &vec) {\n    os << \"[ \";\n \
    \   for (auto v : vec) os << v << \" \";\n    return os << \"]\";\n}\n\n#include\
    \ <deque>\ntemplate <class OStream, class T> OStream &operator<<(OStream &os,\
    \ const std::deque<T> &vec) {\n    os << \"[ \";\n    for (auto v : vec) os <<\
    \ v << \" \";\n    return os << \"]\";\n}\n\n#include <set>\ntemplate <class OStream,\
    \ class T> OStream &operator<<(OStream &os, const std::set<T> &vec) {\n    os\
    \ << \"{ \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"}\"\
    ;\n}\ntemplate <class OStream, class T> OStream &operator<<(OStream &os, const\
    \ std::multiset<T> &vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v\
    \ << \" \";\n    return os << \"}\";\n}\n\n#include <unordered_set>\ntemplate\
    \ <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T,\
    \ TH> &vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v << \" \";\n \
    \   return os << \"}\";\n}\ntemplate <class OStream, class T, class TH> OStream\
    \ &operator<<(OStream &os, const std::unordered_multiset<T, TH> &vec) {\n    os\
    \ << \"{ \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"}\"\
    ;\n}\n\n#include <map>\ntemplate <class OStream, class TK, class TV> OStream &operator<<(OStream\
    \ &os, const std::map<TK, TV> &mp) {\n    os << \"{ \";\n    for (auto v : mp)\
    \ os << v << \" \";\n    return os << \"}\";\n}\n\n#include <unordered_map>\n\
    template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream\
    \ &os, const std::unordered_map<TK, TV, TH> &mp) {\n    os << \"{ \";\n    for\
    \ (auto v : mp) os << v << \" \";\n    return os << \"}\";\n}\n"
  code: "#pragma once\n\n#include <iomanip>\n#define show(x) std::cerr << std::setprecision(15)\
    \ << __LINE__ << \" : \" << #x << \" = \" << (x) << std::endl\n\n#include <utility>\n\
    template <class OStream, class T, class U> OStream &operator<<(OStream &os, const\
    \ std::pair<T, U> &pir) { return os << \"(\" << pir.first << \", \" << pir.second\
    \ << \")\"; }\n\n#include <tuple>\ntemplate <class OStream, class... T> OStream\
    \ &operator<<(OStream &os, const std::tuple<T...> &tpl) {\n    os << \"(\";\n\
    \    std::apply([&os](auto &&...args) { ((os << args << \", \"), ...); }, tpl);\n\
    \    return os << \")\";\n}\n\n#include <array>\ntemplate <class OStream, class\
    \ T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz> &arr)\
    \ {\n    os << \"[ \";\n    for (auto v : arr) os << v << \" \";\n    return os\
    \ << \"]\";\n}\n\n#include <vector>\ntemplate <class OStream, class T> OStream\
    \ &operator<<(OStream &os, const std::vector<T> &vec) {\n    os << \"[ \";\n \
    \   for (auto v : vec) os << v << \" \";\n    return os << \"]\";\n}\n\n#include\
    \ <deque>\ntemplate <class OStream, class T> OStream &operator<<(OStream &os,\
    \ const std::deque<T> &vec) {\n    os << \"[ \";\n    for (auto v : vec) os <<\
    \ v << \" \";\n    return os << \"]\";\n}\n\n#include <set>\ntemplate <class OStream,\
    \ class T> OStream &operator<<(OStream &os, const std::set<T> &vec) {\n    os\
    \ << \"{ \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"}\"\
    ;\n}\ntemplate <class OStream, class T> OStream &operator<<(OStream &os, const\
    \ std::multiset<T> &vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v\
    \ << \" \";\n    return os << \"}\";\n}\n\n#include <unordered_set>\ntemplate\
    \ <class OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T,\
    \ TH> &vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v << \" \";\n \
    \   return os << \"}\";\n}\ntemplate <class OStream, class T, class TH> OStream\
    \ &operator<<(OStream &os, const std::unordered_multiset<T, TH> &vec) {\n    os\
    \ << \"{ \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"}\"\
    ;\n}\n\n#include <map>\ntemplate <class OStream, class TK, class TV> OStream &operator<<(OStream\
    \ &os, const std::map<TK, TV> &mp) {\n    os << \"{ \";\n    for (auto v : mp)\
    \ os << v << \" \";\n    return os << \"}\";\n}\n\n#include <unordered_map>\n\
    template <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream\
    \ &os, const std::unordered_map<TK, TV, TH> &mp) {\n    os << \"{ \";\n    for\
    \ (auto v : mp) os << v << \" \";\n    return os << \"}\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2023-10-02 21:09:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
