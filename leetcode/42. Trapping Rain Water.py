from typing import List
class Solution:
    def trap(self, height: List[int]) -> int:
        # 일단 시작점, 끝점 처리 해주어야할 듯
        standard = -1
        count = 0
        for i in range(len(height) - 1):
            if standard != -1:
                if standard > height[i]:
                    count += standard - height[i]
                    continue
                else:
                    standard = height[i]
            else:
                if height[i] > height[i+1]:
                    standard = height[i]
                elif height[i] <= height[i+1] and standard == -1:
                    continue
print(Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1]))


        