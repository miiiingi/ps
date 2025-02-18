#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main()
{
    int N;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    vector<pair<int, pii>> answer;
    int left = 0, right = N - 1;
    while (left < right)
    {
        long long diff = abs(arr[right] + arr[left]);
        if (diff > 0)
        {
            answer.push_back(make_pair(diff, make_pair(arr[left], arr[right])));
            long long diffL = abs(arr[right] + arr[left + 1]);
            long long diffR = abs(arr[right - 1] + arr[left]);
            if (diffL < diffR)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        else
        {
            cout << arr[left] << " " << arr[right];
            return 0;
        }
    }

    sort(answer.begin(), answer.end(), [](const pair<int, pii> &a, const pair<int, pii> &b)
         { return a.first < b.first; });
    cout << answer[0].second.first << " " << answer[0].second.second;

    return 0;
}