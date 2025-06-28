#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Card{
    int number;
    struct _Card *next;
}Card;

typedef struct _Queue{
    int size;
    Card* front, *rear;
}Queue;

Queue makeQueue(){
    Card* dummy = (Card*)malloc(sizeof(Card));
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

void enqueue(Queue* queue, int number){
    Card* newDummy = (Card*)malloc(sizeof(Card));
    newDummy->next = NULL;

    queue->rear->number = number;
    queue->rear->next = newDummy;
    queue->rear = newDummy;
    queue->size++;
}

int dequeue(Queue* queue){
    if(isEmpty(queue))
        return -1;
    Card* deCard = queue->front;
    int deItem = deCard->number;
    queue->front = deCard->next;
    queue->size--;
    free(deCard);
    return deItem;
}

void deleteQueue(Queue* queue){
    while(!isEmpty(queue))
        dequeue(queue);
    free(queue->front);
}

int main(){
    Queue deck = makeQueue();
    int number;
    scanf("%d", &number);
    for(int i = 1; i <= number; i++)
        enqueue(&deck, i);

    while(deck.size != 1){
        dequeue(&deck);
        enqueue(&deck, dequeue(&deck));
    }

    printf("%d", dequeue(&deck));

    deleteQueue(&deck);
    return 0;
}
