#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MAX_CNT 34

int xlim, ylim, call_cnt = 0;

void ready() {
    // 표준 입력에서 값 읽기
    scanf("%d %d", &xlim, &ylim);
}

int experiment(int x, int y) {
    call_cnt += 1;

    if (call_cnt > MAX_CNT) {
        printf("-999\n");
        printf("%d",call_cnt);
    }

    if (x > xlim || y > ylim) return -1;
    else return 1;
}

void report_maxE(long value) {
    if (value == ((xlim + ylim) * (xlim + ylim))) {
        printf("%ld\n", value);  // 정답 출력
        exit(0);
    } else {
        printf("-999\n");
        exit(0);
    }
}
