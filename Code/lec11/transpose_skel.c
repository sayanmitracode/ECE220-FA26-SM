/* Transpose an M x N matrix stored flat (1-D) */
#include <stdio.h>
#define M 3   /* rows of input    */
#define N 4   /* columns of input */

void transpose(int *in_matrix, int *out_matrix) {
    /* loop over rows and columns of the input;   */
    /* in[i][j] lives at flat offset i*N + j --   */
    /* where does it go in the N x M output?      */

}

int main() {
    int in[M * N] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int out[N * M], i, j;
    transpose(in, out);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            printf("%3d", out[i * M + j]);
        printf("\n");
    }
    return 0;
}
