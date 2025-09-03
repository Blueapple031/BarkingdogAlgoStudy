#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int totalSum = N * (N + 1) / 2;
    int totalSquareSum = N * (N + 1) * (2 * N + 1) / 6;
    int givenSum = 0, givenSquareSum = 0;

    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        int num;
        if (!(cin >> num)) break;
        givenSum += num;
        givenSquareSum += num * num;
        count++;
    }

    int missingSum = totalSum - givenSum;  // X + Y
    int missingSquareSum = totalSquareSum - givenSquareSum; // X^2 + Y^2

    if (count == N - 1) {
        cout << missingSum << "\n";
        return 0;
    }

    int productXY = (missingSum * missingSum - missingSquareSum) / 2; // XY
    int D = sqrt(missingSum * missingSum - 4 * productXY);
    int X = (missingSum + D) / 2;
    int Y = missingSum - X;

    if (X > Y) swap(X, Y);
    cout << X << "\n" << Y << "\n";

    return 0;
}
