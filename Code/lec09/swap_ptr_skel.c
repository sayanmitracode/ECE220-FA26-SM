/* swap, fixed: pass ADDRESSES, not values */
#include <stdio.h>

void swap(int *x, int *y) {
    /* declare a temporary */

    /* exchange the values x and y POINT TO */

}

int main() {
    int x = 2, y = 3;
    /* call swap with the ADDRESSES of x and y */

    printf("x = %d, y = %d\n", x, y);
    return 0;
}
