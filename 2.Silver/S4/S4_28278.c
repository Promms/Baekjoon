#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int item;
    struct _Node* next;
}Node;

typedef struct _Stack{
    int size;
    Node* head;
}Stack;

Stack makeStack(){
    Stack newStack;
    newStack.head = (Node*)malloc(sizeof(Node));
    newStack.head->next = NULL;
    newStack.size = 0;
    return newStack;
}

bool isEmpty(Stack* stack){
    return stack->size == 0;
}

void push(Stack* stack, int newItem){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = newItem;
    newNode->next = stack->head->next;
    stack->head->next = newNode;
    stack->size++;
}

int pop(Stack* stack){
    if(isEmpty(stack))
        return -1;

    Node* popNode = stack->head->next;
    int popItem = popNode->item;
    stack->head->next = popNode->next;
    stack->size--;
    free(popNode);
    return popItem;
}

int peek(Stack* stack){
    if(isEmpty(stack))
        return -1;
    return stack->head->next->item;
}

int main(){
    int num_inst, inst, value;
    Stack stack = makeStack();

    scanf("%d", &num_inst);
    for(int i = 0; i < num_inst; i++){
        scanf("%d", &inst);
        switch (inst){
            case 1:
                scanf("%d", &value);
                //printf("Insert %d!\n", value);
                push(&stack, value);
                break;
            case 2:
                //printf("Delete %d!\n", pop(&stack));
                printf("%d\n", pop(&stack));
                break;
            case 3:
                //printf("Stack size: %d\n", stack.size);
                printf("%d\n", stack.size);
                break;
            case 4:
                //printf("Stack is empty? (1=true/0=false): %d\n", isEmpty(&stack));
                printf("%d\n", isEmpty(&stack));
                break;
            default:
                printf("%d\n", peek(&stack));
                //printf("Peek %d!\n", peek(&stack));
                break;
        }
    }
    return 0;
}
