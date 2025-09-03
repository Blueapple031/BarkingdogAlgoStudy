#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<int, bool> exist;

    int N, a;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> a;
        exist[a] = true; 
    }
    int M, b;
    cin >> M;
    for(int i = 0; i<M; i++){
        cin >> b;
        if(exist[b] == true)
            cout << "1\n";
        else cout << "0\n";
    }
}