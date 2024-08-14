#include <iostream>
#include <deque>
#include <string>
using namespace std;
int T, cnt;
deque<string> sList;

int isPalindrome(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        cnt++;
        if (s[start] != s[end])
        {
            return 0;
        } else
        {
            start += 1;
            end -= 1;
        }
    }
    cnt++;
    return 1;
}

int main() {
    cin >> T;
    sList.resize(T);
    for (size_t i = 0; i < T; i++)
    {
        cnt = 0;
        cin >> sList[i];
        cout << isPalindrome(sList[i]) << " " << cnt << "\n";
    }
    return 0;
}