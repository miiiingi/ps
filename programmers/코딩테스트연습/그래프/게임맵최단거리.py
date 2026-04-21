from collections import deque


def solution(maps):
    n = len(maps)
    m = len(maps[0])
    queue = deque()
    queue.append([0, 0])
    d = [[-1, 0], [1, 0], [0, 1], [0, -1]]
    while queue:
        x, y = queue.popleft()
        for dx, dy in d:
            nx, ny = x + dx, y + dy
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if maps[nx][ny] == 0:
                continue
            if maps[nx][ny] == 1:
                print(f"nx: {nx}, ny: {ny}")
                maps[nx][ny] = maps[x][y] + 1
                queue.append([nx, ny])
    answer = maps[n - 1][m - 1]
    return answer
