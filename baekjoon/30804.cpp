#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    deque<int> fruits;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        fruits.push_back(temp);
    }
    int left = 0;
    int maxValue = 0;
    int distinct = 0;

    vector<int> fruitsCount(10, 0);
    for (int start = 0; start < N; start++)
    {
        if (++fruitsCount[fruits[start]] == 1)
        {
            distinct++;
        }
        while (distinct > 2)
        {
            if (--fruitsCount[fruits[left]] == 0)
            {
                distinct--;
            }
            left++;
        }

        maxValue = max(maxValue, start - left + 1);
    }

    cout << maxValue;

    return 0;
}