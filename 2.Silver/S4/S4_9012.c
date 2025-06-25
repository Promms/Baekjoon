#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 50

typedef struct _Node{
    char item;
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
    Stack stack = makeStack();
    char input[MAX_NUM];
    int num, index;
    bool isValid;

    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        isValid = true; index = 0;
        scanf("%s", input);

        while(input[index] != '\0'){
            if(input[index] == '(')
                push(&stack, input[index]);
            else if(input[index] == ')')
                isValid = (pop(&stack) == '(') ? true : false;
            
            if(!isValid)
                break;
            index++;
        }

        if(isValid && isEmpty(&stack))
            printf("YES\n");
        else{
            printf("NO\n");
            while(!isEmpty(&stack)) pop(&stack);
        }
    }


}