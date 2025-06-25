#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int size_set_a, size_set_b;
    cin >> size_set_a >> size_set_b;
    unordered_set<int> set_a, set_b;

    int number;
    for(int i = 0; i < size_set_a; i++){
        cin >> number;
        set_a.insert(number);
    }
    for(int i = 0; i < size_set_b; i++){
        cin >> number;
        set_b.insert(number);
    }

    vector<int> to_remove;
    for(auto& n : set_b){
        if(set_a.find(n) != set_a.end()){
            set_a.erase(set_a.find(n));
            to_remove.emplace_back(n);
        }
    }
    // set_a에서 n요소를 삭제할 때 set_b의 요소도 함께 삭제하면 반복자 무효화 문제가 발생할 가능성이 생김
    // 따라서 삭제할 요소들을 저장했다가 나중에 따로 삭제해주는 것이 안전하다
    for(auto& n : to_remove)
        set_b.erase(set_b.find(n));

    size_set_a = static_cast<int>(set_a.size());
    size_set_b = static_cast<int>(set_b.size());

    cout << size_set_a + size_set_b << '\n';
    return 0;
}