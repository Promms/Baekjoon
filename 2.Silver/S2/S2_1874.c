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

bool isEmpty(Stack *stack){
    return stack->head->next == NULL;
}

void push(Stack *stack, int item){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = stack->head->next;

    stack->head->next = newNode;
}

int pop(Stack *stack){
    if(isEmpty(stack))
        return -1;
    
    Node *popNode = stack->head->next;
    int popItem = popNode->item;

    stack->head->next = popNode->next;
    free(popNode);
    return popItem;
}

int peek(Stack *stack){
    if(isEmpty(stack))
        return -1;
    return stack->head->next->item;
}

void deleteNode(Stack *stack){
    while(!isEmpty(stack))
        pop(stack);
    free(stack->head);
}

int main(){
    Stack stack;
    stack.head = (Node*)malloc(sizeof(Node*));
    stack.head->next = NULL;
    // now_max는 현재까지 스택에 입력된 숫자를 기록하기 위한 수
    int loop, num, now_max = 0;
    scanf("%d", &loop);
    // 한 숫자가 push, pop이 반복될 수 있기 때문에 *2 만큼의 공간을 할당
    char *result = (char*)malloc(sizeof(char)*(loop*2));
    int index = 0;
    bool valid = true;

    for(int i = 0; i < loop; i++){
        scanf("%d", &num);
        // 현재 stack의 top보다 더 작은 숫자가 나와야 하는 것은 불가능함
        if(num < peek(&stack)){
            valid = false;
        }else{
            // top보다 더 큰 수가 입력되면 now_max부터 입력된 수까지 push
            for(int j = now_max + 1; j <= num; j++){
                push(&stack, j);
                result[index++] = '+';
            }
            // 입력된 숫자를 pop 하는데, 만약 now_max보다 큰 수가 입력 되었으면 갱신
            now_max = (num > now_max) ? num : now_max;
            pop(&stack);
            result[index++] = '-';
        }
    }

    if(!valid){
        printf("NO\n");
    }else{
        for(int k = 0; k < index; k++)
            printf("%c\n", result[k]);
    }

    deleteNode(&stack);
    free(result);
    return 0;
}