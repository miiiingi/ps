#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    long long M;
    cin >> N >> M;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int left = 0;
    vector<long long> answer;
    for (int right = 0; right < N; right++)
    {
        long long diff = arr[right] - arr[left];
        if (diff < M)
        {
            continue;
        }
        else
        {
            answer.push_back(diff);
            while (true)
            {
                long long diff = arr[right] - arr[left];
                if (left >= N)
                {
                    break;
                }

                if (diff < M)
                {
                    break;
                }
                else
                {
                    left++;
                    answer.push_back(diff);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer[0];

    return 0;
}