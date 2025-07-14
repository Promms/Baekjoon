#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

string older_than(int birth1[3] , string name1, int birth2[3], string name2, int kin){
    if(birth1[kin] < birth2[kin]){
        return name1;
    }else if(birth1[kin] == birth2[kin])
        return older_than(birth1, name1, birth2, name2, kin-1);
    else{
        return name2;
    }
}

string younger_than(int birth1[3] , string name1, int birth2[3], string name2, int kin){
    if(birth1[kin] > birth2[kin]){
        return name1;
    }else if(birth1[kin] == birth2[kin])
        return younger_than(birth1, name1, birth2, name2, kin-1);
    else{
        return name2;
    }
}

int main() {
    int num_student;
    string name, old_name, young_name;
    int birth[3], young_birth[3] = {12,31,1989}, old_birth[3]={1,1,2011};

    cin >> num_student;

    while (num_student--){
        cin >> name >> birth[0] >> birth[1] >> birth[2];
        old_name = older_than(birth, name, old_birth, old_name, 2);
        young_name = younger_than(birth, name, young_birth, young_name, 2);
        if(name == old_name){
            memcpy(&old_birth, &birth, sizeof(birth));
        }if(name == young_name){
            memcpy(&young_birth, &birth, sizeof(birth));
        }
    }

    cout << young_name << endl << old_name << endl;

    return 0;
}