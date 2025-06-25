#include <iostream>
#include <string>
#include <cmath> // 추가: std::pow를 사용하기 위해

using namespace std;

int character_to_integer(const char& c){
    if(c >= '0' && c <= '9'){
        return c - '0';
    }else if(c >= 'A' && c <= 'Z'){
        return c - 55; //A~Z는 10~35가 되어야 하기 때문에 55만 빼줌
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string numbers;
    int base;

    cin >> numbers >> base;
    int digit = numbers.size()-1;
    int sum = 0;

    for(int i = 0; digit - i >= 0; i++){
        sum += character_to_integer(numbers[i]) * static_cast<int>(pow(base, digit-i));
    }

    cout << sum << '\n';

    return 0;
}