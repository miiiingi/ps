#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N <= 2)
    {
        cout << 0;
        return 0;
    }

    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int good = 0;

    for (int i = 0; i < N; i++)
    {
        long long target = arr[i];
        vector<long long> temp = arr;
        temp.erase(temp.begin() + i);
        int start = 0, end = temp.size() - 1;
        while (start < end)
        {

            long long sum = temp[start] + temp[end];
            if (sum > target)
            {
                end--;
            }
            else if (sum < target)
            {
                start++;
            }
            else
            {
                good++;
                break;
            }
        }
    }

    cout << good;

    return 0;
}