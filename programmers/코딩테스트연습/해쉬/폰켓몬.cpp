#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> pSet;
    for(int i = 0; i < nums.size(); i++){
        pSet.insert(nums[i]);
    }
    int answer = min(nums.size() / 2, pSet.size());
    
    
    return answer;
}