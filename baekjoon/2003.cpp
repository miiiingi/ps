#include <iostream>
#include <vector>

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
    int start = 0, end = 0;
    long long sum = 0, cnt = 0;
    while (true)
    {
        if (sum >= M)
        {
            if (sum == M)
            {
                cnt++;
            }
            sum -= arr[start++];
            if (start > N)
            {
                break;
            }
        }
        else
        {
            sum += arr[end++];
            if (end > N)
            {
                break;
            }
        }
    }
    cout << cnt;

    return 0;
}