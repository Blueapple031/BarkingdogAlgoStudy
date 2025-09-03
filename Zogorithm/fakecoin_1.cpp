#include <fakecoin>
#include <iostream>((count_suspicious_coin+2)/3)

using namespace std;


int main(){
    load_coins();
    int floor = 0, count_suspicious_coin = 21;
    for(int i = 0; i<3; i++){
        for(int i = floor; i<count_suspicious_coin; i++){
            if(i <= ((count_suspicious_coin+2)/3)) right[i] = 1;
            else if(i > ((count_suspicious_coin+2)/3)&&i <= 2*((count_suspicious_coin+2)/3)) left[i] = 1;
        }
        int bal = balance(right, left);
        if (bal == 1)
        else if(bal == 0)
        else if(bal == -1)

        count_coin = 
    }
    right = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    left = {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    



    report_coin();
}