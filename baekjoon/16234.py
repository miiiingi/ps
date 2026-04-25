import sys
from collections import deque

input = sys.stdin.readline

N, L, R = map(int, input().split())
MOVE = [[-1, 0], [1, 0], [0, -1], [0, 1]]
maps = [list(map(int, input().split())) for _ in range(N)]
cnt = 0
while True:
    visited = [[False] * N for _ in range(N)]
    updated = False
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                queue = deque()
                accum = 0
                candidate = []
                queue.append([i, j])
                candidate.append([i, j])
                accum += maps[i][j]
                visited[i][j] = True
                while queue:
                    poped = queue.popleft()
                    y, x = poped
                    for dy, dx in MOVE:
                        ny, nx = y + dy, x + dx
                        if ny < 0 or ny >= N or nx < 0 or nx >= N or visited[ny][nx]:
                            continue
                        if L <= abs(maps[y][x] - maps[ny][nx]) <= R:
                            queue.append([ny, nx])
                            candidate.append([ny, nx])
                            accum += maps[ny][nx]
                            visited[ny][nx] = True

                if len(candidate) > 1:
                    updated = True
                    for c in candidate:
                        y, x = c
                        maps[y][x] = accum // len(candidate)

    if not updated:
        break
    cnt += 1
print(cnt)
