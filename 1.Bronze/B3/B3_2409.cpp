#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

const int NUM_GAMES = 3;
const int NUM_Yut = 4;

// 윷놀이 결과를 나타내는 열거형
enum class YutResult {
    DO,     // 도: 배 1개, 등 3개 // A
    GAE,    // 개: 배 2개, 등 2개 // B
    GEOL,   // 걸: 배 3개, 등 1개 // C
    YUT,    // 윷: 배 4개, 등 0개 // D
    MO,     // 모: 배 0개, 등 4개 // E
    Error   // 에러처리
};

// 입력받은 윷의 상태로부터 결과를 판단하는 함수
YutResult getYutResult(const array<int, 4>& yut) {
    int num_bae = count(yut.begin(), yut.end(), 0);
    
    switch(num_bae){
        case 1 : return YutResult::DO;
        case 2 : return YutResult::GAE;
        case 3 : return YutResult::GEOL;
        case 4 : return YutResult::YUT;
        case 0 : return YutResult::MO;
        default : return YutResult::Error;
    }
}

// 결과를 문자로 변환하는 함수
char getResultChar(YutResult result) {
    switch (result){
        case YutResult::DO: return 'A';
        case YutResult::GAE: return 'B';
        case YutResult::GEOL: return 'C';
        case YutResult::YUT: return 'D';
        case YutResult::MO: return 'E';
        case YutResult::Error: return 'X';
        default: return 'X';
    }
}

int main() {
    for(int i = 0; i < NUM_GAMES; i++) {
        array<int, 4> yut;
        for(int j = 0; j < NUM_Yut; j++)
            cin >> yut[j];
        cout << getResultChar(getYutResult(yut)) << endl;
    }
    
    return 0;
}