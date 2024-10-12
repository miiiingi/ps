#include <vector>
#include <algorithm>
using namespace std;
/*
1. 나는 처음에 외판원 순회처럼 dfs문제인지알고 접근했음
2. 열의 갯수가 정해져있고, 이전에 밟은 열만 밟을 수 없다는 제약조건이 있으므로 그냥 dp의 개념으로 접근하면 되는 것이었다...
3. 문제를 잘 이해하자..
*/

int solution(vector<vector<int>> land) {
    int n = land.size();

    // DP를 이용해 각 행을 갱신
    for (int i = 1; i < n; i++) {
        land[i][0] += max({land[i-1][1], land[i-1][2], land[i-1][3]});
        land[i][1] += max({land[i-1][0], land[i-1][2], land[i-1][3]});
        land[i][2] += max({land[i-1][0], land[i-1][1], land[i-1][3]});
        land[i][3] += max({land[i-1][0], land[i-1][1], land[i-1][2]});
    }

    // 마지막 행에서 최대값을 찾아 반환
    return *max_element(land[n-1].begin(), land[n-1].end());
}