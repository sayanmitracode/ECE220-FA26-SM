/* malloc leaves the bytes as they were; calloc sets them to zero */
#include <stdio.h>
#include <stdlib.h>
#define N 50000

int main() {
    int *a, *b, i;

    a = (int *)malloc(N * sizeof(int));
    if (a == NULL)
        return 1;
    for (i = 0; i < N; i++)
        a[i] = 7;
    free(a);   /* the block goes back */

    a = (int *)malloc(N * sizeof(int));
    b = (int *)calloc(N, sizeof(int));
    if (a == NULL || b == NULL)
        return 1;
    printf("malloc: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\ncalloc: ");
    for (i = 0; i < 5; i++)
        printf("%d ", b[i]);
    printf("\n");
    free(a);
    free(b);
    return 0;
}
