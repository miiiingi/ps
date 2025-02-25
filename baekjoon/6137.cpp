#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string s = "";
    string answer = "";
    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        s += c;
    }
    int left = 0, right = N - 1;
    while (left <= right)
    {
        if (s[left] < s[right])
        {
            answer += s[left];
            left++;
        }
        else if (s[left] > s[right])
        {
            answer += s[right];
            right--;
        }
        else
        {
            answer += s[left];
            int tempLeft = left + 1;
            int tempRight = right - 1;
            while (tempLeft < tempRight && s[tempLeft] == s[tempRight])
            {
                tempLeft++;
                tempRight--;
            }
            if (s[tempLeft] < s[tempRight])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    int iter = answer.size() / 80;
    for (int i = 0; i < iter + 1; i++)
    {
        string temp = answer.substr(i * 80, 80);
        cout << temp << "\n";
    }

    return 0;
}