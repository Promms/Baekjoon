#include <stdio.h>
#include <stdlib.h>

int sumArray(int* items, int n){
    int sum = 0;
    for(int i = 0; i <= n; i++)
        sum += items[i];
    return sum;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void QuickSort(int* items, int n) {
  int l = 1, r = n-1;
  if (n <= 1) 
    return;
  while (l <= r) {
    while (l < n && items[l] < items[0]){
        l ++;
    }while (r > 0 && items[r] >= items[0]){
        r --;
    }if (l < r)
        swap(&items[l], &items[r]);
  }
  swap(&items[0], &items[r]);

  QuickSort(items, r);
  QuickSort(&items[r+1], n-r-1);
}

int main(){
    int population;
    scanf("%d", &population);
    int *array = (int*)malloc(sizeof(int)*population);
    int total_time = 0;

    for(int i = 0; i < population; i++){
        scanf("%d", &array[i]);
    }

    QuickSort(array, population);

    for(int i = 0; i < population; i++){
        //printf("%d(total time) * 2 + %d(array[%d])\n", total_time, array[i], i);
        total_time += sumArray(array, i);
    }

    printf("%d", total_time);

    free(array);
    return 0;
}