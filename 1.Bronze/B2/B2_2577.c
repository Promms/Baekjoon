#include <stdio.h>

int main(){
    int num_a, num_b, num_c;
    int result;
    int frequency[10]= {0};

    scanf("%d %d %d", &num_a, &num_b, &num_c);
    result = num_a * num_b * num_c;

    while (result > 0){
        frequency[result%10]++;
        result /= 10;
    }
    
    for(int i = 0; i < 10; i++)
        printf("%d\n", frequency[i]);

    return 0;
}