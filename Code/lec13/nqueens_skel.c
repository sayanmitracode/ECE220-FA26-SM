/* n-queens on an N x N board: recursion with backtracking */
#include <stdio.h>
#define N 4

/* Is board[row][col] safe from the queens  */
/* in rows 0 .. row-1?  1 = safe, 0 = not.  */
int isSafe(int board[N][N], int row, int col) {
    int i, j;
    /* every square (i, j) in the rows above */
        for (i=0; i<row; i++)
            for (j=0;j<N;j++)
                {
                    if (board[i][j]==1 &&
                        (j==col || 
                            i - j == row-col ||
                            i + j == row + col
                        )
                    )
                    return 0;
                }
        return 1;
}

/* Place queens in rows row .. N-1.         */
/* 1 = solved, 0 = no placement works.      */
int nqueen(int board[N][N], int row) {
    int c;
    /* base case: no more rows to fill */
    if (row == N)
        return 1;
    for (c=0; c < N; c++ ){
    /* try each column c, left to right */
        if (isSafe(board, row, c)==1){

        /* (row, c) safe? place a queen */

            board[row][c] = 1;  /* guess */
            if (nqueen(board, row+1)==1)
                return 1;
        /* rows below solved? return 1 */
            
        /* backtrack: remove the queen */
            board[row][c] = 0;
        }
    }
    /* every column failed */
    return 0;

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
    
    board[1][1] = 1;        
    printf("Safe to place in (0,0): %d \n", isSafe(board, 0,0));
    printf("Safe to place in (1,0): %d \n", isSafe(board, 1,0));
    printf("Safe to place in (0,1): %d \n", isSafe(board, 0,1));
    printf("Safe to place in (2,3): %d \n", isSafe(board, 2,3));
    
    if (nqueen(board, 0) == 1) /* from row 0  */
        printboard(board);
    else
        printf("No solution for N = %d\n", N);
    return 0;
}
