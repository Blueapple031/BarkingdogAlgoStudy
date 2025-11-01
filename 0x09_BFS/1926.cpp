#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second

using namespace std;

int n, m;
bool map[501][501] ={0};
bool visit[501][501] = {0};
int dx = {1,0,-1,0};
int dy = {0,1,0,-1};

int dfs(){//dfs 그림의 넓이를 return

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++) cin >> map[i][j];
    }


}