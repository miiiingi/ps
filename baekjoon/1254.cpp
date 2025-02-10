#include <iostream>
#include <string>

bool isP(std::string s)
{
    std::cout << "s: " << s << "\n";
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main()
{
    std::string s;
    std::cin >> s;

    int start = 0, end = s.size() - 1;
    int length = s.size();
    while (start < end)
    {
        std::string f = s.substr(start, end + 1);
        if (isP(f))
        {
            break;
        }
        start++;
    }
    std::cout << length + start;

    return 0;
}