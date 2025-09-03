#include <iostream>

using namespace std;

int main(){
    int N, K, ans = 0;
    cin >> N >> K;
    int arr[12]={};

    for(int i = 0; i<N; i++){
        int gender, grade = 0;
        cin >> gender >> grade;
        arr[gender+((grade-1)*2)]++;
    }
    for(int i : arr){
        ans += (i+K-1)/K;
    }
    cout << ans;
}