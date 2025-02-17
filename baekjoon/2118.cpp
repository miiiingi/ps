#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

int main()
{
    int N;
    cin >> N;
    vector<pii> distance;
    distance.push_back(make_pair(0, 0));
    long long totalDistance = 0;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        totalDistance += temp;
        distance.push_back(make_pair(i + 1, temp));
    }

    int left = 0;
    long long answer = 0;
    long long base = distance[left].second;
    for (int right = 1; right < N + 1; right++)
    {
        // cout << "==================================" << "\n";
        base += distance[right].second;
        long long comp = totalDistance - base;
        answer = max(answer, min(base, comp));
        // cout << "left: " << left << " right: " << right << "\n";
        // cout << "base: " << base << " comp: " << comp << " answer: " << answer << "\n";
        if (base < comp)
        {
            continue;
        }
        else
        {
            while (true)
            {
                base -= distance[left++].second;
                long long comp = totalDistance - base;
                answer = max(answer, min(base, comp));
                // cout << "left: " << left << " right: " << right << "\n";
                // cout << "base: " << base << " comp: " << comp << " answer: " << answer << "\n";
                if (base < comp)
                {
                    break;
                }
            }
        }
    }
    cout << answer;

    // 0 1 2 3 4 5
    // 1 14 / 3 12 / 5 10 / 6 9 / 10 5 / 9 6 / 7 8 / 12 3 / 9 6

    // 5 10 15
    // 5 25 / 10 20 / 15 15 

    return 0;
}