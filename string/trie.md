---
title: Trie (トライ木)
documentation_of: ./trie.hpp
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
