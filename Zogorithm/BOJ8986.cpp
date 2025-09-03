#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N;
vector<long long> v;
long long calculate_distance(long long distance){
    long long sum_distance = 0;
    for(int i = 0; i<N; i++){
        sum_distance += abs(v[i] - i*distance);
    }
    return sum_distance;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 0; i<N; i++){
        long long k;
        cin >> k;
        v.push_back(k);
    }
    long long bottom = 0, top = v[N-1];
    while(top-bottom > 4){
        long long p = (2*bottom + top)/3, q = (bottom + 2*top)/3;
        if(calculate_distance(p)>calculate_distance(q)) bottom = p;
        else top = q;
    }
    long long min = calculate_distance(bottom);
    for(long long i = bottom+1; i<top; i++){
        long long k = calculate_distance(i);
        if(min > k) min = k;
    }
    cout << min;
}