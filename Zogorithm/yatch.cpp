#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<ll,ll>> p;
    p.reserve(N+1);
    p.emplace_back(0, 500);
    for(int i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }

    int n = N + 1;
    sort(p.begin() + 1, p.end(), [](auto &a, auto &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    vector<vector<ll>> dist(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll dx = p[i].first  - p[j].first;
            ll dy = p[i].second - p[j].second;
            double d = sqrt(double(dx*dx + dy*dy));
            ll di = (ll)(d + 1e-9);
            dist[i][j] = dist[j][i] = di;
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    dp[1][0] = dist[0][1];

    for(int i = 2; i < n; i++){
        for(int j = 0; j <= i-2; j++){
            dp[i][j] = dp[i-1][j] + dist[i-1][i];
        }
        ll best = INF;
        for(int k = 0; k <= i-2; k++){
            best = min(best, dp[i-1][k] + dist[k][i]);
        }
        dp[i][i-1] = best;
    }

    ll answer = dp[n-1][n-2] + dist[n-1][n-2];
    cout << answer << "\n";
    return 0;
}
