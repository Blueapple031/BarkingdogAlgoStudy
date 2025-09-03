#include <bits/stdc++.h>
using namespace std;

int N, M, S;                      
vector<int> x_, y_, distS;        
vector<vector<pair<int,int>>> adj; 

int bestCnt = -1;
vector<int> bestEdges, bestPath;
vector<char> vis;
vector<int> path, edges;

void chk(int w) {
    int cnt = path.size();
    vector<int> se = edges;
    se.push_back(w);
    sort(se.rbegin(), se.rend());

    vector<int> full = path;
    full.push_back(S);

    if (cnt > bestCnt
     || (cnt == bestCnt && (se < bestEdges
     || (se == bestEdges && path[1] < bestPath[1])))) {
        bestCnt = cnt;
        bestEdges = se;
        bestPath = full;
    }
}

void dfs(int u, int sum) {
    for (auto &p : adj[u]) {
        if (p.first == S && sum + p.second == 42) {
            chk(p.second);
        }
    }
    for (auto &p : adj[u]) {
        int v = p.first, w = p.second;
        if (v == S || vis[v]) continue;
        int ns = sum + w;
        if (ns >= 42 || ns + distS[v] > 42) continue;
        vis[v] = 1;
        path.push_back(v);
        edges.push_back(w);
        dfs(v, ns);
        edges.pop_back();
        path.pop_back();
        vis[v] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    x_.resize(N);
    y_.resize(N);
    for(int i = 0, idx; i < N; i++){
        cin >> idx >> x_[i] >> y_[i];
    }
    cin >> M;
    adj.assign(N, {});
    for(int i = 0, idx,u,v; i < M; i++){
        cin >> idx >> u >> v;
        int dx = x_[u]-x_[v], dy = y_[u]-y_[v];
        int w = int(floor(sqrt(double(dx*dx+dy*dy))));
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    S = 0;
    for(int i=0;i<N;i++) {
        sort(adj[i].begin(), adj[i].end(), [](auto &a, auto &b){
            return a.first < b.first;
        });
    }

    distS.assign(N, 1e9);
    distS[S] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,S});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d > distS[u]) continue;
        for(auto &p: adj[u]){
            int v = p.first, w = p.second;
            if(distS[v] > d+w){
                distS[v] = d+w;
                pq.push({distS[v], v});
            }
        }
    }

    vis.assign(N,0);
    vis[S]=1;
    path = {S};
    dfs(S, 0);

    if(bestCnt<0){
        cout << -1;
    } else {
        for(int i=0;i<bestPath.size();i++){
            if(i) cout << ' ';
            cout << bestPath[i];
        }
    }
    return 0;
}
