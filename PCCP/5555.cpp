#include <iostream>
#include <string>
using namespace std;

char arr[101][20];

int main(){
    string str;
    int N;
    int count = 0;
    int len = 0;
    cin >> str >> N;
    for(int i = 0; str[i] != '\0'; i++) len++;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<10; j++){
            cin >> arr[i][j];
        }
        for(int j = 10; j<20; j++){
            arr[i][j] = arr[i][j-10];
        }
    }
    // for(int i = 0; i<N; i++){
    //     for(int j = 0; j<20; j++){
    //         cout << arr[i][j];
    //     }
    //     cout << '\n';
    // }
    int isthere = 0;
    for(int i = 0; i<N; i++){
        for(int j =0; j<10+len; j++){
            for(int k = 0; k<len; k++){
                if(str[k] != arr[i][j+k]) break;
                if(k==len-1) isthere = 1;
            }
            if(isthere){
                count++;
                isthere = 0;
                break;
            }
        }
    }

    cout << count;
    // for(int i = 0; i<N; i++){
    //     for(int j = 0; j<19; j++){
            
    //     }
    // }

}