#pragma once

std::vector<bool> prime_table(int n) {
    std::vector<bool> res(n + 1, true);
    if (n >= 0) res[0] = false;
    if (n >= 1) res[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (!res[p]) continue;
        for (int i = p * p; i <= n; i += p) {
            res[i] = false;
        }
    }
    return res;
}
