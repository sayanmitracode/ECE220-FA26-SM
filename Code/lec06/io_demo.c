/* Basic I/O practice */
#include <stdio.h>
int main() {
    int len, ht, num;
    printf("%+d\n", 43);          /* forced sign */
    printf("%x\n", 43 + 59);      /* hex output  */
    printf("%.3f\n", 22.0 / 7);   /* 3 decimals  */
    scanf("%d %d", &len, &ht);    /* two values  */
    scanf("%x", &num);            /* hex input!  */
    printf("area=%d num=%d\n", len * ht, num);
    return 0;
}
