#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    int answer = 0;
    while(pq.top() < K){
        if(pq.size() == 1){
            return -1;
        }
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int mixed = first + (second * 2);
        pq.push(mixed);
        answer++;
    }
    return answer;

}