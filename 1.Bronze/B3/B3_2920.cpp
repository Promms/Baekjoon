#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> ascending = {1,2,3,4,5,6,7,8};
    vector<int> descending = {8,7,6,5,4,3,2,1}; 
    vector<int> notes(8);

    for(int i = 0; i < 8; i++){
        cin >> notes[i];
    }

    if(notes == ascending)
        cout << "ascending\n";
    else if(notes == descending)
        cout << "descending\n";
    else
        cout << "mixed\n";

    return 0;
}