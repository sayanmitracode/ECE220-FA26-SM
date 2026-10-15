/* Pointer to a struct: ->, and what ++ does to it */
#include <stdio.h>
#include <string.h>

typedef struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
} student;

int main() {
    student ece220[200];
    student s1;
    student *s_ptr, *s_ptr2;
    s_ptr = ece220;  /* to a struct array */
    s_ptr2 = &s1;    /* to a struct */

    strncpy(s_ptr->Name, "Jamie",
            sizeof(s1.Name));
    s_ptr->UIN = 123456789;
    s_ptr->GPA = 3.89;

    s_ptr++;

    strncpy(s_ptr2->Name, "Alex",
            sizeof(s1.Name));
    (*s_ptr2).UIN = 987654321;  /* same as -> */
    s_ptr2->GPA = 3.98;

    printf("ece220[0]: %s\n", ece220[0].Name);
    printf("s1:        %s\n", s1.Name);
    printf("s_ptr is at ece220[%ld]\n",
           s_ptr - ece220);
    printf("it moved %ld bytes\n",
           (char *)s_ptr - (char *)ece220);
    return 0;
}
