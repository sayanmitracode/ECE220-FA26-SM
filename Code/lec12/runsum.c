/* RunningSum(n) = 1 + 2 + ... + n */
#include <stdio.h>

int RunningSum(int n) {
    if (n == 1)
        return 1;                    /* base case */
    else
        return n + RunningSum(n - 1);
}

int main() {
    printf("RunningSum(3) = %d\n", RunningSum(3));
    return 0;
}
