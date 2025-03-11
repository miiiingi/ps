#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string maxS = "";
    string minS = "";
    int mCount = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'M')
        {
            mCount++;
        }
        else
        {
            if (mCount > 0)
            {
                maxS += '5';
                maxS.append(pow(10, mCount - 1), '0');
                mCount = 0;
            }
            else
            {
                maxS += '5';
            }
        }
        cout << "mCount : " << mCount << "\n";
        cout << "maxS: " << maxS << "\n";
    }
    if (mCount > 0)
    {
        auto temp = pow(10, mCount - 1);
        if (temp == 1)
        {
            maxS.append(1, '1');
        }
        else
        {
            maxS.append(pow(10, mCount - 1), '0');
        }
    }

    cout << "maxS: " << maxS << "\n";

    for (size_t i = 0; i < s.size(); i++)
    {
    }

    return 0;
}