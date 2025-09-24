#include <iostream>

using namespace std;

int N, M, i, j ,k;
int dist[1001][1001];
int ans[1001] = {-1};
int buf = 0;

int cal(int start, int dest){
    while(start == dest){
        
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i< N-1; i++){
        cin >> i >> j >> k;
        dist[i][j] = k;
        dist[j][i] = k;
    }
    for(int i = 0; i< M; i++){
        cin >> i >> j;
        ans = cal(i,j);
    }
    for(int i = 0; i< M; i++){
        cout << ans[i] << '\n';
    }


}