import sys

input = sys.stdin.readline
n = int(input())
graph = [list(map(int, input().rstrip())) for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]


def dfs(i, j):
    if i < 0 or i >= n or j < 0 or j >= n or visited[i][j] == True or graph[i][j] == 0:
        return 0
    cnt = 1
    visited[i][j] = True
    cnt += dfs(i + 1, j)
    cnt += dfs(i - 1, j)
    cnt += dfs(i, j + 1)
    cnt += dfs(i, j - 1)
    return cnt


cnt = 0
house_cnt = []
for i in range(n):
    for j in range(n):
        if visited[i][j] == True or graph[i][j] == 0:
            continue
        house_cnt.append(dfs(i, j))
        cnt += 1
print(cnt)
for elem in sorted(house_cnt):
    print(elem)
