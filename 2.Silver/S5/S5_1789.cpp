#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unsigned int Des_num;
    unsigned long long Sum_num;
    int i = 1;

    cin >> Des_num;

    while (-1){
        Sum_num = (i*i + i)/2;
        if(Sum_num > Des_num)
            break;
        i += 1;
    }

    cout << i-1;
    return 0;
}