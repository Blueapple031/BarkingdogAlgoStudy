#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> S;
int N, k, indes = 0;
string cmd;
int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> cmd;
        if(cmd == "push"){
            cin >> k;
            S.push(k);
        }
        else if(cmd == "pop"){
            if(!S.empty()) {
                cout << S.top() <<'\n';
                S.pop();
            }
            else cout << -1 << '\n';
        }
        else if(cmd == "size"){
            cout << S.size() <<'\n';
        }
        else if(cmd == "empty"){
            cout << S.empty() << '\n';
        }
        else if(cmd ==  "top"){
            if(!S.empty())cout << S.top() << '\n';
            else cout << -1 << '\n';
        }
        
    }
}