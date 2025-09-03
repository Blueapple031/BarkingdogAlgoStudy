#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;
stack<pair<int, int>> high;
int main(){
    
    long long N, ans = 0;
    cin >> N;
    vector<int> top(N);
    for(int i = 0; i<N; i++){
        cin >> top[i];
    }
    for(int i = N-1; i>=0; i--){
        while(!high.empty()&&high.top().second<top.at(i)){
            high.pop();
        }
        if(!high.empty()) ans += high.top().first - i-1;
        else if(i!=N-1) ans += N-i-1; 
        high.push({i,top.at(i)});
    }
    cout << ans;
}
