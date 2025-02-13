#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int K;
    cin >> N >> K;
    vector<int> cats(N);
    vector<bool> visited(5001, false);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        cats[i] = temp;
    }
    sort(cats.begin(), cats.end());
    // for (int i = 0; i < N; i++)
    // {
    //     cout << cats[i] << " ";
    // }
    // cout << "\n";

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