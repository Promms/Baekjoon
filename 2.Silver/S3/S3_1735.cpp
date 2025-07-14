#include <iostream>
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


int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    int nu_a, nu_b;
    int de_a, de_b;
    cin >> nu_a >> de_a;
    cin >> nu_b >> de_b;
    nu_a *= de_b;
    nu_b *= de_a;

    int nu_re, de_re;
    nu_re = nu_a + nu_b;
    de_re = de_a * de_b;
    // 단순하게 양 분모를 곱한 뒤 더해줌
    
    int GCD = (nu_re > de_re) ? Find_GCD(nu_re, de_re) : Find_GCD(de_re, nu_re);
    nu_re /= GCD;
    de_re /= GCD;

    cout << nu_re << ' ' << de_re;

    return 0;
}