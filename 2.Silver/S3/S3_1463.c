// 미해결
#include <stdio.h>

int main(){
    int start, count = 0;
    scanf("%d", &start);

    while(start > 1){
        printf("Start: %d", start);
        if(start == 10){
            start = start / 10;
            count += 3;
            printf(" / 10 = %d (count: %d)\n", start, count);
        }else if(start % 3 == 1){
            start = (start - 1) / 3;
            count += 2;
            printf(" - 1 ) / 3 = %d (count: %d)\n", start, count);
        }else if(start % 3 == 0){
            start = start / 3;
            count += 1;
            printf(" / 3 = %d (count: %d)\n", start, count);
        }else if(start % 2 == 0){
            start = start / 2;
            count += 1;
            printf(" / 2 = %d (count: %d)\n", start, count);
        }else{
            start = start - 1;
            count++;
            printf(" - 1 = %d (count: %d)\n", start, count);
        }
    }

    printf("%d", count);

    return 0;
}