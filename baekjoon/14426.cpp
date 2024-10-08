#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool binarySearch(vector<string> &S, string &P)
{
    int start = 0, end = S.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int size = P.size();
        if (S[mid].substr(0, size) > P)
        {
            end = mid - 1;
        }
        else if (S[mid].substr(0, size) < P)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int N, M;
    vector<string> S, P;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        S.push_back(str);
    }
    sort(S.begin(), S.end());
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        P.push_back(str);
    }
    int answer = 0;
    for (int i = 0; i < M; i++)
    {
        if (binarySearch(S, P[i]))
        {
            answer++;
        }
    }
    cout << answer;
    return 0;
}