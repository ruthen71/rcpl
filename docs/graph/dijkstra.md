---
title: Dijkstra's algorithm (ダイクストラ法)
documentation_of: ../../graph/dijkstra.hpp
---

- 多始点スタートに対応
- `s` に始点となる頂点を入れて、`auto [dist, par, root] = dijkstra(G, s, INF);` で距離、親、始点が各頂点について得られる
