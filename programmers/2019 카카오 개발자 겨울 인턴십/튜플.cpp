#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
/*
1. 일단 string을 하나씩 순회하면서 원소를 비교해서 넣어준다는 접근법은 맞았음. 하지만, 나는 처음에 set에 원소를 다 넣어줬었는데 그렇게 하니 순서를 고려하지 못했었다. 
2. 한편, 숫자가 쌓이는 순서는 무엇일까 ? 순서는 원소의 갯수대로 쌓이는 것을 알 수가 있다. 따라서 원소를 크기 순서대로 어떤 자료구조에 넣어줘야하는 것이다.
3. 원소의 크기 순서대로 vector에 넣어준 후, 순회하면서 이전에 등장하지 않았던 원소들을 answer에 넣어주면 된다.
4. stoi <-> to_string / isdigit() / is관련 함수들 잘 숙지하자. 
*/

string tempStr = "";
vector<vector<int>> strGroup;
vector<int> solution(string s) {
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            tempStr += s[i];
        } else if(s[i] == '}' || s[i] == ','){
            if(tempStr.empty()){
                continue;
            }
            strGroup.back().push_back(stoi(tempStr));
            tempStr = "";
        } else{
            strGroup.push_back(vector<int>());
        }
    }
    
    sort(strGroup.begin(), strGroup.end(), [](vector<int> a, vector<int> b){
        return a.size() < b.size();
    });
    
    set<int> used;
    vector<int> answer;
    for(int i = 0; i < strGroup.size(); i++){
        for(int j = 0; j < strGroup[i].size(); j++){
            if(find(used.begin(), used.end(), strGroup[i][j]) == used.end()){
                used.insert(strGroup[i][j]);
                answer.push_back(strGroup[i][j]);
            }
        }
    }
    return answer;
}