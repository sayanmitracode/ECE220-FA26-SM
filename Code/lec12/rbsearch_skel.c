/* Recursive binary search: index or -1 */
#include <stdio.h>

int binary(int array[], int item, int start, int end) {
    /* base case: the region is empty */

    /* probe the middle; found? done  */

    /* recurse into the correct half  */

}

int main() {
    int a[10] = {2,5,8,12,16,23,38,56,72,91};
    printf("23 at %d\n", binary(a, 23, 0, 9));
    return 0;
}
