/* Towers of Hanoi: move a tower of n discs from pole 0 to pole 2 */
#include <stdio.h>

void movetower(int n, int a, int b);

int main() {
    int n;
    printf("Number of discs: ");
    scanf("%d", &n);
    printf("Move tower of %d from pole 0 to pole 2\n", n);
    movetower(n, 0, 2);
    return 0;
}

/* Move n discs from pole a to pole b.      */
/* a, b are in {0, 1, 2} and a != b, so the */
/* third pole is 3 - a - b:                 */
/*   a = 0, b = 2:  3 - a - b = 1           */
/*   a = 0, b = 1:  3 - a - b = 2           */
/*   a = 2, b = 1:  3 - a - b = 0           */
void movetower(int n, int a, int b) {
    if (n == 1) {              /* base case */
        printf("disc %d: %d -> %d\n", n, a, b);
        return;
    } else {
        movetower(n - 1, a, 3 - a - b);
        printf("disc %d: %d -> %d\n", n, a, b);
        movetower(n - 1, 3 - a - b, b);
    }
}
