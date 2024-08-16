#include <iostream>
#include <set>
#include <deque>
#include <map>
#include <vector>

using namespace std;

int main()
{
    // initialize
    int N, M, A, B;
    cin >> N >> M;
    vector<int> answer(N + 1, 0);
    vector<int> needPrerequisite(N + 1, 0);
    map<int, vector<int>> courses;
    deque<int> queue;
    for (size_t i = 0; i < M; i++)
    {
        cin >> A >> B;
        courses[A].push_back(B);
        needPrerequisite[B]++;
    }
    for (size_t i = 1; i <= N; i++)
    {
        if (needPrerequisite[i] == 0)
        {
            queue.push_back(i);
            answer[i] = 1;
        }
    }

    while (!queue.empty())
    {
        int qPop = queue.front();
        queue.pop_front();
        for (auto elem : courses[qPop])
        {
            answer[elem] = max(answer[qPop] + 1, answer[elem]);
            needPrerequisite[elem]--;
            if (needPrerequisite[elem] == 0)
            {
                queue.push_back(elem);
            }
        }
    }
    for (size_t i = 1; i <= N; i++)
    {
        if (i != N)
        {
            cout << answer[i] << " ";
        }
        else
        {
            cout << answer[i];
        }
    }
    return 0;
}