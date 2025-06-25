#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int find_card(const unordered_set<int>& cards, int number){
    return cards.find(number) != cards.end() ? 1 : 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num_input;
    cin >> num_input;
    unordered_set<int> number_cards;
    int tmp;
    for(int i = 0; i < num_input; i++){
        cin >> tmp;
        number_cards.insert(tmp);
    }
    cin >> num_input;
    vector<int> numbers(num_input);
    for(int j = 0; j < num_input; j++){
        cin >> tmp;
        numbers[j] = find_card(number_cards, tmp);
    }

    for(auto& n : numbers)
        cout << n << ' ';
    return 0;
}