#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <cstdlib>

using namespace std;
int numberChoice, N;
vector<int> sList(N);
vector<int> sAccumList;
vector<int> bList(N);
vector<int> bAccumList;
vector<int> sStack;
vector<int> bStack;

void sDfs(int start){
    if (sStack.size() == static_cast<size_t>(numberChoice))
    {
        sAccumList.push_back(accumulate(sStack.begin(), sStack.end(), 1, multiplies<int>()));
        return;
    }
    for (int i = start; i < N; i++)
    {
        sStack.push_back(sList[i]);
        sDfs(i+1);
        sStack.pop_back();
    }
}
void bDfs(int start){
    if (bStack.size() == static_cast<size_t>(numberChoice))
    {
        bAccumList.push_back(accumulate(bStack.begin(), bStack.end(), 0));
        return;
    }
    for (int i = start; i < N; i++)
    {
        bStack.push_back(bList[i]);
        bDfs(i+1);
        bStack.pop_back();
    }
}

int main() {
    int s, b;
    double answer = pow(10, 10);
    cin >> N;
    sList.resize(N);
    bList.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s >> b;
        sList[i] = s;
        bList[i] = b;
    }
    for (numberChoice = 1; numberChoice <= N; numberChoice++)
    {
        sDfs(0);
        bDfs(0);
    }
    for (size_t i = 0; i < sAccumList.size(); i++)
    {
        if (abs(sAccumList[i] - bAccumList[i]) < answer)
        {
            answer = abs(sAccumList[i] - bAccumList[i]);
        }
    }
    cout << answer;
    return 0;
}