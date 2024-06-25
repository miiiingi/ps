import sys
sys.setrecursionlimit(12345678)
R, C, K = map(int, sys.stdin.readline().split())
count = 0
maps = []
for _ in range(R):
    maps.append(list(sys.stdin.readline().strip()))
d = [(-1, 0), (0, -1), (0, 1), (1, 0)]
maps[R-1][0] = 1
def dfs(i, j):
    global count
    if i == 0 and j == C-1:
        if maps[i][j] == K:
            count += 1
        return
    for di, dj in d:
        ui = i + di
        uj = j + dj
        if ui >= 0 and uj >= 0 and ui < R and uj < C:
            if maps[ui][uj] == '.':
                maps[ui][uj] = maps[i][j] + 1
                dfs(ui, uj)
                maps[ui][uj] = '.'
dfs(R-1, 0)
print(count)