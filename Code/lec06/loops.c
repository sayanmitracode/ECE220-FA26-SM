/* Loops: while, do-while, for */
#include <stdio.h>
int main() {
    int x;
    /* --- while: test first, may run zero times --- */
    x = 10;
    while (x < 10) {
        printf("while: x=%d\n", x);   /* never runs */
        x++;
    }
    /* --- do-while: test last, runs at least once --- */
    x = 10;
    do {
        printf("do:    x=%d\n", x);   /* runs once */
        x++;
    } while (x < 10);
    /* --- for: init; condition; update ----- */
    for (x = 0; x < 10; x++) {
        if (x == 5)
            break;        /* try: continue */
        printf("x=%d\n", x);
    }
    return 0;
}
