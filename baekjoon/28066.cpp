#include <deque>
#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    deque<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    int base = 0;
    int cnt = 0;

    while (true)
    {
        if (N - cnt < K)
        {

            break;
        }

        int temp = arr.front();
        for (int i = 0; i < K; i++)
        {
            arr.pop_front();
            cnt++;
        }
        cnt--;

        arr.push_back(temp);
    }

    cout << arr[0];

    return 0;
}