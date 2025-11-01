#include <iostream>
#include <utility>
#include <map>
#define X first
#define Y second
using namespace std;

int N, M, k = 0;
int a,b,c,d;
unsigned long long arr[102][102] = {0};
bool up[102][102];
bool ri[102][102];


void func(int i, int j){//↑→에 개수를 더한다.
    if(up[i][j]){
        arr[i+1][j] += arr[i][j];
    }
    if(ri[i][j]){//right
        arr[i][j+1] += arr[i][j];
    }
}

int main(){
    fill(&up[0][0], &up[0][0] + 102*102, true);
    fill(&ri[0][0], &ri[0][0] + 102*102, true);
    cin >> N >> M >> k;
    for(int i = 0; i<k; i++) {
        cin >> a >> b >> c >> d;
        if(a+1==c) up[a][b] = false;
        if(a==c+1) up[c][d] = false;
        if(b+1==d) ri[a][b] = false;
        if(b==d+1) ri[c][d] = false;
        //이걸 어케 저장해서 검증하지
    }
    arr[0][0] = 1;
    for(int i = 0; i<N+1; i++){
        for(int j = 0; j<M+1; j++){
            func(i,j);
        }
    }
    cout << arr[N][M];
}