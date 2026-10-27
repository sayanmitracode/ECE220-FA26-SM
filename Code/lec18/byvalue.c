/* add_node given head itself (by value): Jamie's node is lost */
#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Node;
struct studentStruct {
    int   UIN;
    float GPA;
    Node *next;
};

/* add_node with Node *list: it changes only its own copy */
void add_node(Node *list,
              int new_UIN, float new_GPA) {
    Node *new_node;
    /* base case 1: insert new node at 'head' */
    if (list == NULL || list->UIN > new_UIN) {
        new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) return;
        new_node->UIN = new_UIN;
        new_node->GPA = new_GPA;
        new_node->next = list;
        list = new_node;             /* the copy */
        return;
    }
    /* base case 2: UIN already exists */
    if (list->UIN == new_UIN) return;
    /* recursive case: the remaining list */
    add_node(list->next, new_UIN, new_GPA);
}

/* print every node: this one, then the rest of the list */
void print_list(Node *head) {
    if (head == NULL)
        return;
    printf("%d %.2f\n", head->UIN, head->GPA);
    print_list(head->next);
}

/* free every node: the rest of the list first, then this one */
void free_list(Node *head) {
    if (head == NULL)
        return;
    free_list(head->next);
    free(head);
}

int main() {
    /* a one-node list, built in main */
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    if (head == NULL) return 1;
    head->UIN = 246813579;              /* Robin */
    head->GPA = 3.52;
    head->next = NULL;

    /* pass head itself: add_node gets a copy */
    add_node(head, 123456789, 3.89);    /* Jamie */
    print_list(head);

    free_list(head);
    return 0;
}
