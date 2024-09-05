#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations)
{
    priority_queue<int> maxPQ;
    priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
    vector<int> answer;
    istringstream iss;
    string str;
    int number;
    int insertCnt = 0;

    for (size_t i = 0; i < operations.size(); i++)
    {
        iss = istringstream(operations[i]);
        iss >> str >> number;
        if (str == "I")
        {
            maxPQ.push(number);
            minPQ.push(number);
            insertCnt++;
        }
        else if (str == "D")
        {
            if (number == -1)
            {
                if (!minPQ.empty())
                {
                    minPQ.pop();
                    insertCnt--;
                }
            }
            else
            {
                if (!maxPQ.empty())
                {
                    maxPQ.pop();
                    insertCnt--;
                }
            }
        }
        if (insertCnt == 0)
        {
            while (!maxPQ.empty())
            {
                maxPQ.pop();
            }
            while (!minPQ.empty())
            {
                minPQ.pop();
            }
        }
    }
    if (insertCnt == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxPQ.top());
        answer.push_back(minPQ.top());
    }

    return answer;
}

int main()
{
    vector<int> answer2 = solution({"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"});
    for (size_t i = 0; i < answer2.size(); i++)
    {
        cout << answer2[i];
    }

    return 0;
}