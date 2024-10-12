#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

/*
1. 어떻게 풀 수 있을 지 생각하는 것이 가장 첫 번째!! 여기서 가장 시간을 많이 써야한다. 어떤 자료구조나 알고리즘을 쓰는가는 부차적인 문제다.
2. 왼쪽, 오른쪽 나누어서 접근할 생각만했는데, 그러다보니 투포인터 등의 방법이 떠올랐음.
3. 문제의 핵심은 갯수와 종류를 세는 것이었기 때문에 map을 이용해서 접근해야했고, 거기서 map을 두 개 많드는 것이 핵심이었음. 모두 다 들어있는 map과 비어있어서 하나씩 추가되는 map 
*/

int solution(vector<int> topping) {
    map<int, int> rMap;
    for(int i = 0; i < topping.size(); i++){
        rMap[topping[i]]++;
    }
    map<int, int>lMap;
    int answer = 0;
    for(int i = 0; i < topping.size(); i++){
        lMap[topping[i]]++;
        if(--rMap[topping[i]] == 0){
            rMap.erase(topping[i]);
        }
        if(lMap.size() == rMap.size()){
            answer++;
        }
    }
    return answer;
}