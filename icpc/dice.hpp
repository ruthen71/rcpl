#pragma once

#include "icpc/template.hpp"

// https://onlinejudge.u-aizu.ac.jp/problems/2703
// d = {x-, x+, y-, y+, z-, z+}
// d = {0,  1,  2,  3,  4,  5}
struct Dice {
    vector<long long> d;
    Dice(vector<long long> &d) : d(d) {}
    void right() { d = {d[2], d[3], d[1], d[0], d[4], d[5]}; }
    void left() { REP(i, 3) right(); }
    void xm() { d = {d[5], d[4], d[2], d[3], d[0], d[1]}; }
    void xp() { REP(i, 3) xm(); }
    void ym() { d = {d[0], d[1], d[5], d[4], d[2], d[3]}; }
    void yp() { REP(i, 3) ym(); }
};