#include <iostream>
#include <vector>

int main()
{
    int T, N, price, base = 0;
    bool asc;
    std::vector<int> priceList;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        long answer = 0;
        int maxValue = 0;
        priceList.clear();
        std::cin >> N;

        for (int j = 0; j < N; j++)
        {
            std::cin >> price;
            priceList.push_back(price);
        }

        for (int k = N - 1; k >= 0; k--)
        {
            if (priceList[k] >= maxValue)
            {
                maxValue = priceList[k];
            }
            else
            {
                answer += (maxValue - priceList[k]);
            }
        }
        std::cout << answer << "\n";
    }
    return 0;
}