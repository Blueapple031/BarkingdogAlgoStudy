#include <bits/stdc++.h>
using namespace std;
static const int MOD = 11111;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int R;
    cin >> R;


    long long sumc = 0;
    for (int v : c) sumc += v;
    int T = R - sumc;
    if (T < 0) {
        cout << 0;
        return 0;
    }

    vector<int> dp(T+1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int w = c[i];
        for (int s = w; s <= T; s++) {
            dp[s] = (dp[s] + dp[s - w]) % MOD;
        }
    }

    cout << dp[T];
    return 0;
}
