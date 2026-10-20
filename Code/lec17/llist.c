/* A list of student records sorted by UIN: find, add, remove */
#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Node;
struct studentStruct {
    int   UIN;
    float GPA;
    Node *next;
};

/* print every node: this one, then the rest of the list */
void print_list(Node *head) {
    if (head == NULL)
        return;
    printf("%d %.2f\n",
           head->UIN, head->GPA);
    print_list(head->next);
}

/* return the node whose UIN is S_UIN, or NULL if there is none */
Node *find_node(Node *head, int S_UIN) {
    /* base case 1: list end, or past S_UIN */
    if (head == NULL || head->UIN > S_UIN) {
        printf("record not found\n");
        return NULL;
    }
    /* base case 2: this node matches S_UIN */
    if (head->UIN == S_UIN) {
        printf("record found\n");
        return head;
    }
    /* recursive case: the remaining list */
    return find_node(head->next, S_UIN);
}

/* add a new node to the sorted list at the correct location */
void add_node(Node **list,
              int new_UIN, float new_GPA) {
    Node *new_node;
    /* base case 1: insert new node at 'head' */
    if (*list == NULL || (*list)->UIN > new_UIN) {
        new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) return;
        new_node->UIN = new_UIN;
        new_node->GPA = new_GPA;
        new_node->next = *list;
        *list = new_node;
        return;
    }
    /* base case 2: UIN already exists */
    if ((*list)->UIN == new_UIN) return;
    /* recursive case: the remaining list */
    add_node(&(*list)->next, new_UIN, new_GPA);
}

/* remove the node whose UIN is old_UIN from the sorted list */
void remove_node(Node **list, int old_UIN) {
    Node *old;
    /* base case 1: list end, or past old_UIN */
    if (*list == NULL || (*list)->UIN > old_UIN) {
        printf("record not found\n");
        return;
    }
    /* base case 2: found: unlink and free it */
    if ((*list)->UIN == old_UIN) {
        old = *list;
        *list = old->next;
        free(old);
        return;
    }
    /* recursive case: the remaining list */
    remove_node(&(*list)->next, old_UIN);
}

/* free every node: the rest of the list first, then this one */
void free_list(Node *head) {
    if (head == NULL)
        return;
    free_list(head->next);
    free(head);
}

int main() {
    Node *head = NULL;
    Node *p;

    add_node(&head, 987654321, 3.98);   /* Alex  */
    add_node(&head, 123456789, 3.89);   /* Jamie */
    add_node(&head, 246813579, 3.52);   /* Robin */
    print_list(head);

    p = find_node(head, 246813579);
    if (p != NULL)
        printf("GPA %.2f\n", p->GPA);
    p = find_node(head, 200000000);

    add_node(&head, 135792468, 3.71);   /* Casey */
    print_list(head);

    remove_node(&head, 246813579);      /* Robin */
    remove_node(&head, 246813579);      /* again */
    print_list(head);

    free_list(head);
    return 0;
}
