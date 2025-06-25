#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_cards, num_check;
    cin >> num_cards;
    unordered_map<int,int> pack_of_cards;

    int number;
    for(int i = 0; i < num_cards; i++){
        cin >> number;
        if(pack_of_cards.find(number) == pack_of_cards.end()){
            pack_of_cards[number] = 0;
        } // 처음 나오는 카드면 등장횟수를 0으로 설정
        pack_of_cards[number]++; 
    }

    cin >> num_check;
    vector<int> store(num_check);
    for(int i = 0; i < num_check; i++){
        cin >> number;
        store[i] = pack_of_cards[number];
    }

    for(auto& n : store)
        cout << n << ' ';

    return 0;
}