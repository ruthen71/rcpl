---
title: 線形ディオファントス方程式 ($ ax + by = c $) / 線形合同式 ( $ ax \equiv b \pmod m $ )
documentation_of: //math/linear_diophantine.hpp
---

線形合同式は $ \bmod m $ で $ a^{-1} $ を求めることでは解が求められない場合がある

例えば、$ 9x \equiv 3 \pmod {15} $ は $ 9^{-1} $ となる値を持たないが、$ x \equiv 2 \pmod 5 $ が解である

このような場合、拡張ユークリッドの互除法を用いることで解が求められる
