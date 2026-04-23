import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
tower = deque(list(map(int, input().split())))
receive_list = [0 for _ in range(N)]
stack = []

for i in range(N):
    current_height = tower[i]
    while stack and stack[-1][1] < current_height:
        stack.pop()
    
    if stack:
        if stack[-1][1] > current_height:
            receive_list[i] = stack[-1][0] + 1
    
    stack.append([i, current_height])
print(*receive_list)
