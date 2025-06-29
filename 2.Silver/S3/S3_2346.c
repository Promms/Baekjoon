#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int item, index;
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

void insert_head(Deque *deque, int item, int index){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->index = index;

    Node* frontNode = deque->head->next;
    newNode->next = frontNode;
    newNode->prev = deque->head;

    frontNode->prev = newNode;
    deque->head->next = newNode;
    deque->size++;
}

void insert_tail(Deque *deque, int item, int index){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->index = index;

    Node* backNode = deque->tail->prev;
    newNode->prev = backNode;
    newNode->next = deque->tail;

    backNode->next = newNode;
    deque->tail->prev = newNode;
    deque->size++;
}

int delete_head(Deque *deque){
    if(isEmpty(deque))
        return 0;
    Node* deleteNode = deque->head->next;
    int deleteIndex = deleteNode->index;

    deque->head->next = deleteNode->next;
    deleteNode->next->prev = deque->head;
    deque->size--;
    free(deleteNode);
    return deleteIndex;
}

int delete_tail(Deque *deque){
    if(isEmpty(deque))
        return 0;
    Node* deleteNode = deque->tail->prev;
    int deleteIndex = deleteNode->index;

    deque->tail->prev = deleteNode->prev;
    deleteNode->prev->next = deque->tail;
    deque->size--;
    free(deleteNode);
    return deleteIndex;
}

int peek_head(Deque *deque){
    if(isEmpty(deque))
        return 0;
    return deque->head->next->item;
}

int peek_tail(Deque *deque){
    if(isEmpty(deque))
        return 0;
    return deque->tail->prev->item;
}

void deleteDeque(Deque *deque){
    while(!isEmpty(deque))
        delete_head(deque);
    free(deque->head);
    free(deque->tail);
}

int main(){
    Deque deque = makeDeque();
    int num, balloon, boom, loop;

    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        scanf("%d", &balloon);
        insert_tail(&deque, balloon, i);
    }

    while(deque.size > 1){
        loop = 1;
        // 터트린 풍선 속 쪽지의 값을 저장
        boom = peek_head(&deque);
        // 풍선의 index를 저장
        int index = delete_head(&deque);
        if(boom > 0){ // 쪽지 값이 양수라면 (boom) - 1 만큼의 풍선을 tail에 삽입
            while(loop < boom){
                int headItem = peek_head(&deque);
                int headIndex = delete_head(&deque);
                insert_tail(&deque, headItem, headIndex);
                loop++;
            }
        }else if(boom < 0){ // 쪽지 값이 음수라면 (boom) 만큼의 풍선을 head에 삽입
            while(loop <= -boom){
                int tailItem = peek_tail(&deque);
                int tailIndex = delete_tail(&deque);
                insert_head(&deque, tailItem, tailIndex);
                loop++;
            }
        }
        printf("%d ", index);
    }

    // 덱에 1개 남은 나머지 풍선의 index도 출력
    printf("%d", delete_head(&deque));

    deleteDeque(&deque);
    return 0;
}