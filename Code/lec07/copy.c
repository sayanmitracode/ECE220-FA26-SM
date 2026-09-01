/* Arguments are COPIES (pass by value) */
#include <stdio.h>

void tryToChange(int a) {
    a = 99;                   /* changes the copy */
    printf("inside:  a = %d\n", a);
}

int main() {
    int x = 5;
    tryToChange(x);
    printf("outside: x = %d\n", x);
    return 0;
}
