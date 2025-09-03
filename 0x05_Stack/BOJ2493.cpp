#include <iostream>
#include <stack>
using namespace std;
int k, N;
stack<int> high;
int main(){
    cin >> N;
    int* arr = new int[N];
    int* ans = new int[N];
    fill(ans, ans+N, 0);
    for(int i =0; i<N; i++){
        cin >> arr[i];
        k = i +1;
        while(!high.empty()&&arr[high.top()]<arr[i]){
            high.pop();
        }
        if(!high.empty()) ans[i] = high.top()+1;    
        high.push(i);
    }
    for(int i = 0; i<N; i++){
        cout << ans[i] << ' ';
    }
}