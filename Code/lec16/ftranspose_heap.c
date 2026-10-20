/* Lecture 14's transpose, with the matrix sized from the file */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in_file, *out_file;
    int *in_matrix;      /* m x n ints, row after row */
    int m, n, r, c;

    in_file = fopen("in_matrix.txt", "r");
    if (in_file == NULL)
        return -1;
    if (fscanf(in_file, "%d %d", &m, &n) != 2
        || m < 1 || n < 1) {
        fclose(in_file);
        return -1;
    }
    /* m * n ints, now that m and n are known */
    in_matrix = (int *)malloc(m * n * sizeof(int));
    if (in_matrix == NULL) {
        fclose(in_file);
        return -1;
    }
    /* element (r, c) is in_matrix[r * n + c] */
    for (r = 0; r < m; r++)
        for (c = 0; c < n; c++)
            fscanf(in_file, "%d", &in_matrix[r * n + c]);
    fclose(in_file);

    out_file = fopen("out_matrix.txt", "w");
    if (out_file == NULL) {
        free(in_matrix);
        return -1;
    }
    fprintf(out_file, "%d %d\n", n, m);
    for (c = 0; c < n; c++) {
        for (r = 0; r < m; r++)
            fprintf(out_file, "%d ", in_matrix[r * n + c]);
        fprintf(out_file, "\n");
    }
    fclose(out_file);
    free(in_matrix);
    return 0;
}
