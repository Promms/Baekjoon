#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int item, index;
    struct _Node *next;
}Node;

// front가 더미를 가리키고, rear가 마지막 데이터를 가리키는 방식이 일반적인 방식
typedef struct _Queue{
    Node *front, *rear;
}Queue;

Queue makeQueue(){
    Queue newQueue;
    Node* Dummy = (Node*)malloc(sizeof(Node));
    Dummy->next = NULL;
    newQueue.front = Dummy;
    newQueue.rear = Dummy;
    return newQueue;
}

bool isEmpty(Queue *queue){
    return queue->front == queue->rear;
}

void enqueue(Queue *queue, int index, int item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->index = index;
    newNode->item = item;
    newNode->next = NULL;

    queue->rear->next = newNode;
    queue->rear = newNode;
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

    // 만약 deNode가 rear인 경우에 그냥 free하게 되면 rear는 해제된 메모리 주소를 가리킨다.
    // 따라서 rear를 front와 동일하게 지정해주어야 함
    if(queue->rear == deNode)
        queue->rear = queue->front;
    
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
        while(true) {
            Node current = peek(&queue); // 맨 앞 문서를 확인
            // 현재 문서의 중요도가 가장 높은 경우
            if (current.item == priority[count]) {
                count++; // 인쇄 순서 증가
                dequeue(&queue); // 큐에서 제거 (인쇄)
                // 방금 인쇄한 문서가 우리가 찾던 target 문서라면 루프 종료
                if (current.index == target) {
                    printf("%d\n", count); // count가 이미 인쇄 순서이므로 그대로 출력
                    break;
                }
            } else { // 중요도가 가장 높지 않은 경우 큐의 맨 뒤로 보냄
                Node temp = dequeue(&queue);
                enqueue(&queue, temp.index, temp.item);
            }
        }
        // 다음 케이스를 위해 큐를 비움
        clearQueue(&queue);
    }
    deleteQueue(&queue);
    return 0;
}