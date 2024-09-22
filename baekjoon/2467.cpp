#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> fluids(N);
    vector<pair<int, int>> answer;
    for (int i = 0; i < N; i++)
    {
        cin >> fluids[i];
    }
    sort(fluids.begin(), fluids.end());
    int start = 0, end = N - 1;
    int leftmin = 0, rigthmin = 0;
    int minValue = 2000000001;
    while (start != end)
    {
        int sumValue = fluids[start] + fluids[end];
        if (minValue > abs(sumValue))
        {
            minValue = abs(sumValue);
            leftmin = fluids[start], rigthmin = fluids[end];
        }
        if (sumValue <= 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    cout << leftmin << " " << rigthmin;

    return 0;
}