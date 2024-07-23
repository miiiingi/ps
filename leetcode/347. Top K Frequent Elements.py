from typing import List
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        common_list = Counter(nums).most_common(k)
        answer = []
        for i in range(k):
            answer.append(common_list[i][0])
        return answer

print(Solution().topKFrequent([1,1,1,2,2,3], 2))

