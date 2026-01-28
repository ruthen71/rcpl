#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include <iostream>
#include <map>
#include <set>

#include "../../random/base.hpp"
#include "../inversion_number.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto&& e : a) std::cin >> e;
    long long ans1 = inversion_number<int>(a);
    // a -> b への全単射 f を作成
    std::map<int, long long> f;
    std::set<long long> seen;
    for (int i = 0; i < n; i++) {
        if (f.count(a[i]) > 0) continue;
        while (true) {
            auto val = rng_auto.rand_int();
            if (seen.count(val) == 0) {
                f[a[i]] = val;
                seen.insert(val);
                break;
            }
        }
    }
    // a -> a_sorted の転倒数 (ans1) と
    // f(a) -> f(a_sorted) の転倒数 (ans2) が一致することを確認
    auto a_sorted = a;
    std::sort(a_sorted.begin(), a_sorted.end());
    std::vector<long long> b(n), b_sorted(n);
    for (int i = 0; i < n; i++) {
        b[i] = f[a[i]];
        b_sorted[i] = f[a_sorted[i]];
    }
    long long ans2 = inversion_number<long long>(b, b_sorted);
    assert(ans1 == ans2);
    std::cout << ans1 << '\n';
    return 0;
}
