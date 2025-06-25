#include <iostream>
#include <vector>
using namespace std;

const int quarter = 25;
const int dime = 10;
const int nickel = 5;

void how_many_coins(vector<int>& coins, int cent){
    coins[0] = cent / quarter;
    cent -= coins[0] * quarter;
    coins[1] = cent / dime;
    cent -= coins[1] * dime;
    coins[2] = cent / nickel;
    cent -= coins[2] * nickel;
    coins[3] = cent;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_customer, cent;
    cin >> num_customer;
    vector<vector<int>> coins(num_customer, vector<int>(4,0));

    for(int i = 0; i < num_customer; i++){
        cin >> cent;
        how_many_coins(coins[i], cent);
    }

    for(int i = 0; i < num_customer; i++){
        for(auto n : coins[i])
            cout << n << ' ';
        cout << '\n';
    }

    return 0;
}
// 잔돈을 가장 적게 주는 방법을 계산하는 법
// https://www.acmicpc.net/problem/2720