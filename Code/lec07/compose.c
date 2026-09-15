/* Calls inside calls: a return value becomes an argument */
#include <stdio.h>
#include <math.h>                  /* sqrt, pow */

int Fact(int n);

int main() {
    double a = 3.0, b = 4.0, hyp;
    int n = 5, k = 2, ways;

    /* inner calls finish first */
    hyp  = sqrt(pow(a, 2) + pow(b, 2));
    /* Fact runs three times */
    ways = Fact(n) / (Fact(k) * Fact(n - k));

    printf("hyp = %.1f, ways = %d\n", hyp, ways);
    return 0;
}

int Fact(int n) {
    int i, result = 1;
    for (i = 1; i <= n; i++)
        result = result * i;
    return result;
}
