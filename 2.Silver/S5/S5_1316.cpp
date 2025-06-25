#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool isitSame(string& word){
    for(int i = 0; i < static_cast<int>(word.size()) - 1; i++){
        for(int j = i+1; j < static_cast<int>(word.size()); j++){
            if(word[i] == word[j]){
                if(word[i] != word[j-1])
                    return false; // 
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    vector<string> words(num);

    for(int i = 0; i < num; i++)
        cin >> words[i];
    int num_group = 0;


    for(int i = 0; i < static_cast<int>(words.size()); i++){
        if(static_cast<int>(words[i].size()) <= 2){
            num_group++;
        }else{
            if(isitSame(words[i]))
                num_group++;
        }
    }
    cout << num_group;

    return 0;
}