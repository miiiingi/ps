#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define pii pair<int, int>

int main()
{
    int N;
    cin >> N;
    int C;
    cin >> C;
    deque<pair<int, pii>> count;
    for (int i = 0; i < C; i++)
    {
        int temp;
        cin >> temp;
        bool exist = false;
        for (size_t j = 0; j < count.size(); j++)
        {
            auto &c = count[j];
            if (c.first == temp)
            {
                c.second.first++;
                exist = true;
                break;
            }
        }
        if (!exist)
        {
            if (count.size() >= N)
            {
                int p = count.front().first;
                count.pop_front();
                count.push_back(make_pair(temp, make_pair(1, i)));
            }
            else
            {
                count.push_back(make_pair(temp, make_pair(1, i)));
            }
        }

        sort(count.begin(), count.end(), [](const pair<int, pii> &a, const pair<int, pii> &b) {
            if (a.second.first == b.second.first)
            {
                return a.second.second < b.second.second;
            }
            return a.second.first < b.second.first;
        });
    }

    sort(count.begin(), count.end(),
         [](const pair<int, pii> &a, const pair<int, pii> &b) { return a.first < b.first; });

    for (size_t i = 0; i < count.size(); i++)
    {
        cout << count[i].first << " ";
    }

    return 0;
}