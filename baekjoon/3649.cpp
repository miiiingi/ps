#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main()
{
    int x;
    while (cin >> x)
    {
        x *= 10e6;
        int n;
        cin >> n;

        vector<int> lList(n);
        for (int i = 0; i < n; i++)
        {
            cin >> lList[i];
        }
        if (n < 2)
        {
            cout << "danger" << "\n";
            continue;
        }

        sort(lList.begin(), lList.end());
        vector<pii> answer;
        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = lList[left] + lList[right];
            if (sum == x)
            {
                answer.push_back(make_pair(lList[left], lList[right]));
                left++;
                right--;
            }
            else if (sum > x)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        sort(answer.begin(), answer.end(), [](const pii &a, const pii &b)
             { return abs(a.second - a.first) > abs(b.second - b.first); });

        if (answer.empty())
        {
            cout << "danger" << "\n";
        }
        else
        {
            cout << "yes" << " " << answer[0].first << " " << answer[0].second << "\n";
        }
    }

    return 0;
}