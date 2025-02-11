#include <iostream>
#include <string>
#include <vector>

int judge(std::vector<std::string> &cnt, char c)
{
    for (size_t i = 0; i < cnt.size(); i++)
    {
        char back = cnt[i].back();
        // std::cout << "back: " << back << " c: " << c << "\n";
        // std::cout << i << " : " << cnt[i] << "\n";
        if (c == 'q' && back == 'k' || c == 'u' && back == 'q' || c == 'a' && back == 'u' || c == 'c' && back == 'a' || c == 'k' && back == 'c')
        {
            cnt[i] += c;
            // std::cout << "cnt: " << cnt[i] << "\n";
            c = '-';
        }
    }
    if (c == 'q')
    {
        // std::cout << "empty next q: " << c << "\n";
        std::string temp = "";
        temp += c;
        cnt.push_back(temp);
        // std::cout << "cnt size: " << cnt.size() << "\n";
        c = '-';
    }

    if (c != '-')
    {
        return -1;
    }

    return 0;
}

int main()
{
    std::string reference;
    std::cin >> reference;
    std::vector<std::string> cnt;
    std::string s = "";

    for (size_t i = 0; i < reference.size(); i++)
    {
        // std::cout << "==============" << "\n";
        if (cnt.empty())
        {
            if (reference[i] != 'q')
            {
                std::cout << -1;
                return 0;
            }
            // std::cout << "first s: " << reference[i] << "\n";

            s += reference[i];
            cnt.push_back(s);
        }
        else
        {
            // std::cout << "next s: " << reference[i] << "\n";
            if (judge(cnt, reference[i]) < 0)
            {
                std::cout << -1;
                return 0;
            }
        }
    }
    int answer = 0;
    for (size_t i = 0; i < cnt.size(); i++)
    {
        if (cnt[i].back() != 'k')
        {
            std::cout << -1;
            return 0;
        }
        answer++;
    }
    std::cout << answer;

    return 0;
}