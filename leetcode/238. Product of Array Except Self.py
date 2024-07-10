from typing import List
# class Solution:
#     def productExceptSelf(self, nums: List[int]) -> List[int]:
#         answer = []
#         for i in range(len(nums)):
#             result = 1
#             for j in range(len(nums)):
#                 if i == j:
#                     continue
#                 else:
#                     result *= nums[j]
#             answer.append(result)
        # return answer   
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = []
        p = 1
        for i in range(len(nums)):
            answer.append(p)
            p *= nums[i]
        p = 1
        for j in range(len(nums)-1, -1, -1):
            answer[j] *= p
            p *= nums[j]
        return answer   
print(Solution().productExceptSelf([1,2,3,4]))

