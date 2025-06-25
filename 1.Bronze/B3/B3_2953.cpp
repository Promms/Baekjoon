#include <iostream>
#include <numeric>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int person[5][4] = {}; // 5명의 4개의 점수를 저장할 배열
    pair<int, int> winner = {0, 0}; // 우승자의 번호와 점수를 저장할 변수

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> person[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        int now_sum = accumulate(person[i], person[i] + 4, 0);
        if(now_sum > winner.second) {
            winner.second = now_sum; // 현재 참가자의 점수의 합이 더 클 경우
            winner.first = i + 1; // 현재 참가자의 번호를 저장
        }
    }
    cout << winner.first << " " << winner.second << "\n";

    return 0;
}
