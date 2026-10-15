/* union: all members share the same memory */
#include <stdio.h>

typedef union StudentUnion {
    char  Name[100];
    int   UIN;
    float GPA;
} studentU;

int main() {
    studentU su1;
    printf("sizeof(studentU) = %lu\n",
           sizeof(studentU));

    su1.UIN = 123456789;
    printf("UIN = %d\n", su1.UIN);

    su1.GPA = 3.89;
    printf("UIN = %d\n", su1.UIN);
    printf("GPA = %f\n", su1.GPA);
    return 0;
}
