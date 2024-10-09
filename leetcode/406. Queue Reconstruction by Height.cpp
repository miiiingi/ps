/*
내풀이
1. answer에 있는 사람들 중 첫번째 원소보다 크거나 같은 사람의 숫자를 센다. 
2. 그것과 1번째 원소와 비교해서 더 큰 경우 중 첫번째 원소가 작은 값을 순서대로 answer에 넣는다. 
3. 내풀이로 푸는 경우 정렬 및 find_if의 반복 호출로 시간초과가 남

GPT 풀이와의 비교
1. 문제의 조건을 보았을 때, 내 앞에 큰 사람이 몇명이나 있는지 세고 비교해서 정렬하는 문제이다.  
2. 따라서 오름차순말고 내림차순으로 정렬하면 내 앞에 나보다 큰 사람이 몇명 있는지 확인하기 더 수월해짐 그렇기 때문에 내림차순으로 정렬하고, 두 번째 경우 후순위에 정렬되어야하므로 오름차순으로 정렬한다.
3. 삽입하는 것이 재밌는데, 내림차순으로 정렬했으므로, 두 번째 원소가 해당 순서가 되도록 삽입하면 된다.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> answer;
        while (!people.empty()) {
            sort(people.begin(), people.end(),
                [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
            // for(int i = 0; i < people.size(); i++){
            //     cout << "first: " << people[i][0] << " " << "second: " <<
            //     people[i][1] << "\n";
            // }
            auto it =
                find_if(people.begin(), people.end(), [answer](vector<int> p) {
                    int count = 0;
                    for (int i = 0; i < answer.size(); i++) {
                        if (answer[i][0] >= p[0]) {
                            count++;
                        }
                    }
                    return count >= p[1];
                });
            int ind = it - people.begin();
            // cout << "ind: " << ind << "\n";
            answer.push_back(people[ind]);
            people.erase(it);
            // cout << "people size: " << people.size() << "\n";
        }
        return answer;
    }
};
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 키 큰 사람부터 내림차순으로 정렬하되, 같은 키인 경우 k값(앞에 있는 사람 수)을 기준으로 오름차순 정렬
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> answer;
        
        // 정렬된 사람들을 차례대로 k 값에 맞는 위치에 삽입
        for (const auto& p : people) {
            answer.insert(answer.begin() + p[1], p);
        }
        
        return answer;
    }
};
