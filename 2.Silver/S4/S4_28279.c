#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Node{
    int item;
    struct _Node* next, *prev;
}Node;

typedef struct _deque{
    int size;
    Node* front, *back;
}Deque;

Deque makeDeque(){
    // front가 가리키는 더미노드와 back이 가리키는 더미노드를 생성
    Node* frontDummy = (Node*)malloc(sizeof(Node));
    Node* backDummy = (Node*)malloc(sizeof(Node));
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;

    Deque newDeque;
    newDeque.front = frontDummy;
    newDeque.back = backDummy;
    newDeque.size = 0;
    return newDeque;
}

bool isEmpty(Deque* deque){
    return deque->front->next == deque->back;
}

// front 더미 노드의 다음 위치에 삽입
void push_front(Deque* deque, int item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* firstNode = deque->front->next;
    newNode->item = item;
    newNode->next = firstNode;
    newNode->prev = deque->front;

    firstNode->prev = newNode;
    deque->front->next = newNode;
    deque->size++;
}

// back 더미 노드의 이전 위치에 삽입
void push_back(Deque* deque, int item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* lastNode = deque->back->prev;
    newNode->item = item;
    newNode->next = deque->back;
    newNode->prev = lastNode;

    lastNode->next = newNode;
    deque->back->prev = newNode;
    deque->size++;
}

int pop_front(Deque* deque){
    if(isEmpty(deque))
        return -1;
    Node* popNode = deque->front->next;
    int popItem = popNode->item;
    deque->front->next = popNode->next;
    popNode->next->prev = deque->front;
    deque->size--;
    free(popNode);
    return popItem;
}

int pop_back(Deque* deque){
    if(isEmpty(deque))
        return -1;
    Node* popNode = deque->back->prev;
    int popItem = popNode->item;
    deque->back->prev = popNode->prev;
    popNode->prev->next = deque->back;
    deque->size--;
    free(popNode);
    return popItem;
}

void removeDeque(Deque* deque){
    while(!isEmpty(deque))
        pop_front(deque);
    free(deque->front);
    free(deque->back);
}

int peek_front(Deque* deque){
    if(isEmpty(deque))  return -1;
    return deque->front->next->item;
}

int peek_back(Deque* deque){
    if(isEmpty(deque))  return -1;
    return deque->back->prev->item;
}

int main(){
    Deque deque = makeDeque();
    int inst;
    int num, input;
    scanf("%d", &num);

    for(int i = 0; i < num; i ++){
        scanf("%d", &inst);
        if(inst ==1){
            scanf("%d", &input);
            push_front(&deque, input);
        }else if(inst == 2){
            scanf("%d", &input);
            push_back(&deque, input);
        }else if(inst == 3){
            printf("%d\n", pop_front(&deque));
        }else if(inst == 4){
            printf("%d\n", pop_back(&deque));
        }else if(inst == 5){
            printf("%d\n", deque.size);
        }else if(inst == 6){
            printf("%d\n", isEmpty(&deque));
        }else if(inst == 7){
            printf("%d\n", peek_front(&deque));
        }else if(inst == 8){
            printf("%d\n", peek_back(&deque));
        }
    }
    removeDeque(&deque);
    return 0;
}
