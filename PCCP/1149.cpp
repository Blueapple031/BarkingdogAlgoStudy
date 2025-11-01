#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001][3] = {0};//RGB
int dp[1001][3] = {0};

void dpfunc(int i, int j){
    dp[i+1][j] = arr[i+1][j] + min(dp[i][(j+1)%3],dp[i][(j+2)%3]);
}

int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j =0; j<3; j++){
            cin >> arr[i][j];
            if(i==0) dp[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        for(int j =0; j<3; j++){
            dpfunc(i,j);
        }
    }
    int m = min(dp[N-1][0],dp[N-1][1]);
    cout << min(m,dp[N-1][2]);
}