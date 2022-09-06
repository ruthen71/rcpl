#pragma once

std::vector<int> totient_table(int n) {
    std::vector<int> res(n + 1);
    std::iota(res.begin(), res.end(), 0);
    for (int p = 2; p <= n; p++) {
        if (res[p] != p) continue;
        for (int i = p; i <= n; i += p) {
            res[i] /= p;
            res[i] *= p - 1;
        }
    }
    return res;
}