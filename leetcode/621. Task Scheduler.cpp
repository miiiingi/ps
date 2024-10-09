#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
/*
1. 왜 그리디하게 분류할 수 있는지는 솔직히 감이 잘 안온다. 
2. 일단 cpu 스케줄러의 개념을 조금 알고있다면 도움이 될 것 같은데, 태스크의 수가 많을수록 우선순위가 높아서 더 먼저 처리해야한다. 
3. 따라서 map을 이용해서 태스크의 수를 세어준다. 
4. 그리고 진짜 cpu가 일을 처리하는 방식처럼 순회를 하는데, 조금 놀란점은 cycle을 지정해서 유휴시간까지 고려해줄 수 있다는 것과 pq, temp로 따로 관리해서 cpu의 동작을 잘 구현해주었다는 것이다. 
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        
        // 1. 각 작업의 빈도수 카운트
        for (char task : tasks) {
            taskCount[task]++;
        }

        // 2. 최대 힙을 사용하여 가장 빈도수가 높은 작업부터 처리
        priority_queue<int> pq;
        for (auto& it : taskCount){
            cout << "taskCount.second: " << it.second << "\n";
            pq.push(it.second);
        }

        int intervals = 0;
        
        // 3. 작업이 남아 있는 동안 계속 처리
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;  // 한 사이클당 n + 1개의 작업 또는 유휴 시간을 처리 가능

            // 한 사이클 동안 n+1개의 작업을 최대한 처리
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    cout << "pq.top " << pq.top() << "\n";
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            cout << "pq.size(): " << pq.size() << " " << "temp.size()" << temp.size() << "\n";

            // 사이클이 끝나면 남은 작업이 있으면 다시 힙에 넣음
            for (int freq : temp) {
                if (--freq > 0) {
                    pq.push(freq);  // 아직 남은 작업이 있다면 다시 힙에 넣음
                }
            }

            // 한 사이클에서 모든 작업이 완료되었는지 확인
            if (!pq.empty()) {
                // 작업이 남아 있으면 n+1만큼 모두 처리해야 하므로 사이클 수만큼 더함
                intervals += cycle;
            } else {
                // 마지막 사이클에서 남은 작업이 없으면 temp.size()만큼만 더함
                intervals += temp.size();
            }
            cout << "intervals: " << intervals << "\n";
        }

        return intervals;
    }
};