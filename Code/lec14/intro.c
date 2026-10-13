/* Write a self-introduction to intro.txt */
#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];

    file = fopen("intro.txt", "w");
    if (file == NULL) {
        printf("Cannot open intro.txt\n");
        return -1;
    }
    printf("Introduce yourself: ");
    fgets(buffer, 100, stdin);    /* keyboard */

    fputs("Your self introduction: ", file);
    fputs(buffer, file);          /* file     */
    fclose(file);

    fputs(buffer, stdout);        /* monitor  */
    return 0;
}
