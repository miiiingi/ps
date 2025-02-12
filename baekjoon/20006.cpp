#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define pii pair<int, string>

using namespace std;

int main()
{
    int p, m;
    cin >> p >> m;
    map<int, vector<pii>> room;
    int startNumber = 0;
    for (int i = 0; i < p; i++)
    {
        int l;
        string n;
        bool newRoom = true;
        cin >> l >> n;
        if (room.empty())
        {
            room[startNumber].push_back(make_pair(l, n));
            continue;
        }
        for (auto roomPair : room)
        {
            if (abs(roomPair.second[0].first - l) <= 10 && roomPair.second.size() < m)
            {
                room[roomPair.first].push_back(make_pair(l, n));
                newRoom = false;
                break;
            }
        }
        if (newRoom)
        {
            startNumber++;
            room[startNumber].push_back(make_pair(l, n));
        }
    }

    for (auto roomPair : room)
    {
        sort(roomPair.second.begin(), roomPair.second.end(), [](const pii &a, const pii &b)
             { return a.second < b.second; });

        if (roomPair.second.size() == m)
        {
            cout << "Started!" << "\n";
        }
        else
        {
            cout << "Waiting!" << "\n";
        }
        for (size_t i = 0; i < roomPair.second.size(); i++)
        {
            cout << roomPair.second[i].first << " " << roomPair.second[i].second << "\n";
        }
    }

    return 0;
}
