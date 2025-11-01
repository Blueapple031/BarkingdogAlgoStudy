#include <iostream>

using namespace std;

char arr[51][51];
int arr2[51][51] = {0};
int famous = 0;
int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            cin >> arr[i][j];

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(arr[i][j] == 'Y') arr2[i][j] = 1;
            if(arr[i][j] == 'N'&& i!=j){//모르는 새끼 등장
                //모르는 새끼와 공통인 친구를 찾고 2친구가 있으면 Y로 바꿈
                for(int k = 0; k<N; k++){
                    if(arr[j][k] == 'Y' && arr[i][k]=='Y'){
                        arr2[i][j] = 1;
                    }
                }
            }
        }
    }
    int ans[51] = {0};
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            ans[i] += arr2[i][j];

    for(int i = 0; i<N; i++){
        if(famous<=ans[i]) famous = ans[i];
    }
    cout << famous;

}