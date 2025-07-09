#include <stdio.h>
#include <stdlib.h>

int checkCoin(int coin, int* target){
    int count = 0;
    while(*target >= coin){
        count++;
        *target -= coin;
        //printf("Now target: %d, coin %d\n", *target, coin);
    }

    return count;
}

int main(){
    int num_coin, target;
    int less_coin = 0;
    scanf("%d %d ", &num_coin, &target);

    int *coins = (int*)malloc(sizeof(int)*num_coin);
    for(int i = 0; i < num_coin; i++){
        scanf("%d", &coins[i]);
    }

    for(int j = num_coin - 1; j >= 0; j--){
        less_coin += checkCoin(coins[j], &target);
        if(target == 0) break;
    }

    printf("%d\n", less_coin);

    free(coins);
    return 0;
}