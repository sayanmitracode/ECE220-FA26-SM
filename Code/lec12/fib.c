/* Fibonacci: 0 1 1 2 3 5 8 13 ... */
#include <stdio.h>

int Fibonacci(int n) {   /* n >= 0 */
    if (n == 0)
        return 0;        /* base case 1 */
    if (n == 1)
        return 1;        /* base case 2 */
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    printf("Fib(10) = %d\n", Fibonacci(10));
    return 0;
}
