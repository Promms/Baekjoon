#include <iostream>
#include <array>
using namespace std;

const int row = 100;
const int col = 100;
const int row_paper = 10;
const int col_paper = 10;

void set_paper(array<array<bool, col>, row>& matrix, int index_row, int index_col, int& total_area){
    for(int i = index_row; i < index_row + row_paper; i++){
        for(int j = index_col; j < index_col + col_paper; j++){
            if(matrix[i][j] == false){
                matrix[i][j] = true;    total_area++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    array<array<bool, col>, row> Matrix = {false}; // 색종이가 올려진 여부를 저장하는 2차원 matrix
    int num_paper , row_input, col_input;
    cin >> num_paper;
    int total_Area = 0;

    for(int i = 0; i < num_paper; i++){
        cin >> row_input >> col_input;
        set_paper(Matrix, row_input, col_input, total_Area);
    }
/*
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << static_cast<int>(Matrix[i][j]);
        }
        cout << '\n';
    }
    시각적으로 확인하기 위한 부분
*/
    cout << total_Area << endl;

    return 0;
}
// 100*100 크기의 종이 위에 있는 10*10 크기의 색종이들의 넓이의 합
// 색종이끼리 겹치는 부분을 제외하기 위해 100*100을 모눈으로 생각했을때
// 1*1 크기의 모눈을 기준으로 종이가 올라와있으면 true 아니면 false로 구분하기로 함
// 따라서 이미 종이가 올라와있는 구역은 이미 true이기 때문에 또 올라와도 true로 유지
// 마지막에 결국 true인 1*1의 칸을 모두 더하면 넓이가 나온다.
// https://www.acmicpc.net/problem/2563