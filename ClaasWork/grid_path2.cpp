#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+7;
const int MAX = 2e6+5;

int fact[MAX], invfact[MAX];

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = fact[i-1] * i % MOD;

    invfact[MAX-1] = power(fact[MAX-1], MOD-2);
    for (int i = MAX-2; i >= 0; i--)
        invfact[i] = invfact[i+1] * (i+1) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> traps(m);
    for (auto &t : traps) cin >> t.first >> t.second;

    sort(traps.begin(), traps.end());

    vector<int> dp(m);

    for (int i = 0; i < m; i++) {
        int y = traps[i].first;
        int x = traps[i].second;

        dp[i] = nCr(y + x - 2, y - 1);

        for (int j = 0; j < i; j++) {
            int y2 = traps[j].first;
            int x2 = traps[j].second;

            if (x2 <= x) {
                int ways = nCr((y - y2) + (x - x2), y - y2);
                dp[i] = (dp[i] - dp[j] * ways % MOD + MOD) % MOD;
            }
        }
    }

    int ans = nCr(2*n - 2, n - 1);

    for (int i = 0; i < m; i++) {
        int y = traps[i].first;
        int x = traps[i].second;

        int ways = nCr((n - y) + (n - x), n - y);
        ans = (ans - dp[i] * ways % MOD + MOD) % MOD;
    }

    cout << ans << "\n";
}