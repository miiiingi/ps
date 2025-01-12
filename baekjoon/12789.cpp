#include <iostream>
#include <vector>

int main()
{
    int N;
    int target = 1;
    std::cin >> N;
    std::vector<int> stack;
    for (int i = 0; i < N; i++)
    {
        int temp;
        std::cin >> temp;
        if (temp != target)
        {
            stack.push_back(temp);
        }
        else
        {
            target++;

            while (!stack.empty() && stack.back() == target)
            {
                stack.pop_back();
                target++;
            }
        }
    }
    int size = stack.size();

    for (int i = 0; i < size; i++)
    {
        int temp = stack.back();
        if (temp != target)
        {
            std::cout << "Sad" << "\n";
            break;
        }
        else
        {
            target++;
        }

        stack.pop_back();
    }

    if (stack.size() == 0)
    {
        std::cout << "Nice" << "\n";
    }

    return 0;
}