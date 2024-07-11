from typing import List
import collections
# class Solution:
#     def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
#         answer = []
#         for i in range(len(temperatures)):
#             count = 0
#             for j in range(i+1, len(temperatures)):
#                 if temperatures[i] < temperatures[j]:
#                     count += j - i
#                     break
#             answer.append(count)
#         return answer
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        count = [0 for _ in range(len(T))] 
        stack = [] 
        T = collections.deque(T) 
        for ind, item in enumerate(T) :
            while stack and T[stack[-1]] < item :  
                last = stack.pop()
                count[last] = ind - last
            stack.append(ind)
        return count    
print(Solution().dailyTemperatures([73,74,75,71,69,72,76,73]))

        