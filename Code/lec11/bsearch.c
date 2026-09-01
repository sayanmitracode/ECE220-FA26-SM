/* Iterative binary search: index of item, or -1 */
#include <stdio.h>
#define SIZE 10

int binary_search(int array[], int item) {
    int low = 0, high = SIZE - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == item)
            return mid;
        if (item < array[mid])
            high = mid - 1;   /* first half  */
        else
            low = mid + 1;    /* second half */
    }
    return -1;
}

int main() {
    int a[SIZE] = {2,5,8,12,16,23,38,56,72,91};
    printf("23 at index %d\n", binary_search(a, 23));
    printf("40 at index %d\n", binary_search(a, 40));
    return 0;
}
