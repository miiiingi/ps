#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == S)
        {
            cout << 1;
            return 0;
        }
    }
    int left = 0, right = 1;
    int minLength = 10e4;
    int sum = arr[left] + arr[right];
    while (left <= right)
    {
        if (left >= N || right >= N)
        {
            break;
        }

        if (sum < S)
        {
            sum += arr[++right];
        }
        else
        {
            minLength = min(minLength, right - left + 1);
            sum -= arr[left++];
        }
    }
    if (minLength == 10e4)
    {
        cout << 0;
    }
    else
    {
        cout << minLength;
    }

    return 0;
}