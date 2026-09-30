/* Insertion sort, ascending.
   s scans the sorted part; u is the first unsorted item. */
#include <stdio.h>
#define SIZE 6

void insertion_sort(int array[], int n) {
    int s, u, temp, empty_idx;
    for (u = 1; u < n; u++) {
        /* take array[u]; remember the gap index */

        /* scan the sorted part right-to-left:   */
        /* shift larger elements right,          */
        /* moving the gap left as you go         */

        /* insert the taken item into the gap    */

    }
}

int main() {
    int a[SIZE] = {5, 2, 6, 1, 3, 9}, i;
    insertion_sort(a, SIZE);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
