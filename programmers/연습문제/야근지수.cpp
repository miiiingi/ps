#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    /*
    정답으로 더해주는 값이 기하급수이기 때문에 어떻게 하면 큰 수를 줄이면서 전체적으로 균일한 값을 만들 수 있을 것인가를 생각해봐야하는 것 같다.
    */
    priority_queue<int> queue;
    for (size_t i = 0; i < works.size(); i++)
    {
        queue.push(works[i]);
    }
    while (n--  && !queue.empty())
    {
        int qTop = queue.top();
        queue.pop();
        if (qTop > 0)
        {
            queue.push(qTop - 1);
        }
    }

    long long answer = 0;
    while (!queue.empty())
    {
        int qTop = queue.top();
        queue.pop();
        answer += qTop * qTop;
    }

    return answer;
}

int main()
{
    // int n = 4;
    // vector<int> works = {4, 3, 3};
    // int n = 1;
    // vector<int> works = {2, 1, 2};
    int n = 3;
    vector<int> works = {1, 1};
    long long answer = solution(n, works);
    cout << answer;
    return 0;
}