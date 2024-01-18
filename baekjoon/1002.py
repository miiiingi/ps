import math
iter = int(input())
for _ in range(iter):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
    l_r, s_r = max(r1, r2), min(r1, r2)
    if x1 == x2 and y1 == y2 and r1 == r2:
        print(-1)
    elif l_r + s_r < distance or s_r + distance < l_r:
        print(0)
    elif l_r + s_r == distance or s_r + distance == l_r:
        print(1)
    elif l_r + s_r > distance or s_r + distance > l_r:
        print(2)
    