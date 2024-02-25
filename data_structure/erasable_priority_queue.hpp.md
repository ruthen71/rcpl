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
  bundledCode: "#line 2 \"data_structure/erasable_priority_queue.hpp\"\n#include <queue>\n\
    \n// \u8981\u7D20\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u3053\u3068\u304C\u4FDD\
    \u8A3C\u3055\u308C\u3066\u3044\u308B\u5834\u5408\u306B\u524A\u9664\u53EF\u80FD\
    \u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n// std::multiset \u3088\
    \u308A\u3082\u5B9A\u6570\u500D\u304C\u826F\u3044\n// ErasablePriorityQueue<int,\
    \ std::greater<int>> \u3068\u3059\u308C\u3070\u6700\u5C0F\u306E\u3082\u306E\u304B\
    \u3089\u9806\u306B\u53D6\u308A\u51FA\u305B\u308B\ntemplate <class T, class F =\
    \ std::less<T>> struct ErasablePriorityQueue {\n   private:\n    std::priority_queue<T,\
    \ std::vector<T>, F> que, erase_que;\n    void reduce() {\n        while (que.size()\
    \ and erase_que.size() and que.top() == erase_que.top()) {\n            que.pop();\n\
    \            erase_que.pop();\n        }\n    }\n\n   public:\n    size_t size()\
    \ const {\n        assert(que.size() >= erase_que.size());\n        return que.size()\
    \ - erase_que.size();\n    }\n    void push(const T& t) { que.push(t); }\n   \
    \ void erase(const T& t) { erase_que.push(t); }\n    const T& top() {\n      \
    \  reduce();\n        return que.top();\n    }\n    void pop() {\n        reduce();\n\
    \        que.pop();\n    }\n};\n"
  code: "#pragma once\n#include <queue>\n\n// \u8981\u7D20\u304C\u542B\u307E\u308C\
    \u3066\u3044\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\u3066\u3044\u308B\
    \u5834\u5408\u306B\u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\
    \u30AD\u30E5\u30FC\n// std::multiset \u3088\u308A\u3082\u5B9A\u6570\u500D\u304C\
    \u826F\u3044\n// ErasablePriorityQueue<int, std::greater<int>> \u3068\u3059\u308C\
    \u3070\u6700\u5C0F\u306E\u3082\u306E\u304B\u3089\u9806\u306B\u53D6\u308A\u51FA\
    \u305B\u308B\ntemplate <class T, class F = std::less<T>> struct ErasablePriorityQueue\
    \ {\n   private:\n    std::priority_queue<T, std::vector<T>, F> que, erase_que;\n\
    \    void reduce() {\n        while (que.size() and erase_que.size() and que.top()\
    \ == erase_que.top()) {\n            que.pop();\n            erase_que.pop();\n\
    \        }\n    }\n\n   public:\n    size_t size() const {\n        assert(que.size()\
    \ >= erase_que.size());\n        return que.size() - erase_que.size();\n    }\n\
    \    void push(const T& t) { que.push(t); }\n    void erase(const T& t) { erase_que.push(t);\
    \ }\n    const T& top() {\n        reduce();\n        return que.top();\n    }\n\
    \    void pop() {\n        reduce();\n        que.pop();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/erasable_priority_queue.hpp
  requiredBy: []
  timestamp: '2024-02-25 19:21:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/erasable_priority_queue.hpp
layout: document
title: "Erasable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\u304D\
  \u30AD\u30E5\u30FC)"
---

要素が含まれていることが保証されている場合に削除可能

`std::multiset` よりも定数倍が良い

比較関数を自分で定義する場合は `ErasablePriorityQueue<int, std::greater<int>>` などとする
