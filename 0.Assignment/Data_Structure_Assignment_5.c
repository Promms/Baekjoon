#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100000

// you can modify any part of this code

typedef struct _Task {
    int id;
    int R, C, P;
} Task;

typedef struct _Heap {
    Task items[MAX_SIZE+1];
    int size;
} Heap;

void swap(Task *a, Task *b);
void insert(Heap *heap, Task task);
void delete(Heap *heap);

int N;
Task Tasks[MAX_SIZE+1];
Heap TaskBuffer; // use this heap structure

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++){
    Tasks[i].id = i;
    scanf("%d %d %d", &Tasks[i].R, &Tasks[i].C, &Tasks[i].P);
    }

    // you must implement priority-based task management system here
    int time = 0;
    int completeTask = 1;
    
    // 모든 Task들이 완료되었을 때 종료
    while(completeTask <= N || TaskBuffer.size > 0){
        // arriaval time이 현재 시간보다 이전인 Task만 TaskBuffer에 넣음
        while(completeTask <= N && Tasks[completeTask].R <= time){
            //printf("Insert Task: %d %d %d %d\n", Tasks[completeTask].R, Tasks[completeTask].C, Tasks[completeTask].P, Tasks[completeTask].id);
            insert(&TaskBuffer, Tasks[completeTask]);
            completeTask++;
        }

        // TaskBuffer에 들어가 있는 Task가 있다면 그 중 우선도가 가장 높은 하나를 수행
        // 수행한 작업의 computation time을 더해주어 현재 시간을 변경
        if(TaskBuffer.size >= 1){
            //printf("Start time: %d ", time);
            printf("%d\n", TaskBuffer.items[1].id);
            time += TaskBuffer.items[1].C;
            //printf("End time : %d End Task %d\n", time, TaskBuffer.items[1].id);
            delete(&TaskBuffer);
        }
        
        // 만약 지금 수행할 수 있는 Task가 없다면 수행하지 않은 Task가 있는
        // 가장 가까운 시간으로 이동
        if(time < Tasks[completeTask].R && TaskBuffer.size == 0){
            //printf("Pass\n");
            time = Tasks[completeTask].R;
        }
    }
    return 0;
}

void swap(Task *a, Task *b) {
    Task tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert(Heap *heap, Task task) {
    // you must implement this function
    heap->size += 1;
    heap->items[heap->size] = task;
    // priority가 높은 것이 우선순위가 위로 오게 함
    for(int i = heap->size; i > 1; i /= 2){
        if(heap->items[i/2].P < heap->items[i].P)
            swap(&heap->items[i/2], &heap->items[i]);
        else
            break;
    }
}

void delete(Heap *heap) {
    // you must implement this function
    swap(&heap->items[1], &heap->items[heap->size]);
    heap->size -= 1;

    int i = 1;
    while(i*2 <= heap->size){
        int priority;
        if(heap->items[i*2].P > heap->items[i*2+1].P || i*2+1 > heap->size)
            priority = i*2;
        else
            priority = i*2 + 1;
        if(heap->items[i].P > heap->items[priority].P)  break;
        swap(&heap->items[i], &heap->items[priority]);
        i = priority;
    }
}