/* After free the pointer still holds the address: a dangling pointer */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;

    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL)
        return 1;
    *ptr = 10;
    free(ptr);
    /* ptr dangles: the block is not ours */
    printf("%d\n", *ptr);  /* undefined */
    ptr = NULL;            /* the habit */
    free(ptr);             /* does nothing */
    printf("%d\n", *ptr);  /* seg fault */
    return 0;
}
