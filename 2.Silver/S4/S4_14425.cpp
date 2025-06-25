#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

int find_card(const unordered_set<string>& standard_words, string word){
    return standard_words.find(word) != standard_words.end() ? 1 : 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num_words, num_input;
    cin >> num_words >> num_input;
    unordered_set<string> standard_words;
    string tmp;
    for(int i = 0; i < num_words; i++){
        cin >> tmp;
        standard_words.insert(tmp);
    }
    
    int Dupli_num = 0;
    for(int j = 0; j < num_input; j++){
        cin >> tmp;
        Dupli_num += find_card(standard_words, tmp);
    }

    cout << Dupli_num << '\n';

    return 0;
}