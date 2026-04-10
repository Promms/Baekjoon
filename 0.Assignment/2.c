#include <stdio.h>
#include <stdlib.h>

typedef struct _line{
    int left;
    int right;
}line;

int main(){
    int n;
    scanf("%d", &n);

    int crossing = 0;
    line *connection = (line*)calloc(n + 1, sizeof(line));
    int *cities = (int*)malloc(sizeof(line) * 2 * n);
    int city;
    
    for(int i = 1; i < 2*n + 1; i++){
        scanf("%d", &cities[i]);
        city = cities[i];

        if(connection[city].left == 0){
            connection[city].left = i;
            // printf("(SET) CITY[%d] -> (%d ~ None)\n", city, i);
        }else{
            connection[city].right = i;
            // printf("(SET) CITY[%d] -> (%d ~ %d)\n", city, connection[city].left, i);
        }
    }

    int al, ar, bl, br;
    for(int j = 1; j < n + 1; j++){
        al = connection[j].left;
        ar = connection[j].right;

        for(int k = j + 1; k < n + 1; k++){
            bl = connection[k].left;
            br = connection[k].right;
            // printf("CITY[%d] -> (%d ~ %d) \t CITY[%d] -> (%d ~ %d)\n", j, al, ar, k, bl, br);
            if(al < bl && bl < ar && ar < br){
                // printf("Crossing! (%d)\n", crossing);
                crossing++;
            }else if(bl < al && al < br && br < ar){
                // printf("Crossing! (%d)\n", crossing);
                crossing++;
            }
        }
    }

    printf("%d", crossing);
    
    free(cities);
    free(connection);
    return 0;
}