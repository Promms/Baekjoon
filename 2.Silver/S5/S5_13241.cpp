#include <iostream>
#include <vector>
using namespace std;

int Find_GCD(int a, int b){
    int q = a / b;
    int r = a % b;
    while(r != 0){
        a = b; b = r; r = a % b;
    }
    return b;
} // a = q*b + r 일때 GCD(a,b)는 GCD(q,r)과 같다. (0 <= r < b)
  // r = 0이라면 GCD(a,b) = r이 된다.

long long int Find_LCM(int a, int b){
    int GCD = (a > b) ? Find_GCD(a,b) : Find_GCD(b,a);
    return static_cast<long long int>(a) * b / GCD;
} // 두 수를 곱한 수에 GCD를 나눠주면 LCM이 나옴

int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    long long int LCM; // 최소공배수
    int num_one, num_two;
    cin >> num_one >> num_two;

    LCM = Find_LCM(num_one, num_two);
    cout << LCM;
    return 0;
}