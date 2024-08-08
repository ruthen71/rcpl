---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/enumerate_segment_tree_nodes.hpp
    title: "Segment Tree \u306E 1 \u70B9\u5909\u66F4\u3084\u533A\u9593\u7DCF\u7A4D\
      \u3092\u884C\u3046\u969B\u306B\u30A2\u30AF\u30BB\u30B9\u3059\u308B\u30CE\u30FC\
      \u30C9\u756A\u53F7\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: data_structure/erasable_priority_queue.hpp
    title: "Erasable Priority Queue (\u524A\u9664\u53EF\u80FD\u512A\u5148\u5EA6\u4ED8\
      \u304D\u30AD\u30E5\u30FC)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc342/tasks/abc342_g
    links:
    - https://atcoder.jp/contests/abc342/tasks/abc342_g
  bundledCode: "#line 1 \"verify/data_structure/erasable_priority_queue.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc342/tasks/abc342_g\"\n\n#include\
    \ <iostream>\n#line 2 \"data_structure/erasable_priority_queue.hpp\"\n\n#include\
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
    \u51FA\u305B\u308B\n#line 2 \"data_structure/enumerate_segment_tree_nodes.hpp\"\
    \n\n#include <vector>\n#line 5 \"data_structure/enumerate_segment_tree_nodes.hpp\"\
    \n#include <algorithm>\n\n// \u9577\u3055 size (2\u3079\u304D) \u306E Segment\
    \ Tree \u306B\u304A\u3044\u3066\u533A\u9593 [l, r) \u3092\u30AB\u30D0\u30FC\u3059\
    \u308B\u533A\u9593\u306E\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u8FD4\u3059\n// \u533A\
    \u9593\u306E\u4F4D\u7F6E\u304C\u5C0F\u3055\u3044\u9806\u306B (\u5DE6\u304B\u3089\
    ) \u8FD4\u3059\ntemplate <class T> std::vector<T> enumerate_segment_tree_range_covering_nodes(const\
    \ T size, T l, T r) {\n    std::vector<T> ret, ret_rev;\n    l += size;\n    r\
    \ += size;\n    while (l < r) {\n        if (l & 1) ret.push_back(l++);\n    \
    \    if (r & 1) ret_rev.push_back(--r);\n        l >>= 1;\n        r >>= 1;\n\
    \    }\n    std::reverse(ret_rev.begin(), ret_rev.end());\n    ret.insert(ret.end(),\
    \ ret_rev.begin(), ret_rev.end());\n    return ret;\n}\n\n// \u9577\u3055 size\
    \ (2\u3079\u304D) \u306E Segment Tree \u306B\u304A\u3044\u3066 seg[p] \u304C\u542B\
    \u307E\u308C\u308B\u533A\u9593\u306E\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u8FD4\
    \u3059\n// \u533A\u9593\u306E\u5E45\u304C\u5C0F\u3055\u3044\u9806\u306B (\u4E0B\
    \u304B\u3089) \u8FD4\u3059\ntemplate <class T> std::vector<T> enumerate_segment_tree_point_containing_nodes(const\
    \ T size, T p) {\n    p += size;\n    std::vector<T> ret;\n    for (int i = 0;\
    \ (1LL << i) <= size; i++) ret.push_back(p >> i);\n    return ret;\n}\n\n// \u9577\
    \u3055 size (2\u3079\u304D) \u306E Segment Tree \u306B\u304A\u3044\u3066\u30CE\
    \u30FC\u30C9\u756A\u53F7 i \u306B\u5BFE\u5FDC\u3059\u308B\u533A\u9593 [l, r) \u3092\
    \u8FD4\u3059\n// https://atcoder.jp/contests/abc349/tasks/abc349_d\n// https://atcoder.jp/contests/abc355/tasks/abc355_e\n\
    template <class T> std::pair<T, T> segment_tree_node_to_range(const T size, const\
    \ T i) {\n    assert(size > 0 and i > 0);\n    // (1 << n) = size\n    const int\
    \ n = 63 - __builtin_clzll(size);\n    // i \u306E\u6700\u4E0A\u4F4D\u30D3\u30C3\
    \u30C8\n    const int topbiti = 63 - __builtin_clzll(i);\n    // [(2 ^ x) * y,\
    \ (2 ^ x) * (y + 1))\n    const int x = n - topbiti;\n    const T y = i - (1LL\
    \ << topbiti);\n    return {(1LL << x) * y, (1LL << x) * (y + 1)};\n}\n#line 6\
    \ \"verify/data_structure/erasable_priority_queue.test.cpp\"\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(0);\n    int N;\n   \
    \ std::cin >> N;\n    std::vector<int> A(N);\n    for (int i = 0; i < N; i++)\
    \ std::cin >> A[i];\n\n    // \u524A\u9664\u53EF\u80FD\u306A priority_queue \u3092\
    \u4E57\u305B\u305F\u30BB\u30B0\u6728\u3092\u4F5C\u6210\n    int log = 0;\n   \
    \ while ((1 << log) < N) log++;\n    int size = 1 << log;\n    std::vector<ErasablePriorityQueue<int>>\
    \ d(size << 1);\n    for (int i = 0; i < N; i++) d[i + size].push(A[i]);\n\n \
    \   int Q;\n    std::cin >> Q;\n    std::vector<int> l(Q, -1), r(Q, -1), x(Q,\
    \ -1), id(Q, -1);\n    for (int qq = 0; qq < Q; qq++) {\n        int type;\n \
    \       std::cin >> type;\n        if (type == 1) {\n            std::cin >> l[qq]\
    \ >> r[qq] >> x[qq];\n            l[qq]--;\n            auto nodes = enumerate_segment_tree_range_covering_nodes(size,\
    \ l[qq], r[qq]);\n            for (auto&& i : nodes) d[i].push(x[qq]);\n     \
    \   } else if (type == 2) {\n            std::cin >> id[qq];\n            id[qq]--;\n\
    \            auto nodes = enumerate_segment_tree_range_covering_nodes(size, l[id[qq]],\
    \ r[id[qq]]);\n            for (auto&& i : nodes) d[i].erase(x[id[qq]]);\n   \
    \     } else {\n            std::cin >> id[qq];\n            id[qq]--;\n     \
    \       auto nodes = enumerate_segment_tree_point_containing_nodes(size, id[qq]);\n\
    \            int mx = 0;\n            for (auto&& i : nodes) {\n             \
    \   if (d[i].size() > 0) mx = std::max(mx, d[i].top());\n            }\n     \
    \       std::cout << mx << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc342/tasks/abc342_g\"\n\n\
    #include <iostream>\n#include \"data_structure/erasable_priority_queue.hpp\"\n\
    #include \"data_structure/enumerate_segment_tree_nodes.hpp\"\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(0);\n    int N;\n   \
    \ std::cin >> N;\n    std::vector<int> A(N);\n    for (int i = 0; i < N; i++)\
    \ std::cin >> A[i];\n\n    // \u524A\u9664\u53EF\u80FD\u306A priority_queue \u3092\
    \u4E57\u305B\u305F\u30BB\u30B0\u6728\u3092\u4F5C\u6210\n    int log = 0;\n   \
    \ while ((1 << log) < N) log++;\n    int size = 1 << log;\n    std::vector<ErasablePriorityQueue<int>>\
    \ d(size << 1);\n    for (int i = 0; i < N; i++) d[i + size].push(A[i]);\n\n \
    \   int Q;\n    std::cin >> Q;\n    std::vector<int> l(Q, -1), r(Q, -1), x(Q,\
    \ -1), id(Q, -1);\n    for (int qq = 0; qq < Q; qq++) {\n        int type;\n \
    \       std::cin >> type;\n        if (type == 1) {\n            std::cin >> l[qq]\
    \ >> r[qq] >> x[qq];\n            l[qq]--;\n            auto nodes = enumerate_segment_tree_range_covering_nodes(size,\
    \ l[qq], r[qq]);\n            for (auto&& i : nodes) d[i].push(x[qq]);\n     \
    \   } else if (type == 2) {\n            std::cin >> id[qq];\n            id[qq]--;\n\
    \            auto nodes = enumerate_segment_tree_range_covering_nodes(size, l[id[qq]],\
    \ r[id[qq]]);\n            for (auto&& i : nodes) d[i].erase(x[id[qq]]);\n   \
    \     } else {\n            std::cin >> id[qq];\n            id[qq]--;\n     \
    \       auto nodes = enumerate_segment_tree_point_containing_nodes(size, id[qq]);\n\
    \            int mx = 0;\n            for (auto&& i : nodes) {\n             \
    \   if (d[i].size() > 0) mx = std::max(mx, d[i].top());\n            }\n     \
    \       std::cout << mx << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - data_structure/erasable_priority_queue.hpp
  - data_structure/enumerate_segment_tree_nodes.hpp
  isVerificationFile: true
  path: verify/data_structure/erasable_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-08-09 02:21:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/data_structure/erasable_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/data_structure/erasable_priority_queue.test.cpp
- /verify/verify/data_structure/erasable_priority_queue.test.cpp.html
title: verify/data_structure/erasable_priority_queue.test.cpp
---
