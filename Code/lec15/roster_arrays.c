/* A class roster in three parallel arrays */
#include <stdio.h>
#define N 3

int main() {
    char  Name[N][100] = {"Jamie", "Alex", "Robin"};
    int   UIN[N] = {123456789, 987654321, 246813579};
    float GPA[N] = {3.89, 3.98, 3.52};
    int   i, t;

    /* exchange students 0 and 1 */
    t = UIN[0];
    UIN[0] = UIN[1];
    UIN[1] = t;

    for (i = 0; i < N; i++)
        printf("%s %d %.2f\n",
               Name[i], UIN[i], GPA[i]);
    return 0;
}
