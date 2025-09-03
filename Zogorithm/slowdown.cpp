#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Task { int profit, due; };

ll greedy_max_profit(const vector<Task>& tasks, int T, int M, vector<int>* scheduled_idxs=nullptr) {
    int N = tasks.size();
    vector<int> cap(T+1, M), parent(T+1);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> findp = [&](int x) {
        return parent[x] == x ? x : parent[x] = findp(parent[x]);
    };

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){
        return tasks[a].profit > tasks[b].profit;
    });

    ll total = 0;
    if (scheduled_idxs) scheduled_idxs->clear();

    for (int i : idx) {
        int d = findp(tasks[i].due);
        if (d == 0) continue;
        total += tasks[i].profit;
        if (scheduled_idxs) scheduled_idxs->push_back(i);
        if (--cap[d] == 0) {
            parent[d] = findp(d - 1);
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T, M;
    cin >> N >> T >> M;
    vector<Task> tasks(N);
    for (int i = 0; i < N; i++) {
        cin >> tasks[i].profit >> tasks[i].due;
    }

    vector<int> S;
    ll A = greedy_max_profit(tasks, T, M, &S);

    ll B = 0;
    for (int idx : S) {
        vector<Task> tmp; tmp.reserve(N-1);
        for (int i = 0; i < N; i++) if (i != idx) tmp.push_back(tasks[i]);
        ll v = greedy_max_profit(tmp, T, M, nullptr);
        if (v < A) B = max(B, v);
    }

    cout << A << " " << B << "\n";
    return 0;
}
