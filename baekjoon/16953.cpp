#include <iostream>
#include <queue>

#define pii std::pair<long, long>

int main()
{
    long A, B;
    std::cin >> A >> B;

    std::queue<pii> queue;
    queue.push(std::make_pair(A, 0));

    while (!queue.empty())
    {
        pii temp = queue.front();
        queue.pop();
        if (temp.first == B)
        {
            std::cout << temp.second + 1;
            return 0;
        }

        if (temp.first * 2 <= B)
        {
            queue.push(std::make_pair(temp.first * 2, temp.second + 1));
        }

        if (temp.first * 10 + 1 <= B)
        {
            queue.push(std::make_pair(temp.first * 10 + 1, temp.second + 1));
        }
        }

    std::cout << -1;
    return 0;
}