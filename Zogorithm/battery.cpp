#include "battery.h"
#include <iostream>
#include <cmath>

using namespace std;

int cx = -1, cy = -1;

int binary_search(int x, int y, int min, int max) {
    while (min <= max) {
        int mid = (min + max) / 2;
        int result = experiment(x * mid, y * mid);
        if (result == 1) {
           min = mid + 1;
        } else if (result == -1) {
            max = mid - 1;
        }
    }
    if (x == 1)
      cx = min - 1;
    if (y == 1)
      cy = min - 1;
    return min-1;
}


int main() {
    long mymaxE;
    ready();

    //cout << binary_search(1, 0, 0, 100001) << '\n';
    //cout << binary_search(0, 1, 0, 100001) << '\n';
    binary_search(1, 0, 0, 100001);
    binary_search(0, 1, 0, 100001);
    mymaxE = (cx+cy) * (cx+cy); //pow 이 새끼가 문제였음음
    report_maxE(mymaxE);
    return 0;
}