#include <string>
#include <vector>
#include <map>

using namespace std;
/*
1. 전체 배열을 순회하면서 10개씩 끊어서 숫자를 센다.
2. 숫자를 세어서 주어진 조건과 맞는지 세고 그 경우 1을 더한다. 
*/

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i = 0; i < discount.size() - 10 + 1; i++){
        map<string, int>countMap;
        bool isRegister = true;
        vector<string> temp(discount.begin() + i, discount.begin() + i + 10);
        for(int j = 0; j < temp.size(); j++){
            countMap[temp[j]]++;
        }
        for(int k = 0; k < want.size(); k++){
            if(countMap[want[k]] != number[k]){
                isRegister = false;
                break;
            }
        }
        if(isRegister){
            answer++;
        }
    }
    return answer;
}