#include <iostream>
#include <vector>
using namespace std;

namespace switch_game {

    // 스위치 상태를 반전시키는 함수
    void toggleSwitch(vector<bool>& switches, int position) {
        switches[position] = !switches[position];  // 스위치 상태 반전
    }

    // 남학생의 동작을 처리하는 함수
    void processMaleStudent(vector<bool>& switches, int number) {
        const int size = static_cast<int>(switches.size())-1;
        for(int count = 1; count * number <= size; count++) {
            toggleSwitch(switches, count * number);
        }
    }

    // 여학생의 동작을 처리하는 함수
    void processFemaleStudent(vector<bool>& switches, int number) {
        const int size = static_cast<int>(switches.size())-1;
        toggleSwitch(switches, number);
        for(int count = 1; ; count++) {
            if(number - count < 1 || number + count > size) {
                break;
            }
            if(switches[number - count] == switches[number + count]) {
                toggleSwitch(switches, number - count);
                toggleSwitch(switches, number + count);
            } else {
                break;
            }
        }
    }

    // 스위치 상태를 출력하는 함수
    void printSwitches(const vector<bool>& switches) {
        const int size = static_cast<int>(switches.size()) - 1;
        for(int count = 1; count <= size; count++) {
            cout << switches[count] << " ";
            if(count % 20 == 0) {
                cout << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int NUM_SWITCH;  // 스위치 개수
    int NUM_STUDENT; // 학생 수
    cin >> NUM_SWITCH;
    
    vector<bool> switches(NUM_SWITCH + 1);  // 1-based indexing

    for(int i = 1; i <= NUM_SWITCH; i++) {
        int state;
        cin >> state;
        switches[i] = state;
    }

    cin >> NUM_STUDENT;

    for(int j = 0; j < NUM_STUDENT; j++) {
        int gender, number;
        cin >> gender >> number;
        if(gender == 1){
            switch_game::processMaleStudent(switches, number);
        }else if(gender == 2){
            switch_game::processFemaleStudent(switches, number);
        }else{
            return 1; // 에러로 인한 종료
        }
    }

    switch_game::printSwitches(switches);
    return 0;
}
