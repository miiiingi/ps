#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int elem;
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (size_t i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        while (k--)
        {
            elem = pq.top();
            pq.pop();
        }
        return elem;
    }
};