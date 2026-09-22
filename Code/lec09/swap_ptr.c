/* swap, fixed: pass ADDRESSES, not values */
#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;       /* read through a  */
    *a = *b;
    *b = temp;       /* write through b */
}

int main() {
    int x = 2, y = 3;
    swap(&x, &y);    /* pass the addresses */
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
