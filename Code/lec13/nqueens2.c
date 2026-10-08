/* n-queens on an N x N board: recursion with backtracking */
#include <stdio.h>
#define N 12

/* Is board[row][col] safe from the queens  */
/* in rows 0 .. row-1?  1 = safe, 0 = not.  */
int isSafe(int board[N][N], int r, int c) {
    int i, j;
    for (i = 0; i< N; i++) /* all rows*/
        if (board[i][c] == 1) /* queen in same column as c */
            return 0;

    for (j = 0; j< N; j++) /* all cols */
        if (board[r][j] == 1) /* queen in same row as r */
            return 0;        

    for (i = 0; i< N; i++) /* all row */
        for (j = 0; j< N; j++) /* all col */
            if (board[i][j] == 1 && /* queen at (i, j) */
                (i - j == r - c ||   /* diag 1 */
                 i + j == r + c))    /* diag 2 */
                return 0;
    return 1;
}

/* Place queens in rows row .. N-1.         */
/* 1 = solved, 0 = no placement works.      */
int nqueen(int board[N][N], int row) {
    int c;
    /* base case: no more rows to fill */
    if (row == N)              /* no rows left */
        return 1;
    for (c=0;c<N;c++) { /* try (row, c) */
        if (isSafe(board, row,c) ==1) {
            board[row][c] = 1; /* place queen (guess)*/
            if (nqueen(board, row+1)==1)
                return 1;
            board[row][c] = 0; /* remove row,c */
        }

    }    
    return 0;

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
    // board[0][0] = 1; /* place a queen in row 0, col 0 */
    printboard(board);
    printf("Can we place queens in (0, 0): %d \n", isSafe(board, 0, 0));
    printf("Can we place queens in (0, 1): %d \n", isSafe(board, 0, 1));
    printf("Can we place queens in (2, 0): %d \n", isSafe(board, 2, 0));
    printf("Can we place queens in (2, 2): %d \n", isSafe(board, 2, 2));
    printf("Can we place queens in (2, 1): %d \n", isSafe(board, 2, 1));


    if (nqueen(board, 0) == 1) /* from row 0  */
        printboard(board);
    else
        printf("No solution for N = %d\n", N);
    return 0;
}
