#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> numList(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numList[i] = temp;
    }
    long long k;
    cin >> k;
    int start = 0, end = 0;
    long long sum = 0, cnt = 0;
    while (true)
    {
        if (sum <= k)
        {
            sum += numList[end++];
            if (end > n)
            {
                break;
            }
        }
        else
        {

            cnt += n - end + 1;
            sum -= numList[start++];
            if (start > n)
            {
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}