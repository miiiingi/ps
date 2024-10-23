#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    // 요청 시간 기준으로 정렬
    sort(jobs.begin(), jobs.end());
    
    // 최소 힙 (작업 시간을 기준으로 우선순위 큐)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int time = 0;        // 현재 시각
    int index = 0;       // jobs 배열의 인덱스
    int total_time = 0;  // 총 작업 소요 시간
    int num_jobs = jobs.size();

    while (index < num_jobs || !pq.empty()) {
        // 현재 시간(time) 이전에 요청된 작업을 모두 큐에 넣음
        while (index < num_jobs && jobs[index][0] <= time) {
            pq.push({jobs[index][1], jobs[index][0]});  // {작업 소요 시간, 요청 시간}
            index++;
        }

        if (!pq.empty()) {
            // 작업 시간이 가장 짧은 작업을 처리
            auto current = pq.top();
            pq.pop();

            time += current.first;  // 작업 소요 시간만큼 현재 시간 진행
            total_time += time - current.second;  // 요청부터 종료까지 걸린 시간

        } else {
            // 처리할 작업이 없으면 시간을 다음 작업의 요청 시간으로 맞춤
            time = jobs[index][0];
        }
    }

    return total_time / num_jobs;  // 평균 시간 (소수점 이하 버림)
}
