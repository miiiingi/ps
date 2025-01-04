#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> stack;
vector<int> numList;
vector<vector<int>> answer;
int N, M;

void dfs()
{
    if (stack.size() == static_cast<size_t>(M))
    {
        answer.push_back(stack);
        return;
    }

    int prevNum = -1; // 이전에 선택한 숫자를 기억
    for (int i = 0; i < N; i++)
    {
        // 이미 방문한 숫자거나, 이전에 선택한 숫자와 같은 경우 스킵
        if (prevNum == numList[i])
            continue;
        
        if (!stack.empty() && stack.back() > numList[i])
        {
            continue;
        }
        

        stack.push_back(numList[i]); // 숫자 선택
        prevNum = numList[i]; // 이전 숫자 업데이트

        dfs(); // 재귀 호출

        stack.pop_back(); // 백트래킹
    }
}

int main()
{
    cin >> N >> M;
    numList.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numList[i];
    }

    // 정렬하여 중복 순열 방지
    sort(numList.begin(), numList.end());

    // DFS 시작
    dfs();

    // 결과 출력
    for (const auto &seq : answer)
    {
        for (int j = 0; j < seq.size(); j++)
        {
            if (j != seq.size() - 1)
            {
                cout << seq[j] << " ";
            }
            else
            {
                cout << seq[j] << "\n";
            }
        }
    }

    return 0;
}