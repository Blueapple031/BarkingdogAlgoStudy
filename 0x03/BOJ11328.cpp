#include <iostream>
#include <string>
using namespace std;

bool isStrfry(int* arrarr, int* arr_fryarr){
    int ans = 0;
    
        for(int j = 0; j<26; j++){
            if(arrarr[j] != arr_fryarr[j]) return false;
        }
        return true;
    

}

int main(){
    int N = 0;
    cin >> N;
    
    string* arr = new string[N];
    string* arr_fry = new string[N];
    int (*arrarr)[26] = new int[N][26]();
    int (*arr_fryarr)[26] = new int[N][26]();
    
    for(int i = 0; i<N; i++){
        cin >> arr[i] >> arr_fry[i];
        for(int j = 0; arr[i][j] != '\0'; j++){
            arrarr[i][arr[i][j]-97]++;
        }
        for(int j = 0; arr_fry[i][j] != '\0'; j++){
            arr_fryarr[i][arr_fry[i][j]-97]++;
        }
    }
    for(int i =0; i<N; i++){
        if(isStrfry(arrarr[i], arr_fryarr[i])){
            cout << "Possible" << '\n';
        }
        else cout << "Impossible" << '\n';
    }
}