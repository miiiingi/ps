from typing import List
class Solution:
    '''
    처음에는 0번 인덱스, 빈 배열로 시작해서 하나씩 원소를 넣고, 백트래킹하면서 빼주려고 했는데, 인덱스 기반으로 계산하다보니 인덱스가 넘어가는 경우에 제대로 동작하지 않는 문제가 있었음.
    따라서 인덱스를 쓰지않고 원소를 쌓는 방법을 생각하다가 처음에 모든 원소를 다 주고 순회하는 방식으로 변경
    '''
    def __init__(self):
        self.answer = [] 
        self.stack = []
        self.nums = []
    
    # def dfs(self, index, stack):
    #     if len(stack) == len(self.nums):
    #         self.answer.append(stack[:])
    #         return
        
    #     for i in range(index, len(self.nums)):
    #         stack.append(num)
    #         self.dfs(i+1, stack)
    #         stack.pop()

    def dfs(self, nums):
        if len(self.stack) == len(self.nums):
            self.answer.append(self.stack[:])
            return
        
        for num in nums:
            next_stack = nums[:]
            next_stack.remove(num)
            self.stack.append(num)
            self.dfs(next_stack)
            self.stack.pop()

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.nums = nums
        
        # self.dfs(0, self.stack)
        self.dfs(self.nums[:])
            
        return self.answer
print(Solution().permute([1,2,3]))
        