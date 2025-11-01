#include <iostream>
using namespace std;

int N, S = 0, count = 0, k =0;
int arr[20] = {};

void back(int j){
    if(k == S){
        count++;
        if(j == N) return;
    }
    for(int i=j; i<N; i++){
        k+=arr[i];
        back(i+1);
        k-=arr[i];
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    back(0);
    if(S==0) count--;
    cout << count;
}