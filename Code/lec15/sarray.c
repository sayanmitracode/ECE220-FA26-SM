/* An array of structs: one element, then one member */
#include <stdio.h>

typedef struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
} student;

int main() {
    student ece220[200];

    ece220[0].Name[0] = 'J';
    ece220[0].Name[1] = 'a';
    ece220[0].Name[2] = 'm';
    ece220[0].Name[3] = 'i';
    ece220[0].Name[4] = 'e';
    ece220[0].Name[5] = '\0';
    ece220[0].UIN = 123456789;
    ece220[0].GPA = 3.89;

    printf("%s %d %.2f\n", ece220[0].Name,
           ece220[0].UIN, ece220[0].GPA);
    printf("ece220[0] to ece220[1]: %ld bytes\n",
           (char *)&ece220[1] - (char *)&ece220[0]);
    return 0;
}
