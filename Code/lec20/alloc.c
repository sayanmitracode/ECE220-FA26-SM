/* Dynamic allocation in C: malloc and free (Lecture 16) */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p, *q, i;
    p = (int *)malloc(sizeof(int));         /* one int */
    q = (int *)malloc(10 * sizeof(int));    /* array of 10 */
    *p = 220;
    for (i = 0; i < 10; i++)
        q[i] = i * i;
    printf("%d %d\n", *p, q[9]);
    free(p);
    free(q);
    return 0;
}
