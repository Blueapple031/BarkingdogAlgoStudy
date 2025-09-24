#include <iostream>

using namespace std;

int count = 0;
int N = 0;
int QueenCanExist[15][15] = {};
int recursion = 0;

void rangeQueen(int col, int row, int state) {
    //가로
    for(int i= 0; i<N; i++) QueenCanExist[col][i] += state;
    //세로
    for(int i= 0; i<N; i++) QueenCanExist[i][row] += state;
    //↗방향
    for(int i= 0; col-i >=0 && row+i <= N; i++){
        QueenCanExist[col-i][row+i] += state;
    }
    //↙방향 
    for(int i= 0; row-i >=0 && col+i <= N; i++){
        QueenCanExist[col+i][row-i] += state;
    }   
    //↖방향
    for(int i= 0; row-i >=0 && col-i >= N; i++){
        QueenCanExist[col-i][row-i] += state;
    }    
    //↙방향 
    for(int i= 0; row+i <=14 && col+i <= N; i++){
        QueenCanExist[col+i][row+i] += state;
    }     
     
}

void setQueen(int N, int numOfQueen){
    if(N==numOfQueen){
        count++;
        return;
    }
    int i = numOfQueen;
        for(int j = 0; j<N; j++){
            if(QueenCanExist[i][j] <=0) {
                recursion++;
                numOfQueen++;
                rangeQueen(i,j,1);
                setQueen(N, numOfQueen);
                numOfQueen--;
                rangeQueen(i,j,-1);
            }
        }
    
}

int main(){
    cin >> N;
    setQueen(N, 0);
    cout << count;
}