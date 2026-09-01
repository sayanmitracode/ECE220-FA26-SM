/* Loops: while, do-while, for */
#include <stdio.h>
int main() {
    int x;
    /* --- while: may run zero times -------- */
    x = 0;
    while (x < 10) {
        printf("x=%d\n", x);
        x++;
    }
    /* --- do-while: runs at least once ----- */
    x = 0;
    do {
        printf("x=%d\n", x);
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
