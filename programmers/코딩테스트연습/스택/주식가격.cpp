#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int base;
    for(int i = 0; i < prices.size(); i++){
        base = 0;
        for(int j = i + 1; j < prices.size(); j++){
            base++;
            if(prices[i] > prices[j]){
                break;
            }
        }
        answer.push_back(base);
    }
    return answer;
}