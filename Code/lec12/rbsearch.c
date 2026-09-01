/* Recursive binary search: index or -1 */
#include <stdio.h>

int binary(int array[], int item, int start, int end) {
    int mid;
    if (start > end)
        return -1;               /* base: empty region */
    mid = (start + end) / 2;
    if (array[mid] == item)
        return mid;              /* base: found        */
    if (item < array[mid])
        return binary(array, item, start, mid - 1);
    else
        return binary(array, item, mid + 1, end);
}

int main() {
    int a[10] = {2,5,8,12,16,23,38,56,72,91};
    printf("23 at %d\n", binary(a, 23, 0, 9));
    return 0;
}
