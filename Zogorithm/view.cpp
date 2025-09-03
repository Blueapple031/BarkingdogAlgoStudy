#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<char, int>> buildings(N);
    vector<char> ans_mou, ans_sea;

    for (int i = 0; i < N; i++) {
        cin >> buildings[i].first >> buildings[i].second;
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        if (buildings[i].second > max) {
            ans_mou.push_back(buildings[i].first);
            max = buildings[i].second;
        }
    }

    max = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (buildings[i].second > max) {
            ans_sea.push_back(buildings[i].first);
            max = buildings[i].second;
        }
    }

    for (char c : ans_mou) cout << c << " ";
    cout << "\n";
    reverse(ans_sea.begin(), ans_sea.end());
    for (char c : ans_sea) cout << c << " ";
    cout << "\n";
}
