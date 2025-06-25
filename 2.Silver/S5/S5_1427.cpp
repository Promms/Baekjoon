#include <iostream>
#include <vector>
using namespace std;

void Insertion_Sort_reverse(vector<int>& arr, int length){
    int key;
    for(int i = 1; i < length; i++){
        key = arr[i];
        int j = i - 1;
        while(j >= 0 && key > arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

vector<int> decompose_Num(int number){
    vector<int> Decomposed;
    while(number > 0){
        Decomposed.emplace_back(number % 10);
        number /= 10;
    }
    return Decomposed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_input;
    cin >> num_input;
    vector<int> numbers = decompose_Num(num_input);
    Insertion_Sort_reverse(numbers, numbers.size());

    for(auto& n : numbers){
        cout << n;
    }
    return 0;
}
