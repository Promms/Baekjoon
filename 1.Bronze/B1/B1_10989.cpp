#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000;

void Cout_Counts(const vector<int>& counts, int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < counts[i]; j++){
            cout << i << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_input;
    cin >> num_input;
    vector<int> numbers(MAX+1,0);
    int input;

    for(int i = 0; i < num_input; i++){
        cin >> input;
        numbers[input]++;
    }

    Cout_Counts(numbers, MAX+1);
    return 0;
}
