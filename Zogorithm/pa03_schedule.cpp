#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int base_research, work_time;
    cin >> base_research >> work_time;

    vector<int> noise(work_time, 0); // 0~(work_time-1) 시간 구간에 대한 소음 누적치

    int num_teams;
    cin >> num_teams;

    for (int t = 0; t < num_teams; ++t) {
        int task_count;
        cin >> task_count;

        for (int i = 0; i < task_count; ++i) {
            int start, end, volume;
            cin >> start >> end >> volume;
            for (int j = start; j < end; ++j) {
                noise[j] += -volume; // 음수 소음 → 누적은 양수
            }
        }
    }

    int total_research = 0;
    for (int i = 0; i < work_time; ++i) {
        int available = base_research - noise[i];
        total_research += max(0, available); // 음수면 0으로 간주
    }

    cout << total_research << endl;
    return 0;
}
