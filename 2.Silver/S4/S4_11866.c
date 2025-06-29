#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int item;
    struct _Node *next;
}Node;

typedef struct _Queue{
    int size;
    Node *front, *rear;
}Queue;

Queue makeQueue(){
    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->next = NULL;
    Queue newQueue;
    newQueue.size = 0;
    newQueue.front = dummy;
    newQueue.rear = dummy;
    return newQueue;
}

bool isEmpty(Queue* queue){
    return queue->front == queue->rear;
}

void enqueue(Queue* queue, int item){
    Node* newDummy = (Node*)malloc(sizeof(Node));
    newDummy->next = NULL;
    queue->rear->item = item;
    queue->rear->next = newDummy;
    queue->rear = newDummy;
    queue->size++;
}

int dequeue(Queue* queue){
    if(isEmpty(queue))
        return -1;
    Node* deNode = queue->front;
    int deItem = deNode->item;
    queue->front = deNode->next;
    queue->size--;
    free(deNode);
    return deItem;
}

void deleteQueue(Queue* queue){
    while(!isEmpty(queue))
        dequeue(queue);
    free(queue->front);
}

int main(){
    Queue queue = makeQueue();
    int num, term;
    scanf("%d %d", &num, &term);
    for(int i = 1; i <= num; i++)
        enqueue(&queue, i);
   
    printf("<");
    while(queue.size > 1){
        int j = 1;
        while(j < term){
            enqueue(&queue, dequeue(&queue));
            j++;
        }
        printf("%d, ", dequeue(&queue));
    }

    printf("%d>", dequeue(&queue));
    deleteQueue(&queue);
    return 0;
}