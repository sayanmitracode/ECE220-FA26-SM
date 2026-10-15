/* One student record: define the type, fill it, print it */
#include <stdio.h>
#include <string.h>

struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
};

int main() {
    struct StudentStruct s1;
    /* declare and initialize at once */
    struct StudentStruct s2 =
        {"Alex", 987654321, 3.98};

    strncpy(s1.Name, "Jamie", sizeof(s1.Name));
    s1.UIN = 123456789;
    s1.GPA = 3.89;

    printf("%s %d %.2f\n", s1.Name, s1.UIN, s1.GPA);
    printf("%s %d %.2f\n", s2.Name, s2.UIN, s2.GPA);
    return 0;
}
