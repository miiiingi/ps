#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    istringstream iss;
    string str;
    int number;
    multiset<int> ms;

    for (size_t i = 0; i < operations.size(); i++)
    {
        iss = istringstream(operations[i]);
        iss >> str >> number;
        if (str == "I")
        {
            ms.insert(number);
        }
        else if (str == "D")
        {
            if (!ms.empty())
            {
                if (number == 1)
                {
                    ms.erase(--ms.end());
                }
                else if (number == -1)
                {
                    ms.erase(ms.begin());
                }
            }
        }
    }
    if (ms.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*--ms.end());
        answer.push_back(*ms.begin());
    }
    return answer;
}