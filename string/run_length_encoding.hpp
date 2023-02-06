#pragma once

std::vector<std::pair<char, int>> run_length_encoding(std::string &S) {
    assert(S.size() > 0);
    std::vector<std::pair<char, int>> res = {{S.front(), 0}};
    for (auto &si : S) {
        if (si != res.back().first) {
            res.push_back({si, 0});
        }
        res.back().second++;
    }
    return res;
}