import sys
import bisect
N, M = map(int, sys.stdin.readline().split())
M_list = list(map(int, sys.stdin.readline().split()))
M_list_acc = [0] * M
M_list_acc[0] = M_list[0]
for i in range(1, M):
    M_list_acc[i] = M_list_acc[i-1] + M_list[i]
N_list = []
for _ in range(N):
    N_list.append(int(sys.stdin.readline()))
for ind_N in range(len(N_list)):
    index = bisect.bisect_left(M_list_acc, N_list[ind_N])
    if index < M :
        print(index + 1)
    else:
        print("Go away!")