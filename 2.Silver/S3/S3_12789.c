#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int item;
    struct _Node *next;
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
    Node* newNode = (Node*)malloc(sizeof(Node));
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

int peek(Stack* stack){
    if(isEmpty(stack))
        return -1;
    return stack->head->next->item;
}

void removeStack(Stack* stack){
    while(!isEmpty(stack))
        pop(stack);
    free(stack->head);
}

int main(){
    Stack stack = makeStack();
    int num;
    int order, now_order = 1;
    bool isValid = true;

    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        // 대기열에 현재 입장 순서에 해당하는 인원이 있는지 확인 (순서대로 서있을 가능성이 있기 때문에 반복문으로 구성)
        while(peek(&stack) == now_order){
            now_order++;
            pop(&stack);
        }

        scanf("%d", &order);
        if(order == now_order){
            now_order++;
        }else{
            push(&stack, order);
        }
    }

    // 대기열 인원들을 확인
    while(!isEmpty(&stack)){
        if(pop(&stack) != now_order){
            isValid = false;
            break;
        }else{
            now_order++;
        }
    }

    if(isValid)
        printf("Nice");
    else
        printf("Sad");

    return 0;
}