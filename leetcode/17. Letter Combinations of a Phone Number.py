from typing import List
class Solution:
    # 어떻게 안으로 들어가는 로직을 짤 것인가 ? -> 거꾸로 생각하면 좋을 듯! 어떻게 다음 조건으로 빠져 나올 것인가 ? 
    # 종료 조건을 어떻게 줄 것인가 ? -> ad, ae, af 인 경우에 종료해주어야하는데 이것을 어떻게 정의할 것인가 ? 
    def __init__(self) -> None:
        self.letter = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        self.answer = []

    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(index, path):
            '''
            index: 몇 번째 글자 위치인지에 대한 정보
            
            '''
            if len(path) == len(digits):
                self.answer.append(path)
                return
            
            for i in range(index, len(digits)):
                for j in self.letter[digits[i]]:
                    dfs(i + 1, path + j)
        
        if not digits:
            return []
        
        dfs(0, "")
        return self.answer
print(Solution().letterCombinations("23"))
            



        