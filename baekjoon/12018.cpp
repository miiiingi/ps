#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int numberOfSubject, mileage, p, l, count = 0;
    cin >> numberOfSubject >> mileage;
    vector<int> pList;
    vector<int> answer;

    for (int i = 0; i < numberOfSubject; i++)
    {
        cin >> p >> l;
        pList.resize(p);
        for (int i = 0; i < p; i++)
        {
            cin >> pList[i];
        }
        if (p < l)
        {
            answer.push_back(1);
        } else
        {
            sort(pList.begin(), pList.end());
            answer.push_back(pList[p-l]);
        }
    }
    sort(answer.begin(), answer.end());
	int cnt = 0;
	for (int i : answer)
	{
		if (mileage >= i)
		{
			count++;
			mileage -= i;
		}
	}
    cout << count;
    return 0;
}