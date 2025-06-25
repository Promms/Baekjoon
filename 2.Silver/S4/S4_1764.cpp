#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int a_num, b_num;
    int ab_num = 0;
    cin >> a_num >> b_num;
    unordered_set<string> n_hear;
    string name;
    for(int i = 0; i < a_num; i++){
        cin >> name;
        n_hear.insert(name);
    }
    vector<string> n_hear_see;
    for(int j = 0; j < b_num; j++){
        cin >> name;
        if(n_hear.find(name) != n_hear.end()){
            ab_num++;
            n_hear_see.emplace_back(name);
        }
    }

    cout << ab_num << '\n';
    sort(n_hear_see.begin(), n_hear_see.end());
    for(auto& n : n_hear_see)
        cout << n << '\n';

    return 0;
}