/* RunningSum(n) = 1 + 2 + ... + n, with the result kept in a local */
#include <stdio.h>

int RunningSum(int n) {
    int fn;
    if (n == 1)
        fn = 1;             /* base case */
    else
        fn = n + RunningSum(n - 1);
    return fn;
}

int main() {
    int result;
    result = RunningSum(3);
    printf("RunningSum(3) = %d\n", result);
    return 0;
}
