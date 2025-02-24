#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> answer(N, -1);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    if (N == 1)
    {
        cout << -1;
        return 0;
    }
    int left = 0, right = 0;
    while (true)
    {
        if (left >= N)
        {
            break;
        }
        int ref = arr[left];
        while (ref == arr[right])
        {
            right++;
            if (right >= N)
            {
                break;
            }
        }
        if (right >= N)
        {
            break;
        }

        for (int i = left; i < right; i++)
        {
            answer[i] = right + 1;
        }
        left = right;
    }

    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}