/* answer = Fact(number): the example we trace by hand */
#include <stdio.h>
int Fact(int n);

int main() {
    int number, answer;
    printf("Enter a number: ");
    scanf("%d", &number);
    answer = Fact(number);
    printf("factorial of %d is %d\n", number, answer);
    return 0;
}

int Fact(int n) {
    int i, result = 1;
    for (i = 1; i <= n; i++)
        result = result * i;
    return result;
}
