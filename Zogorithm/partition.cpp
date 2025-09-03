#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point{
    int x, y;
};

int ccw(const Point& a, const Point& b, const Point& c){
    int cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return (cross > 0) ? 1 : (cross < 0 ? -1 : 0);
}

int main (){
    int N;
    cin >> N;
    vector<Point> points(N);
    for(int i = 0; i<N; i++)
        cin >> points[i].x >> points[i].y;

    int best_i = -1, best_j = -1;
    double best_dist = 0;

    for(int i = 0; i<N; i++){
        for(int j = i+1; j <N; j++){
            int left = 0, right =0;
            for (int k = 0; k<N; k++){
                if(k==i || k==j) continue;
                int sign = ccw(points[i], points[j], points[k]);
                if(sign > 0) left++;
                else if (sign < 0) right++;
            }
            if(left == N/2 -1 && right == N/2 -1){
                double dist = hypot(points[i].x - points[j].x, points[i].y - points[j].y);
                if (dist > best_dist){
                    best_dist = dist;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }
    if(best_i == -1){
        cout << 0 << ' ' << 0;
    } else{
        cout << best_i +1 << ' ' << best_j+1;
    }
}