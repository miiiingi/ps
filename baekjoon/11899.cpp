#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    std::vector<char> stack;

    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (stack.empty())
        {
            stack.push_back(c);
            cnt++;
        }
        else
        {
            if (stack.back() == '(' && c == ')')
            {
                stack.pop_back();
                cnt--;
            }
            else
            {
                stack.push_back(c);
                cnt++;
            }
        }
    }

    std::cout << cnt << "\n";
    return 0;
}