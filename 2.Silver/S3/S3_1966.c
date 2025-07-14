#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int item, index;
    struct _Node *next;
}Node;

typedef struct _Queue{
    Node *front, *rear;
}Queue;

Queue makeQueue(){
    Queue newQueue;
    Node* frontDummy = (Node*)malloc(sizeof(Node));
    Node* rearDummy = (Node*)malloc(sizeof(Node));
    frontDummy->next = rearDummy;
    rearDummy->next = NULL;
    newQueue.front = frontDummy;
    newQueue.rear = rearDummy;
    return newQueue;
}

bool isEmpty(Queue *queue){
    return queue->front->next == queue->rear;
}

void enqueue(Queue *queue, int index, int item){
    Node* newDummy = (Node*)malloc(sizeof(Node));
    newDummy->next = NULL;

    queue->rear->index = index;
    queue->rear->item = item;
    queue->rear->next = newDummy;

    queue->rear = newDummy;
}

Node dequeue(Queue *queue){
    if(isEmpty(queue)){
        Node emptyNode;
        emptyNode.index = -1;
        return emptyNode;
    }
    
    Node *deNode = queue->front->next;
    Node returnNode;
    returnNode.index = deNode->index;
    returnNode.item = deNode->item;

    queue->front->next = deNode->next;
    free(deNode);
    return returnNode;
}

Node peek(Queue *queue){
    if(isEmpty(queue)){
        Node emptyNode;
        emptyNode.index = -1;
        return emptyNode;
    }
    return *(queue->front->next);
}

void clearQueue(Queue *queue){
    while(!isEmpty(queue))
        dequeue(queue);
}

void deleteQueue(Queue *queue){
    clearQueue(queue);
    free(queue->rear);
    free(queue->front);
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void QuickReverseSort(int* items, int n) {
  int l = 1, r = n-1;
  if (n <= 1) 
    return;
  while (l <= r) {
    while (l < n && items[l] > items[0]){
        l ++;
    }while (r > 0 && items[r] <= items[0]){
        r --;
    }if (l < r)
        swap(&items[l], &items[r]);
  }
  swap(&items[0], &items[r]);

  QuickReverseSort(items, r);
  QuickReverseSort(&items[r+1], n-r-1);
}

int main(){
    int cases;
    int papers, target;
    int priority[100];
    int count; // 현재까지 인쇄된 문서의 개수를 저장하는 변수
    Queue queue = makeQueue();
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        count = 0;
        scanf("%d %d", &papers, &target);
        // 문서의 중요도를 입력받아 큐에 순서대로 인덱스 정보와 함께 넣음.
        for(int j = 0; j < papers; j++){
            scanf(" %d", &priority[j]);
            enqueue(&queue, j, priority[j]);
        }
        // 문서의 갯수만큼의 중요도를 내림차순으로 정렬
        QuickReverseSort(priority, papers);
        // 타겟 문서의 인덱스와 dequeue되는 문서의 인덱스가 같고, 현재 가장 큰 중요도와 동일하면 루프를 멈춤
        while(!(peek(&queue).index == target && peek(&queue).item == priority[count])){
            // 만약 dequeue되는 문서의 중요도와 현재 가장 높은 중요도가 같으면 인쇄
            // 문서 하나를 인쇄했기 때문에 count가 1 증가함
            if(peek(&queue).item == priority[count]){
                dequeue(&queue);
                count++;
            }else if(peek(&queue).item < priority[count]){
                // 만약 dequeue되는 문서의 중요도가 현재 문서들의 중요도 중 최대가 아니라면 큐의 마지막으로 다시 넣음
                enqueue(&queue, peek(&queue).index, peek(&queue).item);
                dequeue(&queue);
            }
        }
        // 루프에서 타겟문서를 찾았을 때 인쇄(dequeue)가 없었기 때문에 count를 1 증가한 값을 출력해야 함
        printf("%d\n", count+1);
        // 다음 케이스를 위해 큐를 비움
        clearQueue(&queue);
    }
    deleteQueue(&queue);
    return 0;
}