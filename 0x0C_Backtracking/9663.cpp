#include <iostream>

using namespace std;

int count = 0;
int N, col = 0;


void setQ(bool* arr[], int col, int row) {
    for(int i = 0; i < N; i++) {
        arr[col][i] = true;    // 같은 열
        arr[i][row] = true;    // 같은 행
    }

    for(int i = 0; i < N; i++) {
        // ↘ 방향
        if(col + i < N && row + i < N)
            arr[col + i][row + i] = true;

        // ↗ 방향
        if(col + i < N && row - i >= 0)
            arr[col + i][row - i] = true;

        // ↙ 방향
        if(col - i >= 0 && row + i < N)
            arr[col - i][row + i] = true;

        // ↖ 방향
        if(col - i >= 0 && row - i >= 0)
            arr[col - i][row - i] = true;
    }
}

void func(bool* arr[], int n){
    if(n==1){
        count++;
        return;
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(!arr[i][j]){//다음 열에 둘 곳이 있다면.
                setQ(arr, i,j);
                func(arr, n-1);//1개의 퀸을 어딘가 둠.
            }
            else return;
        }
    }    
}

int main(){
    cin >> N;
    bool* arr[15] = {};
    for(int i = 0; i<15; i++) arr[i] = new bool[15]{};
    func(arr, N);
    cout << count;
}