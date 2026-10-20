/* realloc: a bigger block, maybe somewhere else, same contents */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *ptr2, *ptr3;

    ptr2 = (char *)calloc(100, sizeof(char));
    if (ptr2 == NULL)
        return 1;
    strncpy(ptr2, "Example using calloc", 100);
    printf("%s, at %p\n", ptr2, (void *)ptr2);

    ptr3 = (char *)realloc(ptr2, 200 * sizeof(char));
    if (ptr3 == NULL) {
        free(ptr2);
        return 1;
    }
    printf("%s, at %p\n", ptr3, (void *)ptr3);
    free(ptr3);
    return 0;
}
