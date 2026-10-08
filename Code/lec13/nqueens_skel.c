/* n-queens on an N x N board: recursion with backtracking */
#include <stdio.h>
#define N 4

/* Is board[row][col] safe from the queens  */
/* in rows 0 .. row-1?  1 = safe, 0 = not.  */
int isSafe(int board[N][N], int row, int col) {
    int i, j;
    /* every square (i, j) in the rows above */



        /* queen at (i, j) attacks (row, col)? */




    /* no queen attacks (row, col) */


}

/* Place queens in rows row .. N-1.         */
/* 1 = solved, 0 = no placement works.      */
int nqueen(int board[N][N], int row) {
    int c;
    /* base case: no more rows to fill */



    /* try each column c, left to right */


        /* (row, c) safe? place a queen */



        /* rows below solved? return 1 */



        /* backtrack: remove the queen */



    /* every column failed */


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
