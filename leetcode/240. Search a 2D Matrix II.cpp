#include <vector>

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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int pivot = matrix.size();
        for (size_t i = 0; i < matrix.size(); i++)
        {
            if (target < matrix[i][0])
            {
                pivot = i;
                break;
            }
            else if (target == matrix[i][0])
            {
                return true;
            }
        }
        for (size_t i = 0; i < pivot; i++)
        {
            if (binarySearch(matrix[i], 0, matrix[i].size() - 1, target) != -1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol = Solution();
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    sol.searchMatrix(matrix, 5);
    return 0;
}