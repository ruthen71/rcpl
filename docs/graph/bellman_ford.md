# Bellman-Ford algorithm (ベルマンフォード法)

## 概要

- 到達できない場合は `INF`
- 負閉路を使って小さくできる場合は `-INF`
- 多始点スタートに対応
- `s` に始点となる頂点を入れて、`auto [dist, par, root] = bellman_ford(G, s, INF);` で距離、親、始点が各頂点について得られる
