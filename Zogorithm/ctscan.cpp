#include <bits/stdc++.h>
using namespace std;
#define F(i,n) for(int i=0;i<n;i++)
#define CNT(x) __builtin_popcount(x)

int n, A[6], B[6], D1[11], D2[11], R[6];

bool dfs(int r){
    if(r==n){
        F(i,n){
            F(j,n)
                cout<<((R[i]>>j&1)?'B':'-')<<(j+1<n?' ':'\n');
        }
        return true;
    }
    for(int m=0;m<1<<n;m++){
        if(CNT(m)!=B[r]) continue;
        bool ok=1;
        F(j,n) if(m>>j&1){
            if(--A[j]<0||--D1[r+j]<0||--D2[r-j+n-1]<0) ok=0;
        }
        if(ok){
            R[r]=m;
            if(dfs(r+1)) return true;
        }
        F(j,n) if(m>>j&1){
            A[j]++; D1[r+j]++; D2[r-j+n-1]++;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    F(i,n) cin>>A[i];          // ↓
    F(i,n) cin>>B[i];          // →
    F(i,2*n-1) cin>>D2[i];     // ↘ → D2 에 저장
    F(i,2*n-1) cin>>D1[i];     // ↙ → D1 에 저장
    dfs(0);
    return 0;
}
