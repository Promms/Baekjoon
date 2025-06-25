#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numbers;
    int base;

    cin >> numbers >> base;
    int digit = 0;
    long int power = 1; // base^0

    while(power <= numbers){
        //cout << power << ' ' << numbers << endl;
        digit++;
        power *= base;
    }
    //cout << "Digit : " << digit << endl;
    //cout << "Power : " << power << endl;

    vector<int> cont(digit);

    for(int i = 1; digit - i >= 0; i++){
        power = power / base;
        cont[i-1] = numbers / power;
        numbers -= power * cont[i-1];
       // cout << cont[i-1] << ' ' << numbers << endl;
    }


    for(int& c : cont){
        if(c >= 10 && c <=35)
            cout << static_cast<char>(c+55);
        else
            cout << c;
    }

    return 0;
}