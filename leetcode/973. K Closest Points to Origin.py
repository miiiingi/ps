from typing import List
from math import sqrt
import heapq
class Solution:
    # 1. 원점에서의 거리를 기준으로 점들을 정렬함.
    # 2. 반복문 돌면서 k개 만큼 점들을 반환
    def cal_dist(self, x, y):
        return sqrt(x**2 + y**2)
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        queue = [(self.cal_dist(p[0], p[1]), p) for p in points]
        heapq.heapify(queue)
        answer = [h[-1] for h in heapq.nsmallest(k, queue)]
        print(answer)
        return answer 

        