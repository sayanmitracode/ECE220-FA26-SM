/* Reverse an integer array in place */
#include <stdio.h>

void array_reversal(int array[], int n) {
    int i, temp;
    for (i = 0; i < n / 2; i++) {
        temp = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = temp;
    }
}

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6}, i;
    array_reversal(a, 6);
    for (i = 0; i < 6; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
