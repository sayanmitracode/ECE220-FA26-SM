/* Bit gymnastics: shifts and bitwise OR */
#include <stdio.h>

int main() {
    int x, y, z;          /* declare      */
    x = 3;
    y = x * x;            /* y = 9        */
    y = y << x;           /* y = 72       */
    z = x | y;            /* z = 75       */
    printf("z = %d\n", z);
    return 0;
}
