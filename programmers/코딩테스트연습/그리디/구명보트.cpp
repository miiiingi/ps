#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end());
    int start = 0, end = people.size() - 1, answer = 0;
    while (start <= end)
    {
        if (people[start] + people[end] <= limit)
        {
            start++;
        }
        end--;
        answer++;
    }
    return answer;
}