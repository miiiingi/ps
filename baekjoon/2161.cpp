#include <iostream>
#include <deque>
using namespace std;
int main() {
    int N;
    cin >> N;
    deque<int> arr(N);
    deque<int> answer;
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    while (arr.size() > 0)
    {
        int elem = arr.front();
        arr.pop_front();
        int elem2 = arr.front();
        arr.pop_front();
        arr.push_back(elem2);
        answer.push_back(elem);
    }
    for (size_t i = 0; i < answer.size(); i++)
    {
        if (i != answer.size() - 1)
        {
            cout << answer[i] << " ";
        } else {
            cout << answer[i];
        }
    }
    return 0;
}
