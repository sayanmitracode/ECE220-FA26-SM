/* Insertion sort, ascending.
   s scans the sorted part; u is the first unsorted item. */
#include <stdio.h>
#define SIZE 6

void insertion_sort(int array[], int n) {
    int s, u, temp, empty_idx;
    for (u = 1; u < n; u++) {
        temp = array[u];      /* take next item */
        empty_idx = u;
        for (s = u - 1; s >= 0; s--)
            if (temp < array[s]) {
                array[s + 1] = array[s]; /* shift */
                empty_idx = s;
            }
        array[empty_idx] = temp;  /* insert */
    }
}

int main() {
    int a[SIZE] = {5, 2, 6, 1, 3, 9}, i;
    insertion_sort(a, SIZE);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
