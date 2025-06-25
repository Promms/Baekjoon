#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    char word;
    struct _Node* next;
}Node;

typedef struct _Stack{
    int size;
    Node* head;
}Stack;

Stack makeStack(){
    Stack newStack;
    newStack.head = NULL;
    newStack.size = 0;
    return newStack;
}

int main(){

}
