#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int num_subject = 20;

double ScoretoInt(const string& score){
    if(score == "A+")   return 4.5;
    else if(score == "A0")  return 4.0;
    else if(score == "B+")  return 3.5;
    else if(score == "B0")  return 3.0;
    else if(score == "C+")  return 2.5;
    else if(score == "C0")  return 2.0;
    else if(score == "D+")  return 1.5;
    else if(score == "D0")  return 1.0;
    else return 0.0;
} // string은 switch-case가 불가능

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<double,string>> scores(num_subject);
    string trash_info;

    for(int i = 0; i < num_subject; i++){
        cin >> trash_info >> scores[i].first >> scores[i].second;
    }

    double Sum_scores = 0;
    double not_pf_lecture = 0;

    for(int j = 0; j < num_subject; j++){
        if(scores[j].second != "P"){
            not_pf_lecture += scores[j].first;
            Sum_scores += ScoretoInt(scores[j].second) * scores[j].first;
        }
    }

    cout << Sum_scores / not_pf_lecture;
    return 0;
}

/*
#include <unordered_map>

unordered_map<string, double> score_map = {
    {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0},
    {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0},
    {"F", 0.0}
}; -> unordered_map은 고유한 키와 값의 쌍으로 구성
    - score_map.count(score)은 unordered_map에 score 키가 있으면 1 없으면 0
    - score_map[score]은 score키와 쌍인 값을 반환한다.
*/