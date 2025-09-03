#include <iostream>
#include <string>

using namespace std;

int findDifference(int* arr_A, int* arr_B){
    int ans = 0;
    for(int i = 0; i<26; i++){
        if(arr_A[i]!=arr_B[i]){
            if(arr_A[i]>arr_B[i]) ans += arr_A[i]-arr_B[i];
            else ans += arr_B[i] - arr_A[i];
        }
    }
    return ans;
}
int main(){
    string A, B;
    cin >> A >> B;
    int arr_A[26]={}, arr_B[26] = {};
    for(char c : A){
        arr_A[c-'a']++;
    }
    for(char c : B){
        arr_B[c-'a']++;
    }
    int ans = findDifference(arr_A, arr_B);
    cout << ans;
}