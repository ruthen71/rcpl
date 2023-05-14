#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3331"

#include "icpc/template.hpp"
#include "icpc/modint.hpp"
#include "icpc/ntt.hpp"

using mint = Modint<998244353>;
template<> const mint mint::G = mint(3);

int main() {
    string S;
    cin >> S;
    int M = int(S.size());
    V<int> A(M);
    REP(i, M) A[i] = S[i] - '0';
    V<mint> p(M, 0);
    p[0] = 1;
    REP(i, M - 1) p[i + 1] = (p[i] * 10) + 1;
    mint las = 0;
    mint SM = 0;
    REP(i, M) SM = SM * 10 + A[i];
    SM += 1;
    V<mint> B;
    REP(i, M - 1) {
        for (int j = 1; j <= 9; j++) {
            B.push_back(p[i] * j - las);
            las = p[i] * j;
        }
    }
    for (int j = 1; j <= 10; j++) {
        int ok = 1;
        for (int i = 0; i < M; i++) {
            if (A[i] < j) {
                ok = 0;
                break;
            }
            if (A[i] > j) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            B.push_back(p[M - 1] * j - las);
            las = p[M - 1] * j;
        } else {
            B.push_back(SM - las);
            break;
        }
    }
    auto Brev = B;
    reverse(Brev.begin(), Brev.end());
    auto C = multiply(B, Brev);
    for (int k = 1; k <= 9 * M; k++) {
        if (k - 1 + B.size() < C.size()) {
            cout << C[k - 1 + B.size()] << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
