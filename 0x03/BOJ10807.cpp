#include <iostream>

using namespace std;

int main(){
    int N, V=0;
    cin >> N;
    int* arr = new int[N]();
    int* check_arr = new int[N*2]();
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        if(arr[i]>=0) check_arr[arr[i]]++;
        else check_arr[arr[i]*(-1)+100]++;
    }
    cin >> V;
    if(V>=0) cout << check_arr[V];
    else cout << check_arr[V*(-1)+100];
    
}