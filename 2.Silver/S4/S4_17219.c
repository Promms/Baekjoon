// 아직 해결중
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 50000
#define MAX_LEN 20

typedef struct _Node{
    char password[MAX_LEN];
    struct _Node* next;
}Node;

int hash(char* array, int size){
    int hash = 0;
    for(int i = 0; i < size; i++){
        hash += array[0];
    }
}