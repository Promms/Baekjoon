#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int item;
    struct _Node* next;
}Node;

typedef struct _Stack{
    Node* head;
}Stack;

Stack makeStack(){
    Stack newStack;
    newStack.head = (Node*)malloc(sizeof(Node*));
    newStack.head->next = NULL;
    return newStack;
}

bool isEmpty(Stack* stack){
    return stack->head->next == NULL;
}

void push(Stack* stack, int item){
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->item = item;
    newNode->next = stack->head->next;
    stack->head->next = newNode;
}

int pop(Stack* stack){
    if(isEmpty(stack))
        return -1;

    Node* popNode = stack->head->next;
    int popItem = popNode->item;
    stack->head->next = popNode->next;
    free(popNode);
    return popItem;
}

int main(){
    Stack stack = makeStack();
    int num, inst;
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        scanf("%d", &inst);
        if(inst == 0)
            pop(&stack);
        else
            push(&stack, inst);
    }

    int sum = 0;
    while(stack.head->next != NULL)
        sum += pop(&stack);
    
    printf("%d", sum);
    return 0;
}
