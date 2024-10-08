#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> strNumbers(numbers.size());
    for(int i = 0; i< numbers.size(); i++){
        strNumbers[i] = to_string(numbers[i]);
    }
    
    sort(strNumbers.begin(), strNumbers.end(), [](string a, string b){
        return a+b > b+a;
    });
    string answer = "";
    for(int i = 0; i< strNumbers.size(); i++){
        answer += strNumbers[i];
    }
    if(answer[0] == '0'){
        return "0";
    }
    return answer;
}