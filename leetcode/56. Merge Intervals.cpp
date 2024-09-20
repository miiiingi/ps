#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] > b[1]; });
        for (size_t i = 0; i < intervals.size(); i++)
        {
            vector<int> interval = intervals[i];
            if (answer.empty() || answer.back()[0] > interval[1])
            {
                answer.push_back(interval);
            }
            else
            {
                if (answer.back()[0] > interval[0])
                {
                    answer.back()[0] = interval[0];
                }
            }
        }

        return answer;
    }
};

int main()
{
    Solution sol = Solution();
    vector<vector<int>> intervals = {{1, 4}, {2, 3}};
    // vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    vector<vector<int>> answer = sol.merge(intervals);

    return 0;
}