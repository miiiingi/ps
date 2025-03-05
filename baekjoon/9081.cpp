#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    // EHLSTU
    // SHUTTLE 4265531
    // SLEHTTU 4312556

    // BEER 1223
    // BERE 1232

    for (int i = 0; i < T; i++)
    {
        string s;
        cin >> s;
        char start;
        bool isSorted = true;
        for (int j = s.size() - 2; j >= 0; j--)
        {
            if (s[j] < s[j + 1])
            {
                isSorted = false;
                start = s[j];
                sort(s.begin() + j + 1, s.end());
                for (int k = j + 1; k < s.size(); k++)
                {
                    if (start < s[k])
                    {
                        swap(s[j], s[k]);
                        break;
                    }
                }

                cout << s << "\n";
                break;
            }
        }
        if (isSorted)
        {
            cout << s << "\n";
        }
    }

    return 0;
}