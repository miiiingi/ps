import sys
from itertools import combinations


input = sys.stdin.readline
house = []
chicken = []
maps = []
N, M = map(int, input().split())
for r in range(N):
    row = list(map(int, input().split()))
    for i, c in enumerate(row):
        if c == 1:
            house.append([r, i])
        elif c == 2:
            chicken.append([r, i])
    maps.append(row)
candidate = list(combinations(chicken, M))
# 3개를 고랐는데 어떻게 각 치킨집별로 최소 거리를 구할 것인가 ? > 모든 위치에서 각 치킨집까지의 거리를 구하고 최소 값을 도출한다.
cnt = []
all_chicken_dist = 10e9
for c1 in candidate:
    accum = 0
    for h in house:
        y, x = h
        min_chicken_dist = 10e9
        for c2 in c1:
            yc, xc = c2
            dist = abs(yc - y) + abs(xc - x)
            if dist < min_chicken_dist:
                min_chicken_dist = dist
        accum += min_chicken_dist
    if accum < all_chicken_dist:
        all_chicken_dist = accum
print(all_chicken_dist)
