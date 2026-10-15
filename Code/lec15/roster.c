/* The same roster as an array of structs */
#include <stdio.h>

typedef struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
} student;

int main() {
    student ece220[200] = {
        {"Jamie", 123456789, 3.89},
        {"Alex",  987654321, 3.98},
        {"Robin", 246813579, 3.52}};
    student t;
    int i;

    /* exchange students 0 and 1 */
    t = ece220[0];
    ece220[0] = ece220[1];
    ece220[1] = t;

    for (i = 0; i < 3; i++)
        printf("%s %d %.2f\n", ece220[i].Name,
               ece220[i].UIN, ece220[i].GPA);
    return 0;
}
