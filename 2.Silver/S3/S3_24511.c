#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _Node{
    int item;
    struct _Node *next, *prev;
}Node;

typedef struct _Deque{
    int size;
    Node *head, *tail;
}Deque;

Deque makeDeque(){
    Node* headDummy = (Node*)malloc(sizeof(Node));
    Node* tailDummy = (Node*)malloc(sizeof(Node));
    
    Deque newDeque;
    newDeque.head = headDummy;
    newDeque.tail = tailDummy;
    newDeque.size = 0;

    newDeque.head->prev = NULL;
    newDeque.head->next = newDeque.tail;
    newDeque.tail->prev = newDeque.head;
    newDeque.tail->next = NULL;

    return newDeque;
}

bool isEmpty(Deque* deque){
    return deque->head->next == deque->tail;
}

void insert_head(Deque *deque, int item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;

    Node* frontNode = deque->head->next;
    newNode->next = frontNode;
    newNode->prev = deque->head;

    frontNode->prev = newNode;
    deque->head->next = newNode;
    deque->size++;
}

void insert_tail(Deque *deque, int item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;

    Node* backNode = deque->tail->prev;
    newNode->prev = backNode;
    newNode->next = deque->tail;

    backNode->next = newNode;
    deque->tail->prev = newNode;
    deque->size++;
}

int delete_tail(Deque *deque){
    if(isEmpty(deque))
        return 0;
    Node* deleteNode = deque->tail->prev;
    int deleteItem = deleteNode->item;

    deque->tail->prev = deleteNode->prev;
    deleteNode->prev->next = deque->tail;
    deque->size--;
    free(deleteNode);
    return deleteItem;
}

void deleteDeque(Deque *deque){
    while(!isEmpty(deque))
        delete_tail(deque);
    free(deque->head);
    free(deque->tail);
}


int main(){
    int length_A;
    int length_C;
    int insert_element;
    // 새롭게 들어오는 원소가 맨 앞으로 오고, 가장 뒤에 있는 원소가 빠져나오기 때문에
    // 앞 삽입, 후 제거가 가능한 덱 자료구조를 사용
    Deque deque = makeDeque();

    scanf("%d", &length_A);

    // 스택인지 큐인지 저장할 배열을 생성
    int *structType = (int*)malloc(sizeof(int)*length_A);

    for(int i = 0; i < length_A; i++)
        scanf("%d", &structType[i]);
    

    int filter;
    for(int i = 0; i < length_A; i++){
        scanf("%d", &filter);
        // 스택은 이전 배열에서 넘어온 값을 그대로 넘기기 때문에 실질적으로 의미가 있는
        // 큐로만 배열을 구성
        if(structType[i] == 0)
            insert_tail(&deque, filter);
    }

    scanf("%d", &length_C);

    // 문제에서 큐 자료구조는 새롭게 들어온 원소를 남기고 기존 원소를 다음 주소로
    // 넘기기 때문에 크게 보면 새로운 원소가 헤드에 삽입되는 것과 같다.
    // 그 후 배열의 전체 길이는 유지되어야 하기 때문에 마지막 원소를 제거
    for(int j = 0; j < length_C; j++){
        scanf("%d", &insert_element);
        insert_head(&deque, insert_element);
        printf("%d ", delete_tail(&deque));
    }

    free(structType);
    deleteDeque(&deque);
    return 0;
}