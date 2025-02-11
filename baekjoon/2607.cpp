#include <iostream>
#include <string>
#include <vector>

std::vector<int> calcIndex(std::string s)
{
    std::vector<int> result(26, 0);
    for (size_t i = 0; i < s.size(); i++)
    {
        result[s[i] - 'A']++;
    }

    return result;
}
int main()
{
    int N, answer = 0;
    std::cin >> N;
    std::string reference;
    std::cin >> reference;
    std::vector<int> refInd = calcIndex(reference);
    std::vector<int> difference;
    for (int i = 0; i < N - 1; i++)
    {
        std::string str;
        std::cin >> str;
        // std::cout << "i: " << i << std::endl;
        std::vector<int> compInd = calcIndex(str);
        difference.clear();
        for (int j = 0; j < 26; j++)
        {
            if (refInd[j] != compInd[j])
            {
                difference.push_back(refInd[j] - compInd[j]);
                // std::cout << "j: " << j << "\n";
            }
        }
        if (difference.empty())
        {
            answer++;
        }
        else if (difference.size() == 1 && abs(difference[0]) == 1)
        {
            answer++;
        }
        else if (difference.size() == 2 && abs(difference[0]) == 1 && difference[0] + difference[1] == 0)
        {
            answer++;
        }
    }
    std::cout << answer;

    return 0;
}