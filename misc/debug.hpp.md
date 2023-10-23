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
  bundledCode: "#line 2 \"misc/debug.hpp\"\n\n#include <iomanip>\n#include <utility>\n\
    #include <tuple>\n#include <array>\n#include <vector>\n#include <deque>\n#include\
    \ <set>\n#include <unordered_set>\n#include <map>\n#include <unordered_map>\n\n\
    #define show(x) std::cerr << std::setprecision(15) << __LINE__ << \" : \" << #x\
    \ << \" = \" << (x) << std::endl\n\ntemplate <class OStream, class T, class U>\
    \ OStream &operator<<(OStream &os, const std::pair<T, U> &pir);\ntemplate <class\
    \ OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...>\
    \ &tpl);\ntemplate <class OStream, class T, size_t sz> OStream &operator<<(OStream\
    \ &os, const std::array<T, sz> &arr);\ntemplate <class OStream, class T> OStream\
    \ &operator<<(OStream &os, const std::vector<T> &vec);\ntemplate <class OStream,\
    \ class T> OStream &operator<<(OStream &os, const std::deque<T> &vec);\ntemplate\
    \ <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T>\
    \ &vec);\ntemplate <class OStream, class T> OStream &operator<<(OStream &os, const\
    \ std::multiset<T> &vec);\ntemplate <class OStream, class T, class TH> OStream\
    \ &operator<<(OStream &os, const std::unordered_set<T, TH> &vec);\ntemplate <class\
    \ OStream, class T, class TH> OStream &operator<<(OStream &os, const std::unordered_multiset<T,\
    \ TH> &vec);\ntemplate <class OStream, class TK, class TV> OStream &operator<<(OStream\
    \ &os, const std::map<TK, TV> &mp);\ntemplate <class OStream, class TK, class\
    \ TV, class TH> OStream &operator<<(OStream &os, const std::unordered_map<TK,\
    \ TV, TH> &mp);\n\ntemplate <class OStream, class T, class U> OStream &operator<<(OStream\
    \ &os, const std::pair<T, U> &pir) { return os << \"(\" << pir.first << \", \"\
    \ << pir.second << \")\"; }\ntemplate <class OStream, class... T> OStream &operator<<(OStream\
    \ &os, const std::tuple<T...> &tpl) {\n    os << \"(\";\n    std::apply([&os](auto\
    \ &&...args) { ((os << args << \", \"), ...); }, tpl);\n    return os << \")\"\
    ;\n}\ntemplate <class OStream, class T, size_t sz> OStream &operator<<(OStream\
    \ &os, const std::array<T, sz> &arr) {\n    os << \"[ \";\n    for (auto v : arr)\
    \ os << v << \" \";\n    return os << \"]\";\n}\ntemplate <class OStream, class\
    \ T> OStream &operator<<(OStream &os, const std::vector<T> &vec) {\n    os <<\
    \ \"[ \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"]\";\n\
    }\ntemplate <class OStream, class T> OStream &operator<<(OStream &os, const std::deque<T>\
    \ &vec) {\n    os << \"[ \";\n    for (auto v : vec) os << v << \" \";\n    return\
    \ os << \"]\";\n}\ntemplate <class OStream, class T> OStream &operator<<(OStream\
    \ &os, const std::set<T> &vec) {\n    os << \"{ \";\n    for (auto v : vec) os\
    \ << v << \" \";\n    return os << \"}\";\n}\ntemplate <class OStream, class T>\
    \ OStream &operator<<(OStream &os, const std::multiset<T> &vec) {\n    os << \"\
    { \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"}\";\n}\n\
    template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const\
    \ std::unordered_set<T, TH> &vec) {\n    os << \"{ \";\n    for (auto v : vec)\
    \ os << v << \" \";\n    return os << \"}\";\n}\ntemplate <class OStream, class\
    \ T, class TH> OStream &operator<<(OStream &os, const std::unordered_multiset<T,\
    \ TH> &vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v << \" \";\n \
    \   return os << \"}\";\n}\ntemplate <class OStream, class TK, class TV> OStream\
    \ &operator<<(OStream &os, const std::map<TK, TV> &mp) {\n    os << \"{ \";\n\
    \    for (auto v : mp) os << v << \" \";\n    return os << \"}\";\n}\ntemplate\
    \ <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os,\
    \ const std::unordered_map<TK, TV, TH> &mp) {\n    os << \"{ \";\n    for (auto\
    \ v : mp) os << v << \" \";\n    return os << \"}\";\n}\n"
  code: "#pragma once\n\n#include <iomanip>\n#include <utility>\n#include <tuple>\n\
    #include <array>\n#include <vector>\n#include <deque>\n#include <set>\n#include\
    \ <unordered_set>\n#include <map>\n#include <unordered_map>\n\n#define show(x)\
    \ std::cerr << std::setprecision(15) << __LINE__ << \" : \" << #x << \" = \" <<\
    \ (x) << std::endl\n\ntemplate <class OStream, class T, class U> OStream &operator<<(OStream\
    \ &os, const std::pair<T, U> &pir);\ntemplate <class OStream, class... T> OStream\
    \ &operator<<(OStream &os, const std::tuple<T...> &tpl);\ntemplate <class OStream,\
    \ class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz>\
    \ &arr);\ntemplate <class OStream, class T> OStream &operator<<(OStream &os, const\
    \ std::vector<T> &vec);\ntemplate <class OStream, class T> OStream &operator<<(OStream\
    \ &os, const std::deque<T> &vec);\ntemplate <class OStream, class T> OStream &operator<<(OStream\
    \ &os, const std::set<T> &vec);\ntemplate <class OStream, class T> OStream &operator<<(OStream\
    \ &os, const std::multiset<T> &vec);\ntemplate <class OStream, class T, class\
    \ TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec);\n\
    template <class OStream, class T, class TH> OStream &operator<<(OStream &os, const\
    \ std::unordered_multiset<T, TH> &vec);\ntemplate <class OStream, class TK, class\
    \ TV> OStream &operator<<(OStream &os, const std::map<TK, TV> &mp);\ntemplate\
    \ <class OStream, class TK, class TV, class TH> OStream &operator<<(OStream &os,\
    \ const std::unordered_map<TK, TV, TH> &mp);\n\ntemplate <class OStream, class\
    \ T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pir) { return\
    \ os << \"(\" << pir.first << \", \" << pir.second << \")\"; }\ntemplate <class\
    \ OStream, class... T> OStream &operator<<(OStream &os, const std::tuple<T...>\
    \ &tpl) {\n    os << \"(\";\n    std::apply([&os](auto &&...args) { ((os << args\
    \ << \", \"), ...); }, tpl);\n    return os << \")\";\n}\ntemplate <class OStream,\
    \ class T, size_t sz> OStream &operator<<(OStream &os, const std::array<T, sz>\
    \ &arr) {\n    os << \"[ \";\n    for (auto v : arr) os << v << \" \";\n    return\
    \ os << \"]\";\n}\ntemplate <class OStream, class T> OStream &operator<<(OStream\
    \ &os, const std::vector<T> &vec) {\n    os << \"[ \";\n    for (auto v : vec)\
    \ os << v << \" \";\n    return os << \"]\";\n}\ntemplate <class OStream, class\
    \ T> OStream &operator<<(OStream &os, const std::deque<T> &vec) {\n    os << \"\
    [ \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"]\";\n}\n\
    template <class OStream, class T> OStream &operator<<(OStream &os, const std::set<T>\
    \ &vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v << \" \";\n    return\
    \ os << \"}\";\n}\ntemplate <class OStream, class T> OStream &operator<<(OStream\
    \ &os, const std::multiset<T> &vec) {\n    os << \"{ \";\n    for (auto v : vec)\
    \ os << v << \" \";\n    return os << \"}\";\n}\ntemplate <class OStream, class\
    \ T, class TH> OStream &operator<<(OStream &os, const std::unordered_set<T, TH>\
    \ &vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v << \" \";\n    return\
    \ os << \"}\";\n}\ntemplate <class OStream, class T, class TH> OStream &operator<<(OStream\
    \ &os, const std::unordered_multiset<T, TH> &vec) {\n    os << \"{ \";\n    for\
    \ (auto v : vec) os << v << \" \";\n    return os << \"}\";\n}\ntemplate <class\
    \ OStream, class TK, class TV> OStream &operator<<(OStream &os, const std::map<TK,\
    \ TV> &mp) {\n    os << \"{ \";\n    for (auto v : mp) os << v << \" \";\n   \
    \ return os << \"}\";\n}\ntemplate <class OStream, class TK, class TV, class TH>\
    \ OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp) {\n\
    \    os << \"{ \";\n    for (auto v : mp) os << v << \" \";\n    return os <<\
    \ \"}\";\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/debug.hpp
  requiredBy: []
  timestamp: '2023-10-23 12:46:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/debug.hpp
layout: document
redirect_from:
- /library/misc/debug.hpp
- /library/misc/debug.hpp.html
title: misc/debug.hpp
---
