#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> strMap;
    for(int i = 0; i < participant.size(); i++){
        if(strMap.find(participant[i]) == strMap.end()){
            strMap[participant[i]] = 1;
        } else {
            strMap[participant[i]]++;
        }
    }
    string answer = "";
    for(int i = 0; i < completion.size(); i++){
        strMap[completion[i]]--;
    }
    for(int i = 0; i < participant.size(); i++){
        if(strMap[participant[i]] > 0){
            answer = participant[i];
        }
    }
    return answer;
}

int main(){
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    string answer = solution(participant, completion);
    cout << answer;
    return 0;
}