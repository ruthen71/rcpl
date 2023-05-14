#pragma once

#include "icpc/template.hpp"

struct UF {
    V<int> par;

    UF() {}
    UF(int n) : par(n, -1) {}

    int leader(int x) { return par[x] < 0 ? x : par[x] = leader(par[x]); }

    bool merge(int x, int y) {
        x = leader(x), y = leader(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y) { return leader(x) == leader(y); }

    int size(int x) { return -par[leader(x)]; }
};