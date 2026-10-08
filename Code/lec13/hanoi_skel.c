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
/* a, b are in {0, 1, 2} and a != b.        */
void movetower(int n, int a, int b) {
    /* base case: a tower of one disc */



    /* top n-1 discs: pole a to third pole */


    /* disc n: pole a to pole b */


    /* the n-1 discs: third pole to pole b */


}
