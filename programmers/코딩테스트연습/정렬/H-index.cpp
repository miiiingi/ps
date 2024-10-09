#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    if(citations.size() == 1){
        return 1;
    } else {
        sort(citations.begin(), citations.end());
        int answer = 0;
        int cSize = citations.size();
        for(int j = 0; j < cSize; j++){
            int h = citations[j];
            int count = cSize - j;
            if(count <= h){
                answer = count;
                break;
            }
        }
        return answer;
    }
}