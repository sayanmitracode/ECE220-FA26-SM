/* Fahrenheit to Celsius: C = (F-32)*5/9 */
#include <stdio.h>

int main() {
    float fahr, celsius;
    printf("Enter temperature (F): ");
    scanf("%f", &fahr);   /* note the & ! */
    celsius = (fahr - 32) * 5 / 9;
    printf("%.1f F = %.1f C\n", fahr, celsius);
    return 0;
}
