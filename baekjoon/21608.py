import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
MOVE = [[-1, 0], [1, 0], [0, -1], [0, 1]]
student = dict()
for _ in range(N * N):
    temp = deque(map(int, input().split()))
    poped = temp.popleft()
    student[poped] = temp
room = [[0 for _ in range(N)] for _ in range(N)]
registered = []
for ind, (k, v) in enumerate(student.items()):
    if ind == 0:
        room[N // 2][N // 2] = k
        registered.append(k)
        print(room)
    else:
        liked = []
        for vi in v:
            if vi in registered:
                liked.append(vi)
        target = []
        print(f"ind: {ind}, liked: {liked}")
        for i in range(N):
            for j in range(N):
                if liked:
                    for l in liked:
                        if room[i][j] == l:
                            for m in MOVE:
                                x, y = m
                                nx, ny = i + x, j + y
                                if (
                                    nx < 0
                                    or nx >= N
                                    or ny < 0
                                    or ny >= N
                                    or room[nx][ny] != 0
                                ):
                                    continue
                                cnt = 0
                                for m2 in MOVE:
                                    x2, y2 = m2
                                    nx2, ny2 = nx + x2, ny + y2
                                    if (
                                        nx2 < 0
                                        or nx2 >= N
                                        or ny2 < 0
                                        or ny2 >= N
                                        or room[nx2][ny2] != 0
                                    ):
                                        continue
                                    print(f"a nx2: {nx2}, ny2: {ny2}")
                                    cnt += 1
                                target.append([nx, ny, cnt])
                                print(f"58 target: {target}")
                else:
                    if room[i][j] != 0:
                        continue
                    for m in MOVE:
                        x, y = m
                        nx, ny = i + x, j + y
                        if nx < 0 or nx >= N or ny < 0 or ny >= N:
                            continue
                        cnt = 0
                        for m2 in MOVE:
                            x2, y2 = m2
                            nx2, ny2 = nx + x2, ny + y2
                            if (
                                nx2 < 0
                                or nx2 >= N
                                or ny2 < 0
                                or ny2 >= N
                                or room[nx2][ny2] != 0
                            ):
                                continue
                            cnt += 1
                        target.append([nx, ny, cnt])
        if target:
            target.sort(key=lambda x: (-x[2], x[0], x[1]))
            print(f'83 target: {target}')
            x, y, c = target[0]
            room[x][y] = k
            registered.append(k)
            print(room)
# print(room)