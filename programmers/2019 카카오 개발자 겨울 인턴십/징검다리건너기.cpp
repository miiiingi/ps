#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k)
{
    int minValue = *min_element(stones.begin(), stones.end());
    int maxValue = *max_element(stones.begin(), stones.end());
    int answer = 0;
    while (minValue <= maxValue)
    {
        int midValue = (minValue + maxValue) / 2, skipCount = 0;
        int maxSkipCount = 0;
        for (size_t i = 0; i < stones.size(); i++)
        {
            if (stones[i] - midValue < 0)
            {
                skipCount++;
            }
            else
            {
                skipCount = 0;
            }
            maxSkipCount = max(maxSkipCount, skipCount);
        }
        if (maxSkipCount < k)
        {
            answer = max(answer, midValue);
            minValue = midValue + 1;
        } else
        {
            maxValue = midValue - 1;
        }
    }
    return answer;
}

int main()
{
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    int answer = solution(stones, k);
    return 0;
}