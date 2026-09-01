/* Follow-ups: sized, validated, early-stopping matrix */
#include <stdio.h>
int main() {
    int n, i, j, stop = 0;
    do {                          /* validate 0 < n < 10 */
        printf("Enter n (1-9): ");
        scanf("%d", &n);
        if (n <= 0 || n >= 10)
            printf("Number entered is invalid\n");
    } while (n <= 0 || n >= 10);

    for (i = 0; i < n && !stop; i++) {
        for (j = 0; j < n && !stop; j++) {
            if (i == j) printf("1 ");
            else        printf("0 ");
            if (i == j && i == 2)
                stop = 1;   /* break exits ONE loop only */
        }
        printf("\n");
    }
    return 0;
}
