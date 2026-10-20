/* Two blocks, one pointer left: the first block is lost */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *ptr_2;

    ptr = (int *)malloc(sizeof(int));
    *ptr = 5;
    ptr_2 = (int *)malloc(sizeof(int));
    *ptr_2 = 6;
    ptr = ptr_2;
    printf("*ptr = %d, *ptr_2 = %d\n", *ptr, *ptr_2);
    free(ptr_2);
    return 0;
}
