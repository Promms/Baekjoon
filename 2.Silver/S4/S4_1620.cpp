#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num_dex, num_input;
    string name;
    unordered_map<int,string> Poke_dex_name;
    unordered_map<string,int> Poke_dex_number;
    Poke_dex_name[0] = "Unknown";
    Poke_dex_number["Unknown"] = 0;

    cin >> num_dex >> num_input;
    for(int i = 1; i <= num_dex; i++){
        cin >> name;
        Poke_dex_name[i] = name;
        Poke_dex_number[name] = i;
    }

    // String으로 입력받은 후 숫자인지 판단한 후 숫자이면 숫자로 변환
    vector<string> inputs(num_input);
    string input;
    for(int i = 0; i < num_input; i++){
        cin >> input;
        inputs[i] = input;
    }

    for(int i = 0; i < num_input; i++){
        if(inputs[i][0] >= 48 && inputs[i][0] <= 57){
            // input이 숫자라면
            cout << Poke_dex_name[stoi(inputs[i])] << '\n';
        }else{
            cout << Poke_dex_number[inputs[i]] << '\n';
        }
    }

    return 0;
}