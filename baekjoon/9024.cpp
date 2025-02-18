#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    std::ios::sync_with_stdio(false);
    for (int i = 0; i < t; i++)
    {
        int n, K;
        cin >> n >> K;
        vector<int> arr(n);
        for (int k = 0; k < n; k++)
        {
            cin >> arr[k];
        }
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        int minValue = 2 * 10e7;
        vector<int> answerList;
        while (left < right)
        {
            int diff = arr[left] + arr[right] - K;
            if (diff == 0)
            {
                left++;
                right--;
            }
            else if (diff > 0)
            {
                right--;
            }
            else
            {
                left++;
            }
            minValue = min(minValue, abs(diff));
            answerList.push_back(abs(diff));
        }
        int cnt = 0;
        for (size_t j = 0; j < answerList.size(); j++)
        {
            if (answerList[j] == minValue)
            {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}