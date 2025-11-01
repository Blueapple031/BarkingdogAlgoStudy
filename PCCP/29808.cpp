#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    unsigned int num;
    int count = 0;
    vector<pair<int,int>> arr;
    // (kor>eng)? (kor-eng)*508 : (eng-kor)*108;
    // (mat>sci)? (mat-sci)*212 : (sci-mat)*305;
    cin >> num;
    if(num%4763 != 0) {
        cout << 0;
        return 0;
    }
    int num1 = num/4763;
    for(int i = 0; i<200; i++){
        for(int j = 0; j<200; j++){
            if((i*508+j*212) ==num1){
            
                arr.push_back({i,j});
            }
            if((i*508+j*305) ==num1){
                
                arr.push_back({i,j});
            }
            if((i*108+j*212) ==num1){
                
                arr.push_back({i,j});
            }
            if((i*108+j*305) ==num1){
                
                arr.push_back({i,j});
            }
        }
    }
    sort(arr.begin(),arr.end(),[](auto a, auto b){
        if(a.first==b.first)return a.second<b.second;
        else return a.first<b.first;
    });
    arr.erase(unique(arr.begin(),arr.end()),arr.end());

    cout << arr.size() << '\n';
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i].first << " "<< arr[i].second << '\n';
    }
}