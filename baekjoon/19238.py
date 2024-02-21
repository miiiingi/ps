import sys
N, M, F = map(int, sys.stdin.readline().split(' '))
cnt = 0
Map = [[] for _ in range(N)]
Users = [[] for _ in range(M)]
visited = []

for i in range(N):
    Map[i] = list(map(int, sys.stdin.readline().split(' ')))
start_x, start_y = map(int, sys.stdin.readline().split(' '))
for i in range(M):
    Users[i] = list(map(int, sys.stdin.readline().split(' ')))

# 필요한 것: 지금까지 몇 번 움직였는지 -> 이것을 이용해서 가장 가까이에 있는 승객을 알아내야함.
# 그리고 그 후에 다시 visited을 초기화하고 도착지까지 연료가 몇 소모되는지 계산해야함.

def dfs(i, j, dest_x, dest_y, visited, cnt):
    if i < 0 or i >= len(Map) or j < 0 or j >= len(Map[0]) or Map[i][j] == 1 or [i, j] in visited or (i==dest_x and j==dest_y):
        return
    Map[i][j] = 1
    visited.append([i, j])
    cnt +=1
    dfs(i, j-1, dest_x, dest_y, visited, cnt)
    dfs(i+1, j, dest_x, dest_y, visited, cnt)
    dfs(i-1, j, dest_x, dest_y, visited, cnt)
    dfs(i, j+1, dest_x, dest_y, visited, cnt)

for User in Users:
    dfs(start_x-1, start_y-1, User[0]-1, User[1]-1,visited, cnt)