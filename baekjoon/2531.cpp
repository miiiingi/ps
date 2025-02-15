#include <iostream>
#include <vector>

using namespace std;

int countSushiType(vector<int> &count)
{
    int result = 0;
    for (size_t i = 0; i < count.size(); i++)
    {
        if (count[i] != 0)
        {
            result++;
        }
    }

    return result;
}

int main()
{
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> count(d + 1, 0);
    vector<int> sushi(N);
    int left = 0, right = left + k - 1;
    for (int i = 0; i < N; i++)
    {
        cin >> sushi[i];
        if (left <= i && i <= right)
        {
            count[sushi[i]]++;
        }
    }
    count[c]++;
    int maxValue = countSushiType(count);
    for (int i = left + 1; i < N; i++)
    {
        right = (i + k - 1) % N;
        count[sushi[i - 1]]--;
        count[sushi[right]]++;
        maxValue = max(maxValue, countSushiType(count));
    }
    cout << maxValue;

    return 0;
}