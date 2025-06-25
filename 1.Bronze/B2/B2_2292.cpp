#include <iostream>
using namespace std;

const int n_gon = 6;

int search_direction(int direction){
    int sum, count = 1;
    while(true){
        sum = 3*count*(count-1) + 1;
        if(sum >= direction)
            return count;
        count++;
    }
} // 첫 번째 항이 0이고 등차가 6인 등차수열의 합을 구한 뒤 등차수열이 아닌 첫 번째 항 1을 더함
// 그러면 목표하는 숫자가 몇 번째 층에 있는지 비교할 수 있음

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int direction;

    cin >> direction;

    cout << search_direction(direction);

    return 0;
}
// 6각형 맵의 중심에서 특정숫자까지 갈때 걸리는 칸의 수
// https://www.acmicpc.net/problem/2292