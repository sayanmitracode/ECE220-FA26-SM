/* addhead.c with the addresses printed: where head, list and the nodes live */
#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Node;
struct studentStruct {
    int   UIN;
    float GPA;
    Node *next;
};

/* add_node from addhead.c, printing list and new_node */
void add_node(Node **list,
              int new_UIN, float new_GPA) {
    Node *new_node;
    printf("  add_node: list at %p holds %p\n",
           (void *)&list, (void *)list);
    printf("  new_UIN at %p, new_GPA at %p\n",
           (void *)&new_UIN, (void *)&new_GPA);
    if (*list == NULL || (*list)->UIN > new_UIN) {
        new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) return;
        new_node->UIN = new_UIN;
        new_node->GPA = new_GPA;
        new_node->next = *list;
        *list = new_node;
        printf("  new_node at %p holds %p\n",
               (void *)&new_node, (void *)new_node);
        return;
    }
    if ((*list)->UIN == new_UIN) return;
    add_node(&(*list)->next, new_UIN, new_GPA);
}

/* free every node: the rest of the list first, then this one */
void free_list(Node *head) {
    if (head == NULL)
        return;
    free_list(head->next);
    free(head);
}

int main() {
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    if (head == NULL) return 1;
    head->UIN = 246813579;              /* Robin */
    head->GPA = 3.52;
    head->next = NULL;
    printf("head at %p holds %p (Robin)\n", (void *)&head, (void *)head);

    add_node(&head, 123456789, 3.89);   /* Jamie */
    printf("head at %p holds %p (Jamie)\n", (void *)&head, (void *)head);
    printf("Jamie's next field is at %p\n", (void *)&head->next);

    add_node(&head, 135792468, 3.71);   /* Casey */
    printf("Jamie's next holds %p (Casey)\n", (void *)head->next);

    free_list(head);
    return 0;
}
