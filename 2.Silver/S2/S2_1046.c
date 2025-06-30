#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 100000

typedef struct _Node{
    char word;
    struct _Node *next;
}Node;

typedef struct _Stack{
    int size;
    Node* head;
}Stack;

Stack makeStack(){
    Stack newStack;
    newStack.head = (Node*)malloc(sizeof(Node*));
    newStack.head->next = NULL;
    newStack.size = 0;
    return newStack;
}

bool isEmpty(Stack *stack){
    return stack->head->next == NULL;
}

void push(Stack *stack, char item){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->word = item;
    newNode->next = stack->head->next;
    stack->head->next = newNode;
    stack->size++;
}

char pop(Stack *stack){
    if(isEmpty(stack))
        return '\0';

    Node *popNode = stack->head->next;
    char popItem = popNode->word;
    stack->head->next = popNode->next;
    stack->size--;
    free(popNode);
    return popItem;
}

void deleteStack(Stack *stack){
    while(!isEmpty(stack))
        pop(stack);
    free(stack->head);
}

int main(){
    // 커서 왼쪽에 위치한 문자들을 보관하는 스택
    Stack left_cursor = makeStack();
    // 커서 오른쪽에 위치한 문자들을 보관하는 스택
    Stack right_cursor = makeStack();
    char inst, word;
    char init[MAX_NUM];
    int num;

    scanf("%s", init);
    for(int i = 0; init[i] != '\0'; i++)
        push(&left_cursor, init[i]);

    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf(" %c", &inst);
        // P라면 추가 문자를 입력받아 커서의 왼쪽 스택에 넣음
        if(inst == 'P'){
            scanf(" %c", &word);
            push(&left_cursor, word);
        }
        // L이고 현재 커서가 맨 앞이 아니면 커서를 왼쪽으로 한 칸 이동
        else if(inst == 'L' && left_cursor.size > 0)
            push(&right_cursor, pop(&left_cursor));
        // D이고 현재 커서가 맨 뒤가 아니면 커서를 오른쪽으로 한 칸 이동
        else if(inst == 'D' && right_cursor.size > 0)
            push(&left_cursor, pop(&right_cursor));
        // B라면 커서 왼쪽의 문자 하나를 지움
        else if(inst == 'B')
            pop(&left_cursor);
        
    }

    // 스택을 반대로 출력하기 위해 커서 right_cursor로 모두 옮김
    while(!isEmpty(&left_cursor))
        push(&right_cursor, pop(&left_cursor));
    
    // right_cursor의 모든 원소들을 pop
    while(!isEmpty(&right_cursor))
        printf("%c", pop(&right_cursor));
    
    deleteStack(&left_cursor);
    deleteStack(&right_cursor);

    return 0;
}