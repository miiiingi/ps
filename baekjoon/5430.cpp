#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

deque<string> nList;
void divide(const string& str){
    nList.clear();
    string temp = "";
    for (auto ch: str)
    {
        if (ch == '[')
        {
            continue;
        } else if (ch == ',' or ch == ']')
        {
            if (!temp.empty())
            {
                nList.push_back(temp);
                temp = "";
            }
            
        } else
        {
            temp += ch;
        }
    }
}

void print(bool reverseFlag){
    cout << '[';
    if (reverseFlag)
    {
        for (auto i = nList.rbegin(); i != nList.rend(); i++)
        {
            if (i != nList.rend() - 1)
            {
                cout << *i << ',';
            } else
            {
                cout << *i;
            }
            
        }
    } else
    {
        for (auto i = nList.begin(); i != nList.end(); i++)
        {
            if (i != nList.end() - 1)
            {
                cout << *i << ',';
            } else
            {
                cout << *i;
            }
        }
    }
    cout << ']' << '\n';
}

int main(){
    int n, T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        bool reverseFlag = false;
        bool errorFlag = false;
        string p, nString;
        string answer = "[";
        cin >> p >> n >> nString;
        divide(nString);
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
                    errorFlag = !errorFlag;
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
        if (!errorFlag)
        {
            print(reverseFlag);
        }
    }
    return 0;
}