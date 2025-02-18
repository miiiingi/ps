#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    string S, E, Q;
    cin >> S >> E >> Q;
    int chatCnt = 0;
    string time, nickname;
    map<string, bool> nicknames;

    while (cin >> time >> nickname) // 🔥 한 줄씩 정확히 입력받음
    {
        if (time <= S)
        {
            nicknames[nickname] = true;
        }
        else if (E <= time && time <= Q)
        {
            if (nicknames[nickname])
            {
                nicknames[nickname] = false;
                chatCnt++;
            }
        }
    }

    cout << chatCnt;
    return 0;
}
