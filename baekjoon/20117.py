import sys
import collections
N = sys.stdin.readline()
answer = 0
quality = collections.deque(sorted(list(map(int, sys.stdin.readline().split()))))
while quality:
    if len(quality) == 1:
        num_tail = quality.pop()
        answer += num_tail
        break
    num_head = quality.popleft()
    num_tail = quality.pop()
    answer += (num_tail * 2)
print(answer)
