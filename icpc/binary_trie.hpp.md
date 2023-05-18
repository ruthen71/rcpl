---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/3333
  bundledCode: "#line 2 \"icpc/binary_trie.hpp\"\n\n#include <vector>\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3333\n\
    \ntemplate <class T, int B = 32> class BinaryTrie {\n   public:\n    struct Node\
    \ {\n        int size;\n        int l, r;\n        Node() : size(0), l(-1), r(-1)\
    \ {}\n        friend std::ostream& operator<<(std::ostream& os, const Node& v)\
    \ { return os << \"{ \" << v.size << \", \" << v.l << \", \" << v.r << \" }\"\
    ; }\n    };\n    std::vector<Node> nodes;\n\n    BinaryTrie() : nodes(std::vector<Node>(0))\
    \ { nodes.push_back(Node()); }\n\n    void insert(T val) { add(0, val); }\n  \
    \  void erase(T val) { sub(0, val); }\n    T min_element(T x) { return get_min(0,\
    \ x); }\n    T max_element(T x) { return get_min(0, ~x); }\n\n   private:\n  \
    \  int add(int id, T val, int b = B - 1) {\n        if (id == -1) {\n        \
    \    id = int(nodes.size());\n            nodes.push_back(Node());\n        }\n\
    \        nodes[id].size++;\n        if (b < 0) return id;\n        if (val >>\
    \ b & 1) {\n            nodes[id].r = add(nodes[id].r, val, b - 1);\n        }\
    \ else {\n            nodes[id].l = add(nodes[id].l, val, b - 1);\n        }\n\
    \        return id;\n    }\n\n    int sub(int id, T val, int b = B - 1) {\n  \
    \      assert(id != -1);\n        nodes[id].size--;\n        if (b < 0) return\
    \ id;\n        if (val >> b & 1) {\n            nodes[id].r = sub(nodes[id].r,\
    \ val, b - 1);\n        } else {\n            nodes[id].l = sub(nodes[id].l, val,\
    \ b - 1);\n        }\n        return id;\n    }\n\n    T get_min(int id, T val,\
    \ int b = B - 1) {\n        assert(id != -1);\n        if (b < 0) return 0;\n\
    \        int i = val >> b & 1;\n        if (i == 1 and (nodes[id].r == -1 or nodes[nodes[id].r].size\
    \ == 0)) i = 0;\n        if (i == 0 and (nodes[id].l == -1 or nodes[nodes[id].l].size\
    \ == 0)) i = 1;\n        int diff = (val >> b & 1) != i;\n        if (i == 1)\
    \ {\n            return get_min(nodes[id].r, val, b - 1) ^ (diff << b);\n    \
    \    } else {\n            return get_min(nodes[id].l, val, b - 1) ^ (diff <<\
    \ b);\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3333\n\
    \ntemplate <class T, int B = 32> class BinaryTrie {\n   public:\n    struct Node\
    \ {\n        int size;\n        int l, r;\n        Node() : size(0), l(-1), r(-1)\
    \ {}\n        friend std::ostream& operator<<(std::ostream& os, const Node& v)\
    \ { return os << \"{ \" << v.size << \", \" << v.l << \", \" << v.r << \" }\"\
    ; }\n    };\n    std::vector<Node> nodes;\n\n    BinaryTrie() : nodes(std::vector<Node>(0))\
    \ { nodes.push_back(Node()); }\n\n    void insert(T val) { add(0, val); }\n  \
    \  void erase(T val) { sub(0, val); }\n    T min_element(T x) { return get_min(0,\
    \ x); }\n    T max_element(T x) { return get_min(0, ~x); }\n\n   private:\n  \
    \  int add(int id, T val, int b = B - 1) {\n        if (id == -1) {\n        \
    \    id = int(nodes.size());\n            nodes.push_back(Node());\n        }\n\
    \        nodes[id].size++;\n        if (b < 0) return id;\n        if (val >>\
    \ b & 1) {\n            nodes[id].r = add(nodes[id].r, val, b - 1);\n        }\
    \ else {\n            nodes[id].l = add(nodes[id].l, val, b - 1);\n        }\n\
    \        return id;\n    }\n\n    int sub(int id, T val, int b = B - 1) {\n  \
    \      assert(id != -1);\n        nodes[id].size--;\n        if (b < 0) return\
    \ id;\n        if (val >> b & 1) {\n            nodes[id].r = sub(nodes[id].r,\
    \ val, b - 1);\n        } else {\n            nodes[id].l = sub(nodes[id].l, val,\
    \ b - 1);\n        }\n        return id;\n    }\n\n    T get_min(int id, T val,\
    \ int b = B - 1) {\n        assert(id != -1);\n        if (b < 0) return 0;\n\
    \        int i = val >> b & 1;\n        if (i == 1 and (nodes[id].r == -1 or nodes[nodes[id].r].size\
    \ == 0)) i = 0;\n        if (i == 0 and (nodes[id].l == -1 or nodes[nodes[id].l].size\
    \ == 0)) i = 1;\n        int diff = (val >> b & 1) != i;\n        if (i == 1)\
    \ {\n            return get_min(nodes[id].r, val, b - 1) ^ (diff << b);\n    \
    \    } else {\n            return get_min(nodes[id].l, val, b - 1) ^ (diff <<\
    \ b);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: icpc/binary_trie.hpp
  requiredBy: []
  timestamp: '2023-05-18 16:04:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/binary_trie.hpp
layout: document
redirect_from:
- /library/icpc/binary_trie.hpp
- /library/icpc/binary_trie.hpp.html
title: icpc/binary_trie.hpp
---
