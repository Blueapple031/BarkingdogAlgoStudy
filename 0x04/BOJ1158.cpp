#include <iostream>
using namespace std;

void makeLink(int* dat, int* nxt, int N){
    for(int i = 0; i<N+1; i++){
        dat[i] = i;
        nxt[i] = i+1;
    }
    nxt[N] = 1;
}
void process(int* dat, int* nxt, int index, int N){
    //TODO pre를 안 쓰고 delete구현

}


int main(){
    int N, K, pre;
    cin >> N >> K;
    int* nxt = new int[N+1];
    int* dat = new int[N+1];
    //Link
    makeLink(dat, nxt, N);
    //Delete & Print
    int cur = 0, remain = N;
    cout << "<";
    while(remain>1){
        for(int j =0; j<K; j++){
            pre = cur;
            cur = nxt[cur];
            if(j==K-1) nxt[pre] = nxt[cur];
        }
        cout << dat[cur] << ", ";
        remain--;
    }
    cout << dat[nxt[cur]];
    cout << ">";
}