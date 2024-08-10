#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

string p, nString;
int n;
string temp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        bool reverseFlag = false;
        deque<int> nList;
        string answer = "[";
        cin >> p;
        cin >> n;
        cin >> nString;
        // if (p.size() > n)
        // {
        //     cout << "error" << "\n";
        //     continue;
        // }

        for(char c : nString){
           if (isdigit(c))
           {
            temp.append(1, c);
           }
           if (c == ',')
           {
            nList.push_back(stoi(temp));
            temp = "";
           }
           if (c == ']')
           {
            if (temp != "")
            {
            nList.push_back(stoi(temp));
            temp = "";
            }
           }
        }
        for (size_t i = 0; i < p.size(); i++)
        {
            if (p[i] == 'R')
            {
                reverseFlag = !reverseFlag;
            } else if (p[i] == 'D')
            {
                if (nList.empty())
                {
                    cout << "error" << "\n";
                    break;
                }
                if (!reverseFlag)
                {
                    nList.pop_front();
                } else
                {
                    nList.pop_back();
                }
            }
        }
        if (nList.empty())
        {
            continue;
        }
        
        if (!reverseFlag)
        {
            for (size_t i = 0; i < nList.size(); i++)
            {
                answer.append(to_string(nList[i]));
                if (i != nList.size() - 1)
                {
                    answer.append(",");
                }
            }
        } else
        {
            for (int i = nList.size() - 1; i >= 0; i--)
            {
                answer.append(to_string(nList[i]));
                if (i != 0)
                {
                    answer.append(",");
                }

            }
        }

        answer.append("]");
        cout << answer << "\n";
    }
    return 0;
}