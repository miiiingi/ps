#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int, int>

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int left = 0, right = N - 1;
    vector<pii> answerList;
    while (left < right)
    {
        int sum = abs(arr[left] + arr[right]);
        answerList.push_back(make_pair(arr[left], arr[right]));
        if (sum == 0)
        {
            cout << 0;
            return 0;
        }
        else
        {
            int lSum = abs(arr[left + 1] + arr[right]);
            int rSum = abs(arr[left] + arr[right - 1]);
            if (lSum < rSum)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    sort(answerList.begin(), answerList.end(), [](const pii &a, const pii &b)
         { return abs(a.first + a.second) < abs(b.first + b.second); });

    cout << answerList[0].first + answerList[0].second;

    return 0;
}