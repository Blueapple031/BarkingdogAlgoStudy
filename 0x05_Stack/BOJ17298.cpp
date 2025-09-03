#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

stack<pair<int,int>> top;
stack<int> ans;
int main(){
    int N;
    cin >> N;
    vector<int> num(N);
    for(int i = 0; i<N; i++){
        cin >> num[i];
    }

    top.push({0,1000001});
    for(int i = N-1; i>=0; i--){
        while(num[i]>=top.top().second){
            top.pop();
        }
        if(top.top().first!=0) ans.push(top.top().second);
        else ans.push(-1);

        top.push({i,num[i]});
    }
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
}