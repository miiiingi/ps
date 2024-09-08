#include <string>
#include <vector>
#include <regex>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> bannedList;
set<set<int>> combinationSet;
set<int> initSet;
void findCombination(int startIndex, set<int> combination)
{
    if (startIndex < bannedList.size())
    {
        for (size_t i = 0; i < bannedList[startIndex].size(); i++)
        {
            if (combination.find(bannedList[startIndex][i]) == combination.end())
            {
                set<int> compSet(combination);
                compSet.insert(bannedList[startIndex][i]);
                findCombination(startIndex + 1, compSet);
            }
        }
    }
    else
    {
        combinationSet.insert(combination);
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    bannedList = vector<vector<int>>(banned_id.size());
    int answer = 1;
    for (size_t i = 0; i < banned_id.size(); i++)
    {
        replace(banned_id[i].begin(), banned_id[i].end(), '*', '.');
    }
    
    for (size_t i = 0; i < user_id.size(); i++)
    {
        for (size_t j = 0; j < banned_id.size(); j++)
        {
            if (banned_id[j].size() != user_id[i].size())
            {
                continue;
            }
            
            regex ban(banned_id[j]);
            if (regex_search(user_id[i], ban))
            {
                bannedList[j].push_back(i);
            }
        }
    }
    findCombination(0, initSet);
    return combinationSet.size();
}

int main()
{
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"*rodo", "*rodo", "******"};
    int answer = solution(user_id, banned_id);
    return 0;
}