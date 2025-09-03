#include <iostream>
#include <stack>

using namespace std;
stack<long long> raw;
int main(){
    bool isWall = false;
    int same = 1;
    int N;
    int ans = 0;
    cin >> N;
    for(int i = 0; i<N; i++){
        long long p;
        cin >> p;
        //이거 same while에서 처리해야한다. 
        //쌓으면서 더하지말고 지우면서 더한다면?
        while(!raw.empty() && raw.top() <= p){
            if(raw.top() == p){
                if(isWall){
                    isWall = false;
                    same = 2;
                }
                ans += same;
                ++same;
                raw.pop()
                raw.push(p);
            }
            else if(raw.top() < p){
                raw.pop();
                ans++;
                same = 1;
            }
        }

        if(!raw.empty() && raw.top() > p){
            raw.push(p);
            ans++;
            isWall = true;
        }
        else if(raw.empty()){
            raw.push(p);
        }
        
    }
    cout << ans;
}