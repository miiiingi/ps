#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

bool judge(int N, map<int, queue<string>> &speech, string word)
{
    for (int i = 0; i < N; i++)
    {
        if (speech[i].empty())
        {
            continue;
        }

        string wordComparison = speech[i].front();

        if (wordComparison == word)
        {
            speech[i].pop();

            return true;
        }
    }
    return false;
}

queue<string> makeSplitString(queue<string> &sQueue, string s)
{
    string sStack = "";
    for (size_t j = 0; j < s.size(); j++)
    {
        if (s[j] == ' ')
        {
            sQueue.push(sStack);
            sStack = "";
        }
        else
        {
            sStack += s[j];
        }

        if (j == s.size() - 1)
        {
            sQueue.push(sStack);
        }
    }

    return sQueue;
}
int main()
{
    int N, speechLength = 0;
    cin >> N;
    cin.ignore();
    string temp;
    map<int, queue<string>> speech;

    for (int i = 0; i < N; i++)
    {
        queue<string> sQueue;
        getline(cin, temp);
        makeSplitString(sQueue, temp);
        speech[i] = sQueue;
        speechLength += sQueue.size();
    }
    string reference;
    queue<string> aQueue;
    getline(cin, reference);
    makeSplitString(aQueue, reference);
    int writeLength = aQueue.size();
    if (speechLength != writeLength)
    {
        cout << "Impossible";
        return 0;
    }

    while (!aQueue.empty())
    {
        string q = aQueue.front();
        aQueue.pop();
        if (!judge(N, speech, q))
        {
            cout << "Impossible";
            return 0;
        }
    }

    cout << "Possible";
    return 0;
}