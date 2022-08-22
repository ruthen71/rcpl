# Fenwick Tree (Binary Indexed Tree)

## 概要
- 一点更新区間和取得ができるデータ構造である
- 内部実装では1-indexedで、外部からは0-indexedで利用するようになっている
- `add(i, x)`: `A[i]`に`x`を加算する
- `sum(a, b)`: `A[a] + ... + A[b - 1]`を返す
