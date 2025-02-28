#include <iostream>
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

    for (int i = 0; i < N; i++)
    {
        psi en = entrance[i];
        for (int j = 0; j < N; j++)
        {
            psi ex = exit[j];
            if (en.first == ex.first)
            {
                if (ex.second > en.second)
                {
                    int forward = i;
                    int total = ex.second - en.second;
                    cnt += (forward + ex.second - en.second);
                }
            }
            // 1 2 3 4 5
            // 4 5 1 3 2
        }
    }

    return 0;
}