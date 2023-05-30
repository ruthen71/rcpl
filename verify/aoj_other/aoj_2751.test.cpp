#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2751"

#include "icpc/template.hpp"
#include "icpc/modint.hpp"
#include "icpc/binomal.hpp"

using fp = Modint<1000000007>;

void solve(long long A, long long B, long long C, long long Sx, long long Sy, Binomial<fp>& binom) {
    fp ans = 0;
    long long d = Sx - Sy;
    long long n = A + B + C;
    for (long long x = max(0LL, d); x <= Sx; x++) {
        long long y = x - d;
        long long s = Sx - x;
        if (x < A or y < B or s < 0) continue;
        if (A == 0 and x > 0) continue;
        if (B == 0 and y > 0) continue;
        fp cur = binom.C(s + n - 1, n - 1);
        if (A != 0) cur *= binom.C(x - 1, A - 1);
        if (B != 0) cur *= binom.C(y - 1, B - 1);
        ans += cur;
    }
    ans *= binom.C(n, A) * binom.C(n - A, B);
    cout << ans << '\n';
}

int main() {
    Binomial<fp> binom(4000000);
    long long A, B, C, Sx, Sy;
    while (cin >> A >> B >> C >> Sx >> Sy, !(A == 0 and B == 0 and C == 0 and Sx == 0 and Sy == 0)) {
        solve(A, B, C, Sx, Sy, binom);
    }
    return 0;
}