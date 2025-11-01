#include <iostream>

using namespace std;

int N, M;
unsigned long long cnt = 0;
unsigned long long arr[1001][1001] = {0};

unsigned long long func(int i, int j){
    long long k = 0;
    k = arr[i-1][j-1]%1000000007 + arr[i][j-1]%1000000007 + arr[i-1][j]%1000000007;
    return k;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i<1001; i++){
        arr[i][0] = 1;
        arr[0][i] = 1;
    }
    for(int i = 1; i<N; i++){
        for(int j = 1; j<M; j++){
            arr[i][j] = func(i,j);
        }
    }
    cnt = arr[N-1][M-1];
    cout << cnt%1000000007;
}