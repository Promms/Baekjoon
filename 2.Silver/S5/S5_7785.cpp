#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num_input;
    string name, state;
    unordered_set<string> working;
    cin >> num_input;
    vector<string> remain_workers;

    for(int i = 0; i < num_input; i++){
        cin >> name >> state;
        if(state == "enter")
            working.insert(name);
        else
        working.erase(name);
    }

    for(const auto& name : working) 
        remain_workers.emplace_back(name);
    
    sort(remain_workers.begin(), remain_workers.end());

    auto iter1 = remain_workers.end();
    while(iter1 != remain_workers.begin()){
        iter1--;
        cout << *iter1 << '\n';
    }

    return 0;
}