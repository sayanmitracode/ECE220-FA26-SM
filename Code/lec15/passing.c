/* Pass a struct by value, then by reference */
#include <stdio.h>

typedef struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
} student;

void printname(student s) {
    printf("%s, %lu bytes passed\n",
           s.Name, sizeof(s));
}

void PRINTNAME(student *s) {
    printf("%s, %lu bytes passed\n",
           s->Name, sizeof(s));
}

int main() {
    student s1 = {"Jamie", 123456789, 3.89};
    printname(s1);
    PRINTNAME(&s1);
    return 0;
}
