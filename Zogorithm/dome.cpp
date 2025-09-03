#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M; 

    vector<vector<int>> grid(M+1, vector<int>(N+1, 0));
    for(int lineIdx = 0; lineIdx < N; lineIdx++){
        string rowBits;
        cin >> rowBits;
        int row = M - lineIdx;
        for(int col = 1; col <= M; col++){

            grid[row][col] = (rowBits[col-1] == '1');
        }
    }

    // 누적합 pref[row][col] : (1,1)부터 (row,col)까지 장애물 수
    vector<vector<int>> pref(M+1, vector<int>(N+1, 0));
    for(int r=1; r<=M; r++){
        for(int c=1; c<=N; c++){
            pref[r][c] = pref[r-1][c] + pref[r][c-1] 
                       - pref[r-1][c-1] + (grid[r][c]);
        }
    }

    int maxK=0;
    int ansX=0, ansY=0;  // 왼쪽 아래 꼭짓점

    for(int sizeK = min(N,M); sizeK>=1; sizeK--){
        bool found = false;
        int bestX=INT_MAX, bestY=INT_MAX; 
        for(int y=1; y<=M-sizeK+1; y++){
            for(int x=1; x<=N-sizeK+1; x++){
                int y1=y, y2=y+sizeK-1;
                int x1=x, x2=x+sizeK-1;
                int cnt = pref[y2][x2] 
                        - pref[y1-1][x2] 
                        - pref[y2][x1-1] 
                        + pref[y1-1][x1-1];
                if(cnt <= 1){
                    found = true;
                    if(x < bestX || (x == bestX && y < bestY)){
                        bestX = x; 
                        bestY = y;
                    }
                }
            }
        }
        if(found){
            maxK = sizeK;
            ansX = bestX;
            ansY = bestY;
            break; // 더 작은 K는 볼 필요 없음
        }
    }

    cout << ansX << " " << ansY << "\n" << maxK << "\n";
    return 0;
}
