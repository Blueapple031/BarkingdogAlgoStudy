#include <iostream>

using namespace std;

int main(){
    int A, B, C, mul;
    cin >> A >> B >> C;
    mul = A*B*C;
    int arr[10] = {};
    for(int i = 0; i<9; i++){  
        if(mul < 1) break;
        arr[mul % 10]++;
        mul = mul/10;
    }
    for(int a : arr){
        cout << a << '\n';
    }
}