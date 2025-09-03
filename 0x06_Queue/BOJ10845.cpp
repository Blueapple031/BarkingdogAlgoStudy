#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
queue<int> Q;
enum Command { PUSH, FRONT, BACK, EMPTY, POP, SIZE };

unordered_map<string, Command> commandMap = {
    {"push", PUSH},
    {"front", FRONT},
    {"back", BACK},
    {"empty", EMPTY},
    {"pop", POP},
    {"size", SIZE}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);           
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        string cmd;
        cin >> cmd;
        switch(commandMap[cmd]){
            case PUSH :
                int k;
                cin >> k;
                Q.push(k);
                break;
            case FRONT :
                if(!Q.empty()) cout << Q.front() << '\n';
                else cout << -1 << '\n';
                break;
            case BACK :
                if(!Q.empty()) cout << Q.back() << '\n';
                else cout << -1 << '\n';
                break;
            case EMPTY :
                cout << Q.empty() << '\n';
                break;
            case POP :
                if(!Q.empty()){
                    cout << Q.front() << '\n';
                    Q.pop();
                }
                else cout << -1 << '\n';
                break;
            case SIZE :
                cout << Q.size() << '\n';
                break;
        }
    }
}
