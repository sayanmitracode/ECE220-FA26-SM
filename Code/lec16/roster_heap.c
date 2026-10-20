/* Two rosters read by one function that returns a heap block: it works */
#include <stdio.h>
#include <stdlib.h>

typedef struct StudentStruct {
    char  Name[100];
    int   UIN;
    float GPA;
} student;

/* reads a roster file; line 1 holds the count n */
student *read_roster(char *filename, int *n) {
    student *roster;
    FILE *fp = fopen(filename, "r");
    int i;
    if (fp == NULL)
        return NULL;
    fscanf(fp, "%d", n);
    /* a block of *n students; NULL if none */
    roster = (student *)malloc(*n * sizeof(student));
    if (roster == NULL) {
        fclose(fp);
        return NULL;
    }
    for (i = 0; i < *n; i++)
        fscanf(fp, "%s %d %f", roster[i].Name,
               &roster[i].UIN, &roster[i].GPA);
    fclose(fp);
    return roster;   /* heap address: valid */
}

void print_roster(char *title, student *r, int n) {
    int i;
    printf("%s: %d students\n", title, n);
    for (i = 0; i < n; i++)
        printf("  %s %d %.2f\n", r[i].Name,
               r[i].UIN, r[i].GPA);
}

int main() {
    student *sec_a, *sec_b;
    int n_a, n_b;
    sec_a = read_roster("roster.txt", &n_a);
    sec_b = read_roster("roster_b.txt", &n_b);
    if (sec_a == NULL || sec_b == NULL)
        return 1;
    print_roster("Section A", sec_a, n_a);
    print_roster("Section B", sec_b, n_b);
    /* main is done with both blocks */
    free(sec_a);
    free(sec_b);
    return 0;
}
