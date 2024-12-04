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
  bundledCode: "#line 2 \"debug.hpp\"\n\n#include <iomanip>\n#include <utility>\n\
    #include <tuple>\n#include <array>\n#include <vector>\n#include <deque>\n#include\
    \ <set>\n#include <unordered_set>\n#include <map>\n#include <unordered_map>\n\
    #include <queue>\n\n#define show(x) std::cerr << std::setprecision(15) << __LINE__\
    \ << \" : \" << #x << \" = \" << (x) << std::endl\n\ntemplate <class OStream,\
    \ class T, class U> OStream& operator<<(OStream& os, const std::pair<T, U>& pir);\n\
    template <class OStream, class... T> OStream& operator<<(OStream& os, const std::tuple<T...>&\
    \ tpl);\ntemplate <class OStream, class T, size_t sz> OStream& operator<<(OStream&\
    \ os, const std::array<T, sz>& arr);\ntemplate <class OStream, class T> OStream&\
    \ operator<<(OStream& os, const std::vector<T>& vec);\ntemplate <class OStream,\
    \ class T> OStream& operator<<(OStream& os, const std::deque<T>& vec);\ntemplate\
    \ <class OStream, class T> OStream& operator<<(OStream& os, const std::set<T>&\
    \ vec);\ntemplate <class OStream, class T> OStream& operator<<(OStream& os, const\
    \ std::multiset<T>& vec);\ntemplate <class OStream, class T, class TH> OStream&\
    \ operator<<(OStream& os, const std::unordered_set<T, TH>& vec);\ntemplate <class\
    \ OStream, class T, class TH> OStream& operator<<(OStream& os, const std::unordered_multiset<T,\
    \ TH>& vec);\ntemplate <class OStream, class TK, class TV> OStream& operator<<(OStream&\
    \ os, const std::map<TK, TV>& mp);\ntemplate <class OStream, class TK, class TV,\
    \ class TH> OStream& operator<<(OStream& os, const std::unordered_map<TK, TV,\
    \ TH>& mp);\ntemplate <class OStream, class T> OStream& operator<<(OStream& os,\
    \ std::queue<T> que);\ntemplate <class OStream, class T, class Container, class\
    \ Compare> OStream& operator<<(OStream& os, std::priority_queue<T, Container,\
    \ Compare> pque);\n\n// pair\ntemplate <class OStream, class T, class U> OStream&\
    \ operator<<(OStream& os, const std::pair<T, U>& pir) { return os << \"(\" <<\
    \ pir.first << \", \" << pir.second << \")\"; }\n// tuple\ntemplate <class OStream,\
    \ class... T> OStream& operator<<(OStream& os, const std::tuple<T...>& tpl) {\n\
    \    os << \"(\";\n    std::apply([&os](auto&&... args) { ((os << args << \",\
    \ \"), ...); }, tpl);\n    return os << \")\";\n}\n// array\ntemplate <class OStream,\
    \ class T, size_t sz> OStream& operator<<(OStream& os, const std::array<T, sz>&\
    \ arr) {\n    os << \"[ \";\n    for (auto v : arr) os << v << \" \";\n    return\
    \ os << \"]\";\n}\n// vector\ntemplate <class OStream, class T> OStream& operator<<(OStream&\
    \ os, const std::vector<T>& vec) {\n    os << \"[ \";\n    for (auto v : vec)\
    \ os << v << \" \";\n    return os << \"]\";\n}\n// deque\ntemplate <class OStream,\
    \ class T> OStream& operator<<(OStream& os, const std::deque<T>& vec) {\n    os\
    \ << \"[ \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"]\"\
    ;\n}\n// set\ntemplate <class OStream, class T> OStream& operator<<(OStream& os,\
    \ const std::set<T>& vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v\
    \ << \" \";\n    return os << \"}\";\n}\n// multiset\ntemplate <class OStream,\
    \ class T> OStream& operator<<(OStream& os, const std::multiset<T>& vec) {\n \
    \   os << \"{ \";\n    for (auto v : vec) os << v << \" \";\n    return os <<\
    \ \"}\";\n}\n// unordered_set\ntemplate <class OStream, class T, class TH> OStream&\
    \ operator<<(OStream& os, const std::unordered_set<T, TH>& vec) {\n    os << \"\
    { \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"}\";\n}\n\
    // unordered_multiset\ntemplate <class OStream, class T, class TH> OStream& operator<<(OStream&\
    \ os, const std::unordered_multiset<T, TH>& vec) {\n    os << \"{ \";\n    for\
    \ (auto v : vec) os << v << \" \";\n    return os << \"}\";\n}\n// map\ntemplate\
    \ <class OStream, class TK, class TV> OStream& operator<<(OStream& os, const std::map<TK,\
    \ TV>& mp) {\n    os << \"{ \";\n    for (auto v : mp) os << v << \" \";\n   \
    \ return os << \"}\";\n}\n// unordered_map\ntemplate <class OStream, class TK,\
    \ class TV, class TH> OStream& operator<<(OStream& os, const std::unordered_map<TK,\
    \ TV, TH>& mp) {\n    os << \"{ \";\n    for (auto v : mp) os << v << \" \";\n\
    \    return os << \"}\";\n}\n// queue\ntemplate <class OStream, class T> OStream&\
    \ operator<<(OStream& os, std::queue<T> que) {\n    std::vector<T> vec;\n    while\
    \ (!que.empty()) {\n        auto v = que.front();\n        que.pop();\n      \
    \  vec.push_back(v);\n    }\n    os << vec;\n    for (auto v : vec) que.push(v);\n\
    \    return os;\n}\n// priority_queue\ntemplate <class OStream, class T, class\
    \ Container, class Compare> OStream& operator<<(OStream& os, std::priority_queue<T,\
    \ Container, Compare> pque) {\n    std::vector<T> vec;\n    while (!pque.empty())\
    \ {\n        auto v = pque.top();\n        pque.pop();\n        vec.push_back(v);\n\
    \    }\n    os << vec;\n    for (auto v : vec) pque.push(v);\n    return os;\n\
    }\n"
  code: "#pragma once\n\n#include <iomanip>\n#include <utility>\n#include <tuple>\n\
    #include <array>\n#include <vector>\n#include <deque>\n#include <set>\n#include\
    \ <unordered_set>\n#include <map>\n#include <unordered_map>\n#include <queue>\n\
    \n#define show(x) std::cerr << std::setprecision(15) << __LINE__ << \" : \" <<\
    \ #x << \" = \" << (x) << std::endl\n\ntemplate <class OStream, class T, class\
    \ U> OStream& operator<<(OStream& os, const std::pair<T, U>& pir);\ntemplate <class\
    \ OStream, class... T> OStream& operator<<(OStream& os, const std::tuple<T...>&\
    \ tpl);\ntemplate <class OStream, class T, size_t sz> OStream& operator<<(OStream&\
    \ os, const std::array<T, sz>& arr);\ntemplate <class OStream, class T> OStream&\
    \ operator<<(OStream& os, const std::vector<T>& vec);\ntemplate <class OStream,\
    \ class T> OStream& operator<<(OStream& os, const std::deque<T>& vec);\ntemplate\
    \ <class OStream, class T> OStream& operator<<(OStream& os, const std::set<T>&\
    \ vec);\ntemplate <class OStream, class T> OStream& operator<<(OStream& os, const\
    \ std::multiset<T>& vec);\ntemplate <class OStream, class T, class TH> OStream&\
    \ operator<<(OStream& os, const std::unordered_set<T, TH>& vec);\ntemplate <class\
    \ OStream, class T, class TH> OStream& operator<<(OStream& os, const std::unordered_multiset<T,\
    \ TH>& vec);\ntemplate <class OStream, class TK, class TV> OStream& operator<<(OStream&\
    \ os, const std::map<TK, TV>& mp);\ntemplate <class OStream, class TK, class TV,\
    \ class TH> OStream& operator<<(OStream& os, const std::unordered_map<TK, TV,\
    \ TH>& mp);\ntemplate <class OStream, class T> OStream& operator<<(OStream& os,\
    \ std::queue<T> que);\ntemplate <class OStream, class T, class Container, class\
    \ Compare> OStream& operator<<(OStream& os, std::priority_queue<T, Container,\
    \ Compare> pque);\n\n// pair\ntemplate <class OStream, class T, class U> OStream&\
    \ operator<<(OStream& os, const std::pair<T, U>& pir) { return os << \"(\" <<\
    \ pir.first << \", \" << pir.second << \")\"; }\n// tuple\ntemplate <class OStream,\
    \ class... T> OStream& operator<<(OStream& os, const std::tuple<T...>& tpl) {\n\
    \    os << \"(\";\n    std::apply([&os](auto&&... args) { ((os << args << \",\
    \ \"), ...); }, tpl);\n    return os << \")\";\n}\n// array\ntemplate <class OStream,\
    \ class T, size_t sz> OStream& operator<<(OStream& os, const std::array<T, sz>&\
    \ arr) {\n    os << \"[ \";\n    for (auto v : arr) os << v << \" \";\n    return\
    \ os << \"]\";\n}\n// vector\ntemplate <class OStream, class T> OStream& operator<<(OStream&\
    \ os, const std::vector<T>& vec) {\n    os << \"[ \";\n    for (auto v : vec)\
    \ os << v << \" \";\n    return os << \"]\";\n}\n// deque\ntemplate <class OStream,\
    \ class T> OStream& operator<<(OStream& os, const std::deque<T>& vec) {\n    os\
    \ << \"[ \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"]\"\
    ;\n}\n// set\ntemplate <class OStream, class T> OStream& operator<<(OStream& os,\
    \ const std::set<T>& vec) {\n    os << \"{ \";\n    for (auto v : vec) os << v\
    \ << \" \";\n    return os << \"}\";\n}\n// multiset\ntemplate <class OStream,\
    \ class T> OStream& operator<<(OStream& os, const std::multiset<T>& vec) {\n \
    \   os << \"{ \";\n    for (auto v : vec) os << v << \" \";\n    return os <<\
    \ \"}\";\n}\n// unordered_set\ntemplate <class OStream, class T, class TH> OStream&\
    \ operator<<(OStream& os, const std::unordered_set<T, TH>& vec) {\n    os << \"\
    { \";\n    for (auto v : vec) os << v << \" \";\n    return os << \"}\";\n}\n\
    // unordered_multiset\ntemplate <class OStream, class T, class TH> OStream& operator<<(OStream&\
    \ os, const std::unordered_multiset<T, TH>& vec) {\n    os << \"{ \";\n    for\
    \ (auto v : vec) os << v << \" \";\n    return os << \"}\";\n}\n// map\ntemplate\
    \ <class OStream, class TK, class TV> OStream& operator<<(OStream& os, const std::map<TK,\
    \ TV>& mp) {\n    os << \"{ \";\n    for (auto v : mp) os << v << \" \";\n   \
    \ return os << \"}\";\n}\n// unordered_map\ntemplate <class OStream, class TK,\
    \ class TV, class TH> OStream& operator<<(OStream& os, const std::unordered_map<TK,\
    \ TV, TH>& mp) {\n    os << \"{ \";\n    for (auto v : mp) os << v << \" \";\n\
    \    return os << \"}\";\n}\n// queue\ntemplate <class OStream, class T> OStream&\
    \ operator<<(OStream& os, std::queue<T> que) {\n    std::vector<T> vec;\n    while\
    \ (!que.empty()) {\n        auto v = que.front();\n        que.pop();\n      \
    \  vec.push_back(v);\n    }\n    os << vec;\n    for (auto v : vec) que.push(v);\n\
    \    return os;\n}\n// priority_queue\ntemplate <class OStream, class T, class\
    \ Container, class Compare> OStream& operator<<(OStream& os, std::priority_queue<T,\
    \ Container, Compare> pque) {\n    std::vector<T> vec;\n    while (!pque.empty())\
    \ {\n        auto v = pque.top();\n        pque.pop();\n        vec.push_back(v);\n\
    \    }\n    os << vec;\n    for (auto v : vec) pque.push(v);\n    return os;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2024-12-04 12:30:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
