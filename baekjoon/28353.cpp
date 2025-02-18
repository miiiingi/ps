#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> cats(N);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        cats[i] = temp;
    }
    sort(cats.begin(), cats.end());
    int cnt = 0, left = 0, right = N - 1;
    while (left < right)
    {
        if (cats[left] + cats[right] > K)
        {
            right--;
        }
        else
        {
            cnt++;
            right--;
            left++;
        }
    }

    cout << cnt;

    return 0;
}