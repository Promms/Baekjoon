#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 길이가 같은 두 단어를 사전 순으로 알려주는 함수수
int Dictionary_Sort(string arr1, string arr2){
    int length = arr1.size();
    for(int i = 0; i < length; i++){
        if(arr1[i] < arr2[i]) // arr1의 글자가 더 알파벳 앞 글자 (소문자일때만 가능능)
            return 1;
        else if(arr1[i] > arr2[i]) // arr2의 글자가 더 알파벳 앞 글자 (소문자일때만 가능능)
            return 2;
    }
    return 2; // 두 단어가 같다면 그냥 중복되서 정렬되게 한 후에 제거거
}

void Merge(vector<pair<string,int>>& arr, int left, int mid, int right){
    vector<pair<string,int>> arr1(arr.begin()+left,arr.begin()+mid+1);
    vector<pair<string,int>> arr2(arr.begin()+mid+1,arr.begin()+right+1);

    auto iter1 = arr1.begin();
    auto iter2 = arr2.begin();
    int count = left;

    while(iter1 != arr1.end() && iter2 != arr2.end()){
        if(iter1->second < iter2->second){ // arr1의 길이가 더 짧으면
            arr[count] = *iter1;
            iter1++;    count++;
        }else if(iter1->second > iter2->second){ // arr2의 길이가 더 짧으면
            arr[count] = *iter2;
            iter2++;    count++;
        }else{ // arr의 길이가 같다면면
            int dic = Dictionary_Sort(iter1->first, iter2->first); 
            switch(dic){
                case 1 : arr[count] = *iter1; iter1++; count++; break;
                default : arr[count] = *iter2; iter2++; count++; break;
            }
        }
    }
    while(iter1 != arr1.end()){
        arr[count] = *iter1;
        iter1++;    count++;
    }
    while(iter2 != arr2.end()){
        arr[count] = *iter2;
        iter2++;  count++;
    }
}

void Merge_Sort(vector<pair<string,int>>& arr, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}
// 중복된 단어를 지우기 위한 함수수
void Remove_Du(vector<pair<string,int>>& arr){
    string before = arr[0].first;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i].first == before){ // 이전 단어와 같다면
            arr.erase(arr.begin() + i); // 이번 단어를 지움
            i--; // 이번 단어를 지움으로써 다시 커서를 한 칸 뒤로 이동
        }
        before = arr[i].first; // 이전 단어를 재설정.
    }
}

int main() {
    ios_base::sync_with_stdio(false); // 실행시간을 빨라지게 해줌
    cin.tie(NULL); cout.tie(NULL); // but, printf 같은 C의 입출력문 사용 금지

    int num_input;
    cin >> num_input;
    vector<pair<string,int>> words(num_input);

    for(int i = 0; i < num_input; i++){
        cin >> words[i].first;
        words[i].second = (words[i].first).size();
    }

    Merge_Sort(words,0,num_input-1);
    Remove_Du(words);

    for(auto& w : words){
        cout << w.first << '\n';
    }

    return 0;
}