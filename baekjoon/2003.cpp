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
        // cout << "=====================" << "\n";
        // cout << "pre sum : " << sum << "\n";
        // cout << "pre start: " << start << " pre end: " << end << "\n";
        if (sum >= M)
        {
            if (sum == M)
            {
                cnt++;
                // cout << "cnt: " << cnt << "\n";
            }
            sum -= arr[start++];
            if (start > N)
            {
                break;
            }

            // cout << "match post sum : " << sum << "\n";
            // cout << "match post start: " << start << " post end: " << end << "\n";
        }
        else
        {
            sum += arr[end++];
            if (end > N)
            {
                break;
            }

            // cout << "post sum : " << sum << "\n";
            // cout << "post start: " << start << " post end: " << end << "\n";
        }
    }
    cout << cnt;

    return 0;
}