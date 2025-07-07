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

int absolute(int num){
    return (num > 0) ? num : -num;
}

void insert(int item){
    heap.size += 1;
    heap.items[heap.size] = item;

    int index = heap.size;

    while(index > 1 && absolute(heap.items[index]) <= absolute(heap.items[index/2])){
        // 절댓값이 같다면 부호가 음수인 것이 우선순위로 오게 함
        if(absolute(heap.items[index]) == absolute(heap.items[index/2])){
            if(heap.items[index] < heap.items[index/2]){
                swap(&heap.items[index], &heap.items[index/2]);
                index /= 2;
            }else
                break; // 무한루프에 걸리지 않기 위해 break를 추가
            
        }else{
            swap(&heap.items[index], &heap.items[index/2]);
            index /= 2;
        }
    }
}

int deleteHeap(){
    if(heap.size == 0)
        return 0;
    int deleteItem = heap.items[1];
    swap(&heap.items[1], &heap.items[heap.size--]);

    int index = 1;
    int smallIndex;

    while(index*2 <= heap.size){
        if(absolute(heap.items[index*2]) < absolute(heap.items[index*2+1]) || index*2+1 > heap.size)
            smallIndex = index*2;
        else if(absolute(heap.items[index*2]) == absolute(heap.items[index*2+1]) && heap.items[index*2] != heap.items[index*2+1])
            smallIndex = (heap.items[index*2] < heap.items[index*2+1]) ? index*2 : index*2+1;
        else
            smallIndex = index*2+1;

        if(absolute(heap.items[index]) == absolute(heap.items[smallIndex]) && heap.items[index] < 0) break;
        if(absolute(heap.items[index]) < absolute(heap.items[smallIndex])) break;
        
        swap(&heap.items[index], &heap.items[smallIndex]);
        index = smallIndex;
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