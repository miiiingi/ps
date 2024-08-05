#include<iostream>
#include<vector>
#include<numeric>

using namespace std;
vector<int> arr;
vector<int> stack;
vector<int> nextStack;
int numberChoice, s, cnt = 0, n;

void dfs(int start){
    if (stack.size() == static_cast<size_t>(numberChoice))
    {
        if (accumulate(stack.begin(), stack.end(), 0) == s)
        {
            cnt++;
        }
        return;
    }
    for (int i = start; i < n; i++)
    {
        stack.push_back(arr[i]);
        dfs(i+1);
        stack.pop_back();
    }
}

int main(){
    cin >> n >> s;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (numberChoice = 1; numberChoice <= n; numberChoice++)
    {
        dfs(0);
    }
    cout << cnt;
    return 0;
}