/* The same block freed twice: the allocator stops the program */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *ptr_2;

    ptr = (int *)malloc(sizeof(int));
    *ptr = 5;
    ptr_2 = (int *)malloc(sizeof(int));
    *ptr_2 = 6;
    ptr = ptr_2;
    free(ptr);
    free(ptr_2);     /* same address as ptr */
    return 0;
}
