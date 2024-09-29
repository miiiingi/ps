#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /*
    1. 인덱스 기반으로 세 개를 나눌까 ? -> 안의 원소들이 어떤 방식으로 정렬되었을 지 알 수 없기 때문에 사용 X?
    2. 전체 합을 기준으로 이분 탐색을 할까 ? (하나씩 더해가면서 기준 값을 넘으면 벡터에 남겨줄까 ?)
    */
    int N, M;
    int maxNumber = 0;
    cin >> N >> M;
    vector<int> lectures(N);
    for (int i = 0; i < N; i++)
    {
        cin >> lectures[i];
        maxNumber += lectures[i];
    }
    int minNumber = *max_element(lectures.begin(), lectures.end());
    while (minNumber <= maxNumber)
    {
        int temp = 0, count = 0;
        int mid = (minNumber + maxNumber) / 2;
        for (int i = 0; i < N; i++)
        {
            if (temp + lectures[i] > mid)
            {
                count++;
                temp = 0;
            }
            temp += lectures[i];
        }
        if (temp != 0)
        {
            count++;
        }

        if (count <= M)
        {
            maxNumber = mid - 1;
        }
        else
        {
            minNumber = mid + 1;
        }
    }
    cout << minNumber;

    return 0;
}