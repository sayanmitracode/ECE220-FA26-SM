/* Fibonacci with a lookup table (memoization) */
#include <stdio.h>

int table[100];          /* main sets all to -1 */

int fibonacci(int n) {   /* 0 <= n < 100 */
    if (table[n] != -1)
        return table[n];         /* already known */
    if (n == 0)
        table[n] = 0;
    else if (n == 1)
        table[n] = 1;
    else
        table[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return table[n];
}

int main() {
    int i;
    for (i = 0; i < 100; i++) table[i] = -1;
    printf("fib(40) = %d\n", fibonacci(40));
    return 0;
}
