#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, C;
    cin >> N >> C;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (N == 1)
    {
        if (arr[0] == C)
        {
            cout << 1;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }

    int left = 0, right = N - 1;
    while (left < right)
    {
        if (arr[left] == C || arr[right] == C)
        {
            cout << 1;
            return 0;
        }

        int sum = arr[left] + arr[right];
        if (sum == C)
        {
            cout << 1;
            return 0;
        }
        else if (sum > C)
        {
            right--;
        }
        else
        {
            for (int i = left + 1; i < right; i++)
            {
                int temp = sum + arr[i];
                if (temp == C)
                {
                    cout << 1;
                    return 0;
                }
            }
            left++;
        }
    }

    cout << 0;
    return 0;
}