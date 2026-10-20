/* A roster sorted by UIN in an array: a late enrollment shifts records */
#include <stdio.h>

typedef struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
} student;

/* insert s so that ece220[0..n] stays sorted by UIN; */
/* returns how many records had to move */
int insert_sorted(student ece220[], int n,
                  student s) {
    int i = n;
    while (i > 0 && ece220[i - 1].UIN > s.UIN) {
        ece220[i] = ece220[i - 1];  /* move up */
        i--;
    }
    ece220[i] = s;
    return n - i;
}

int main() {
    student ece220[200] = {
        {"Jamie", 123456789, 3.89},
        {"Robin", 246813579, 3.52},
        {"Alex",  987654321, 3.98}};
    student casey = {"Casey", 135792468, 3.71};
    int n = 3, moved, i;

    moved = insert_sorted(ece220, n, casey);
    n++;
    for (i = 0; i < n; i++)
        printf("%s %d %.2f\n", ece220[i].Name,
               ece220[i].UIN, ece220[i].GPA);
    printf("%d records moved, %lu bytes each\n",
           moved, sizeof(student));
    return 0;
}
