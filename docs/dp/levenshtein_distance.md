---
title: Levenshtein Distance (レーベンシュタイン距離)
documentation_of: //dp/levenshtein_distance.hpp
---

Edit Distance (編集距離) とも呼ばれ, 1 文字の挿入, 1 文字の削除, 1 文字の置換を行うことで $s$ を $t$ に一致させるための操作回数を表す

DP のイメージは LCS と似ており, 編集前の $s$ における各文字が $t$ のどの文字と対応するかを考えながら計算を進める

LCS では dp 配列の更新が $s_i = t_j$ となるような対応付けを行うときのみ発生していたため, `dp[n][j]` や `dp[i][m]` からの更新は発生しなかったが, Levenshtein Distance の場合は `dp[n][j]` から $s$ に 1 文字挿入を行うことで `dp[n][j + 1]` を更新できるため, `i = n` や `j = m` からも遷移を計算する必要がある

## 使い方

```cpp
std::string s, t;
auto d = levenshtein_distance(s, t);
```

## 参考文献

- [Wikipedia, レーベンシュタイン距離](https://ja.wikipedia.org/wiki/レーベンシュタイン距離)
    - 擬似コードはもらう DP で書かれており, このライブラリは配る DP で書かれていることに注意