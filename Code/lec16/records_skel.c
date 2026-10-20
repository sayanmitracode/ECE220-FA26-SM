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
    /* 100-char block; copy "To be set" in */




    /* UIN -1, GPA 0.0 */



}

/* free n NAME blocks, then the records */
void free_all(student *records, int n) {
    int i;
    /* every NAME block first */



    /* then the records */


}

int main() {
    student *records, *grown;
    int i;

    /* 1. a block of 200 records; NULL check */




    /* 2. initialize all 200 */



    printf("records[199]: %s %d %.1f\n", records[199].NAME,
           records[199].UIN, records[199].GPA);

    /* 3. grow to 400: realloc, NULL check, */
    /*    records = grown, init 200..399    */





    printf("records[399]: %s %d %.1f\n", records[399].NAME,
           records[399].UIN, records[399].GPA);

    /* 4. free everything */


    return 0;
}
