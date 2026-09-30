/* Bubble sort, with Lecture 9's pointer swap */
#include <stdio.h>
#define SIZE 5

void swap(int *x, int *y) {
    int t = *x; *x = *y; *y = t;
}

void bubble_sort(int array[], int n) {
    int i, swapped;
    do {
        swapped = 0;
        for (i = 0; i < n - 1; i++)
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                swapped = 1;
            }
    } while (swapped);
}

int main() {
    int a[SIZE] = {8, 1, 4, 2, 5}, i;
    bubble_sort(a, SIZE);
    for (i = 0; i < SIZE; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
