#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> realLost;
    for(int i = 0; i < lost.size(); i++){
        int lostNumber = lost[i];
        if(find(reserve.begin(), reserve.end(), lostNumber) == reserve.end()){
            realLost.push_back(lost[i]);
        } else{
            reserve.erase(find(reserve.begin(), reserve.end(), lostNumber));
        }
    }
    sort(realLost.begin(), realLost.end());
    sort(reserve.begin(), reserve.end());
    int count = 0;
    for(int i = 0; i < realLost.size(); i++){
        int lostNumber = realLost[i];
        auto it = find_if(reserve.begin(), reserve.end(), [lostNumber](int r){
            return lostNumber - 1 == r || lostNumber + 1 == r;
        });
        if(it == reserve.end()){
            count++;
        } else{
            reserve.erase(it);
        }
    }
    return n - count;
}