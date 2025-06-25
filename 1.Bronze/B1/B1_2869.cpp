#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int liftup, liftdown, goal;

    cin >> liftup >> liftdown >> goal;
    int diff = liftup - liftdown;
    if(diff <= 0){
        cout << "Wrong Input!!" << endl;
        return 1;
    }
    double event_height = goal - liftup;
    int event_day = static_cast<int>(ceil(event_height/diff));
    
    cout << event_day + 1 << endl;

    return 0;
}
// 달팽이가 올라가는 데 걸리는 시간 계산 / 핵심은 컴파일 시간 단축
// https://www.acmicpc.net/problem/2869