/* Recursive binary search: index of item, or -1.
   The loop's low and high are now parameters. */
#include <stdio.h>
#define SIZE 10

int recursive_bin_search(int array[], int item,
                         int low, int high) {
    int mid;
    /* base case: is the region empty?  */

    /* probe the middle; found it? done */

    /* keep the half that can hold item, */
    /* then search it --- call yourself  */

}

int main() {
    int a[SIZE] = {2,5,8,12,16,23,38,56,72,91};
    int idx;
    idx = recursive_bin_search(a, 23, 0, SIZE - 1);
    printf("23 at index %d\n", idx);
    printf("40 at index %d\n",
           recursive_bin_search(a, 40, 0, SIZE - 1));
    return 0;
}
