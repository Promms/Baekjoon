#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Swap(int* front, int* back){
    int tmp = *front;
    *front = *back;
    *back = tmp;
}

int Partition(int* scores, int left, int right){
    int point = (rand() % (right - left + 1)) + left;
    int pivot = scores[point];
    int tmp = scores[right]; scores[right] = pivot; scores[point] = tmp; // 피봇을 배열의 마지막으로 옮겨줌
    int i = left - 1; // 시작은 피봇보다 작은 수가 없다고 생각하고 시작

    for(int k = left; k < right; k++){
        if(scores[k] <= pivot){
            i++; // 피봇보다 작은 수 +1
            Swap(&scores[i],&scores[k]); // 피봇보다 작은 수를 한 쪽으로 모음
        }
    }
    Swap(&scores[i+1],&scores[right]); // 피봇보다 작은 수들을 scores[i]까지 모았으니 그 다음 위치에 피봇을 둔다
    return i + 1; // 피봇의 위치를 리턴
}
void Quick_Sort(int* numbers, int left, int right){
    if(left < right){
        int point_pivot = Partition(numbers, left, right);
        Quick_Sort(numbers,left,point_pivot- 1); // 피봇보다 작은 부분을 정렬
        Quick_Sort(numbers,point_pivot+1,right); // 피봇보다 큰 부분을 정렬
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));

    int num_input;
    cin >> num_input;
    int* numbers = new int[num_input];

    for(int i = 0; i < num_input; i++)
        cin >> numbers[i];

    Quick_Sort(numbers,0,num_input-1);

    for(int i = 0; i < num_input; i++)
        cout << numbers[i] << '\n';

    delete[] numbers;
    return 0;
}