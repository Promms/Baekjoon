#include <iostream>
#include <vector>
using namespace std;

void Merge_second(vector<pair<int,int>>& arr, int left, int middle, int right){
    vector<pair<int,int>> arr1(arr.begin() + left, arr.begin()+middle+1); // left ~ mid까지 복사
    vector<pair<int,int>> arr2(arr.begin()+middle+1, arr.begin()+right+1); // mid+1 ~ right까지 복사
    auto iter1 = arr1.begin(); // arr1의 시작점을 가리키는 반복자
    auto iter2 = arr2.begin(); // arr2의 시작점을 가리키는 반복자

    int count = left; // 정렬의 시작이 되는 부분인 arr의 가장 left 부분
    while(iter1 != arr1.end() && iter2 != arr2.end()){ // 반복자가 end지점까지 도달하면 반복문 탈출
        if((*iter1).first < (*iter2).first){ // 만약 arr1의 요소가 더 작다면
            arr[count] = *iter1; // arr에 arr1의 요소를 배열
            iter1++;    count++; // 그 후 arr1의 반복자를 한 칸 뒤로 이동
        }else if((*iter1).first > (*iter2).first){
            arr[count] = *iter2;
            iter2++;    count++;
        }else{                     // 만약 arr1의 요소와 arr2의 요소의 크기가 같다면 -> (x,y)좌표
            if((*iter1).second < (*iter2).second){ // y 좌표의 크기까지 비교해서 배열열
                arr[count] = *iter1;
                iter1++;    count++;
            }else{
                arr[count] = *iter2;
                iter2++;    count++;
            }
        }
    }

    while(iter1 != arr1.end()){ // 만약 arr2의 반복자가 end에 도달했다면
        arr[count] = *iter1;    // 남은 arr1의 요소들을 정렬해준다
        iter1++;    count++;
    }
    while(iter2 != arr2.end()){ // 만약 arr1의 반복자가 end에 도달했다면
        arr[count] =  *iter2;   // 남은 arr2의 요소들을 정렬해준다
        iter2++;    count++;
    }
}

void Merge_Sort_second(vector<pair<int,int>>& arr, int left, int right){
    if(left < right){ // 더 이상 분할할 수 없으면 함수에서 탈출출
        int mid = (left + right)/2;
        Merge_Sort_second(arr,left,mid); // left ~ mid까지로 분할
        Merge_Sort_second(arr,mid+1,right); // mid + 1 ~ right까지로 분할
        Merge_second(arr,left,mid,right);
    }
}

int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    int num_input;
    cin >> num_input;
    vector<pair<int,int>> Coordinates(num_input);

    for(int i = 0; i < num_input; i++)
        cin >> Coordinates[i].first >> Coordinates[i].second;

    Merge_Sort_second(Coordinates,0,num_input-1);

    for(auto p : Coordinates)
        cout << p.first << ' ' << p.second << '\n';
    
    return 0;
}
// (x,y)좌표를 x오름차순으로 정렬하고 x좌표가 같은 것 끼리는 y좌표를 오름차순으로 정리하는 알고리즘
// https://www.acmicpc.net/problem/11650