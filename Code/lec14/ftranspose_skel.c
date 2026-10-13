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




    /* read the m x n elements, row by row */




    /* close in_matrix.txt */


    /* open out_matrix.txt for writing */
    out_file = fopen("out_matrix.txt", "w");
    if (out_file == NULL)
        return -1;
    /* write the dimensions of the transpose */


    /* write the elements of the transpose */




    /* close out_matrix.txt */


    return 0;
}
