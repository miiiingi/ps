#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int G;
    cin >> G;
    int left = 1, right = 1;
    vector<int> answer;
    bool finded = false;
    while (true)
    {
        int comp = pow(right, 2) - pow(left, 2);
        if (comp < G)
        {
            right++;
        }
        else
        {
            if (comp == G)
            {
                answer.push_back(right);
                finded = true;
            }
            if (right - left == 1 && comp > G)
            {
                break;
            }

            left++;
        }
    }
    if (finded)
    {
        sort(answer.begin(), answer.end());
        for (size_t i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << "\n";
        }
    }
    else
    {
        cout << -1;
    }

    return 0;
}