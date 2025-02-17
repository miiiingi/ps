#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    long long M;
    cin >> N >> M;
    vector<int> numList(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numList[i];
    }
    int left = 0;
    long long volumeCount = 0, maxVolume = 0;
    for (int right = 0; right < N; right++)
    {
        volumeCount += numList[right];
        if (volumeCount > M)
        {
            while (true)
            {
                volumeCount -= numList[left++];
                if (left >= N)
                {
                    break;
                }

                if (volumeCount <= M)
                {
                    maxVolume = max(maxVolume, volumeCount);
                    break;
                }
            }
        }
        else
        {
            maxVolume = max(maxVolume, volumeCount);
        }
    }
    cout << min(M, maxVolume);

    return 0;
}