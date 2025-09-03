#include "twofakes.h"
#include <string.h>

int first_fake, second_fake;

void reset_scale() {
    for (int i = 0; i < 11; i++) {
        left[i] = 0;
        right[i] = 0;
    }
}

int compare_one(int l, int r) {
    reset_scale();
    left[l] = 1;
    right[r] = 1;
    return balance(left, right);
}

void handle_balanced_case() {
    int result = compare_one(1, 3); // compare group A
    if (result == 0) {
        two_fakes(9, 10); // both fakes in group C
        return;
    }

    first_fake = (result == 1) ? 3 : 1;

    reset_scale();
    left[5] = left[6] = 1;
    right[7] = right[8] = 1;
    result = balance(left, right);

    if (result == 1) {
        result = compare_one(7, 8);
        second_fake = (result == 1) ? 8 : 7;
    } else if (result == -1) {
        result = compare_one(5, 6);
        second_fake = (result == 1) ? 6 : 5;
    } else {
        second_fake = 6; // default fallback (should not reach here)
    }

    two_fakes(first_fake, second_fake);
}

void handle_unbalanced_case(int left_heavy) {
    int base = left_heavy ? 5 : 1;
    int result = compare_one(base, base + 1);

    if (result == 0) {
        result = compare_one(base + 2, base + 3);
        if (result == 0) {
            reset_scale();
            left[base] = left[base + 1] = 1;
            right[9] = right[10] = 1;
            result = balance(left, right);
            if (result == 0) two_fakes(base, base + 1);
            else two_fakes(base + 2, base + 3);
            return;
        } else {
            first_fake = (result == 1) ? base + 3 : base + 2;
        }
    } else {
        first_fake = (result == 1) ? base + 1 : base;
    }

    result = compare_one(9, 10);
    second_fake = (result == 1) ? 10 : 9;

    two_fakes(first_fake, second_fake);
}

int main() {
    load_coins();

    reset_scale();
    for (int i = 1; i <= 4; i++) left[i] = 1;
    for (int i = 5; i <= 8; i++) right[i] = 1;

    int result = balance(left, right);
    if (result == 0)
        handle_balanced_case();
    else
        handle_unbalanced_case(result == 1);

    return 0;
}
