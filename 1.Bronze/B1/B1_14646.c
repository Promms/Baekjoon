#include <stdio.h>

#define ISBN_DIGIT 13

int main(){
    int sum = 0, damaged, damaged_index, check;
    char num;

    for(int i = 1; i < ISBN_DIGIT; i++){
        scanf("%c", &num);
        if(num >= '0' && num <= '9'){
            sum += (i%2 == 0) ? (num - '0')*3 : (num - '0');
        }else
            damaged_index = i;
    }

    scanf("%d", &check);

    damaged = (10-(sum + check)%10);
    damaged = (damaged == 10) ? 0 : damaged;

    // 나머지 계산을 역으로 할 수 있는 방법이 있으면 이렇게 노가다로 안 해도 되는데
    // 지금은 모르겠어서 공부를 더 해야할 것 같음
    if(damaged_index % 2 == 0){
        switch(damaged){
            case 1:
                damaged = 7;
                break;
            case 2:
                damaged = 4;
                break;
            case 3:
                damaged = 1;
                break;
            case 4:
                damaged = 8;
                break;
            case 5:
                damaged = 5;
                break;
            case 6:
                damaged = 2;
                break;
            case 7:
                damaged = 9;
                break;
            case 8:
                damaged = 6;
                break;
            case 9:
                damaged = 3;
                break;
            default:
                damaged = 0;
                break;
        }
    }

    printf("%d", damaged);
    return 0;
}