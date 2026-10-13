/* Two getchar calls: what does the second one read? */
#include <stdio.h>

int main() {
    char inChar1, inChar2;

    printf("ECE student? (y/n): ");
    inChar1 = getchar();
    printf("Taking ECE 220? (y/n): ");
    inChar2 = getchar();

    printf("\ninChar1 = %d\n", inChar1);
    printf("inChar2 = %d\n", inChar2);
    return 0;
}
