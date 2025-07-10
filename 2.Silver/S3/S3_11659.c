#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, loop, tmp;
    scanf("%d %d", &num, &loop);
    int *array = (int*)malloc(sizeof(int)*(num+1));
    array[0] = 0;
    
    for(int i = 1; i < num + 1 ; i++){
        scanf("%d", &tmp);
        array[i] = array[i-1] + tmp;
    }

    int left, right;
    for(int i = 0; i < loop; i++){
        scanf("%d %d", &left, &right);
        printf("%d\n", array[right] - array[left-1]);
    }

    free(array);
    return 0;
}