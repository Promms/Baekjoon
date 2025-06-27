#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Node{
    int item;
    struct _Node* next;
    struct _Node* prev;
}Node;

typedef struct _Queue{
    int size;
    Node* front;
    Node* rear;
}Queue;

Queue makeQueue(){
    Queue newQueue;
    // front와 rear가 dummy 노드를 가리키는 상태로 시작
    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->next = NULL;
    dummy->prev = NULL;
    newQueue.front = dummy;
    newQueue.rear = dummy;
    newQueue.size = 0;
    return newQueue;
}

bool isEmpty(Queue* queue){
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, int item){
    // 새로운 더미노드를 rear가 가리키고 기존의 rear 자리에 item을 삽입
    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->next = NULL;
    dummy->prev = queue->rear;
    queue->rear->item = item;
    queue->rear->next = dummy;
    queue->rear = dummy;
    queue->size++;
}

int dequeue(Queue* queue){
    if(isEmpty(queue))
        return -1;
    Node* deNode = queue->front;
    int deItem = deNode->item;
    queue->front = queue->front->next;
    queue->size--;
    free(deNode);
    return deItem;
}

int peek(Queue* queue){
    if(isEmpty(queue))
        return -1;
    return queue->front->item;
}

int back(Queue* queue){
    if(isEmpty(queue))
        return -1;
    //rear가 가리키는 더미노드의 이전 노드가 가장 마지막 큐의 맨 끝 원소
    return queue->rear->prev->item;
}

void removeQueue(Queue* queue){
    while(!isEmpty(queue))
        dequeue(queue);
    free(queue->front);
}

int main(){
    Queue queue = makeQueue();
    char inst[10];
    int num, input;
    scanf("%d", &num);

    for(int i = 0; i < num; i ++){
        scanf("%s", inst);
        if(strcmp(inst,"push") == 0){
            scanf("%d", &input);
            enqueue(&queue, input);
        }else if(strcmp(inst, "pop") == 0){
            printf("%d\n", dequeue(&queue));
        }else if(strcmp(inst, "size") == 0){
            printf("%d\n", queue.size);
        }else if(strcmp(inst, "empty") == 0){
            printf("%d\n", isEmpty(&queue));
        }else if(strcmp(inst, "front") == 0){
            printf("%d\n", peek(&queue));
        }else if(strcmp(inst, "back") == 0){
            printf("%d\n", back(&queue));
        }
    }
    removeQueue(&queue);
    return 0;
}