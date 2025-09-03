#include <iostream>
#include <list>
#include <string>
using namespace std;

int N = 0;
list<char> arr ={};
auto cursor = arr.begin();

void process(string str){
    for(char& c : str){
        switch(c){
            case '<':
                //커서위치 왼
                if(cursor != arr.begin()) --cursor;
                break;
            case '>':
                //커서위치 오른
                if(cursor != arr.end()) ++cursor;
                break;
            case '-':
                //커서 앞글자 삭제
                if(cursor != arr.begin())arr.erase(prev(cursor));
                break;
            default :
                arr.insert(cursor,c);
        }
    }
}

int main(){
    cin >> N;
    string* strarr = new string[N];
    for(int i = 0; i<N; i++){
        cin >> strarr[i];

        arr.clear();
        cursor = arr.begin();
        
        process(strarr[i]);
        for(char c : arr) cout << c;
        cout << '\n';
        
    }

    delete[] strarr;
}