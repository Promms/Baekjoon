#include <iostream>

using namespace std;


int sum_of_digit(int number){
    int sum = number;
    while(number > 0){
        if(number % 10 == 0) return 0;
        sum += number % 10;
        number /= 10;
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    int target;
    int constructor = 0;
    cin >> target;

    for(int i = target; i > 0; i--){
        if(sum_of_digit(i) == target){
            constructor = i;
            break;
        }
    }

    if(constructor != 0){
        cout << constructor << endl;
    }else{
        cout << '0' << endl;
    }

    return 0;
}