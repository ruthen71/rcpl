---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/aoj_other/aoj_3206.text.cpp
    title: verify/aoj_other/aoj_3206.text.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/3206
  bundledCode: "#line 2 \"data_structure/dice.hpp\"\n#include <array>\n#include <cassert>\n\
    #include <string>\n#include <vector>\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3206\n\
    struct Dice {\n    std::array<int, 6> d;\n    // \u9762\n    //  2\n    // 341\n\
    \    //  0\n    //  5\n    // \u5411\u304D\n    //  v\n    // vvv\n    //  v\n\
    \    //  v\n    Dice() { d = {0, 0, 0, 0, 0, 0}; }\n    // v>^< -> 0123\n    int\
    \ ctoi(char c) {\n        if (c == 'v') return 0;\n        if (c == '>') return\
    \ 1;\n        if (c == '^') return 2;\n        if (c == '<') return 3;\n     \
    \   assert(false);\n    }\n    int cw(int x) { return (x + 3) % 4; }\n    int\
    \ ccw(int x) { return (x + 1) % 4; }\n    int rev(int x) { return (x + 2) % 4;\
    \ }\n    void rotate0() {\n        // v\u65B9\u5411\u306B\u5012\u3059\n      \
    \  // \u9762\n        //  2      4\n        // 341 => 301\n        //  0     \
    \ 5\n        //  5      2\n        // \u5411\u304D\n        //  v      v\n   \
    \     // vvv => >v<\n        //  v      v\n        //  v      v\n        d = {d[5],\
    \ cw(d[1]), d[4], ccw(d[3]), d[0], d[2]};\n    }\n    void rotate1() {\n     \
    \   // >\u65B9\u5411\u306B\u5012\u3059\n        // \u9762\n        //  2     \
    \ 2\n        // 341 => 415\n        //  0      0\n        //  5      3\n     \
    \   // \u5411\u304D\n        //  v      <\n        // vvv => vv^\n        // \
    \ v      >\n        //  v      ^\n        d = {ccw(d[0]), rev(d[5]), cw(d[2]),\
    \ d[4], d[1], rev(d[3])};\n    }\n    void rotate2() {\n        // ^\u65B9\u5411\
    \u306B\u5012\u3059\n        rotate0();\n        rotate0();\n        rotate0();\n\
    \    }\n    void rotate3() {\n        // <\u65B9\u5411\u306B\u5012\u3059\n   \
    \     rotate1();\n        rotate1();\n        rotate1();\n    }\n    void rotate_cw()\
    \ {\n        // \u6642\u8A08\u56DE\u308A\u306B\u56DE\u3059\n        // \u9762\n\
    \        //  2      3\n        // 341 => 042\n        //  0      1\n        //\
    \  5      5\n        // \u5411\u304D\n        //  v      <\n        // vvv =>\
    \ <<<\n        //  v      <\n        //  v      >\n        d = {cw(d[1]), cw(d[2]),\
    \ cw(d[3]), cw(d[0]), cw(d[4]), ccw(d[5])};\n    }\n    void rotate_ccw() {\n\
    \        // \u53CD\u6642\u8A08\u56DE\u308A\u306B\u56DE\u3059\n        rotate_cw();\n\
    \        rotate_cw();\n        rotate_cw();\n    }\n};\n\nDice read_dice(std::vector<std::string>&\
    \ s) {\n    const int h = (int)(s.size());\n    assert(h > 0);\n    const int\
    \ w = (int)(s[0].size());\n    std::vector seen(h, std::vector(w, 0));\n    Dice\
    \ res;\n    auto rec = [&](auto f, int x, int y) -> void {\n        seen[x][y]\
    \ = 1;\n        res.d[4] = res.ctoi(s[x][y]);\n        // v\n        if (x + 1\
    \ < h) {\n            int nx = x + 1, ny = y;\n            if (s[nx][ny] != '.'\
    \ and seen[nx][ny] == 0) {\n                res.rotate0();\n                f(f,\
    \ nx, ny);\n                res.rotate2();\n            }\n        }\n       \
    \ // >\n        if (y + 1 < w) {\n            int nx = x, ny = y + 1;\n      \
    \      if (s[nx][ny] != '.' and seen[nx][ny] == 0) {\n                res.rotate1();\n\
    \                f(f, nx, ny);\n                res.rotate3();\n            }\n\
    \        }\n        // ^\n        if (x - 1 >= 0) {\n            int nx = x -\
    \ 1, ny = y;\n            if (s[nx][ny] != '.' and seen[nx][ny] == 0) {\n    \
    \            res.rotate2();\n                f(f, nx, ny);\n                res.rotate0();\n\
    \            }\n        }\n        // <\n        if (y - 1 >= 0) {\n         \
    \   int nx = x, ny = y - 1;\n            if (s[nx][ny] != '.' and seen[nx][ny]\
    \ == 0) {\n                res.rotate3();\n                f(f, nx, ny);\n   \
    \             res.rotate1();\n            }\n        }\n    };\n    for (int i\
    \ = 0; i < h; i++) {\n        for (int j = 0; j < w; j++) {\n            if (s[i][j]\
    \ != '.' and seen[i][j] == 0) rec(rec, i, j);\n        }\n    }\n    return res;\n\
    }\n\nint difference(Dice& a, Dice& b) {\n    int res = 0;\n    for (int i = 0;\
    \ i < 6; i++) res += a.d[i] != b.d[i];\n    return res;\n}\n\nint min_difference(Dice&\
    \ a, Dice& b) {\n    int res = 6;\n    // 4\u9762\u30C1\u30A7\u30C3\u30AF\n  \
    \  for (int i = 0; i < 4; i++) {\n        for (int j = 0; j < 4; j++) {\n    \
    \        res = std::min(res, difference(a, b));\n            a.rotate_cw();\n\
    \        }\n        a.rotate0();\n    }\n    // >\u65B9\u5411\n    a.rotate1();\n\
    \    for (int j = 0; j < 4; j++) {\n        res = std::min(res, difference(a,\
    \ b));\n        a.rotate_cw();\n    }\n    a.rotate3();\n    // <\u65B9\u5411\n\
    \    a.rotate3();\n    for (int j = 0; j < 4; j++) {\n        res = std::min(res,\
    \ difference(a, b));\n        a.rotate_cw();\n    }\n    a.rotate1();\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <string>\n#include\
    \ <vector>\n\n// https://onlinejudge.u-aizu.ac.jp/problems/3206\nstruct Dice {\n\
    \    std::array<int, 6> d;\n    // \u9762\n    //  2\n    // 341\n    //  0\n\
    \    //  5\n    // \u5411\u304D\n    //  v\n    // vvv\n    //  v\n    //  v\n\
    \    Dice() { d = {0, 0, 0, 0, 0, 0}; }\n    // v>^< -> 0123\n    int ctoi(char\
    \ c) {\n        if (c == 'v') return 0;\n        if (c == '>') return 1;\n   \
    \     if (c == '^') return 2;\n        if (c == '<') return 3;\n        assert(false);\n\
    \    }\n    int cw(int x) { return (x + 3) % 4; }\n    int ccw(int x) { return\
    \ (x + 1) % 4; }\n    int rev(int x) { return (x + 2) % 4; }\n    void rotate0()\
    \ {\n        // v\u65B9\u5411\u306B\u5012\u3059\n        // \u9762\n        //\
    \  2      4\n        // 341 => 301\n        //  0      5\n        //  5      2\n\
    \        // \u5411\u304D\n        //  v      v\n        // vvv => >v<\n      \
    \  //  v      v\n        //  v      v\n        d = {d[5], cw(d[1]), d[4], ccw(d[3]),\
    \ d[0], d[2]};\n    }\n    void rotate1() {\n        // >\u65B9\u5411\u306B\u5012\
    \u3059\n        // \u9762\n        //  2      2\n        // 341 => 415\n     \
    \   //  0      0\n        //  5      3\n        // \u5411\u304D\n        //  v\
    \      <\n        // vvv => vv^\n        //  v      >\n        //  v      ^\n\
    \        d = {ccw(d[0]), rev(d[5]), cw(d[2]), d[4], d[1], rev(d[3])};\n    }\n\
    \    void rotate2() {\n        // ^\u65B9\u5411\u306B\u5012\u3059\n        rotate0();\n\
    \        rotate0();\n        rotate0();\n    }\n    void rotate3() {\n       \
    \ // <\u65B9\u5411\u306B\u5012\u3059\n        rotate1();\n        rotate1();\n\
    \        rotate1();\n    }\n    void rotate_cw() {\n        // \u6642\u8A08\u56DE\
    \u308A\u306B\u56DE\u3059\n        // \u9762\n        //  2      3\n        //\
    \ 341 => 042\n        //  0      1\n        //  5      5\n        // \u5411\u304D\
    \n        //  v      <\n        // vvv => <<<\n        //  v      <\n        //\
    \  v      >\n        d = {cw(d[1]), cw(d[2]), cw(d[3]), cw(d[0]), cw(d[4]), ccw(d[5])};\n\
    \    }\n    void rotate_ccw() {\n        // \u53CD\u6642\u8A08\u56DE\u308A\u306B\
    \u56DE\u3059\n        rotate_cw();\n        rotate_cw();\n        rotate_cw();\n\
    \    }\n};\n\nDice read_dice(std::vector<std::string>& s) {\n    const int h =\
    \ (int)(s.size());\n    assert(h > 0);\n    const int w = (int)(s[0].size());\n\
    \    std::vector seen(h, std::vector(w, 0));\n    Dice res;\n    auto rec = [&](auto\
    \ f, int x, int y) -> void {\n        seen[x][y] = 1;\n        res.d[4] = res.ctoi(s[x][y]);\n\
    \        // v\n        if (x + 1 < h) {\n            int nx = x + 1, ny = y;\n\
    \            if (s[nx][ny] != '.' and seen[nx][ny] == 0) {\n                res.rotate0();\n\
    \                f(f, nx, ny);\n                res.rotate2();\n            }\n\
    \        }\n        // >\n        if (y + 1 < w) {\n            int nx = x, ny\
    \ = y + 1;\n            if (s[nx][ny] != '.' and seen[nx][ny] == 0) {\n      \
    \          res.rotate1();\n                f(f, nx, ny);\n                res.rotate3();\n\
    \            }\n        }\n        // ^\n        if (x - 1 >= 0) {\n         \
    \   int nx = x - 1, ny = y;\n            if (s[nx][ny] != '.' and seen[nx][ny]\
    \ == 0) {\n                res.rotate2();\n                f(f, nx, ny);\n   \
    \             res.rotate0();\n            }\n        }\n        // <\n       \
    \ if (y - 1 >= 0) {\n            int nx = x, ny = y - 1;\n            if (s[nx][ny]\
    \ != '.' and seen[nx][ny] == 0) {\n                res.rotate3();\n          \
    \      f(f, nx, ny);\n                res.rotate1();\n            }\n        }\n\
    \    };\n    for (int i = 0; i < h; i++) {\n        for (int j = 0; j < w; j++)\
    \ {\n            if (s[i][j] != '.' and seen[i][j] == 0) rec(rec, i, j);\n   \
    \     }\n    }\n    return res;\n}\n\nint difference(Dice& a, Dice& b) {\n   \
    \ int res = 0;\n    for (int i = 0; i < 6; i++) res += a.d[i] != b.d[i];\n   \
    \ return res;\n}\n\nint min_difference(Dice& a, Dice& b) {\n    int res = 6;\n\
    \    // 4\u9762\u30C1\u30A7\u30C3\u30AF\n    for (int i = 0; i < 4; i++) {\n \
    \       for (int j = 0; j < 4; j++) {\n            res = std::min(res, difference(a,\
    \ b));\n            a.rotate_cw();\n        }\n        a.rotate0();\n    }\n \
    \   // >\u65B9\u5411\n    a.rotate1();\n    for (int j = 0; j < 4; j++) {\n  \
    \      res = std::min(res, difference(a, b));\n        a.rotate_cw();\n    }\n\
    \    a.rotate3();\n    // <\u65B9\u5411\n    a.rotate3();\n    for (int j = 0;\
    \ j < 4; j++) {\n        res = std::min(res, difference(a, b));\n        a.rotate_cw();\n\
    \    }\n    a.rotate1();\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dice.hpp
  requiredBy:
  - verify/aoj_other/aoj_3206.text.cpp
  timestamp: '2024-06-11 20:42:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/dice.hpp
layout: document
title: "Dice (\u30B5\u30A4\u30B3\u30ED)"
---

[AOJ 3206 アローダイス](https://onlinejudge.u-aizu.ac.jp/problems/3206) を元に作成

各面の向きも持っているが、興味がない場合は `cw`, `ccw`, `rev` を恒等写像にすると良い
