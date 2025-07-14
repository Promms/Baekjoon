#include <iostream>

using namespace std;

void plus_one(char* numbers, int length){
    numbers[0]++;
    for(int i = 0; i < length; i++){
        if(numbers[i] - '0' == 10){
            if(i + 1 < length) { // 배열 범위 체크 추가
                if(numbers[i+1] == '\0')    numbers[i+1] = '1';
                else numbers[i+1]++;
            }
            numbers[i] = '0';
        }
    }
}

bool is_triple_six(char* numbers, int length){
    for(int i = 2; i < length; i++){
        if(numbers[i] == '6')
            if(numbers[i-1] == '6' && numbers[i-2] == '6')
                return true;
    }
    return false;
}

void print_numbers(char* numbers, int length){
    for(int i = length-1; i >= 0; i--){
        if(numbers[i] != '\0')
            cout << numbers[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    char numbers[10] = {'6', '6', '6', '\0', '\0','\0','\0','\0','\0','\0'};
    int target, now = 0;
    cin >> target;

    while(true){
        if(is_triple_six(numbers, 10))  now++;
        if(now == target)   break;
        plus_one(numbers, 10);
    }

    print_numbers(numbers, 10);

    return 0;
}