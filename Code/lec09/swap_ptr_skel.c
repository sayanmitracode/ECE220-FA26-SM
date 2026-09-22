/* swap, fixed: pass ADDRESSES, not values */
#include <stdio.h>

void swap(int *a, int *b) {
    /* declare a temporary */


    /* exchange what a and b POINT TO */



}

int main() {
    int x = 2, y = 3;
    /* call swap with the ADDRESSES */

    printf("x = %d, y = %d\n", x, y);
    return 0;
}
