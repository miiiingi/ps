#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int red = 0, white = 0, blue = nums.size();

        while (white < blue)
        {
            if (nums[white] == 0)  
            {
                int temp = nums[red];
                nums[red] = nums[white];
                nums[white] = temp;
                white++;
                red++;
            }
            else if (nums[white] == 1)
            {
                white++;
            }
            else if (nums[white] == 2)
            {
                blue--;
                int temp = nums[blue];
                nums[blue] = nums[white];
                nums[white] = temp;
            }
        }
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> nums = {2, 0, 1, 1, 2, 0};
    sol.sortColors(nums);
    return 0;
}