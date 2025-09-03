#include <iostream>

using namespace std;
using ll = long long;

ll A, B, C;

ll process(ll b){
    if(b==0) return 1;
    if(b==1) return A%C;
    if(b%2==0){
        ll half = process(b/2);
        return half*half%C;
    }
    return process(b-1)*A%C;
}

int main(){
    cin >> A >>B>>C;
    cout << process(B);
}