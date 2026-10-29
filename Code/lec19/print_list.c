/* print_list: print a linked list of chars, recursively (the list is laid out as in data.asm) */
#include <stdio.h>

typedef struct nodeStruct node;
struct nodeStruct {
    char data;
    node *next;
};

void print_list(node *head) {
    if (head == NULL)
        return;
    printf("%c", head->data);
    print_list(head->next);
}

/* four nodes, in the order they sit in memory (data.asm, from x4000) */
node nodes[4] = { {'E', &nodes[3]}, {'C', &nodes[0]},
                  {'E', &nodes[1]}, {'B', NULL} };

int main() {
    node *head = &nodes[2];
    print_list(head);
    printf("\n");
    return 0;
}
