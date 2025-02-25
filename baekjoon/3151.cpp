#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int sum = arr[i] + arr[j];
            answer +=
                upper_bound(arr.begin() + j + 1, arr.end(), -sum) - lower_bound(arr.begin() + j + 1, arr.end(), -sum);
        }
    }
    cout << answer;

    return 0;
}