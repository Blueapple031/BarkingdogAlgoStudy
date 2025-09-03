#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> pages;

bool is_possible(int limit) {
    int count = 1; // 필요한 사람 수
    int current_sum = 0; 

    for (int i = 0; i < N; ++i) {
        if (pages[i] > limit) return false; // 하나의 챕터가 제한보다 크면 불가능

        if (current_sum + pages[i] > limit) {
            count++;
            current_sum = pages[i]; // 새 사람에게 시작
        } else {
            current_sum += pages[i];
        }
    }

    return count <= K;
}

int main() {
    cin >> N >> K;
    pages.resize(N);

    int total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> pages[i];
        total += pages[i];
    }

    int left = *max_element(pages.begin(), pages.end()); // 최소 제한값
    int right = total; // 최대 제한값
    int answer = total;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (is_possible(mid)) {
            answer = mid;
            right = mid - 1; // 더 작은 값이 있는지 시도
        } else {
            left = mid + 1; // 너무 작아서 불가능 → 키워야 함
        }
    }

    cout << answer << endl;
    return 0;
}
