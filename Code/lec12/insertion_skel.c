/* Insertion sort, ascending */
#include <stdio.h>
#define SIZE 4

void insertion_sort(int array[]) {
    int i, j, temp, empty_idx;
    for (i = 1; i < SIZE; i++) {
        /* take array[i]; remember the gap index  */

        /* scan the sorted part right-to-left:    */
        /* shift larger elements right,           */
        /* moving the gap left as you go          */

        /* insert the taken item into the gap     */

    }
}

int main() {
    int a[SIZE] = {5, 2, 6, 1}, i;
    insertion_sort(a);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
