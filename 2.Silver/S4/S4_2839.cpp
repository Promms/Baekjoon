#include <iostream>
using namespace std;

int calculate_min_bag(int target){
    int number = 0, count_five = 0, count_three = 0;

    while(number < target){
        number += 5;
        count_five++;
    }

    if(number == target)
    return count_five + count_three;

    while(number != target){
        if(number > target){
            number -= 5;
            count_five--;
        }
        if(count_five < 0) return -1;
        number += 3;
        count_three++;
    }

    return count_five + count_three;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int target, result;
    cin >> target;

    result = calculate_min_bag(target);
    cout << result << endl;

    return 0;
}