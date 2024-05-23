# stack이나 정렬 문제라고해서 완전히 그 형태로 만들어야된다는 생각은 버리고 규칙, 제약 조건을 먼저 생각해보자
# [[3, 8], [12, 18], [20, 25]] 4
# [[7, 13], [15, 21]] 3
# [[2, 14]] 2
# [[6, 20]] 1
# [[6, 27]] 5
import sys
import heapq
N = int(sys.stdin.readline())
time_list = []
room = [0] * N
pq = []
num_lectures = 0
for _ in range(N):
    num_l, time_s, time_e = map(int, sys.stdin.readline().split())
    time_list.append([time_s, time_e, num_l-1])
time_list = sorted(time_list, key = lambda x: (x[0], x[1]))
for s, e, idx in time_list:
    if len(pq) > 0:
        if pq[0][0] > s:
            num_lectures += 1
            room[idx] = num_lectures
        else:
            room[idx] = room[pq[0][2]]
            heapq.heappop(pq)
    else:
        num_lectures += 1
        room[idx] = num_lectures
    heapq.heappush(pq, ([e, s, idx]))
print(num_lectures)
for i in room:
    print(i)