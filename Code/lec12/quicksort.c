/* Quicksort, completed */
#include <stdio.h>

int partition(int array[], int start, int end) {
    int pivot = array[end], i = start - 1, j, t;
    for (j = start; j < end; j++)
        if (array[j] < pivot) {
            i++;
            t = array[i]; array[i] = array[j]; array[j] = t;
        }
    t = array[i+1]; array[i+1] = array[end]; array[end] = t;
    return i + 1;            /* pivot's final index */
}

void quicksort(int array[], int start, int end) {
    int p;
    if (start >= end)
        return;              /* base: 0 or 1 element */
    p = partition(array, start, end);
    quicksort(array, start, p - 1);
    quicksort(array, p + 1, end);
}

int main() {
    int a[8] = {38, 5, 91, 16, 23, 2, 72, 56}, i;
    quicksort(a, 0, 7);
    for (i = 0; i < 8; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
