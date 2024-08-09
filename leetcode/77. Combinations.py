from typing import List
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        def dfs(index, path):
            print(f"index: {index}, path: {path}")
            result.append(path)

            for i in range(index, len(nums)):
                dfs(i + 1, path + nums[i])
        # dfs(dfs(dfs(dfs())))
        
        dfs(0, [])
        return result
print(Solution().subsets([1,2,3]))
            