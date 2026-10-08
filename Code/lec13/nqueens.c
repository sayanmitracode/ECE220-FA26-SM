/* n-queens on an N x N board: recursion with backtracking */
#include <stdio.h>
#define N 4

/* Is board[row][col] safe from the queens  */
/* in rows 0 .. row-1?  1 = safe, 0 = not.  */
int isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++)    /* rows above */
        for (j = 0; j < N; j++)
            if (board[i][j] == 1 &&    /* queen */
                (j == col ||           /* col   */
                 i - j == row - col || /* diag  */
                 i + j == row + col))  /* diag  */
                return 0;
    return 1;
}

/* Place queens in rows row .. N-1.         */
/* 1 = solved, 0 = no placement works.      */
int nqueen(int board[N][N], int row) {
    int c;
    if (row == N)              /* no rows left */
        return 1;
    for (c = 0; c < N; c++) {  /* each column  */
        if (isSafe(board, row, c) == 1) {
            board[row][c] = 1; /* place queen  */
            if (nqueen(board, row + 1) == 1)
                return 1;
            board[row][c] = 0; /* remove it    */
        }
    }
    return 0;                  /* none worked  */
}

void printboard(int board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf(" %d", board[i][j]);
        printf("\n");
    }
}

int main() {
    int board[N][N], i, j;
    for (i = 0; i < N; i++)    /* empty board */
        for (j = 0; j < N; j++)
            board[i][j] = 0;
    if (nqueen(board, 0) == 1) /* from row 0  */
        printboard(board);
    else
        printf("No solution for N = %d\n", N);
    return 0;
}
