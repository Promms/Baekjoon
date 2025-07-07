#include <stdio.h>

#define MAX_NUM 100000

typedef struct _Heap{
    int size;
    int items[MAX_NUM+1];
}Heap;

Heap heap;

void swap(int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void insert(int item){
    heap.size += 1;
    heap.items[heap.size] = item;

    int index = heap.size;

    while(index > 1 && heap.items[index] < heap.items[index/2]){
        //printf("Swap! %d(%d) <-> %d(%d)\n", heap.items[index], index, heap.items[index/2], index/2);
        swap(&heap.items[index], &heap.items[index/2]);
        index /= 2;
    }
}

int deleteHeap(){
    if(heap.size == 0)
        return 0;
    int deleteItem = heap.items[1];
    swap(&heap.items[1], &heap.items[heap.size--]);

    int index = 1;
    while(index*2 <= heap.size){
        int smallChild;
        if(heap.items[index*2] < heap.items[index*2+1] || index*2+1 > heap.size)
            smallChild = index*2;
        else
            smallChild = index*2+1;

        if(heap.items[index] < heap.items[smallChild])
            break;
        

        //printf("Swap! %d <-> %d(%d)\n", heap.items[index], heap.items[smallChild], smallChild);
        swap(&heap.items[index], &heap.items[smallChild]);
        index = smallChild;
    }

    return deleteItem;
}

int main(){
    heap.size = 0;
    int loop, inst;
    scanf("%d", &loop);
    for(int i = 0; i < loop; i++){
        scanf(" %d", &inst);
        if(inst == 0){
            printf("%d\n", deleteHeap());
        }else{
            insert(inst);
        }
    }
    return 0;
}