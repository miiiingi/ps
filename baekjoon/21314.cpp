#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string calcMax(string s)
{
    string answer = "";
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
                answer += '5';
                answer.append(mCount, '0');
                mCount = 0;
            }
            else
            {
                answer += '5';
            }
        }
    }
    if (mCount > 0)
    {
        answer.append(mCount, '1');
    }

    return answer;
}

string calcMin(string s)
{
    string answer = "";
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
                answer.append(1, '1');
                answer.append(mCount - 1, '0');
                answer += '5';
                mCount = 0;
            }
            else
            {
                answer += '5';
            }
        }
    }
    if (mCount > 0)
    {
        answer.append(1, '1');
        answer.append(mCount - 1, '0');
    }

    return answer;
}

int main()
{
    string s;
    cin >> s;
    string maxS = calcMax(s);
    string minS = calcMin(s);
    cout << maxS << "\n";
    cout << minS;

    return 0;
}