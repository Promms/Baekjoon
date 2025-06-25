#include <iostream>
using namespace std;

const char WB_BOARD[8][8] = {
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

int BW_change_count(char** board, int row, int col) {
    int count = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[row+i][col+j] != WB_BOARD[i][j]){
                count++;
            }
        }
    }
    return (count > 32) ? 64 - count : count;
    // 만약 바꿔야하는 칸이 64칸의 절반인 32칸을 넘어가는 경우하면
    // 우리가 비교하기 위해 제시한 WB_BOARD와 반대로 BW_BOARD로 만드는 것이
    // 더 적은 수가 들기 때문에 바뀌어야 할 칸과 유지해야 할 칸이 반대가 된다.
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    cin >> row >> col;
    char** input_board = new char* [row];
    for(int i = 0; i < row; i++)
        input_board[i] = new char [col];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> input_board[i][j];
        }
    }

    int should_change = 64; // 초기 선언 최악의 경우인 63보다는 크게
    int now_change;
    
    for(int i = 0; i < row - 7 ; i++){
        for(int j = 0 ; j < col - 7; j++){
            now_change = BW_change_count(input_board, i, j);
            if(now_change < should_change)  should_change = now_change;
        }
    }

    cout << should_change << endl;

    for(int i = 0; i < row; i++)
        delete[] input_board[i];
    delete[] input_board;
    return 0;
}