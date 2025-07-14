#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    int f_slope, f_num;
    int g_slope, n_point;

    cin >> f_slope >> f_num;
    cin >> g_slope;
    cin >> n_point;

    if(f_slope > g_slope){
        cout << '0' << endl;
        return 0;
    }

    int f_point = f_slope*n_point + f_num;
    int g_point = g_slope*n_point;

    cout << ((f_point <= g_point) ? '1' : '0') << endl;

    return 0;
}