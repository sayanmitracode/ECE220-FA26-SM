/* Towers of Hanoi: move a tower of n discs from pole 0 to pole 2 */
#include <stdio.h>

/* function to move a tower of n discs from pole a to pole b */
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
/* a, b are in {0, 1, 2} and a != b.        */
void movetower(int n, int a, int b) {
    /* base case: a tower of one disc */
    if (n == 1) {
        printf("Move disc from pole %d to pole %d\n", a, b);
        return;
    }

    /* top n-1 discs: pole a to third pole */
    movetower(n - 1, a, 3 - a - b);

    /* disc n: pole a to pole b */
    printf("Move disc from pole %d to pole %d\n", a, b);

    /* the n-1 discs: third pole to pole b */
    movetower(n - 1, 3 - a - b, b);

}
