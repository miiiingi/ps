#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numberOfSubject, mileage, p, l;
    cin >> numberOfSubject >> mileage;
    vector<int> pList;

    for (int i = 0; i < numberOfSubject; i++)
    {
        cin >> p >> l;
        pList.resize(p);
        for (int i = 0; i < p; i++)
        {
            cin >> pList[i];
        }
        for (int i = 0; i < p; i++)
        {
            cout << pList[i] << endl;
        }
        
    }

    
    return 0;
}