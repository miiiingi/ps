#include <iostream>
#include <vector>

using namespace std;

#define pii pair<int, int>
#define pipii pair<int, pii>

int calcMinDistance(pipii security, pipii store, int width, int height)
{
    if (security.first == store.first)
    {
        return abs(security.second.first - store.second.first);
    }
    else
    {
        if (security.first == 1 && store.first == 2 || security.first == 2 && store.first == 1)
        {
            if (store.second.first + security.second.first <= store.second.second + security.second.second)
            {
                return store.second.first + security.second.first + height;
            }
            else
            {
                return store.second.second + security.second.second + height;
            }
        }
        else if (security.first == 1 && store.first == 3)
        {
            return security.second.first + store.second.first;
        }
        else if (security.first == 1 && store.first == 4)
        {
            return security.second.second + store.second.first;
        }
        else if (security.first == 2 && store.first == 3)
        {
            return security.second.first + store.second.second;
        }
        else if (security.first == 2 && store.first == 4)
        {
            return security.second.second + store.second.second;
        }
        else if (security.first == 3 && store.first == 4 || security.first == 4 && store.first == 3)
        {
            if (store.second.first + security.second.first <= store.second.second + security.second.second)
            {
                return store.second.first + security.second.first + width;
            }
            else
            {
                return store.second.second + security.second.second + width;
            }
        }
        else if (security.first == 3 && store.first == 1)
        {
            return security.second.first + store.second.first;
        }
        else if (security.first == 3 && store.first == 2)
        {
            return security.second.second + store.second.first;
        }
        else if (security.first == 4 && store.first == 1)
        {
            return security.second.first + store.second.second;
        }
        else if (security.first == 4 && store.first == 2)
        {
            return security.second.second + store.second.second;
        }
    }
}

pii calcDistance(int width, int height, int direction, int distance)
{
    if (direction == 1 || direction == 2)
    {
        return make_pair(distance, width - distance);
    }
    else if (direction == 3 || direction || 4)
    {
        return make_pair(distance, height - distance);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int storeNumber;
    cin >> storeNumber;
    int direction, distance;
    int answer = 0;
    vector<pipii> store;
    for (int i = 0; i < storeNumber; i++)
    {
        cin >> direction >> distance;
        store.push_back(make_pair(direction, calcDistance(n, m, direction, distance)));
    }
    cin >> direction >> distance;
    pipii security = make_pair(direction, calcDistance(n, m, direction, distance));
    for (size_t i = 0; i < store.size(); i++)
    {
        int dist = calcMinDistance(security, store[i], n, m);
        answer += dist;
    }

    cout << answer;

    return 0;
}