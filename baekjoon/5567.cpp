#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    int n, m;
    int start, end;
    std::map<int, std::vector<int>> friends;

    std::cin >> n;
    std::cin >> m;
    std::vector<bool> invited(501, false);
    for (int i = 0; i < m; i++)
    {
        std::cin >> start >> end;
        friends[start].push_back(end);
        friends[end].push_back(start);
    }

    for (auto &pair : friends)
    {
        if (pair.first == 1)
        {
            for (size_t i = 0; i < pair.second.size(); i++)
            {
                if (!invited[pair.second[i]])
                {
                    invited[pair.second[i]] = true;
                }

                for (size_t j = 0; j < friends[pair.second[i]].size(); j++)
                {
                    if (!invited[friends[pair.second[i]][j]] && friends[pair.second[i]][j] != 1)
                    {
                        invited[friends[pair.second[i]][j]] = true;
                    }
                }
            }
        }
        if (find(pair.second.begin(), pair.second.end(), 1) != pair.second.end())
        {
            for (size_t i = 0; i < pair.second.size(); i++)
            {
                if (!invited[pair.second[i]] && pair.second[i] != 1)
                {
                    invited[pair.second[i]] = true;
                }
            }
        }
    }
    std::cout << count(invited.begin(), invited.end(), true) << "\n";

    return 0;
}