#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    vector<string> patterns = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for (const string& pattern : patterns) {
        size_t pos;
        while ((pos = input.find(pattern)) != string::npos) {
            input.replace(pos, pattern.length(), "*");
        }
    }

    int count = input.length();
    cout << count << endl;

    return 0;
}
// find 함수를 사용한 문제 해결법