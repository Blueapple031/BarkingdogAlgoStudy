#include <iostream>

using namespace std;

bool check_arr[2000001]={false};

int solve(int arr[], int x, int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        if(x-arr[i]>=0){
        if(check_arr[x-arr[i]] ){
            ans++;
        }}
        check_arr[arr[i]]=true;
    }
    return ans;
}

int main() {
    int n,x=0;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cin >> x;
    int ans = solve(arr,x,n);
    cout << ans;
}