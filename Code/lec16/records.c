/* 200 student records on the heap: allocate, grow to 400, free all */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentStruct {
    char  *NAME;
    int    UIN;
    float  GPA;
} student;

/* NAME gets a 100-char block; set all 3 members */
void init_record(student *s) {
    s->NAME = (char *)malloc(100 * sizeof(char));
    if (s->NAME != NULL)
        strncpy(s->NAME, "To be set", 100);
    s->UIN = -1;
    s->GPA = 0.0;
}

/* free n NAME blocks, then the records */
void free_all(student *records, int n) {
    int i;
    for (i = 0; i < n; i++)
        free(records[i].NAME);
    free(records);
}

int main() {
    student *records, *grown;
    int i;

    /* 1. a block of 200 records */
    records = (student *)malloc(200 * sizeof(student));
    if (records == NULL)
        return 1;
    /* 2. initialize all 200 */
    for (i = 0; i < 200; i++)
        init_record(&records[i]);
    printf("records[199]: %s %d %.1f\n", records[199].NAME,
           records[199].UIN, records[199].GPA);

    /* 3. grow to 400; initialize 200..399 */
    grown = (student *)realloc(records,
                       400 * sizeof(student));
    if (grown == NULL) {
        free_all(records, 200);
        return 1;
    }
    if (grown != records)
        printf("the block moved\n");
    records = grown;
    for (i = 200; i < 400; i++)
        init_record(&records[i]);
    printf("records[399]: %s %d %.1f\n", records[399].NAME,
           records[399].UIN, records[399].GPA);

    /* 4. free everything */
    free_all(records, 400);
    return 0;
}
