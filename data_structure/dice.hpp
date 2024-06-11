#pragma once
#include <array>
#include <cassert>
#include <string>
#include <vector>

// https://onlinejudge.u-aizu.ac.jp/problems/3206
struct Dice {
    std::array<int, 6> d;
    // 面
    //  2
    // 341
    //  0
    //  5
    // 向き
    //  v
    // vvv
    //  v
    //  v
    Dice() { d = {0, 0, 0, 0, 0, 0}; }
    // v>^< -> 0123
    int ctoi(char c) {
        if (c == 'v') return 0;
        if (c == '>') return 1;
        if (c == '^') return 2;
        if (c == '<') return 3;
        assert(false);
    }
    int cw(int x) { return (x + 3) % 4; }
    int ccw(int x) { return (x + 1) % 4; }
    int rev(int x) { return (x + 2) % 4; }
    void rotate0() {
        // v方向に倒す
        // 面
        //  2      4
        // 341 => 301
        //  0      5
        //  5      2
        // 向き
        //  v      v
        // vvv => >v<
        //  v      v
        //  v      v
        d = {d[5], cw(d[1]), d[4], ccw(d[3]), d[0], d[2]};
    }
    void rotate1() {
        // >方向に倒す
        // 面
        //  2      2
        // 341 => 415
        //  0      0
        //  5      3
        // 向き
        //  v      <
        // vvv => vv^
        //  v      >
        //  v      ^
        d = {ccw(d[0]), rev(d[5]), cw(d[2]), d[4], d[1], rev(d[3])};
    }
    void rotate2() {
        // ^方向に倒す
        rotate0();
        rotate0();
        rotate0();
    }
    void rotate3() {
        // <方向に倒す
        rotate1();
        rotate1();
        rotate1();
    }
    void rotate_cw() {
        // 時計回りに回す
        // 面
        //  2      3
        // 341 => 042
        //  0      1
        //  5      5
        // 向き
        //  v      <
        // vvv => <<<
        //  v      <
        //  v      >
        d = {cw(d[1]), cw(d[2]), cw(d[3]), cw(d[0]), cw(d[4]), ccw(d[5])};
    }
    void rotate_ccw() {
        // 反時計回りに回す
        rotate_cw();
        rotate_cw();
        rotate_cw();
    }
};

Dice read_dice(std::vector<std::string>& s) {
    const int h = (int)(s.size());
    assert(h > 0);
    const int w = (int)(s[0].size());
    std::vector seen(h, std::vector(w, 0));
    Dice res;
    auto rec = [&](auto f, int x, int y) -> void {
        seen[x][y] = 1;
        res.d[4] = res.ctoi(s[x][y]);
        // v
        if (x + 1 < h) {
            int nx = x + 1, ny = y;
            if (s[nx][ny] != '.' and seen[nx][ny] == 0) {
                res.rotate0();
                f(f, nx, ny);
                res.rotate2();
            }
        }
        // >
        if (y + 1 < w) {
            int nx = x, ny = y + 1;
            if (s[nx][ny] != '.' and seen[nx][ny] == 0) {
                res.rotate1();
                f(f, nx, ny);
                res.rotate3();
            }
        }
        // ^
        if (x - 1 >= 0) {
            int nx = x - 1, ny = y;
            if (s[nx][ny] != '.' and seen[nx][ny] == 0) {
                res.rotate2();
                f(f, nx, ny);
                res.rotate0();
            }
        }
        // <
        if (y - 1 >= 0) {
            int nx = x, ny = y - 1;
            if (s[nx][ny] != '.' and seen[nx][ny] == 0) {
                res.rotate3();
                f(f, nx, ny);
                res.rotate1();
            }
        }
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] != '.' and seen[i][j] == 0) rec(rec, i, j);
        }
    }
    return res;
}

int difference(Dice& a, Dice& b) {
    int res = 0;
    for (int i = 0; i < 6; i++) res += a.d[i] != b.d[i];
    return res;
}

int min_difference(Dice& a, Dice& b) {
    int res = 6;
    // 4面チェック
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            res = std::min(res, difference(a, b));
            a.rotate_cw();
        }
        a.rotate0();
    }
    // >方向
    a.rotate1();
    for (int j = 0; j < 4; j++) {
        res = std::min(res, difference(a, b));
        a.rotate_cw();
    }
    a.rotate3();
    // <方向
    a.rotate3();
    for (int j = 0; j < 4; j++) {
        res = std::min(res, difference(a, b));
        a.rotate_cw();
    }
    a.rotate1();
    return res;
}