#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> strList;
    vector<string> answer;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        strList.push_back(str);
    }
    sort(strList.begin(), strList.end());
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            int size = strList[i].size();
            if (strList[i] != strList[i + 1].substr(0, size))
            {
                answer.push_back(strList[i]);
            }
        }
        else
        {
            answer.push_back(strList[i]);
        }
    }
    cout << answer.size();

    return 0;
}