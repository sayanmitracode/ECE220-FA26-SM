#include <stdio.h>
#include <stdlib.h>

typedef struct Nodestruct Node;
struct Nodestruct{
    int item;
    Node* next;
};

Node* top; // top of stack


int push(int a){
    Node * new;
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL){
        printf("\n Overflow");
        return -1; // overflow
    }
    new->item = a;
    new->next = top;
    top = new;
    return 1;
}

int pop(){
    int val;
    Node * temp;
    if (top==NULL){
        printf("Underflow\n");
        return -1;
    }
    val = top->item;
    temp = top;
    top = top->next;
    free(temp);
    return val;
}

void print_stack(Node * top)
{
    if (top==NULL)
        return;
    printf("%d\n",top->item);
    print_stack(top->next);
}

int main(){
    push(5);
    push(3);
    push(2);
    print_stack(top);
    printf("pop %d\n", pop());
    printf("pop %d\n", pop());
    printf("pop %d\n", pop());
    printf("pop %d\n", pop());

    print_stack(top);

}