/* One program, every feature we need today */
#include <stdio.h>
#define TABLE 30         /* slices needed */

int total = 0;           /* global */

int main() {
    int  pizzas = 3;     /* locals live */
    int  each = 8;       /* on the stack */
    char room = 'A';
    int  mine, enough;

    mine = pizzas * each + pizzas % 2;
    {
        int pizzas = 2;  /* TAs: two more */
        total = total + pizzas * each;
    }
    total = total + mine;
    enough = (total > TABLE);  /* 0 or 1 */
    printf("%c%d: %d\n", room, enough, total);
    return 0;
}
