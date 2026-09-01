/* answer = Fact(number): prototype, call, definition */
#include <stdio.h>

int Fact(int n);              /* PROTOTYPE: ends with ; */

int main() {
    int number, answer;
    printf("Enter a number: ");
    scanf("%d", &number);
    answer = Fact(number);    /* the CALL */
    printf("factorial of %d is %d\n", number, answer);
    return 0;
}

int Fact(int n) {             /* the DEFINITION */
    int i, result = 1;        /* locals: born at the call */
    for (i = 1; i <= n; i++)
        result = result * i;
    return result;            /* typed return value */
}
