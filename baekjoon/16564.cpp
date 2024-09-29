#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> X(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    int minNumber = *min_element(X.begin(), X.end());
    int maxNumber = *max_element(X.begin(), X.end());
    int answer = 0;
    while (minNumber <= maxNumber)
    {
        long long diff = 0;
        int mid = (minNumber + maxNumber) / 2;
        for (size_t i = 0; i < n; i++)
        {
            if (X[i] < mid)
            {
                diff += (mid - X[i]);
            }
        }
        if (diff <= k)
        {
            answer = max(answer, mid);
            minNumber = mid + 1;
        }
        else
        {
            maxNumber = mid - 1;
        }
    }
    cout << answer;
    return 0;
}