import sys
import collections
N, K = map(int, sys.stdin.readline().split())
num_list = collections.deque([i for i in range(1, N + 1)])
answer = ''
while num_list:
    for _ in range(K-1):
        num_list.rotate(-1)
    p = num_list.popleft()
    answer += str(p)
print(f"<{', '.join(answer)}>")

