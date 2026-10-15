/* Struct within a struct: reach a member two levels down */
#include <stdio.h>
#include <string.h>

typedef struct StudentName {
    char First[32];
    char Middle[32];
    char Last[36];
} name;

typedef struct StudentStruct {
    name  Name;
    int   UIN;
    float GPA;
} student;

int main() {
    student ece220[200];
    student *ptr;
    ptr = ece220;

    /* set First in the first record, through ptr */
    strncpy(ptr->Name.First, "Jamie",
            sizeof(ptr->Name.First));

    printf("%s\n", ece220[0].Name.First);
    printf("sizeof(name)    = %lu\n", sizeof(name));
    printf("sizeof(student) = %lu\n", sizeof(student));
    return 0;
}
