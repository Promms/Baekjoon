#include <iostream>
#include <string>
using namespace std;

int isCroatianAlphabet_c(const string& input, int position){
    if(input[position+1] == '=' or input[position+1] == '-')
        return 2;
    return 1;
}

int isCroatianAlphabet_d(const string& input, int position){
    if(input[position+1] == 'z'){
        if(input[position+2] == '=')
            return 3;
    }
    if(input[position+1] == '-')
        return 2;
    return 1;
}

int isCroatianAlphabet_l_n(const string& input, int position){
    if(input[position+1] == 'j')
        return 2;
    return 1;
}

int isCroatianAlphabet_s_z(const string& input, int position){
    if(input[position+1] == '=')
        return 2;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    int count = 0;

    for(int i = 0; i < static_cast<int>(input.size()); ){
        switch(input[i]){
            case 'c' : i += isCroatianAlphabet_c(input, i); break;
            case 'd' : i += isCroatianAlphabet_d(input, i); break;
            case 'l' : case 'n' : i += isCroatianAlphabet_l_n(input, i); break;
            case 's' : case 'z' : i += isCroatianAlphabet_s_z(input, i); break;
            default : i++; break;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}
// 크로아티아 알파벳과 일반 알파벳이 섞인 문자열을 입력받아 총 문자수를 출력
// https://www.acmicpc.net/problem/2941