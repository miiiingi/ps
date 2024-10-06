#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int>temp(speeds.size());
    for(int i = 0; i < speeds.size(); i++){
        int residual = 100 - progresses[i];
        int elem;
        if(residual % speeds[i] != 0){
            elem = (residual / speeds[i]) + 1;
        } else {
            elem = (residual / speeds[i]);
        }
        temp[i] = elem;
    }
    int maxValue = temp[0], count = 1;
    vector<int> answer;
    for(int i = 1; i < temp.size(); i++){
        if(temp[i] > maxValue){
            answer.push_back(count);
            maxValue = temp[i];
            count = 1;
        } else {
            count++;
        }
        if(i == temp.size() - 1){
            answer.push_back(count);
        }
        
    }
    return answer;
}