#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<string> strNumber;
    string answer;
    string largestNumber(vector<int> &nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            strNumber.push_back(to_string(nums[i]));
        }
        sort(strNumber.begin(), strNumber.end(), [](string &a, string &b)
             {
                 return a + b > b + a; // 330이 303보다 더 앞에 올 수 있도록 두 수를 더한 후 비교
             });

        for (size_t i = 0; i < strNumber.size(); i++)
        {
            answer += strNumber[i];
        }
        if (answer[0] == '0')
        {
            return "0";
        }
        return answer;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> nums = {3, 30, 34, 5, 9};
    string answer = sol.largestNumber(nums);

    return 0;
}