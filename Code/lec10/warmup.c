/* Warm-up traces: bounds and duality.
 * NOTE: running this may print the answer and then
 * ABORT ("stack smashing detected") -- that abort IS
 * the lesson: trace 1 writes past the end of array. */
#include <stdio.h>
int main() {
    /* --- trace 1: what gets modified? ------ */
    int array[2] = {3, 5};
    int *ptr = array;
    int i;
    for (i = 0; i < 2; i++, ptr++)
        *(ptr + 1) = *ptr + 1;
    /* --- trace 2: final contents? ---------- */
    int buffer[4] = {1, 3, 5, 7};
    int *p = buffer;
    *(buffer + 1) = 9;
    p[3] = 11;
    for (i = 0; i < 4; i++)
        printf("%d ", buffer[i]);
    printf("\n");
    return 0;
}
