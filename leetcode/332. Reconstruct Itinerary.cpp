#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

vector<string> result;


class Solution {
    /*
    해결해야하는 문제
    1. value의 정렬 문제 (ATL < SFO)
    2. 재참조의 문제 (JFK  -> ATL -> JFK)
    */
public:
    unordered_map<string, map<string, bool>> newTickets;
    vector<string> answer;
    int count = 0;
    size_t ticketSize;

    void dfs(string path){
        map<string, bool> value = newTickets[path];
        if (value.size() == 0)
        {
            if (count == ticketSize + 1)
            {
                answer.push_back(path);
            }
            return;
        }
        answer.push_back(path);
        for (auto v: value)
        {
            if (v.second)
            {
                continue;
            }
            newTickets[path].erase(v.first);
            count++;
            dfs(v.first);
            newTickets[path][v.first] = false;
        }
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ticketSize = tickets.size();
        for (auto i = 0; i < tickets.size(); i++)
        {
            string key = tickets[i][0];
            newTickets[key][tickets[i][1]] = false;
        }
        dfs("JFK");
        return answer;
    }
};

int main(){
    Solution sol;
    // vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    // vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    result = sol.findItinerary(tickets);
    return 0;
}
