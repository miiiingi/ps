import sys
sys.setrecursionlimit(12345678)
answer = []
while True:
    w, h = map(int, sys.stdin.readline().split())
    if w == 0 and h == 0:
        break
    else:
        count = 0
        maps = []
        for _ in range(h):
            maps.append(list(sys.stdin.readline().split()))
        d = [(-1, 0), (-1, -1), (-1, 1), (0, -1), (0, 1), (1, 0), (1, -1), (1, 1)]
        def dfs(i, j):
            global count
            for di, dj in d:
                ui = i + di
                uj = j + dj
                if ui >= 0 and uj >= 0 and ui < h and uj < w and maps[ui][uj] == '1':
                    maps[ui][uj] = '0'
                    dfs(ui, uj)
        for i in range(h):
            for j in range(w):
                if maps[i][j] == '1':
                    dfs(i, j)
                    count += 1
        answer.append(count)
for _ in answer:
    print(_)