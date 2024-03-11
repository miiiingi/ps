
# 만약 원래 존재하는 리스트를 우선순위 큐로 바꾼다면, 먼 거리에 있는 것들도 앞으로 나올테니까 이것은 부적절
# 그렇다면 거리와 연료를 비교하면서 하나씩 빼서 우선순위 큐에 넣는다.
# 단위거리 획득 연료량이 많은 순대로 ? -> 거리가 가장 먼 곳 or 연료가 가장 많이 얻을 수 있는 곳
# fuel: 갈 수 있는 최대거리
import sys
import heapq
from collections import deque
N = int(sys.stdin.readline())
info = deque(sorted([list(map(int, sys.stdin.readline().split()))
                     for _ in range(N)], key=lambda x: x[0]))
destination, fuel = map(int, sys.stdin.readline().split())
count = 0
visited = []
if fuel >= destination:
    print(0)
    sys.exit()
while info:
    heap_list = []
    for i in range(len(info)):
        if info[i][0] > fuel:
            continue
        e = info[i]
        heapq.heappush(heap_list, [-e[1], e[0], e[1]])
    if not heap_list:
        print(-1)
        break
    for _ in range(len(heap_list)):
        info.popleft()
    while heap_list:
        heap = heapq.heappop(heap_list)  # 원소가 3개
        fuel += heap[2]
        count += 1
        move_cnt = 0
        for i in range(len(info)):
            if info[i][0] > fuel:
                break
            heapq.heappush(heap_list, [-info[i][1], info[i][0], info[i][1]])
            move_cnt += 1
        for _ in range(move_cnt):
            info.popleft()
        if fuel >= destination:
            break
    else:
        print(-1)
        break
    if fuel >= destination:
        print(count)
        break
else:
    print(-1)
