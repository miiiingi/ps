#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int wine[10005] = {0};
    int dp[10005] = {0};
    vector<int> comp;
    for (int i = 0; i < N; i++)
    {
        cin >> wine[i];
    }
    if (N == 1)
    {
        cout << wine[0];
    }
    else if (N == 2)
    {
        cout << wine[0] + wine[1];
    }
    else if (N == 3)
    {
        comp.push_back(wine[0] + wine[2]);
        comp.push_back(wine[1] + wine[2]);
        comp.push_back(wine[0] + wine[1]);
        cout << *max_element(comp.begin(), comp.end());
    }
    else
    {
        dp[0] = wine[0];
        dp[1] = wine[0] + wine[1];
        comp.push_back(wine[0] + wine[2]);
        comp.push_back(wine[1] + wine[2]);
        comp.push_back(wine[0] + wine[1]);
        dp[2] =  *max_element(comp.begin(), comp.end());
        comp.clear();
        for (int i = 3; i < N; i++)
        {
            comp.push_back(dp[i - 3] + wine[i - 1] + wine[i]);
            comp.push_back(dp[i - 2] + wine[i]);
            comp.push_back(dp[i - 1]);
            dp[i] = *max_element(comp.begin(), comp.end());
            comp.clear();
        }
        cout << dp[N - 1];
    }
    return 0;
}