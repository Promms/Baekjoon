#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void Merge(vector<int>&arr, int left, int mid, int right){
    vector<int> arr_left(arr.begin()+left, arr.begin()+mid+1);
    vector<int> arr_right(arr.begin()+mid+1, arr.begin()+right+1);
    int count = left;
    auto iter1 = arr_left.begin();
    auto iter2 = arr_right.begin();

    while(iter1 != arr_left.end() && iter2 != arr_right.end()){
        if(*iter1 <= *iter2){
            arr[count] = *iter1;
            iter1++; count++;
        }else{
            arr[count] = *iter2;
            iter2++; count++;
        }
    }
    while(iter1 != arr_left.end()){
        arr[count] = *iter1;
        iter1++; count++;
    }
    while(iter2 != arr_right.end()){
        arr[count] = *iter2;
        iter2++; count++;
    }
}

void Merge_Sort(vector<int>& arr, int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);
        Merge(arr,left,mid,right);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_input;
    cin >> num_input;
    vector<int> xpos(num_input);
    for(int i = 0; i < num_input; i++)
        cin >> xpos[i];
    
    vector<int> sorted_xpos(xpos.begin(),xpos.end()); // 최종 출력 때 원본 배열이 필요해서 사본을 만듦
    Merge_Sort(sorted_xpos,0,num_input-1);            // 사본 배열을 오름차순 정렬
    sorted_xpos.erase(unique(sorted_xpos.begin(), sorted_xpos.end()), sorted_xpos.end());// 사본 배열에서 중복을 제거하여 사본 배열의 정렬 위치가 압축 좌표가 됨

    unordered_map<int,int> compression_map;
    for(int i = 0; i < static_cast<int>(sorted_xpos.size()); i++){
        compression_map[sorted_xpos[i]] = i;
    }

    for(auto& n : xpos)
        cout << compression_map[n] << ' '; // 압축 좌표를 찾아서 출력

    return 0;
}