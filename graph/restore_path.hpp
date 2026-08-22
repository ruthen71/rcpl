#pragma once

#include <algorithm>
#include <vector>

// restore path from s to t
std::vector<int> restore_path(std::vector<int>& par, int s, int t) {
    std::vector<int> path = {t};
    while (path.back() != s) path.emplace_back(par[path.back()]);
    std::reverse(path.begin(), path.end());
    return path;
}
