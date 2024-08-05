#include <iostream>
#include <vector>

using namespace std;
vector<int> stack;
vector<int> numList;
int k;

void dfs(int start){
    if (stack.size() == static_cast<size_t>(6))
    {
        for (size_t i = 0; i < stack.size(); i++)
        {
            if (i != stack.size() - 1)
            {
                cout << stack[i] << " ";
            } else
            {
                cout << stack[i] << "\n";
            }
            
            
        }
        
        return;
    }
    for (int i = start; i < k; i++)
    {
        stack.push_back(numList[i]);
        dfs(i+1);
        stack.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (true)
    {
        cin >> k;
        if (k == 0)
        {
            break;
        }
        numList.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> numList[i];
        }
        dfs(0);
        cout << endl;
    }
    return 0;
}