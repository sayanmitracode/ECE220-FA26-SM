/* Copy this source file, line by line, to filecopy_out.c */
#include <stdio.h>

int main() {
    FILE *in_file, *out_file;
    char str[32];

    in_file = fopen("filecopy.c", "r");
    if (in_file == NULL) {
        printf("Unable to open filecopy.c\n");
        return -1;
    }
    out_file = fopen("filecopy_out.c", "w");
    if (out_file == NULL) {
        printf("Unable to open filecopy_out.c\n");
        fclose(in_file);
        return -1;
    }
    fprintf(out_file, "/* a copy of filecopy.c */\n");
    while (fgets(str, 32, in_file) != NULL)
        fputs(str, out_file);

    fclose(in_file);
    fclose(out_file);
    return 0;
}
