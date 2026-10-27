/* Skeleton: a queue of ints on a singly linked list: enqueue at the rear, dequeue at the front */
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
    /* fill new_node: it will be the last node */



    /* link it after the rear node, or as front */




    /* it is the new rear */


}

/* remove the front node; return its data (-1: empty) */
int dequeue() {
    node *old;
    int value;
    if (front == NULL) return -1;   /* empty */
    /* unlink the front node */



    /* the queue may now be empty: fix rear */


    /* free the node; return its data */



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
