/* Iterative binary search: index of item, or -1 */
#include <stdio.h>
#define SIZE 10

int binary_search(int array[], int item) {
    /* low and high bracket the live region */

    /* while the region is non-empty:       */

        /* find the middle; found? return   */

        /* else shrink to the correct half  */

    /* not found */

}

int main() {
    int a[SIZE] = {2,5,8,12,16,23,38,56,72,91};
    printf("23 at index %d\n", binary_search(a, 23));
    printf("40 at index %d\n", binary_search(a, 40));
    return 0;
}
