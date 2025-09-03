#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<char> ans;
stack<int> stk;
int high = 1;
bool process(int* arr, int N){
    for(int i = 0; i<N; i++){
        if(stk.empty() || stk.top() < arr[i] ){
            if(stk.empty()){
                stk.push(high++);
                ans.push_back('+');
            } 
            while(stk.top() != arr[i]) {
                stk.push(high++);
                ans.push_back('+');
            }
            stk.pop();
            ans.push_back('-');
        }
        else if(stk.top() == arr[i]){
            stk.pop();
            ans.push_back('-');
        }
        else if(stk.top() > arr[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    if(process(arr, N)){
        for(char c : ans){
            cout << c << '\n';
        }
    }
    else cout << "NO";

}