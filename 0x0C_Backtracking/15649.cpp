#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0, M = 0;
int arr[10] = {0};
bool check[10] = {0};
// int arr[10] = {0};
// bool check[10] = {0};

// void process(int k){
//     if(k==0){
//         for(int i = 0; i<M; i++){
//             cout << arr[i] << ' ';
//         }
//         cout << '\n';
//         return;
//     }
//     for(int j=0; j<N; j++){
//         if(!check[j+1]) {
//             arr[M-k] = j+1;
//             check[j+1] = true;
//             process(k-1);
//             check[j+1] = false;
//         }
//     }
    
// }

void process(int m)//m은 몇 줄인지,
{
    if(m==0) {
        for(int i = 0; i<M; i++) cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for(int i = 0; i<N; i++){
        if(!check[i+1]){
            arr[M-m] = i+1;
            check[i+1] = true;
            process(m-1);
            check[i+1] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    process(M);











        // cin >> N >> M;
        // vector<int> v{};
        // for(int i = 1; i<N+1; i++){
        //     v.push_back(i);
        // }

        // do{
        //     for(int i = 0; i<M; i++){
        //         cout << v[i] << ' ';
        //     }
        //     cout << '\n';
        // } while(next_permutation(v.begin(),v.end()));
    //process(M);
}