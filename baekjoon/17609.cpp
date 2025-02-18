#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int isP(string s, int left, int right, int limit)
{
    if (limit < 0)
    {
        return 2;
    }

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            if (isP(s, left + 1, right, limit - 1) <= 1 || isP(s, left, right - 1, limit - 1) <= 1)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
    return 0;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        // 팰린드롬을 검사했을 때, 왼쪽이 아닌 경우에도 오른쪽으로 다시 검사할 수 있도록 되돌아가야한다.
        // -> 그냥 단순 재귀로 풀어도 되고 dfs로 풀어도 될 듯 -> x
        // -> dfs로 풀면 메모리 초과나니까 최대한 재귀를 깊이 안들어가게 딱 왼쪽이나 오른쪽이 아닌 경우 한 번만 재귀를 타도록 코드를 작성해야함.
        string s;
        cin >> s;
        int left = 0, right = s.size() - 1;
        int limit = 1;
        cout << isP(s, left, right, limit) << "\n";
    }

    return 0;
}