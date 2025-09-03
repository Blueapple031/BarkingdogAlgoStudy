#include <iostream>

using namespace std;

int ans = 0;
void func(int row, int col, int N){
    if(N == 1){
        ans = ans + (2*row) + col;
        return;
    }
    if(row<(1<<(N-1)) && col<(1<<(N-1))){//arr[0][0]
        func(row, col, N-1);
    }
    else if(row<(1<<(N-1)) && col >=(1<<(N-1))){//arr[0][1]
        ans += (1<<(2*(N-1)));
        func(row,col-(1<<(N-1)),N-1);
    }
    else if(row >=(1<<(N-1))&& col <(1<<(N-1))){//arr[1][0]
        ans += (1<<(2*(N-1)))*2;
        func(row-(1<<(N-1)),col,N-1);
    }
    else{//arr[1][1]
        ans += (1<<(2*(N-1)))*3;
        func(row-(1<<(N-1)),col-(1<<(N-1)),N-1);
    }

}

int main(){
    int N, row, col;
    cin >> N >> row >> col;
    func(row, col, N);
    cout << ans;
}