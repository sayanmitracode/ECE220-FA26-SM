/* Arrays: declare, initialize, index from 0 */
#include <stdio.h>

int average(int array[], int size) {  /* == int *array */
    int i, sum = 0;
    for (i = 0; i < size; i++)
        sum = sum + array[i];
    return sum / size;
}

int main() {
    int grid[5] = {10, 11, 12, 13, 14};
    int i;
    grid[4] = grid[1] + 1;
    for (i = 0; i < 2; i++)
        grid[i+1] = grid[i] + 2;
    for (i = 0; i < 5; i++)
        printf("%d ", grid[i]);
    printf("\navg = %d\n", average(grid, 5));
    return 0;
}
