/* Read an m x n matrix from a file; write its transpose */
#include <stdio.h>
#define MAX 10    /* largest m or n accepted */

int main() {
    FILE *in_file, *out_file;
    int in_matrix[MAX][MAX];
    int m, n, r, c;

    /* open in_matrix.txt for reading */
    in_file = fopen("in_matrix.txt", "r");
    if (in_file == NULL)
        return -1;
    /* read m and n; check that they fit */
    if (fscanf(in_file, "%d %d", &m, &n) != 2
        || m < 1 || m > MAX || n < 1 || n > MAX) {
        fclose(in_file);
        return -1;
    }
    /* read the m x n elements, row by row */
    for (r = 0; r < m; r++)
        for (c = 0; c < n; c++)
            fscanf(in_file, "%d", &in_matrix[r][c]);
    /* close in_matrix.txt */
    fclose(in_file);

    /* open out_matrix.txt for writing */
    out_file = fopen("out_matrix.txt", "w");
    if (out_file == NULL)
        return -1;
    /* write the dimensions of the transpose */
    fprintf(out_file, "%d %d\n", n, m);
    /* write the elements of the transpose */
    for (c = 0; c < n; c++) {
        for (r = 0; r < m; r++)
            fprintf(out_file, "%d ", in_matrix[r][c]);
        fprintf(out_file, "\n");
    }
    /* close out_matrix.txt */
    fclose(out_file);
    return 0;
}
