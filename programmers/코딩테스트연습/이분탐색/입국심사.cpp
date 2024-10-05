#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    /*
    1. count == n 인 경우 나누기 -> 계속 탐색을 계속해야하니까 멈추는 것은 맞지 않다. 따라서 count > n인 경우와 통합
    2. answer = min(answer, mid)와 같이 적으면, 계속 탐색하는 과정에서 이전의 최솟값이 남아서 answer가 변하지 않을 가능성이 있으므로 answer = mid로 적어서 탐색이 끝났을 때의 값을 넣어주는 것이 맞다.
    */
    long long maxTime = *max_element(times.begin(), times.end());
    long long start = 1, end = maxTime * n;
    long long answer = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long count = 0;
        for (size_t i = 0; i < times.size(); i++)
        {
            count += ((long long)mid / times[i]);
        }
        if (count >= n)
        {
            answer = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return answer;
}

int main()
{
    long long answer = solution(6, {7, 10});

    return 0;
}