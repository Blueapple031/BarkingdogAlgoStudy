#include <queue>
#include <iostream>
using namespace std;

queue<int> Q;
int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        Q.push(i+1);
    }
    while(Q.size()>2){
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    if(Q.size()!=1)Q.pop();
    cout << Q.front();
}