#include <iostream>

using namespace std;

char ch[101];
int ans[26];
void chartoint(char ch[], int ans[]){
    int i = 0;
    while (ch[i] != '\0'){
        ans[ch[i]-97]++;
        i++;
    }
}
int main(void){

    for (int& i : ans) i = 0;
    cin >> ch;
    chartoint(ch, ans);
    for(int i : ans) cout << i << ' ';
}