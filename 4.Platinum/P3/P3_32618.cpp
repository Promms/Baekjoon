#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    int num_of_land, first_energy;
    cin >> num_of_land >> first_energy;

    vector<int> war_field(num_of_land);
    vector<int> energy_field(num_of_land);
    vector<int> cost_of_field(num_of_land);

    for(int i = 0; i < num_of_land; i++){
        cin >> war_field[i];
    }
    for(int i = 0; i < num_of_land; i++){
        cin >> energy_field[i];
        cost_of_field[i] = war_field[i] + energy_field[i];
    }

    int corrupted_land = 1;
    
    return 0;
}