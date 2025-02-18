#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> numList(N);
    vector<int> numCount(100001, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> numList[i];
    }
    int cnt = 0;
    int maxLength = 0;
    int left = 0;
    for (int right = 0; right < N; right++)
    {
        numCount[numList[right]]++;
        cnt++;
        if (numCount[numList[right]] > K)
        {
            maxLength = max(maxLength, cnt - 1);
            while (true)
            {
                numCount[numList[left++]]--;
                cnt--;
                if (numCount[numList[right]] <= K)
                {
                    break;
                }
            }
        }
    }
    cout << max(maxLength, cnt);

    return 0;
}