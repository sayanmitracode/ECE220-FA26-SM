/* & takes an address; * follows one */
#include <stdio.h>
int main() {
    int variable = 4;
    int *ptr;             /* declares a pointer to int */
    ptr = &variable;      /* ptr <- address of variable */
    *ptr = *ptr + 1;      /* changes... what? */
    printf("variable = %d\n", variable);
    printf("ptr      = %p\n", (void *)ptr);
    return 0;
}
