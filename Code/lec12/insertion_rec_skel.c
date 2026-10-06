/* Insertion sort, recursive:
   sort the first n-1 items, then insert the last one. */
#include <stdio.h>
#define SIZE 6

void insertion_sort(int array[], int n) {
    int s, temp, empty_idx;
    /* base case: nothing left to sort? */

    /* recursive call: sort the first n-1 */

    /* insert array[n-1] into the sorted */
    /* part, as the loop version did     */

}

int main() {
    int a[SIZE] = {5, 2, 6, 1, 3, 9}, i;
    insertion_sort(a, SIZE);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
