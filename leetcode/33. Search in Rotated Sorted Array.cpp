#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int binarySearch(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (target < nums[mid])
            {
                end = mid - 1;
            }
            else if (target > nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    };

    int search(vector<int> &nums, int target)
    {
        int pivot;
        if (nums.size() == 1)
        {
            pivot = 0;
        }
        else
        {
            for (size_t i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] > nums[i + 1])
                {
                    pivot = i;
                    break;
                }
            }
        }
        int leftPivot = binarySearch(nums, 0, pivot, target);
        int rightPivot = binarySearch(nums, pivot + 1, nums.size() - 1, target);
        if (leftPivot == -1 && rightPivot == -1)
        {
            return -1;
        }
        else
        {
            return max(leftPivot, rightPivot);
        }
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums = {1};
    sol.search(nums, 0);
    return 0;
}