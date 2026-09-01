/* Insertion sort, ascending */
#include <stdio.h>
#define SIZE 4

void insertion_sort(int array[]) {
    int i, j, temp, empty_idx;
    for (i = 1; i < SIZE; i++) {
        temp = array[i];        /* take the next item  */
        empty_idx = i;
        for (j = i - 1; j >= 0; j--)
            if (temp < array[j]) {
                array[j + 1] = array[j];   /* shift */
                empty_idx = j;
            }
        array[empty_idx] = temp; /* insert in the gap  */
    }
}

int main() {
    int a[SIZE] = {5, 2, 6, 1}, i;
    insertion_sort(a);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
