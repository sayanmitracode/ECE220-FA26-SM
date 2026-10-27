/* A doubly linked list of student records: insert Casey after Jamie */
#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Node;
struct studentStruct {
    int   UIN;
    float GPA;
    Node *prev;
    Node *next;
};

/* a new node, not yet linked: prev and next are NULL */
Node *make_node(int UIN, float GPA) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) return NULL;
    n->UIN = UIN;
    n->GPA = GPA;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

/* insert node n after node p (p not NULL) */
void insert_after(Node *p, Node *n) {
    n->prev = p;
    n->next = p->next;
    if (p->next != NULL)
        p->next->prev = n;
    p->next = n;
}

/* print from head to tail, following next */
void print_forward(Node *head) {
    for (; head != NULL; head = head->next)
        printf("%d ", head->UIN);
    printf("\n");
}

/* print from tail to head, following prev */
void print_backward(Node *tail) {
    for (; tail != NULL; tail = tail->prev)
        printf("%d ", tail->UIN);
    printf("\n");
}

/* free every node, front to back */
void free_list(Node *head) {
    Node *next;
    for (; head != NULL; head = next) {
        next = head->next;
        free(head);
    }
}

int main() {
    Node *head, *tail, *n;

    head = make_node(123456789, 3.89);              /* Jamie */
    if (head == NULL) return 1;
    tail = make_node(987654321, 3.98);              /* Alex  */
    if (tail == NULL) return 1;
    insert_after(head, tail);
    n = make_node(246813579, 3.52);                 /* Robin */
    if (n == NULL) return 1;
    insert_after(head, n);
    print_forward(head);

    n = make_node(135792468, 3.71);                 /* Casey */
    if (n == NULL) return 1;
    insert_after(head, n);
    print_forward(head);
    print_backward(tail);
    printf("sizeof(Node) = %zu\n", sizeof(Node));

    free_list(head);
    return 0;
}
