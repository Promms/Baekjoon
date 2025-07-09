#include <stdio.h>
#include <string.h>

#define MAX_NUM 20

// 집합의 모든 요소를 매개변수 num으로 변경시키는 함수
void allChange(char* array, int size, int num){
    // main 함수에서 배열을 1-based index로 구성했기 때문에 조건이 size+1
    for(int i = 1 ; i < size+1; i++)
        array[i] = num;
}

int main(){
    // 1-based index를 이용하여 직관적으로 비트마스킹
    char map[MAX_NUM+1] = {0};
    char inst[10];
    int num, element;

    scanf("%d ", &num);

    for(int i = 0; i < num; i++){
        scanf("%s %d", inst, &element);
        if(strcmp(inst, "add") == 0){
            map[element] = 1;
        }else if(strcmp(inst, "remove") == 0){
            map[element] = 0;
        }else if(strcmp(inst, "check") == 0){
            int answer = (map[element] == 1) ? 1 : 0;
            printf("%d\n", answer);
        }else if(strcmp(inst, "toggle") == 0){
            map[element] = (map[element] == 0) ? 1 : 0;
        }else if(strcmp(inst, "all") == 0){
            allChange(&map[0], MAX_NUM, 1);
        }else if(strcmp(inst, "empty") == 0){
            allChange(&map[0], MAX_NUM, 0);
        }
    }
    return 0;
}