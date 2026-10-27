/* A stack of ints on a singly linked list: push and pop at the head */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct node;
struct nodeStruct {
    int   data;
    node *next;
};

node *top;   /* global: the top node, NULL when empty */

/* push a new node onto the stack */
void push(int new_data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {     /* overflow */
        printf("overflow\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = top;
    top = new_node;
}

/* pop the top node; return its data (-1: empty) */
int pop() {
    node *old;
    int value;
    if (top == NULL) {          /* underflow */
        printf("underflow\n");
        return -1;
    }
    old = top;
    value = old->data;
    top = old->next;
    free(old);
    return value;
}

/* print the stack, top first */
void print_stack() {
    node *current;
    printf("top");
    for (current = top; current != NULL; current = current->next)
        printf(" -> %d", current->data);
    printf(" -> NULL\n");
}

int main() {
    top = NULL;
    push(1);
    push(3);
    push(5);
    print_stack();
    printf("pop returns %d\n", pop());
    print_stack();

    while (top != NULL)         /* empty it: frees every node */
        pop();
    pop();
    return 0;
}
