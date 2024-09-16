#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    /*
    나눠야하는 경우의 수가 여러 개인 경우 어떻게 할 것인가 ?
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
    cout << answer;

    return 0;
}