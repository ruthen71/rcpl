# rcpl

[![Actions Status](https://github.com/ruthen71/rcpl/workflows/verify/badge.svg)](https://github.com/ruthen71/rcpl/actions)

[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://ruthen71.github.io/rcpl/)

## コーディングスタイル

なるべく下表に合わせる努力（←重要!!）をする

### 命名規則

| 対象 | 例 | 説明 |
| ---- | ---- | ---- |
| ファイル名 | `my_lib.hpp` | スネークケース |
| 名前空間名 | `my_namespace` | スネークケース |
| 関数名 | `my_func` | スネークケース |
| 型名 (typedef, using, enum) | `MyInt` | パスカルケース |
| 変数名 (全般) | `my_var` | スネークケース |
| 変数名 (constexpr) | `MY_VAR` | アッパースネークケース |
| 列挙型メンバ名 | `MY_ENUM_VAR` | アッパースネークケース |
| マクロ名 | `MY_MACRO` | アッパースネークケース |
| 構造体名 | `MyStruct` | パスカルケース |
| メンバ変数名 (構造体) | `my_var` | スネークケース |
| クラス名 | `MyClass` | パスカルケース |
| メンバ変数名 (クラス) | `my_var_` | スネークケース + 末尾アンダースコア |

- なるべく省略を避ける
- スネークケースで大文字は使わない
- パスカルケースにおいて、BFS (Breadth First Search) などはすべて大文字でも良い
    - 2D (2 Dimensional) など
    - 省略しないパスカルケースの頭文字を取っていくと考える
- クラスは使う場面がほぼなさそう

### verify ファイルと docs ファイルについて

以下では `data_structure/segment_tree.hpp` を例とする
- verify ファイルは `verify/data_structure/segment_tree.test.cpp` とする
    - ファイルが複数ある場合は `segment_tree_1.test.cpp`, `segment_tree_2.test.cpp`, ... とする
- docs ファイルは `docs/data_structure/segment_tree.md` とする
    - `title` は日本語のみ or 英語+(日本語)

```md
---
title: Segment Tree (セグメント木)
documentation_of: //data_structure/segment_tree.hpp
---

## 使い方

## 使用例
- [問題名](提出URL)

## 参考文献
- [文献タイトル](URL)

```



### 細かいこと

- `#include <bits/stdc++.h>` や `using namespace std;` がなくても動くようにする
- `const` はなるべく付ける
- 入力や出力に対する `assert()` はなるべく付ける
- 参照渡しできるところは参照渡しにしてコピーコストを減らす
    - 参照渡しは `T &a` ではなく `T& a`
    - `for (auto&& e : g[v])` にすると右辺値でも左辺値でも受け取ることができる
- `size_t` から `int` への変換は `(int)(a.size())` とする
    - `int` ではなく `(int)` にしないと `#define int long long` で壊れる (そもそも未定義動作ではあるが)
- `template <typename T>` ではなく `template <class T>`
- 再帰関数の名前は `rec` ではなく `dfs`
- 構造体のコンストラクタ (引数なし) を定義し, `StructName() = default;` か引数ありのコンストラクタを呼び出す実装にする
- `std::vector` に対する `resize()` `assign()` はコンストラクタでは `StructName(int n): vec(n, 0) {}` でなるべく処理する

