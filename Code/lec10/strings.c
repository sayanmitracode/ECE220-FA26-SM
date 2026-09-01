/* Strings: char arrays with a stop sign */
#include <stdio.h>

int my_strlen(char s[]) {       /* in-class */
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

int main() {
    char out[16] = "Result = ";  /* + '\0'  */
    char in[20];
    printf("%s(%d chars)\n", out, my_strlen(out));
    printf("type a word: ");
    scanf("%s", in);             /* no & !  */
    printf("you typed %s\n", in);
    return 0;
}
