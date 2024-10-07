#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int answer = 0;
        for (size_t i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i + 1])
            {
                answer += (prices[i + 1] - prices[i]);
            }
        }
        return answer;
    }
};