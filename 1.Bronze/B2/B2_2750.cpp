#include <iostream>
using namespace std;

void Swap(int* numbers, int pos){
    int tmp = numbers[pos];
    numbers[pos] = numbers[pos+1];
    numbers[pos+1] = tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num_input;
    cin >> num_input;

    int* numbers = new int[num_input];
    for(int i = 0; i < num_input; i++)
        cin >> numbers[i];

    for(int i = 0; i < num_input - 1; i++){
        for(int j = 0; j < num_input - i - 1; j++){
            if(numbers[j] > numbers[j+1])   Swap(numbers, j);
        }
    }

    for(int i = 0; i < num_input; i++)
        cout << numbers[i] << endl;

    delete[] numbers;
    return 0;
}