#include <iostream>
#include <stack>
using namespace std;

stack<int> S;
int main(){
    int N, i, sum = 0;
    cin >> N;
    while(N--){
        cin >> i;
        if(i==0) S.pop();
        else S.push(i);
    }
    while(!S.empty()){
        sum += S.top();
        S.pop();
    }
    cout << sum;
}
