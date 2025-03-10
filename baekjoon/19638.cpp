#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, H, T;
    cin >> N >> H >> T;
    vector<int> giant(N);
    int initT = T;
    for (int i = 0; i < N; i++)
    {
        cin >> giant[i];
    }
    bool check = false;
    make_heap(giant.begin(), giant.end());
    while (1)
    {
        pop_heap(giant.begin(), giant.end());
        auto top = giant.back();
        if (top < H)
        {
            check = true;
            break;
        }
        if (T <= 0 || top == 1)
        {
            check = false;
            break;
        }
        giant.pop_back();
        top /= 2;
        giant.push_back(top);
        push_heap(giant.begin(), giant.end());
        T--;
    }
    if (check)
    {
        cout << "YES" << "\n";
        cout << initT - T;
    }
    else
    {
        cout << "NO" << "\n";
        cout << *max_element(giant.begin(), giant.end());
    }

    return 0;
}