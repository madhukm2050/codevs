#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;
const int N = 1e6 + 5;

vector<int> fact(N), ifact(N);

int powm(int x, int n) {
    x %= MOD;
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int mod_div(int a, int b) {
    return a * powm(b, MOD - 2) % MOD;
}

void precompute_factorials() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
    ifact[N - 1] = powm(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 1; i--)
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
}

void solve() {
    vector<int> c(27);
    for (int i = 1; i <= 26; i++) cin >> c[i];
    int n = accumulate(c.begin(), c.end(), 0LL);

    vector<vector<int>> dp(27, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= n / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            if (c[i] > 0 && j - c[i] >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - c[i]]) % MOD;
        }
    }

    int ans = dp[26][n / 2] * fact[n / 2] % MOD * fact[(n + 1) / 2] % MOD;
    for (int i = 1; i <= 26; i++) {
        ans = ans * ifact[c[i]] % MOD;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_factorials();

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
