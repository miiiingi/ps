import sys
N, K = map(int, sys.stdin.readline().split())
backpack_list = []
DP = []
for _ in range(N):
    W, V = map(int, sys.stdin.readline().split())
    backpack_list.append([W, V])
for i in range(len(backpack_list)+1):
    DP.append([])
    for c in range(K+1):
        if i == 0 or c == 0 :
            DP[i].append(0)
        elif backpack_list[i-1][0] <= c:
            DP[i].append(max(backpack_list[i-1][1] + DP[i-1][c-backpack_list[i-1][0]], DP[i-1][c]))
        else:
            DP[i].append(DP[i-1][c])
print(DP[-1][-1])
