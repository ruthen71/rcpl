# rcpl

[![Actions Status](https://github.com/ruthen71/rcpl/workflows/verify/badge.svg)](https://github.com/ruthen71/rcpl/actions)

[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://ruthen71.github.io/rcpl/)


## AtCoder の問題で verify する方法

[AtCoder のテストケース](https://atcoder.jp/posts/20) で公開されているテストケースを利用してライブラリを verify することができる

[Online Judge Verification Helper の細かい仕様](https://online-judge-tools.github.io/verification-helper/document.ja.html) によれば, AtCoder の問題のテストケースをダウンロードするためには環境変数 `DROPBOX_TOKEN` の設定が必要

token 取得のために `$ oj d --system https://atcoder.jp/contests/agc001/tasks/agc001_a` を手元で実行すると以下のような案内が表示される

```txt
1. Open the following URL in your browser:
    https://www.dropbox.com/oauth2/authorize?client_id=153gig8dqgk3ujg&response_type=code
2. Authorize the app and take the access code.
3. ...
```

ところがこの App は更新が停止しており, `アプリ接続中のエラー：レビューが承認待ちのままになっているので、このアプリで追加ユーザーをリンクできません。` と表示される


解決策として以下の記事を参考に Dropbox のアプリを自分で作成して token を取得した

参考: [online-judge-tooolsでAtCoderのテストケースを取得できない](https://sizk.hatenablog.com/entry/2023/08/20/045153)


1. Dropbox アカウントの作成
1. Dropbox アプリの作成
    - [Dropbox Develpers](https://www.dropbox.com/developers/apps) の `Create app` を選択
    - Choose an API: `Scoped access`
    - Choose the type of access you need: `Full Dropbox`
    - Name your app: `rcpl-verify-atcoder` など
1. Permission の変更
    - Dropbox アプリの設定ページの `Permissions` タブから `files.metadata.read` と `sharing.read` にチェックを入れて保存
1. アクセストークンの取得
    - Dropbox アプリの設定ページの `Settings` タブから `Generated access token` でアクセストークンを取得
    - アクセスコードの取得などはいらない
1. テストケースの取得
    - `oj download https://atcoder.jp/contests/agc001/tasks/agc001_a --system --dropbox-token=${ACCESS_TOKEN}`
    - `${ACCESS_TOKEN}` という文字列を実際のアクセストークンで置き換える

注意: トークンは直接ではなく [ここ](https://github.com/ruthen71/rcpl/settings/secrets/actions) に書くこと

`.github/workflows/verify.yml` が読み取ってくれる

テストが途中で終了した場合, 適宜空コミット `git commit --allow-empty -m "empty"` をする


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
- パスカルケースにおいて, BFS (Breadth First Search) などはすべて大文字でも良い
    - 2D (2 Dimensional) など
    - 省略しないパスカルケースの頭文字を取っていくと考える
- クラスは使う場面がほぼなさそう

```cpp
#pragma once

#include "hoge/fuga.hpp"    // 必要なライブラリ

#include <vector>   // 必要なヘッダー

// 名前
// 計算量
// アルゴリズムの解説, リンクなど
template <class T> struct StructName {
    ...
};
```

### verify ファイルと docs ファイルについて

以下では `data_structure/segment_tree.hpp` を例とする
- verify ファイルは `verify/data_structure/segment_tree.test.cpp` とする
    - ファイルが複数ある場合は `segment_tree_1.test.cpp`, `segment_tree_2.test.cpp`, ... とする

```cpp
#define PROBLEM "https://..."   // 問題の URL

#include <iostream> // 必要なヘッダー

#include "data_structure/segment_tree.hpp"  // 必要なライブラリ

int main() {
    ...
    return 0;
}
```

- docs ファイルは `data_structure/segment_tree.md` とする
    - `title` は日本語のみ or 英語+(日本語)

~~~md
---
title: Segment Tree (セグメント木)
documentation_of: ./segment_tree.hpp
---

## 使い方

```cpp
// 構造体の宣言方法や関数の利用方法を実際のコードを使い説明
```

## 参考文献
- [文献タイトル, 問題名](URL)
    - コメント (あれば)

~~~

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
- `&&` や `||` ではなく `and` や `or` を使う
- `assert()` を除いて 1 行で書ける関数はなるべく `inline` を付ける
- 戻り値で `std::vector` や `std::map` などを返すときには `std::move()` を使うとコピーコストが削減できる
