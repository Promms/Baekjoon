#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    newStack.head = (Node*)malloc(sizeof(Node*));
    newStack.size = 0;
    newStack.head->next = NULL;
    return newStack;
}

bool isEmpty(Stack* stack){
    return stack->head->next == NULL;
}

void push(Stack* stack, int item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = stack->head->next;
    stack->head->next = newNode;
    stack->size++;
}

int pop(Stack* stack){
    if(isEmpty(stack)) return -1;
    Node* popNode = stack->head->next;
    int popItem = popNode->item;
    stack->head->next = popNode->next;
    stack->size--;
    free(popNode);
    return popItem;
}

int peek(Stack* stack){
    if(isEmpty(stack)) return -1;
    return stack->head->next->item;
}

void removeStack(Stack* stack){
    while(!isEmpty(stack))
        pop(stack);
    free(stack->head);
}

int main(){
    Stack stack = makeStack();
    char inst[10];
    int num, input;
    scanf("%d", &num);

    for(int i = 0; i < num; i ++){
        scanf("%s", inst);
        if(strcmp(inst,"push") == 0){
            scanf("%d", &input);
            push(&stack, input);
        }else if(strcmp(inst, "pop") == 0){
            printf("%d\n", pop(&stack));
        }else if(strcmp(inst, "size") == 0){
            printf("%d\n", stack.size);
        }else if(strcmp(inst, "empty") == 0){
            printf("%d\n", isEmpty(&stack));
        }else if(strcmp(inst, "top") == 0){
            printf("%d\n", peek(&stack));
        }
    }
    removeStack(&stack);
    return 0;
}