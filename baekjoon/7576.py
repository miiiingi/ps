import sys
from collections import deque

RIPES = deque()
NOTRIPES = deque()
NOTGO = deque()
DIRECTION = [[-1, 0], [1, 0], [0, -1], [0, 1]]
input = sys.stdin.readline

m, n = map(int, input().split())

visited = [[False for _ in range(m)] for _ in range(n)]
memory = [[0 for _ in range(m)] for _ in range(n)]
storage = [list(map(int, input().split())) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if storage[i][j] == 1:
            RIPES.append([i, j])
            visited[i][j] = True
while RIPES:
    coord_ripes = RIPES.popleft()
    y, x = coord_ripes
    for d in DIRECTION:
        dy, dx = d
        ny = y + dy
        nx = x + dx
        if nx < 0 or nx >= m or ny < 0 or ny >= n or visited[ny][nx]:
            continue
        if storage[ny][nx] == -1 or storage[ny][nx] == 1:
            continue
        memory[ny][nx] = memory[y][x] + 1
        visited[ny][nx] = True
        RIPES.append([ny, nx])
cnt = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j] and storage[i][j] != -1:
            print(-1)
            exit(0)
        if memory[i][j] > cnt:
            cnt = memory[i][j]
print(cnt)