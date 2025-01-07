#include <iostream>
#include <vector>

int main()
{
    int N;
    int command;
    int number;
    int cnt = 0;
    std::vector<int> stack;
    std::vector<int> answer;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> command;
        if (command == 1)
        {
            std::cin >> number;
            stack.push_back(number);
            cnt++;
        }
        else if (command == 2)
        {
            if (stack.empty())
            {
                answer.push_back(-1);
            }
            else
            {
                int temp;
                temp = stack.back();
                stack.pop_back();
                answer.push_back(temp);
                cnt--;
            }
        }
        else if (command == 3)
        {
            answer.push_back(cnt);
        }
        else if (command == 4)
        {
            if (stack.empty())
            {
                answer.push_back(1);
            }
            else
            {
                answer.push_back(0);
            }
        }
        else
        {
            if (stack.empty())
            {
                answer.push_back(-1);
            }
            else
            {
                int temp;
                temp = stack.back();
                answer.push_back(temp);
            }
        }
    }
    int sizes = answer.size();
    for (int i = 0; i < sizes; i++)
    {
        std::cout << answer[i] << "\n";
    }

    return 0;
}