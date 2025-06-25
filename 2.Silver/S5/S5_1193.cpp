#include <iostream>
using namespace std;

pair<int,int> search_diagonal(int direction){
    pair<int,int> sum_count = {0,1};
    while(true){
        sum_count.first += sum_count.second;
        if(sum_count.first >= direction)
            return sum_count;
        sum_count.second++;
    }
} // 대각선 한 줄을 한 층이라고 했을 때 목표하는 분수가 몇 번째 층인지 파악

void print_fraction(pair<int,int> index, int direction){
    int num = index.first - direction;
    if(index.second % 2 == 0)
        cout << index.second - num << '/' << num + 1 << endl;
    else
        cout << num + 1 << '/' << index.second - num << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int direction;

    cin >> direction;
    pair<int,int> num_diagonal = search_diagonal(direction);
    print_fraction(num_diagonal, direction);

    return 0;
}
// 표에 분수가 규칙적으로 배열되어 있을 때 n번째 분수를 찾는 법
// https://www.acmicpc.net/problem/1193