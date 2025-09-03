#include <iostream>
#include <deque>
#include <string>
#include <unordered_map>
using namespace std;
enum Command {PUSH_FRONT, PUSH_BACK, POP_FRONT, POP_BACK, SIZE, EMPTY, FRONT, BACK};
unordered_map<string, Command> commandMap = {
    {"push_front", PUSH_FRONT},
    {"push_back", PUSH_BACK},
    {"pop_front", POP_FRONT},
    {"pop_back", POP_BACK},
    {"size", SIZE},
    {"empty", EMPTY},
    {"front", FRONT},
    {"back", BACK}
};
deque<int> DQ;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    while(N--){
        string cmd;
        cin >> cmd;
        switch(commandMap[cmd]){
            case PUSH_FRONT :
                int k;
                cin >> k;
                DQ.push_front(k);
                break;
            case PUSH_BACK :
                int r;
                cin >> r;
                DQ.push_back(r);
                break;
            case POP_FRONT :
                if(!DQ.empty()) {
                    cout << DQ.front()<< '\n';
                    DQ.pop_front();
                }
                else cout << -1 << '\n';
                break;
            case POP_BACK :
                if(!DQ.empty()) {
                    cout << DQ.back() << '\n';
                    DQ.pop_back();
                }
                else cout << -1 << '\n';
                break;
            case SIZE :
                cout << DQ.size() << '\n';
                break;
            case EMPTY :
                cout << DQ.empty() << '\n';
                break;
            case FRONT :
                if(!DQ.empty()) cout << DQ.front()<< '\n';
                else cout << -1 << '\n';
                break;
            case BACK :
                if(!DQ.empty()) cout << DQ.back()<< '\n';
                else cout << -1 << '\n';
                break;
        }
    }
}