#include "battery.h"
#include <iostream>
using namespace std;

int main(){
    int cmin = 0, cmax = 100001, count = 0;
    int cx = 50000, cy = 50000, result;
    long mymaxE;
    bool isNotXMax = true, isNotYMax = true;
    ready();
    while(isNotXMax){
        result = experiment(cx, cy);
        count++;
        if(result == -1){//터짐
            cmax = cx;
        }
        else if(result == 1){//안터짐
            cmin = cx;
        }
        cx = (cmax+cmin)/2;

        if(cmin+1>=cmax) isNotXMax = false;
    }
    //cout << "xcount : " << count;
    cmin = 0, cmax = 100001;
    while(isNotYMax){
        result = experiment(cx, cy);
        count++;
        if(result == -1){//터짐
            cmax = cy;
        }
        else if(result == 1){//안터짐
            cmin = cy;
        }
        cy = (cmax+cmin)/2;
        if(cmin+1>=cmax) isNotYMax = false;//
    }

    mymaxE = (cx+cy) * (cx+cy);
    //cout << "\ncount : "<< count << "\ncx : " << cx << "\ncy : " << cy << '\n';
    report_maxE(mymaxE);
}