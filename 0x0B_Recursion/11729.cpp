#include <iostream>

using namespace std;
void hanoi(int a, int b, int n){ //n개의 원판을 a에서 b로 옮기는 함수수
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a,6-a-b,n-1);
    cout << a << ' ' << b << '\n';
    hanoi(6-a-b,b,n-1);
}

int main(){
    int N, c = 1;
    cin >> N;
    for(int i = 0; i<N; i++) c *=2;
    cout << c-1 << '\n';
    hanoi(1,3,N);
}