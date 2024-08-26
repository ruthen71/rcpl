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
  bundledCode: "#line 2 \"string/trie.hpp\"\n\n#include <array>\n#include <string>\n\
    #include <vector>\n\ntemplate <int CharSize = 26, int Base = 'a'> struct Trie\
    \ {\n    struct Node {\n        std::array<int, CharSize> next;  // \u5B50 Node\
    \ \u306E id (-1 \u3067\u521D\u671F\u5316)\n        std::vector<int> accept;  \
    \       // \u3053\u306E Node \u3067\u7D42\u308F\u308B\u6587\u5B57\u5217\u306E\
    \ id\n        int val;                         // Node \u304C\u6301\u3064\u6587\
    \u5B57 (-Base)\n        int common;                      // Node \u3092\u901A\u308B\
    \u6587\u5B57\u5217\u306E\u500B\u6570\n        Node(int val = -1) : val(val), common(0)\
    \ { next.fill(-1); }\n    };\n\n    std::vector<Node> nodes;\n    int root;\n\n\
    \    Trie() : root(0) { nodes.push_back(Node(-1)); }\n\n    // s[word_id] \u306B\
    \u5BFE\u5FDC\u3059\u308B Node \u304C next_id\n    void update_child(int node_id,\
    \ int next_id, int word_id) {\n        nodes[node_id].common++;\n        return;\n\
    \    }\n\n    // s[-1] \u306B\u5BFE\u5FDC\u3059\u308B Node \u304C node_id\n  \
    \  void update_direct(int node_id, int word_id) {\n        nodes[node_id].accept.push_back(word_id);\n\
    \        return;\n    }\n\n    // \u6587\u5B57\u5217 s \u3092\u8FFD\u52A0\n  \
    \  void insert(const std::string& s) {\n        int word_id = nodes[root].common,\
    \ node_id = root;\n        for (int i = 0; i < (int)(s.size()); i++) {\n     \
    \       int val = (int)(s[i] - Base);\n            int next_id = nodes[node_id].next[val];\n\
    \            if (next_id == -1) {\n                // make new node\n        \
    \        next_id = (int)(nodes.size());\n                nodes.push_back(Node(val));\n\
    \            }\n            update_child(node_id, next_id, word_id);\n       \
    \     nodes[node_id].next[val] = next_id;\n            node_id = next_id;\n  \
    \      }\n        update_child(node_id, -1, word_id);\n        update_direct(node_id,\
    \ word_id);\n        return;\n    }\n\n    // \u6587\u5B57\u5217 s \u306E\u500B\
    \u6570\n    int count(const std::string& s, bool prefix = false) {\n        int\
    \ node_id = root;\n        for (int i = 0; i < (int)(s.size()); i++) {\n     \
    \       int val = (int)(s[i] - Base);\n            int next_id = nodes[node_id].next[val];\n\
    \            if (next_id == -1) {\n                return 0;\n            }\n\
    \            node_id = next_id;\n        }\n        return prefix ? nodes[node_id].common\
    \ : (int)(nodes[node_id].accept.size());\n    }\n\n    // \u6587\u5B57\u5217 s\
    \ \u3067\u59CB\u307E\u308B\u6587\u5B57\u5217\u306E\u500B\u6570\n    int count_prefix(const\
    \ std::string& s) { return count(s, true); }\n\n    // \u8FFD\u52A0\u3057\u305F\
    \u6587\u5B57\u5217\u306E\u500B\u6570\n    int count() const { return nodes[root].common;\
    \ }\n\n    // \u30CE\u30FC\u30C9\u6570\n    int size() const { return (int)(nodes.size());\
    \ }\n};\n"
  code: "#pragma once\n\n#include <array>\n#include <string>\n#include <vector>\n\n\
    template <int CharSize = 26, int Base = 'a'> struct Trie {\n    struct Node {\n\
    \        std::array<int, CharSize> next;  // \u5B50 Node \u306E id (-1 \u3067\u521D\
    \u671F\u5316)\n        std::vector<int> accept;         // \u3053\u306E Node \u3067\
    \u7D42\u308F\u308B\u6587\u5B57\u5217\u306E id\n        int val;              \
    \           // Node \u304C\u6301\u3064\u6587\u5B57 (-Base)\n        int common;\
    \                      // Node \u3092\u901A\u308B\u6587\u5B57\u5217\u306E\u500B\
    \u6570\n        Node(int val = -1) : val(val), common(0) { next.fill(-1); }\n\
    \    };\n\n    std::vector<Node> nodes;\n    int root;\n\n    Trie() : root(0)\
    \ { nodes.push_back(Node(-1)); }\n\n    // s[word_id] \u306B\u5BFE\u5FDC\u3059\
    \u308B Node \u304C next_id\n    void update_child(int node_id, int next_id, int\
    \ word_id) {\n        nodes[node_id].common++;\n        return;\n    }\n\n   \
    \ // s[-1] \u306B\u5BFE\u5FDC\u3059\u308B Node \u304C node_id\n    void update_direct(int\
    \ node_id, int word_id) {\n        nodes[node_id].accept.push_back(word_id);\n\
    \        return;\n    }\n\n    // \u6587\u5B57\u5217 s \u3092\u8FFD\u52A0\n  \
    \  void insert(const std::string& s) {\n        int word_id = nodes[root].common,\
    \ node_id = root;\n        for (int i = 0; i < (int)(s.size()); i++) {\n     \
    \       int val = (int)(s[i] - Base);\n            int next_id = nodes[node_id].next[val];\n\
    \            if (next_id == -1) {\n                // make new node\n        \
    \        next_id = (int)(nodes.size());\n                nodes.push_back(Node(val));\n\
    \            }\n            update_child(node_id, next_id, word_id);\n       \
    \     nodes[node_id].next[val] = next_id;\n            node_id = next_id;\n  \
    \      }\n        update_child(node_id, -1, word_id);\n        update_direct(node_id,\
    \ word_id);\n        return;\n    }\n\n    // \u6587\u5B57\u5217 s \u306E\u500B\
    \u6570\n    int count(const std::string& s, bool prefix = false) {\n        int\
    \ node_id = root;\n        for (int i = 0; i < (int)(s.size()); i++) {\n     \
    \       int val = (int)(s[i] - Base);\n            int next_id = nodes[node_id].next[val];\n\
    \            if (next_id == -1) {\n                return 0;\n            }\n\
    \            node_id = next_id;\n        }\n        return prefix ? nodes[node_id].common\
    \ : (int)(nodes[node_id].accept.size());\n    }\n\n    // \u6587\u5B57\u5217 s\
    \ \u3067\u59CB\u307E\u308B\u6587\u5B57\u5217\u306E\u500B\u6570\n    int count_prefix(const\
    \ std::string& s) { return count(s, true); }\n\n    // \u8FFD\u52A0\u3057\u305F\
    \u6587\u5B57\u5217\u306E\u500B\u6570\n    int count() const { return nodes[root].common;\
    \ }\n\n    // \u30CE\u30FC\u30C9\u6570\n    int size() const { return (int)(nodes.size());\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2024-08-27 02:16:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
title: "Trie (\u30C8\u30E9\u30A4\u6728)"
---

## 使い方

```cpp
Trie<26, 'a'> trie;     // a ~ z の Trie を作成
trie.insert(s);         // 文字列 s を追加
trie.count(s);          // 文字列 s の個数
trie.count_prefix(s);   // 文字列 s で始まる文字列の個数
trie.size();            // ノード数
trie.count();           // 追加した文字列の個数
```

`update_child()` と `update_direct()` は `insert()` 内の処理と並行して何かしらの処理を行いたい際に書き換える

## 参考文献
