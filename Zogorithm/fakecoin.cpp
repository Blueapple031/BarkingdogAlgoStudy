#include "fakecoin.h"
#include <cstdlib>


int find_fake_coin(int start, int end) {
    if (start == end) return start; // 가짜 동전 발견

    int size = end - start + 1;
    if (size == 2) { 
        // 두 개만 남으면 하나를 저울에 올려 확인
        left[start] = 1; right[start + 1] = 1;
        int result = balance(left, right);
        if (result == -1) return start;
        else return start + 1;
    }

    // 삼등분
    int mid1 = start + size / 3;
    int mid2 = start + 2 * (size / 3);

    // 왼쪽 그룹(A)과 중간 그룹(B) 비교
    for (int i = start; i < mid1; i++) left[i] = 1;
    for (int i = mid1; i < mid2; i++) right[i] = 1;
    int result = balance(left, right);

    // 배열 초기화
    for (int i = start; i < mid1; i++) left[i] = 0;
    for (int i = mid1; i < mid2; i++) right[i] = 0;

    if (result == 0) return find_fake_coin(mid2, end);   // 가벼운 동전이 C 그룹에 있음
    else if (result == 1) return find_fake_coin(mid1, mid2 - 1); // 가벼운 동전이 B 그룹에 있음
    else return find_fake_coin(start, mid1 - 1);  // 가벼운 동전이 A 그룹에 있음
}

int main() {
    load_coins();  // 동전 정보 불러오기
    int fake = find_fake_coin(1, 21);  // 가짜 동전 찾기
    report_coin(fake);  // 결과 보고
}
