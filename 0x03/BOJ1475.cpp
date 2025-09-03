#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N,max=0;
    cin >> N;
    int arr[10]={};
    for(int i = N; i>=1; i/=10){
        if(i%10 == 6 || i%10 == 9) arr[6]++;
        else arr[i%10]++;
    }
    arr[6] = (arr[6]-1)/2 + 1;
    for(int a : arr){
        if(max< a) {
            max = a;
        }
    }
    cout << max;
}