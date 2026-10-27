/* A queue of ints on a singly linked list: enqueue at the rear, dequeue at the front */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct node;
struct nodeStruct {
    int   data;
    node *next;
};

node *front;   /* global: the first node, NULL when empty */
node *rear;    /* global: the last node, NULL when empty */

/* add a new node at the rear */
void enqueue(int new_data) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) return;   /* full */
    new_node->data = new_data;
    new_node->next = NULL;
    if (rear == NULL)               /* was empty */
        front = new_node;
    else
        rear->next = new_node;
    rear = new_node;
}

/* remove the front node; return its data (-1: empty) */
int dequeue() {
    node *old;
    int value;
    if (front == NULL) return -1;   /* empty */
    old = front;
    value = old->data;
    front = old->next;
    if (front == NULL)              /* now empty */
        rear = NULL;
    free(old);
    return value;
}

/* print the queue, front first */
void print_queue() {
    node *current;
    printf("front");
    for (current = front; current != NULL; current = current->next)
        printf(" -> %d", current->data);
    printf(" -> NULL\n");
}

int main() {
    front = NULL;
    rear = NULL;
    enqueue(1);
    enqueue(3);
    enqueue(5);
    print_queue();
    printf("dequeue returns %d\n", dequeue());
    enqueue(7);
    print_queue();

    while (front != NULL)           /* empty it: frees every node */
        dequeue();
    printf("rear is %s\n", rear == NULL ? "NULL" : "not NULL");
    return 0;
}
