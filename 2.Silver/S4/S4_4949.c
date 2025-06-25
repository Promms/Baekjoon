#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 100

typedef struct _Node{
    char item;
    struct _Node* next;
}Node;

typedef struct _Stack{
    Node* head;
}Stack;

Stack makeStack(){
    Stack newStack;
    newStack.head = (Node*)malloc(sizeof(Node));
    newStack.head->next = NULL;
    return newStack;
}

bool isEmpty(Stack* stack){
    return stack->head->next == NULL;
}

void push(Stack* stack, char item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = stack->head->next;
    stack->head->next = newNode;
}

char pop(Stack* stack){
    if(isEmpty(stack))
        return '\0';

    Node* popNode = stack->head->next;
    char popItem = popNode->item;
    stack->head->next = popNode->next;
    free(popNode);
    return popItem;
}

int main(){
    char input[MAX_NUM], tmp;
    bool isVaild;
    Stack stack = makeStack();

    while(true){
        isVaild = true;
        scanf("%[^\n]s", input);
        getchar(); // 개행문자 제거
        tmp = input[0];
        if(input[0] == '.') break;
        for(int index = 0; tmp != '.'; index++){
            tmp = input[index];
            if(tmp == '(' || tmp == '[')
                push(&stack, tmp);
            else if(tmp == ')')
                isVaild = (pop(&stack) == '(') ? true : false;
            else if(tmp == ']')
                isVaild = (pop(&stack) == '[') ? true : false;
            if(!isVaild)    break;
        }
        
        if(isVaild && isEmpty(&stack)) printf("yes\n");
        else{
            printf("no\n");
            while(!isEmpty(&stack)) pop(&stack);
        }
    }
}