#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

struct Circle {
    int id, x, y, r;
};

// 두 원의 겹치는 면적을 계산
double Common_Circle(double x1, double y1, double r1,
                    double x2, double y2, double r2) {
    double dx = x2 - x1, dy = y2 - y1;
    double d = sqrt(dx*dx + dy*dy);
    if (d >= r1 + r2) 
        return 0.0;
    if (d <= fabs(r1 - r2)) {
        double rr = min(r1, r2);
        return PI * rr * rr;
    }
    double a1 = acos((d*d + r1*r1 - r2*r2)/(2*d*r1));
    double a2 = acos((d*d + r2*r2 - r1*r1)/(2*d*r2));
    double area1 = r1*r1 * a1;
    double area2 = r2*r2 * a2;
    double area3 = 0.5 * sqrt((-d + r1 + r2)*(d + r1 - r2)
                             *(d - r1 + r2)*(d + r1 + r2));
    return area1 + area2 - area3;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Circle> C(n);
    for (int i = 0; i < n; i++)
        cin >> C[i].id >> C[i].x >> C[i].y >> C[i].r;

    // 왼쪽 경계(x - r) 순으로 정렬
    sort(C.begin(), C.end(), [](auto &a, auto &b){
        return (a.x - a.r) < (b.x - b.r);
    });

    double max_area = 0.0;
    uint64_t best_ids = 0;           // 상위 32비트: 작은 id, 하위 32비트: 큰 id
    set<pair<int,int>> active;       // {오른쪽 경계(x+r), 원의 인덱스}

    for (int i = 0; i < n; i++) {
        int lb = C[i].x - C[i].r;
        // 더 이상 겹칠 수 없는 원 제거
        while (!active.empty() && active.begin()->first <= lb)
            active.erase(active.begin());
        // 활성화된 원과 영역 비교
        for (auto &pr : active) {
            int j = pr.second;
            double area = Common_Circle(
                C[i].x, C[i].y, C[i].r,
                C[j].x, C[j].y, C[j].r
            );
            if (area >= max_area) {
                uint64_t id1 = C[i].id, id2 = C[j].id;
                uint64_t lo = min(id1, id2), hi = max(id1, id2);
                uint64_t ids = (lo << 32) | hi;
                // 면적이 더 크거나, 면적이 같을 때 사전순으로 작은 쌍 선택
                if (area > max_area || ids < best_ids) {
                    max_area = area;
                    best_ids = ids;
                }
            }
        }
        active.insert({C[i].x + C[i].r, i});
    }

    // 결과 출력
    uint32_t id_lo = best_ids >> 32;
    uint32_t id_hi = best_ids & 0xffffffff;
    cout << id_lo << ' ' << id_hi << "\n";
    return 0;
}
