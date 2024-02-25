import sys
from collections import deque


def findDest(startX, startY, destX, destY, remainedFuel):
    # 손님을 태우고 목적지로 향하는 함수
    fuelMap = [[0 for _ in range(N)] for _ in range(N)]
    visited = [[0 for _ in range(N)] for _ in range(N)]
    locations = deque()
    locations.append([startX, startY, remainedFuel])
    while locations:
        x, y, F = locations.popleft()
        if F <= -1:
            return -1
        if destX == x and destY == y:
            return F + (remainedFuel - F) * 2
        visited[x][y] = 1
        fuelMap[x][y] = F
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ux = x + dx
            uy = y + dy
            uF = F - 1
            if ux < 0 or ux >= N or uy < 0 or uy >= N or visited[ux][uy] == 1 or wall[ux][uy] == 1:
                continue
            if visited[ux][uy] != 1 and wall[ux][uy] != 1:
                visited[ux][uy] = 1
                fuelMap[ux][uy] = uF
                locations.append([ux, uy, uF])
    print(-1)
    exit(0)


def bfs(startX, startY, fuel):
    fuelMap = [[0 for _ in range(N)] for _ in range(N)]
    visited = [[0 for _ in range(N)] for _ in range(N)]
    locations = deque()
    locations.append([startX, startY, fuel])
    finded = False
    findedList = []
    remainedFuel = fuel
    if startList[startX][startY] != 0:
        finededNumber = startList[startX][startY]
        destX, destY = endList[finededNumber-1]
        regainedFuel = findDest(startX, startY, destX, destY, remainedFuel)
        startList[startX][startY] = 0
        return destX, destY, regainedFuel
    while locations:
        x, y, F = locations.popleft()
        if F <= -1:
            return -1, -1, -1
        visited[x][y] = 1
        fuelMap[x][y] = F
        # 이렇게 가야 행 > 열 순서로 탐색을하고 행 번호가 커지지않도록 탐색가능하다.
        for dx, dy in [(-1, 0), (0, -1), (0, 1), (1, 0)]:
            ux = x + dx
            uy = y + dy
            uF = F - 1
            if ux < 0 or ux >= N or uy < 0 or uy >= N or visited[ux][uy] == 1 or wall[ux][uy] == 1:
                continue
            if visited[ux][uy] != 1 and wall[ux][uy] != 1:
                visited[ux][uy] = 1
                fuelMap[ux][uy] = uF
                locations.append([ux, uy, uF])

        if startList[x][y] != 0 and finded and remainedFuel == F:
            findedList.append([x, y])

        if F < remainedFuel and finded:
            findedList.sort()
            startX, startY = findedList[0][0], findedList[0][1]
            finededNumber = startList[startX][startY]
            destX, destY = endList[finededNumber-1]
            regainedFuel = findDest(startX, startY, destX, destY, remainedFuel)
            startList[startX][startY] = 0
            return destX, destY, regainedFuel

        if startList[x][y] != 0 and not finded:
            finded = True
            remainedFuel = F
            findedList.append([x, y])
            if findedList and not locations:
                findedList.sort()
                startX, startY = findedList[0][0], findedList[0][1]
                finededNumber = startList[startX][startY]
                destX, destY = endList[finededNumber-1]
                regainedFuel = findDest(startX, startY, destX, destY, remainedFuel)
                startList[startX][startY] = 0
                return destX, destY, regainedFuel

    print(-1)
    exit(0)


N, M, fuel = map(int, sys.stdin.readline().split(' '))
cnt = 0
startList = [[0 for _ in range(N)] for _ in range(N)]
endList = [[0, 0] for _ in range(M)]
wall = [[] for _ in range(N)]


for i in range(N):
    wall[i] = list(map(int, sys.stdin.readline().split(' ')))
startX, startY = map(int, sys.stdin.readline().split(' '))
for i in range(1, M+1):
    userStartX, userStartY, destX, destY = list(
        map(int, sys.stdin.readline().split(' ')))
    startList[userStartX-1][userStartY-1] = i
    endList[i-1][0] = destX-1
    endList[i-1][1] = destY-1

startX -= 1
startY -= 1
for _ in range(M):
    startX, startY, fuel = bfs(startX, startY, fuel)
print(fuel)
