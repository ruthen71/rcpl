---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/data_structure/erasable_priority_queue.test.cpp
    title: verify/data_structure/erasable_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/erasable_priority_queue.hpp\"\n\n#include\
    \ <queue>\n#include <cassert>\n\n// \u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\
    \u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n// \u30AD\u30E5\u30FC\u306B\u542B\u307E\u308C\
    \u3066\u3044\u306A\u3044\u8981\u7D20\u3092\u524A\u9664\u3057\u3088\u3046\u3068\
    \u3057\u305F\u5834\u5408\u58CA\u308C\u308B\n// std::multiset \u3088\u308A\u3082\
    \u5B9A\u6570\u500D\u304C\u826F\u3044\ntemplate <class T, class Container = std::vector<T>,\
    \ class Compare = std::less<T>> struct ErasablePriorityQueue {\n   private:\n\
    \    std::priority_queue<T, Container, Compare> que, erase_que;\n    void reduce()\
    \ {\n        while (que.size() and erase_que.size()) {\n            if (que.top()\
    \ == erase_que.top()) {\n                que.pop();\n                erase_que.pop();\n\
    \            } else {\n                // Compare = std::less<T> \u306A\u3089\
    \ que.top() < erase_que.top()\n                // Compare()(que.top(), erase_que.top())\
    \ == true\n                assert(!Compare()(que.top(), erase_que.top()));\n \
    \               break;\n            }\n        }\n    }\n\n   public:\n    size_t\
    \ size() const {\n        assert(que.size() >= erase_que.size());\n        return\
    \ que.size() - erase_que.size();\n    }\n    void push(const T t) { que.push(t);\
    \ }\n    void erase(const T t) { erase_que.push(t); }\n    const T& top() {\n\
    \        reduce();\n        return que.top();\n    }\n    void pop() {\n     \
    \   reduce();\n        que.pop();\n    }\n};\n// ErasablePriorityQueue<int, std::vector<int>,\
    \ std::greater<int>> que; // \u6700\u5C0F\u306E\u3082\u306E\u304B\u3089\u53D6\u308A\
    \u51FA\u305B\u308B\n"
  code: "#pragma once\n\n#include <queue>\n#include <cassert>\n\n// \u524A\u9664\u53EF\
    \u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n// \u30AD\u30E5\u30FC\
    \u306B\u542B\u307E\u308C\u3066\u3044\u306A\u3044\u8981\u7D20\u3092\u524A\u9664\
    \u3057\u3088\u3046\u3068\u3057\u305F\u5834\u5408\u58CA\u308C\u308B\n// std::multiset\
    \ \u3088\u308A\u3082\u5B9A\u6570\u500D\u304C\u826F\u3044\ntemplate <class T, class\
    \ Container = std::vector<T>, class Compare = std::less<T>> struct ErasablePriorityQueue\
    \ {\n   private:\n    std::priority_queue<T, Container, Compare> que, erase_que;\n\
    \    void reduce() {\n        while (que.size() and erase_que.size()) {\n    \
    \        if (que.top() == erase_que.top()) {\n                que.pop();\n   \
    \             erase_que.pop();\n            } else {\n                // Compare\
    \ = std::less<T> \u306A\u3089 que.top() < erase_que.top()\n                //\
    \ Compare()(que.top(), erase_que.top()) == true\n                assert(!Compare()(que.top(),\
    \ erase_que.top()));\n                break;\n            }\n        }\n    }\n\
    \n   public:\n    size_t size() const {\n        assert(que.size() >= erase_que.size());\n\
    \        return que.size() - erase_que.size();\n    }\n    void push(const T t)\
    \ { que.push(t); }\n    void erase(const T t) { erase_que.push(t); }\n    const\
    \ T& top() {\n        reduce();\n        return que.top();\n    }\n    void pop()\
    \ {\n        reduce();\n        que.pop();\n    }\n};\n// ErasablePriorityQueue<int,\
    \ std::vector<int>, std::greater<int>> que; // \u6700\u5C0F\u306E\u3082\u306E\u304B\
    \u3089\u53D6\u308A\u51FA\u305B\u308B"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/erasable_priority_queue.hpp
  requiredBy: []
  timestamp: '2024-08-09 02:21:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/data_structure/erasable_priority_queue.test.cpp
documentation_of: data_structure/erasable_priority_queue.hpp
layout: document
title: "Erasable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\u304D\
  \u30AD\u30E5\u30FC)"
---

## 使い方

```cpp
ErasablePriorityQueue<int> que;                                         // 大きい順
ErasablePriorityQueue<int, std::vector<int>, std::greater<int>> que;    // 小さい順
```

要素が含まれていることが保証されている場合に削除可能

`std::multiset` よりも定数倍が良い

## 参考文献

- [AtCoder Beginner Contest 342 G - Retroactive Range Chmax](https://atcoder.jp/contests/abc342/tasks/abc342_g)
    - Dual Segment Tree における作用素を `ErasablePriorityQueue` を用いてすべて持っておくことで Undo 操作を実現している
