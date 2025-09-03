#include <iostream>
#include <vector>
#include <algorithm> // std::sort 사용을 위함

// Point 구조체 정의
struct Point {
    int id; // 원본 점의 인덱스
    long long x, y; // 점의 x, y 좌표 (정수 좌표)

    // 생성자 (기본값 설정)
    Point(int _id = 0, long long _x = 0, long long _y = 0) : id(_id), x(_x), y(_y) {}
};

// 세 점 p, q, r에 대한 부호 있는 넓이 (삼각형 넓이의 2배) 계산 함수
// 이 값은 p->q 벡터에 대해 r의 방향을 나타냄:
// 양수: r이 p->q의 왼쪽에 위치 (반시계 방향)
// 음수: r이 p->q의 오른쪽에 위치 (시계 방향)
// 0: 세 점이 일직선 상에 위치 (공선점)
long long signed_area(Point p, Point q, Point r) {
    return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
}

// 두 점 p1, p2 사이의 유클리드 거리 제곱을 계산하는 함수
// 실제 거리를 구할 필요 없이 비교만 할 때 sqrt 연산을 피하기 위해 사용
long long distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main() {
    // C++ 표준 스트림과 C 표준 스트림의 동기화를 해제하여 입출력 속도를 높임
    std::ios_base::sync_with_stdio(false);
    // cin과 cout의 묶음을 해제하여 입력 버퍼를 비우지 않아도 되게 함
    std::cin.tie(NULL);

    int N;
    std::cin >> N; // 점의 개수 N을 읽어옴 

    // 모든 점을 저장할 벡터 (인덱스에 직접 접근하기 위해 N+1 크기로 선언)
    // P0는 (0,0)으로 고정되어 있으므로 all_points[0]에 저장
    std::vector<Point> all_points(N + 1);
    all_points[0] = Point(0, 0, 0); // P0 (ID:0, 좌표:(0,0)) 설정 

    // N개의 점의 ID와 좌표를 읽어와 all_points에 저장
    // 점의 ID는 1부터 N까지이다. 
    for (int i = 0; i < N; ++i) {
        int id;
        long long x, y;
        std::cin >> id >> x >> y; // ID와 좌표 (x, y)를 읽어옴 
        all_points[id] = Point(id, x, y);
    }

    // 아직 정렬되지 않은(남아있는) 점들을 저장할 벡터
    std::vector<Point> remaining_points;
    for(int i = 1; i <= N; ++i) { // P0를 제외한 점들을 추가
        remaining_points.push_back(all_points[i]);
    }

    Point current_point = all_points[0]; // 현재 회전의 기준이 되는 점 (시작은 P0) 
    std::vector<int> sorted_indices; // 정렬된 점들의 ID를 저장할 벡터

    // 모든 점이 정렬될 때까지 반복
    while (sorted_indices.size() < N) {
        int best_point_idx_in_remaining = -1; // 현재 라운드에서 선택될 최적의 점의 remaining_points 내 인덱스

        // remaining_points 내의 모든 점을 순회하며 다음으로 선택될 점을 찾음
        for (size_t i = 0; i < remaining_points.size(); ++i) {
            if (remaining_points[i].id == -1) continue; // 이미 선택된 점은 건너뛰기 (-1은 사용된 점을 표시)

            // 아직 선택된 점이 없다면 현재 점을 최적의 점으로 초기 설정
            if (best_point_idx_in_remaining == -1) {
                best_point_idx_in_remaining = i;
            } else {
                Point p1 = remaining_points[best_point_idx_in_remaining]; // 현재까지의 최적 점
                Point p2 = remaining_points[i]; // 비교할 다음 점

                // current_point -> p1 벡터에 대한 p2의 방향 (부호 있는 넓이)
                long long orientation = signed_area(current_point, p1, p2);

                if (orientation < 0) { // p2가 p1보다 current_point에 대해 반시계 방향으로 더 앞에 있다면
                                        // (즉, p2가 p1보다 더 '왼쪽'에 있어서 회전 시 먼저 만날 점)
                    best_point_idx_in_remaining = i; // p2를 새로운 최적 점으로 선택
                } else if (orientation == 0) { // 세 점이 일직선 상에 있다면 
                    // current_point에서 더 가까운 점을 선택 
                    if (distSq(current_point, p2) < distSq(current_point, p1)) {
                        best_point_idx_in_remaining = i; // p2가 더 가깝다면 p2를 선택
                    }
                }
                // orientation > 0 (p2가 p1보다 시계 방향으로 더 뒤에 있거나 같은 선상이라면)
                // p1이 여전히 최적 점이거나, 이미 p1이 더 반시계 방향인 경우이므로 아무것도 하지 않음.
            }
        }
        
        // 최적의 점을 찾았다면 정렬된 목록에 추가
        if (best_point_idx_in_remaining != -1) {
            sorted_indices.push_back(remaining_points[best_point_idx_in_remaining].id); // 점의 ID를 추가
            current_point = remaining_points[best_point_idx_in_remaining]; // 다음 회전의 기준점을 이 점으로 업데이트
            remaining_points[best_point_idx_in_remaining].id = -1; // 이 점을 사용되었음으로 표시
        } else {
            // 모든 점을 처리했거나, 예외적인 상황 발생 시 루프 종료
            break; 
        }
    }

    // 정렬된 점들의 인덱스를 한 줄에 하나씩 출력 
    for (int index : sorted_indices) {
        std::cout << index << std::endl;
    }

    return 0; // 프로그램 성공 종료
}