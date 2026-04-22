import sys

NORTH = 0
EAST = 1
SOUTH = 2
WEST = 3
move_dict = {NORTH: WEST, WEST: SOUTH, SOUTH: EAST, EAST: NORTH}

input = sys.stdin.readline

n, m = map(int, input().split())

r, c, d = map(int, input().split())

room = [list(map(int, input().split())) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

cnt = 0

while True:
    if room[r][c] == 0 and not visited[r][c]:
        visited[r][c] = True
        cnt += 1
    if (
        (room[r - 1][c] == 0 and not visited[r - 1][c])
        or (room[r + 1][c] == 0 and not visited[r + 1][c])
        or (room[r][c - 1] == 0 and not visited[r][c - 1])
        or (room[r][c + 1] == 0 and not visited[r][c + 1])
    ):
        for _ in range(4):
            d = move_dict[d]
            if d == NORTH:
                if room[r - 1][c] == 0 and not visited[r - 1][c]:
                    r -= 1
                    break
            elif d == EAST:
                if room[r][c + 1] == 0 and not visited[r][c + 1]:
                    c += 1
                    break
            elif d == SOUTH:
                if room[r + 1][c] == 0 and not visited[r + 1][c]:
                    r += 1
                    break
            else:
                if room[r][c - 1] == 0 and not visited[r][c - 1]:
                    c -= 1
                    break
    else:
        if d == NORTH:
            if room[r + 1][c] == 1:
                break
            else:
                r += 1
        elif d == EAST:
            if room[r][c - 1] == 1:
                break
            else:
                c -= 1
        elif d == SOUTH:
            if room[r - 1][c] == 1:
                break
            else:
                r -= 1
        else:
            if room[r][c + 1] == 1:
                break
            else:
                c += 1

print(cnt)