#include <iostream>

using namespace std;

int arr[100005] = {0};
int isThere[100000005] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    int x;
    int query;
    cin >> N >> Q;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        isThere[arr[i]]++;
    }
    while(Q--){
        cin >> query >> x;
        bool isAns = 0;
        if(query == 1){
            if(N<2) cout << 0 << '\n';
            else{
                if(x == 0){
                    if(isThere[0]>0){
                        cout << 1 << '\n';
                        isAns = 1;
                    }
                }
                else{
                    for(int i = 0; i<N; i++){
                        if(arr[i]!=0 && x%arr[i] == 0){
                            isThere[arr[i]]--;//자기꺼 빼
                            //Ai가 0이 아니면서 x와 나누었을때 나누어떨어짐
                            int k = x/arr[i];
                            if(isThere[k]>=1){//k가 있네??
                                cout << 1 << '\n';
                                isThere[arr[i]]++;
                                isAns = 1;
                                break;
                            }
                            else isThere[arr[i]]++;
                        }
                    }
                }
                if(!isAns) cout << 0 << '\n';
            }
        }

        else if(query == 2){
            isThere[arr[x-1]]--;
            arr[x-1] = 0;
            isThere[0]++;
            
        }
        // for(int i = 0; i<N; i++) cout << arr[i] << ' ';
        // cout << '\n';
        // for(int i = 0; i<10000; i++){
        //     if(isThere[i]!=0) cout << i << " : " << isThere[i] << '\n';
        // }
    }

}