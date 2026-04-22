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
print(house)
print(candidate)
# 3개를 고랐는데 어떻게 각 치킨집별로 최소 거리를 구할 것인가 ? > 모든 위치에서 각 치킨집까지의 거리를 구하고 최소 값을 도출한다.
cnt = []
for c1 in candidate:
    accum = 0
    for c2 in c1:
        yc, xc = c2
        dist = []
        for h in house:
            y, x = h
            dist.append(abs(yc - y) + abs(xc - x))
            print(f"h: {h}, yc: {yc}, xc: {xc}, dist: {abs(yc-y) + abs(xc-x)}")
        accum += sum(dist)
    cnt.append(accum)
print(F'cnt: {cnt}')
print(f"cnt min ind: {cnt.index(min(cnt))}")
print(f'f candi: {candidate[9]}')
