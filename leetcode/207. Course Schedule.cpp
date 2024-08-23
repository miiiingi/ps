#include <set>
#include <map>

using namespace std;

class Solution {
public:
    map<int, vector<int>> prerequisitesMap;
    set<int> visited = {};

    bool dfs(int course){
        if (visited.find(course) != visited.end())          
        {
            return false;
        }
        visited.insert(course);
        for (auto next: prerequisitesMap[course])   
        {
            if (!dfs(next))
            {
                return false;
            }
        }
        visited.erase(course);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (size_t i = 0; i < prerequisites.size(); i++)
        {
            prerequisitesMap[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (auto M : prerequisitesMap) 
        {
            if(!dfs(M.first)){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0},{2,0}, {3,0}, {4,0}, {3, 4}};
    bool result = sol.canFinish(numCourses, prerequisites);
    return 0;
}