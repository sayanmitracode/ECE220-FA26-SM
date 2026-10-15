/* Where the members sit, and what a struct costs in bytes */
#include <stdio.h>
#include <stddef.h>     /* offsetof */

typedef struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
} student;

typedef struct {        /* one more char */
    char  Name[101];
    int   UIN;
    float GPA;
} student101;

int main() {
    student ece220[200];

    printf("char %lu int %lu float %lu\n",
        sizeof(char), sizeof(int), sizeof(float));
    printf("Name +%lu\n", offsetof(student, Name));
    printf("UIN  +%lu\n", offsetof(student, UIN));
    printf("GPA  +%lu\n", offsetof(student, GPA));
    printf("student    %lu\n",
           sizeof(student));
    printf("ece220     %lu\n",
           sizeof(ece220));

    printf("UIN  +%lu\n", offsetof(student101, UIN));
    printf("GPA  +%lu\n", offsetof(student101, GPA));
    printf("student101 %lu\n",
           sizeof(student101));
    return 0;
}
