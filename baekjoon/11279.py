import sys
import heapq
N = int(sys.stdin.readline())
heap = []
answer = []
for _ in range(N):
    x = int(sys.stdin.readline())
    if x != 0:
        heapq.heappush(heap, -x)
    else:
        if heap:
            p = heapq.heappop(heap)
            answer.append(-p)
        else:
            answer.append(0)
for a in answer:
    print(a)
