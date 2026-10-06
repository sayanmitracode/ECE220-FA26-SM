/* Insertion sort, recursive:
   sort the first n-1 items, then insert the last one. */
#include <stdio.h>
#define SIZE 6

void insertion_sort(int array[], int n) {
    int s, temp, empty_idx;
    if (n <= 1)
        return;                    /* base case */
    insertion_sort(array, n - 1);  /* first n-1 */
    temp = array[n - 1];           /* take the last */
    empty_idx = n - 1;
    for (s = n - 2; s >= 0; s--)
        if (temp < array[s]) {
            array[s + 1] = array[s]; /* shift */
            empty_idx = s;
        }
    array[empty_idx] = temp;       /* insert */
}

int main() {
    int a[SIZE] = {5, 2, 6, 1, 3, 9}, i;
    insertion_sort(a, SIZE);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
