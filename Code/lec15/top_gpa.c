/* Find the record with the highest GPA, through a pointer */
#include <stdio.h>

typedef struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
} student;

/* returns the address of the best record */
student *top_gpa(student *s_ptr, int n) {
    student *best = s_ptr;
    int i;
    for (i = 1; i < n; i++) {
        s_ptr++;
        if (s_ptr->GPA > best->GPA)
            best = s_ptr;
    }
    return best;
}

int main() {
    student ece220[200];
    student *top;
    int n = 0;
    FILE *fp = fopen("roster.txt", "r");
    if (fp == NULL) {
        printf("cannot open roster.txt\n");
        return 1;
    }
    while (n < 200 && fscanf(fp, "%s %d %f",
               ece220[n].Name, &ece220[n].UIN,
               &ece220[n].GPA) == 3)
        n++;
    fclose(fp);

    top = top_gpa(ece220, n);
    printf("%d records\n", n);
    printf("%s %d %.2f\n",
           top->Name, top->UIN, top->GPA);
    return 0;
}
