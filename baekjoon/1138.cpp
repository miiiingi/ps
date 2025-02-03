#include <iostream>
#include <vector>

int main()
{
    int N, temp;
    std::cin >> N;
    std::vector<int> answer(N, 0);
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (cnt == temp)
            {
                int ind = 0;
                while (true)
                {
                    if (answer[j + ind] == 0)
                    {
                        answer[j + ind] = i + 1;
                        break;
                    }
                    else
                    {
                        ind++;
                    }
                }
                break;
            }

            if (answer[j] == 0)
            {
                cnt++;
            }
        }
    }
    for (int k = 0; k < N; k++)
    {
        std::cout << answer[k] << " ";
    }

    return 0;
}