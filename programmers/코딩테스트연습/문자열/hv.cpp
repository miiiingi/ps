#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define psi pair<string, int>


psi commandProcess(psi next, char command, char ch)
{
    string str = next.first;
    int location = next.second;
    if (command == 'L' && location > 0)
    {
        location -= 1;
    }
    else if (command == 'P')
    {
        string temp = str.substr(location);
        if (str.size() == 0)
        {
            str += ch;
        }
        str[location] = ch;
        str += temp;
        location += 1;
    }
    else if (command == 'D' && location > 0)
    {
        location -= 1;
        str.erase(location, 1);
    }
    else if (command == 'R' && location < str.size() - 1)
    {
        location += 1;
    }
    else if (command == 'l')
    {
        str.replace(location, 1, 1, ch);
        location += 1;
    }
    next.first = str;
    next.second = location;
    return next;
}
string solution(string initString, vector<string> commandList)
{
    char command;
    char ch;
    psi next;
    next.first = initString;
    if (initString.size() == 0)
    {
        next.second = 0;
    }
    
    next.second = initString.size();
    for (size_t i = 0; i < commandList.size(); i++)
    {
        istringstream iss(commandList[i]);
        iss >> command;
        iss >> ch;
        next = commandProcess(next, command, ch);
    }
    return next.first;
}

int main()
{
    // string answer = solution("abcd", {"L", "P Z", "L", "D", "R", "l x"});
    string answer = solution("", {"P a", "P b", "L", "l c", "l d"});
    cout << answer;
    return 0;
}