/* Decisions: if, if-else, switch */
#include <stdio.h>
int main() {
    int x = 14, y = 0, month = 4;
    /* --- if ------------------------------- */
    if (x < 0)
        x = -x;           /* negate only if negative */
    if ((x > 10) && (x < 20)) {
        y = x % 4;        /* y = ? */
        printf("y = %d\n", y);
    }
    /* --- if-else -------------------------- */
    if (x % 2 == 0)
        printf("%d is even\n", x);
    else
        printf("%d is odd\n", x);
    /* --- switch --------------------------- */
    switch (month) {
        case 12: case 1: case 2:
            printf("winter\n");
            break;        /* without it: fall-through! */
        case 3: case 4: case 5:
            printf("spring\n");
            break;
        default:
            printf("summer or fall\n");
    }
    return 0;
}
