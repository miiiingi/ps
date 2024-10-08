#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<pii> q;
    for(int i = 0; i < priorities.size(); i++){
        pq.push(priorities[i]);
        q.push({i, priorities[i]});
    }
    int count = 0;
    while(!q.empty()){
        pii qTop = q.front();
        q.pop();
        if(qTop.second == pq.top()){
            pq.pop();
            count++;
            if(qTop.first == location){
                return count;
            }
        } else{
            q.push(qTop);
        }
    }
}