#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
/*
1. 나는 투 포인터로 풀었는데, 그렇게하면 O(N^2)이어서 시간초과가남. 그리고 앞에서부터 풀이를 진행해서 투포인터로 풀어야겠다고 생각한 듯.
2. 정답은 stack으로 푸는 것이었는데, 스택을 하나 가정하고 스택의 가장 위에 있는 원소가 현재 위치의 원소보다 크면 그것을 크지만 가장 가까운 원소라고 생각하고 answer에 추가해주고, 아닌 경우, stack에서 제거해준다. 
3. 이런 유형의 스택 문제도 잘 풀어보자.
2. 
*/

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, -1);  // 결과를 저장할 벡터 (-1로 초기화)
    stack<int> st;

    // 배열을 뒤에서부터 탐색
    for (int i = n - 1; i >= 0; --i) {
        // 스택의 맨 위에 있는 값이 현재 값보다 작거나 같으면 제거 -> 가장 큰 수가 아니라는 뜻
        
        while (!st.empty() && st.top() <= numbers[i]) {
            st.pop();
        }

        // 스택이 비어 있지 않다면, 스택의 맨 위가 뒷 큰수
        if (!st.empty()) {
            answer[i] = st.top();
        }

        // 현재 값을 스택에 넣음 (현재 값보다 큰 값들을 찾기 위해)
        st.push(numbers[i]);
    }

    return answer;
}
