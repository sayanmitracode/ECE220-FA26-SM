/* Bubble sort, with Lecture 9's pointer swap */
#include <stdio.h>
#define SIZE 5

void swap(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

void bubble_sort(int array[]) {
    /* declare counter and "swapped" flag */

    do {
        /* reset the flag */

        /* one pass: compare neighbors,   */
        /* swap out-of-order pairs,       */
        /* remember that you swapped      */

    } while (            );  /* when to go again? */
}

int main() {
    int a[SIZE] = {5, 1, 4, 2, 8}, i;
    bubble_sort(a);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
