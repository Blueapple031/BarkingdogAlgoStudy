#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c;
    while(!(a==0&&b==0&&c==0)){
        cin >> a >> b >> c;
        if(a*b*c == 0) break;
        if((a*a)==(b*b)+(c*c)||
            pow(b,2)==pow(c,2)+pow(a,2)||
            pow(c,2)==pow(a,2)+pow(b,2))    cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }
}