#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Merge(vector<pair<int,string>>& arr, int left, int mid, int right){
    vector<pair<int,string>> left_arr(arr.begin()+left, arr.begin()+mid+1);
    vector<pair<int,string>> right_arr(arr.begin()+mid+1, arr.begin()+right+1);
    int count = left;
    auto iter1 = left_arr.begin();
    auto iter2 = right_arr.begin();

    while(iter1 != left_arr.end() && iter2 != right_arr.end()){
        if(iter1->first <= iter2->first){
            arr[count] = *iter1;
            iter1++; count++;
        }else{
            arr[count] = *iter2;
            iter2++; count++;
        }
    }
    while(iter1 != left_arr.end()){
        arr[count] = *iter1;
        iter1++; count++;
    }
    while(iter2 != right_arr.end()){
        arr[count] = *iter2;
        iter2++; count++;
    }
}

void Merge_Sort(vector<pair<int,string>>& arr, int left, int right){
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
    vector<pair<int,string>> users(num_input);
    for(int i = 0; i < num_input; i++)
        cin >> users[i].first >> users[i].second;
    Merge_Sort(users,0,num_input-1);

    for(auto& u : users)
        cout << u.first << ' ' << u.second << '\n';

    return 0;
}