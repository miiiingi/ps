#include <iostream>
#include <vector>

int main()
{
    int N, temp;
    std::vector<int> answer(N, 0);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (cnt == temp)
            {
                while (true)
                {
                    if (answer[cnt] == 0)
                    {
                        answer[cnt] = i + 1;
                        break;
                    }
                    else
                    {
                        cnt++;
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
        std::cout << "answer " << k << ": " << answer[k] << "\n";
    }

    return 0;
}