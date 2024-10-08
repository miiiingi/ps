#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, vector<string>> clothesMap;
    for(int i = 0; i < clothes.size(); i++){
        vector<string>cloth = clothes[i];
        clothesMap[cloth[1]].push_back(cloth[0]);
    }
    for(auto clothPair: clothesMap){
        answer *= (clothPair.second.size() + 1);
    }
    return answer - 1;
}