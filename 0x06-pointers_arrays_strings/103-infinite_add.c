#include "main.h"

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int carry = 0;
    int idx1 = 0, idx2 = 0, idx_r = 0;
    int sum, num1, num2;

    while (n1[idx1] != '\0' || n2[idx2] != '\0' || carry != 0) {
        num1 = (n1[idx1] != '\0') ? n1[idx1] - '0' : 0;
        num2 = (n2[idx2] != '\0') ? n2[idx2] - '0' : 0;

        sum = num1 + num2 + carry;
        carry = sum / 10;

        if (idx_r < size_r - 1) {
            r[idx_r++] = (sum % 10) + '0';
        } else {
            return 0;  // Result cannot be stored in r
        }

        idx1++;
        idx2++;
    }

    r[idx_r] = '\0';

    return (r);
}
