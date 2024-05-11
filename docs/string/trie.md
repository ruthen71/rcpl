---
title: Trie (トライ木)
documentation_of: //string/trie.hpp
---

`Trie<CharSize, Base>` で文字の種類数が `CharSize` で開始文字が `Base` である Trie を作成

使い方
- `insert(s)`: 文字列 `s` を追加
- `count(s)`: 文字列 `s` の個数を求める
- `count_prefix(s)`: 文字列 `s` で始まる文字列の個数を求める
- `size()`: ノード数を求める
- `count()`: 追加した文字列の個数を求める

`update_child()` と `update_direct()` は `insert` 内の処理と並行して何かしらの処理を行いたい際に書き換える
