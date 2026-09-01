/* swap, fixed: pass ADDRESSES, not values */
#include <stdio.h>

void swap(int *x, int *y) {
    int temp;
    temp = *x;            /* read through the pointer  */
    *x = *y;
    *y = temp;            /* write through the pointer */
}

int main() {
    int x = 2, y = 3;
    swap(&x, &y);         /* hand over the addresses   */
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
