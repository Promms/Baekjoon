#include <stdio.h>

#define ROW 3
#define COL 3

int matrix[ROW][COL];

int main(){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int non_corner_max = 0;

    if(matrix[0][0] > non_corner_max)
        non_corner_max = matrix[0][0];
    if(matrix[0][2] > non_corner_max)
        non_corner_max = matrix[0][2];
    if(matrix[2][0] > non_corner_max)
        non_corner_max = matrix[2][0];
    if(matrix[2][2] > non_corner_max)
        non_corner_max = matrix[2][2];
    
    if(matrix[0][1] <= non_corner_max)
        printf("none");
    else if(matrix[1][0] <= non_corner_max)
        printf("none");
    else if(matrix[1][1] <= non_corner_max)
        printf("none");
    else if(matrix[1][2] <= non_corner_max)
        printf("none");
    else if(matrix[2][1] <= non_corner_max)
        printf("none");
    else
        printf("plus");

    return 0;
}
