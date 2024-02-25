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
        # 연료가 0인 상태에서 한 칸 더 간 경우
        if F <= -1:
            print(-1)
            exit(0)
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
            visited[ux][uy] = 1
            fuelMap[ux][uy] = uF
            locations.append([ux, uy, uF])

    # 손님을 찾지 못했는데, 더 이상 갈 수 있는 곳이 없는 상태 -> 갇혔다거나.. 
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
    # 만약 택시의 시작점에 손님이 있는 경우 -> 바로 목적지 탐색.
    if startList[startX][startY] != 0:
        finededNumber = startList[startX][startY]
        destX, destY = endList[finededNumber-1]
        regainedFuel = findDest(startX, startY, destX, destY, remainedFuel)
        startList[startX][startY] = 0
        return destX, destY, regainedFuel
    while locations:
        x, y, F = locations.popleft()
        if F <= -1:
            # 연료가 0인 상태에서 한 칸 더 간 경우
            print(-1)
            exit(0)
        visited[x][y] = 1
        fuelMap[x][y] = F
        # 행 > 열 순서로 탐색, 행 번호가 커지지않도록 탐색.
        for dx, dy in [(-1, 0), (0, -1), (0, 1), (1, 0)]:
            ux = x + dx
            uy = y + dy
            uF = F - 1
            if ux < 0 or ux >= N or uy < 0 or uy >= N or visited[ux][uy] == 1 or wall[ux][uy] == 1:
                continue
            visited[ux][uy] = 1
            fuelMap[ux][uy] = uF
            locations.append([ux, uy, uF])

        # 같은 거리에 손님이 있는 경우, 그 손님을 findedList에 추가함. -> bfs이기 때문에 처리를 해줘야함.
        if startList[x][y] != 0 and finded and remainedFuel == F:
            findedList.append([x, y])

        # 찾은 상태에서 더 탐색하려고 할 때, 바로 찾은 손님들 중에서 가장 행 번호, 열 번호가 작은 손님의 목적지를 향해서 출발함.
        if F < remainedFuel and finded:
            findedList.sort()
            startX, startY = findedList[0][0], findedList[0][1]
            finededNumber = startList[startX][startY]
            destX, destY = endList[finededNumber-1]
            regainedFuel = findDest(startX, startY, destX, destY, remainedFuel)
            startList[startX][startY] = 0
            return destX, destY, regainedFuel

        # 처음 손님을 만났을 때, finded 함수를 True로 설정
        if startList[x][y] != 0 and not finded:
            finded = True
            remainedFuel = F
            findedList.append([x, y])
            if findedList and not locations:
                findedList.sort()
                startX, startY = findedList[0][0], findedList[0][1]
                finededNumber = startList[startX][startY]
                destX, destY = endList[finededNumber-1]
                regainedFuel = findDest(
                    startX, startY, destX, destY, remainedFuel)
                startList[startX][startY] = 0
                return destX, destY, regainedFuel

    # 손님을 찾지 못했는데, 더 이상 갈 수 있는 곳이 없는 상태 -> 갇혔다거나.. 
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
