#include <iostream>
#include <stack>
using namespace std;

int N, index = 0;
int ans[500000];
void process(int* arr, int N){
    for(int i = 0; i<N; i++){
        if(i==0) ans[i] = 0;
        else{
            for(int j = i; j>=0; j--){
                if(arr[i] < arr[j]) {
                    ans[i] = j+1;
                    break;
                }
            }
        }
        if(ans[i] == -1) ans[i] = 0;
    }
}
int main(){
    cin >> N;
    int* arr = new int[N];
    fill(ans, ans+500000, -1);
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    process(arr, N);
    while(ans[index] != -1){
        cout << ans[index++] << ' '; 
    }
}