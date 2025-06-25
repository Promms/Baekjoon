#include <iostream>
using namespace std;

long long int power(int base, int exponent){
    long long int num = base;
    for(int i = 1; i < exponent; i++){
        num *= base;
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_term;

    cin >> num_term;

    long long int num_dots = power((power(2,num_term)+1),2);
    cout << num_dots;

    return 0;
}
// 규칙에 따라 증가하는 점의 갯수를 예측하는 코드
// https://www.acmicpc.net/problem/2903