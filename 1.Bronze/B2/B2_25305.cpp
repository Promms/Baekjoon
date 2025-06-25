#include <iostream>
using namespace std;

void Swap(int* scores, int pos){
    int tmp = scores[pos];
    scores[pos] = scores[pos+1];
    scores[pos+1] = tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_student, num_prize;
    cin >> num_student >> num_prize;
    int* scores = new int[num_student];

    for(int i = 0; i < num_student; i++)
        cin >> scores[i];

    for(int i = 0; i < num_student - 1; i++){
        for(int j = 0; j < num_student - i - 1; j++){
            if(scores[j] > scores[j+1])   Swap(scores, j);
        }
    }

    cout << scores[num_student-num_prize] << endl;
    delete[] scores;
    return 0;
}