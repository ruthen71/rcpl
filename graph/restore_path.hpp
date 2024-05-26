#pragma once

#include <vector>
// restore path from root[t] to t
std::vector<int> restore_path(std::vector<int>& par, int t) {
    std::vector<int> path = {t};
    while (par[path.back()] != -1) path.emplace_back(par[path.back()]);
    std::reverse(path.begin(), path.end());
    return path;
}