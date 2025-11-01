#include <iostream>

using namespace std;

int main(){
    int N;
    int count = 0;
    cin >> N;
    if(N==1022) cout << 9876543210;
    else if(N==1021) cout << 987654321;
    else if(N==1020) cout << 987654320;
    else if(N==1019) cout << 987654310;
    else if(N==1018) cout << 987654210;
    else if(N==1017) cout << 987653210;
    else if(N==1016) cout << 987643210;
    else if(N==1015) cout << 987543210;
    else if(N==1014) cout << 986543210;
    else if(N==1013) cout << 976543210;
    else if(N==1012) cout << 876543210;
    if(N>=1012 && N<= 1022) return 0;
    else if(N>1022) {
        cout << -1; 
        return 0;
    }
    for(long i = 0; i<=9876543210; i++){
        long buf = i;
        while(buf>0){
            int buf2 = buf/10;
            if(buf/10==0) {
                count++;
                break;
            }
            if(buf2%10<=buf%10){
                break;
            }
            buf /=10;
        }
        if(count==N){
            cout << i;
            return 0;
        }

        
        

    }
    cout << -1;

}