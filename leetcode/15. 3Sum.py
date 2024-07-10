from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer = []
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                for k in range(j+1, len(nums)):
                    if nums[i]+nums[j]+nums[k] == 0:
                        e = sorted([nums[i], nums[j], nums[k]])
                        if e not in answer:
                            answer.append(e)
        return answer
print(Solution().threeSum([-1,0,1,2,-1,-4]))

# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         answer = []
#         nums.sort()
#         for i in range(len(nums) - 2):
#             s, e = i + 1, len(nums) - 1
#             while s < e:
#                 sum_list = [nums[i], nums[s], nums[e]]
#                 if sum(sum_list) < 0:
#                     s += 1
#                 elif sum(sum_list) > 0:
#                     e -= 1
#                 else:
#                     if sum_list not in answer:
#                         answer.append(sum_list)
#                     s += 1
#                     e -= 1
#         return answer

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer = []
        nums.sort()
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            s, e = i + 1, len(nums) - 1
            while s < e:
                sum_list = [nums[i], nums[s], nums[e]]
                if sum(sum_list) < 0:
                    s += 1
                elif sum(sum_list) > 0:
                    e -= 1
                else:
                    answer.append(sum_list)
                    while s < e and nums[s] == nums[s + 1]:
                        s += 1
                    while s < e and nums[e] == nums[e - 1]:
                        e -= 1
                    s += 1
                    e -= 1
        return answer

print(Solution().threeSum([-1,0,1,2,-1,-4]))

