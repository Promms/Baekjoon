#include <stdio.h>

int main(){
    int loop, series;
    int score;
    char answer = ' ';

    // 개행문자 \n을 제거하기 위해 %d 뒤에 한 칸 띄움
    scanf("%d ", &loop);

    for(int i = 0; i < loop; i++){
        score = series = 0;
        answer = ' ';
        while(answer != '\n'){
            scanf("%c", &answer);
            if(answer == 'O'){
                series++;
                score += series;
            }else if(answer == 'X'){
                series = 0;
            }
        }
        printf("%d\n", score);
    }

    return 0;
}