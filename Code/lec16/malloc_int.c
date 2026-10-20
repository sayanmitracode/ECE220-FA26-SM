/* malloc and free: one int on the heap, then an array of 10 ints */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *arr, i;

    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("ERROR - malloc failure!\n");
        return 1;
    }
    *ptr = 10;
    printf("*ptr = %d\n", *ptr);
    free(ptr);

    /* an array of 10 ints */
    arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL)
        return 1;
    for (i = 0; i < 10; i++)
        arr[i] = i * i;
    printf("arr[9] = %d\n", arr[9]);
    free(arr);
    return 0;
}
