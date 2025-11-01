#include <iostream>

using namespace std;

bool func(long long buf, int iter){//buf의 각 자리수 buf가 나누어지는가
    long long bufbuf = buf/iter;
    for(int i = 0; i<10; i++){
        if(bufbuf%10 != 0){
            int k = bufbuf%10;
            if(buf%k != 0){//각 자리수가 하나라도 안 나누어 떨어짐
                return 0;
            }
        }
        bufbuf /= 10;
    }
    return 1;
}

int main(){
    //0~9, 10~99, 100~999, 1000~9999
    int N;

    cin >> N;
    long long buf = N;

    if(func(buf,1)){
            cout << buf;
            return 0;
    }
    int iter = 1;
    for(int i = 0; i<8; i++){
        buf*=10;//한자리수
        iter*=10;//반복자
        for(int a = 0; a<iter; a++){
            buf +=a;
            if(func(buf, iter)){
                cout << buf;
                return 0;
            }
            buf -=a;
        }
    }
}