#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<string> grid;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    int maxW = 0;
    int best_x = 0, best_y = 0;

    // 1. 가로 방향 탐색 (2×W)
    for (int i = 0; i < N - 1; i++) { // 행을 순회
        for (int j = 0; j < M; j++) { // 열을 순회
            if (grid[i][j] == '1' || grid[i + 1][j] == '1') continue; // 장애물이면 패스
            
            int W = 0;
            while (j + W < M && grid[i][j + W] == '0' && grid[i + 1][j + W] == '0') {
                W++;
            }

            if (W > maxW) {
                maxW = W;
                best_x = i + 1;
                best_y = j + 1;
            } else if (W == maxW && (i + 1 < best_x || (i + 1 == best_x && j + 1 < best_y))) {
                best_x = i + 1;
                best_y = j + 1;
            }
        }
    }

    // 2. 세로 방향 탐색 (W×2)
    for (int i = 0; i < N; i++) { // 행을 순회
        for (int j = 0; j < M - 1; j++) { // 열을 순회
            if (grid[i][j] == '1' || grid[i][j + 1] == '1') continue; // 장애물이면 패스

            int W = 0;
            while (i + W < N && grid[i + W][j] == '0' && grid[i + W][j + 1] == '0') {
                W++;
            }

            if (W > maxW) {
                maxW = W;
                best_x = i + 1;
                best_y = j + 1;
            } else if (W == maxW && (i + 1 < best_x || (i + 1 == best_x && j + 1 < best_y))) {
                best_x = i + 1;
                best_y = j + 1;
            }
        }
    }

    // 3. 결과 출력
    if (maxW == 0) {
        cout << "0 0 0\n";
    } else {
        cout << best_x << " " << best_y << " " << maxW << "\n";
    }

    return 0;
}
