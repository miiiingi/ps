#include <iostream>
#include <string>
#include <vector>

std::string reverseString(std::string s)
{
    std::string result = "";
    bool flag = false;
    if (s[0] == '<')
    {
        for (int i = 0; i < s.size(); i++)
        {
            result += s[i];
        }
        return result;
    }
    else
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                flag = true;
                continue;
            }

            result += s[i];
        }
        if (flag)
        {
            return " " + result;
        }
        else
        {
            return result;
        }
    }
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::string> stack;
    std::string temp = "";
    std::string answer = "";
    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '<')
        {
            if (!temp.empty())
            {
                stack.push_back(reverseString(temp));
                temp = "";
            }

            temp += s[i];
            flag = true;
            continue;
        }
        else if (s[i] == '>')
        {
            temp += s[i];
            flag = false;
            stack.push_back(reverseString(temp));
            temp = "";
            continue;
        }

        if (flag)
        {
            temp += s[i];
        }
        else
        {
            if (s[i] == ' ')
            {
                stack.push_back(reverseString(temp));
                temp = " ";
            }
            else
            {
                temp += s[i];
            }
        }
    }
    if (!temp.empty())
    {
        stack.push_back(reverseString(temp));
    }
    for (int i = 0; i < stack.size(); i++)
    {
        for (int j = 0; j < stack[i].size(); j++)
        {
            answer += stack[i][j];
        }
    }

    std::cout << answer;

    return 0;
}