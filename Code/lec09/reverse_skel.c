/* Reverse an integer array in place */
#include <stdio.h>

void array_reversal(int array[], int n) {
    /* declare a loop counter and a temporary */

    /* how far does the loop need to go? */

        /* swap array[i] with its mirror element */

}

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6}, i;
    array_reversal(a, 6);
    for (i = 0; i < 6; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
