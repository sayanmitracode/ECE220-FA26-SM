/* Exchange two rows of an M x N matrix */
#include <stdio.h>
#define M 3
#define N 4

void row_exchange(int matrix[M][N], int row_x, int row_y) {
    /* declare a column counter and a temporary */

    /* walk the columns; swap the two rows' cells */

}

int main() {
    int m[M][N] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int i, j;
    row_exchange(m, 0, 2);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            printf("%3d", m[i][j]);
        printf("\n");
    }
    return 0;
}
