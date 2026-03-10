#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <limits>
#include <cstdio>

using namespace std;

class Height_Matrix{
public:
    int nRow = 0, nCol = 0;
    int T_limit = 0;
    int S_limit = 0;

    vector<vector<int>> h_info;

    Height_Matrix(){/* void */}
    Height_Matrix(const char *_filename){
        FILE *input = fopen(_filename, "r");

        if(!input){
            perror("파일을 열 수 없습니다");
            return;
        }

        fscanf(input, "%d %d", &nRow, &nCol);
        fscanf(input, "%d %d", &T_limit, &S_limit);

        h_info.resize(nRow);

        for(int i = 0; i < nRow; i++){
            for(int j = 0; j < nCol; j++){
                int cost;
                if(fscanf(input, "%d", &cost) == 1)
                    h_info[i].push_back({cost});
                }
        }
        fclose(input);
    }
};

void Cost_Calculate(const char *_filename, Height_Matrix &_matrix){
    int row = _matrix.nRow;
    int col = _matrix.nCol;
    int T_limit = _matrix.T_limit;
    int S_limit = _matrix.S_limit;

    bool visit[row][col];
    int up_cost[row][col];
    int down_cost[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            visit[i][j] = false;
            up_cost[i][j] = numeric_limits<int>::max();
            down_cost[i][j] = numeric_limits<int>::max();
        }
    }

    visit[0][0] = true;
    up_cost[0][0] = 0;
    down_cost[0][0] = 0;

    bool changed = true;
    while(changed){
        changed = false; // 이번 턴에 바뀐 게 없으면 종료

        for(int i=0; i < row; i++) {
            for(int j=0; j < col; j++) {
                if (visit[i][j] == false) continue;
                // 4방향 탐색 (상, 하, 좌, 우)
                int dr[4] = {-1, 1, 0, 0};
                int dc[4] = {0, 0, -1, 1};

                for(int dir=0; dir<4; dir++) {
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];

                    // 범위 체크
                    if(nr < 0 || nr >= row || nc < 0 || nc >= col) continue;

                    int curr_height = _matrix.h_info[i][j];
                    int adjacent_height = _matrix.h_info[nr][nc];
                    int h_diff = adjacent_height - curr_height;
                    // printf("curr_h: %d, adj_h: %d\n", curr_height, adjacent_height);
                    if(abs(h_diff) > T_limit) continue;
                    
                    int down_weight = (h_diff > 0) ? h_diff*h_diff : 1;
                    int up_weight = (h_diff > 0) ? 1 : h_diff*h_diff;

                    if(up_cost[i][j] + up_weight < up_cost[nr][nc]) {
                        up_cost[nr][nc] = up_cost[i][j] + up_weight;
                        visit[nr][nc] = true;
                        changed = true;
                    }

                    if(down_cost[i][j] + down_weight < down_cost[nr][nc]) {
                        down_cost[nr][nc] = down_cost[i][j] + down_weight;
                        visit[nr][nc] = true;
                        changed = true;
                    }
                }
            }
        }
    }

    int higest_height = -1;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(up_cost[i][j]+down_cost[i][j] <= S_limit && visit[i][j] == true){
                if(_matrix.h_info[i][j] > higest_height)
                    higest_height = _matrix.h_info[i][j];
            }
        }
    }

    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         if(visit[i][j] == true)
    //             printf("%2d ", up_cost[i][j] + down_cost[i][j]);
    //         else
    //             printf("-1 ");
    //     }
    //     printf("\n");
    // }

    // printf("\n");

    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         printf("%2d ", _matrix.h_info[i][j]);
    //     }
    //     printf("\n");
    // }

    FILE *output = fopen(_filename, "w");
    fprintf(output, "%d\n", higest_height);
    fclose(output);
}

int main(int argc, char **argv){
	if(argc != 3){
		fprintf( stderr , "USAGE:  EXECUTABLE   INPUT_FILE_NAME   OUTPUT_FILE_NAME\n");
		return 1;
	}
    Height_Matrix h(argv[1]);
    Cost_Calculate (argv[2], h);
	return 1;
}