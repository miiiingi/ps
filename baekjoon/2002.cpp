#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
#define psi pair<string, int>
int main()
{
    int N;
    cin >> N;
    vector<psi> entrance(N);
    vector<psi> exit(N);

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        entrance[i] = make_pair(temp, i);
    }

    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        exit[i] = make_pair(temp, i);
    }

    int cnt = 0;

    set<string> exceed;
    set<string> forward;
    for (int i = 0; i < N; i++)
    {
        psi en = entrance[i];
        forward.insert(en.first);
        for (int j = 0; j < N; j++)
        {
            psi ex = exit[j];
            if (en.first == ex.first)
            {
                break;
            }
            else
            {
                if (find(forward.begin(), forward.end(), ex.first) == forward.end() &&
                    find(exceed.begin(), exceed.end(), ex.first) == exceed.end())
                {

                    exceed.insert(ex.first);
                }
            }
        }
    }

    cout << exceed.size();

    return 0;
}