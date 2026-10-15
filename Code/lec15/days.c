/* enum: names for a list of related integer constants */
#include <stdio.h>

enum Days {SUN, MON, TUE, WED, THU, FRI, SAT};
/* then try:  enum Days {SUN=1, MON, TUE, ...};  */

int main() {
    enum Days today;
    today = THU;
    printf("today = %d\n", today);
    if (today == SAT || today == SUN)
        printf("weekend\n");
    else
        printf("%d days to SAT\n", SAT - today);
    return 0;
}
