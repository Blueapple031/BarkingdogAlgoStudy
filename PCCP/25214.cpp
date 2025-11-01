#include <iostream>

using namespace std;

int N;
int arr[200001] = {0};
int maxA = 0, minA = 1000000000, k = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(minA > arr[i]) minA = arr[i];
        if(maxA < arr[i]) maxA = arr[i]; 
        if(i == 0) cout << "0 ";
        else{
            if(k < arr[i] - arr[i-1]) k = arr[i] - arr[i-1];
            if(k < arr[i]-minA) k = arr[i]-minA;
            cout << k << " ";
        }
    }
}