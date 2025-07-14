#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    string input;
    vector<char> container;
    unordered_set<string> part_string;
    cin >> input;
    int length = input.size();
    for(char& n : input){
        container.emplace_back(n);
    }

    string tmp = "";
    for(int i = 0; i < length; i++){
        for(int j = i; j < length; j++){
            tmp += container[j];
            part_string.insert(tmp);
        }
        tmp = "";
    }

    cout << part_string.size();
    
    return 0;
}