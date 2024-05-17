# stack이나 정렬 문제라고해서 완전히 그 형태로 만들어야된다는 생각은 버리고 규칙, 제약 조건을 먼저 생각해보자
# [[3, 8], [12, 18], [20, 25]] 4
# [[7, 13], [15, 21]] 3
# [[2, 14]] 2
# [[6, 20]] 1
# [[6, 27]] 5
import sys
import heapq
N = int(sys.stdin.readline())
time_list = [[] for _ in range(N)]
pq = []
num_lectures = 0
for ind in range(N):
    num_l, time_s, time_e = map(int, sys.stdin.readline().split())
    time_list[ind].append(time_s)
    time_list[ind].append(time_e)
    time_list[ind].append(num_l)
time_list = sorted(time_list, key = lambda x: (x[0], x[1]))
p = None
for ind in range(N):
    if len(pq) > 0:
        if pq[0][0] > time_list[ind][0]:
            num_lectures += 1
        else:
            p = heapq.heappop(pq)
    else:
        num_lectures += 1
    if p is not None:
        time_list[ind][2] = p[2]
    heapq.heappush(pq, ([time_list[ind][1], time_list[ind][0], num_lectures]))
elements_set = {sublist[2] for sublist in time_list}
print(len(elements_set))
for time in time_list:
    print(list(elements_set).index(time[2]))

