/* Build a list of three student records by hand, then walk it */
#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Node;
struct studentStruct {
    int   UIN;
    float GPA;
    Node *next;
};

/* walk the list from head and print every node */
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d %.2f\n",
               current->UIN, current->GPA);
        current = current->next;
    }
}

int main() {
    Node *head, *n1, *n2, *n3;

    n1 = (Node *)malloc(sizeof(Node)); /* Jamie */
    n2 = (Node *)malloc(sizeof(Node)); /* Robin */
    n3 = (Node *)malloc(sizeof(Node)); /* Alex  */
    if (n1 == NULL || n2 == NULL || n3 == NULL)
        return 1;
    n1->UIN = 123456789;  n1->GPA = 3.89;
    n2->UIN = 246813579;  n2->GPA = 3.52;
    n3->UIN = 987654321;  n3->GPA = 3.98;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    head = n1;

    print_list(head);
    printf("second GPA: %.2f\n", head->next->GPA);

    /* where malloc put the nodes, and what head holds */
    printf("sizeof(Node) = %lu\n", sizeof(Node));
    printf("n1 at %p  next %p\n", (void *)n1, (void *)n1->next);
    printf("n2 at %p  next %p\n", (void *)n2, (void *)n2->next);
    printf("n3 at %p  next %p\n", (void *)n3, (void *)n3->next);
    printf("head at %p holds %p\n", (void *)&head, (void *)head);

    free(n1);
    free(n2);
    free(n3);
    return 0;
}
