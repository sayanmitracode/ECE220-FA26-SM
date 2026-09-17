/* n choose k: main -> Choose -> Fact, three times */
#include <stdio.h>

int Fact(int n) {
    int i, result = 1;
    for (i = 1; i <= n; i++)
        result = result * i;
    return result;
}

int Choose(int n, int k) {
    int ways;
    ways = Fact(n);
    ways = ways / Fact(k);
    ways = ways / Fact(n - k);
    return ways;
}

int main() {
    int answer;
    answer = Choose(5, 2);
    printf("5 choose 2 = %d\n", answer);
    return 0;
}
