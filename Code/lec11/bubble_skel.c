/* Bubble sort, with Lecture 9's pointer swap */
#include <stdio.h>
#define SIZE 5

void swap(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

void bubble_sort(int array[], int n) {
    /* declare counter and "swapped" flag */

    do {
        /* reset the flag */

        /* one pass: compare neighbors,   */
        /* swap out-of-order pairs,       */
        /* remember that you swapped      */

    } while (            );  /* when to go again? */
}

int main() {
    int a[SIZE] = {8, 1, 4, 2, 5}, i;
    bubble_sort(a, SIZE);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
