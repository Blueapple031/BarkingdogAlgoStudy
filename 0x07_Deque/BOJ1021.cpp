#include <iostream>
#include <deque>
using namespace std;

int main(){
    int N, M, k, ans = 0;
    cin >> N >> M;
    deque<int> DQ;
    for(int i = 0; i<N; i++){
        DQ.push_back(i+1);
    }
    for(int i = 0; i<M; i++){
        cin >> k;
        int buf1 = 0, buf2=0;
        deque<int> temp_DQ1 = DQ;
        deque<int> temp_DQ2 = DQ;

        while(temp_DQ1.front()!=k){
            temp_DQ1.push_front(temp_DQ1.back());
            temp_DQ1.pop_back();
            buf1++;
        }
        while(temp_DQ2.front()!=k){
            temp_DQ2.push_back(temp_DQ2.front());
            temp_DQ2.pop_front();
            buf2++;
        }
        if(buf1>=buf2) {
            DQ = temp_DQ2;
            DQ.pop_front();
            ans += buf2;
        }
        else {
            DQ = temp_DQ1;
            DQ.pop_front();
            ans += buf1;
        }
    }
    cout << ans;
}