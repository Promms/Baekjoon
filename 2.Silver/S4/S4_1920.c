#include <stdio.h>
#include <stdlib.h>

#define TABLE_NUM 20000

typedef struct _Node{
    long long int number;
    struct _Node *next;
}Node;

Node* HashTable[TABLE_NUM];

int makeHash(long long int number){
    // 음수 값도 있기 때문에 간단히 제곱한 후 테이블 숫자로 나눈 나머지를 해시 값으로 설정
    return (number*number)%TABLE_NUM;
}

void insertTable(long long int number){
    int hash = makeHash(number);

    Node* curr = HashTable[hash];

    // 순서가 중요하지 않기 때문에 시간 복잡도를 줄이기 위해 연결리스트의 맨 앞에 삽입
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->number = number;
    newNode->next = curr;

    HashTable[hash] = newNode;
}

int findNumber(long long int number){
    int hash = makeHash(number);

    Node* curr = HashTable[hash];

    while(curr != NULL){
        if(curr->number == number)
            return 1;
        curr = curr->next;
    }

    return 0;
}

int main(){
    int loop_A, loop_B;
    long long int num, find_num;
    scanf("%d", &loop_A);

    for(int i = 0; i < loop_A; i++){
        scanf("%lld", &num);
        insertTable(num);
    }

    scanf("%d", &loop_B);
    for(int i = 0; i < loop_B; i++){
        scanf("%lld", &find_num);
        printf("%d\n", findNumber(find_num));
    }

    return 0;
}