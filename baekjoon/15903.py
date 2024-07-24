import sys
import heapq
m, n = map(int, sys.stdin.readline().split())
answer = 0 
a = list(map(int, sys.stdin.readline().split()))
while(n > 0):
    pre_answer = 0
    heapq.heapify(a)
    for _ in range(2):
        pre_answer += heapq.heappop(a)
    for _ in range(2): 
        heapq.heappush(a, pre_answer)
    n -= 1
print(sum(a))