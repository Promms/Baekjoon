#include <iostream>
using namespace std;

const int num_input = 5;

void Swap(int* numbers, int pos){
    int tmp = numbers[pos];
    numbers[pos] = numbers[pos+1];
    numbers[pos+1] = tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int* numbers = new int[num_input];
    int sum = 0, middle = num_input / 2;

    for(int i = 0; i < num_input; i++){
        cin >> numbers[i];
        sum += numbers[i];
    }
    for(int i = 0; i < num_input - 1; i++){
        for(int j = 0; j < num_input - i - 1; j++){
            if(numbers[j] > numbers[j+1])   Swap(numbers, j);
        }
    }

    cout << sum / num_input << endl;
    cout << numbers[middle] << endl;
    
    delete[] numbers;
    return 0;
}