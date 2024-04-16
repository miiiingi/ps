import sys
N, K = map(int, sys.stdin.readline().split())
backpack_list = []
DP = [[[0, 0] for _ in range(N)] for _ in range(2)]
for _ in range(N):
    W, V = map(int, sys.stdin.readline().split())
    backpack_list.append([W, V])
backpack_list = sorted(backpack_list, key=lambda x: x[0])
for i in range(len(backpack_list)):
    if i == 0 :
        if backpack_list[i][0] <= K:
            DP[1][i][0] = backpack_list[i][0]
            DP[1][i][1] = backpack_list[i][1]
        else:
            DP[1][i][0] = backpack_list[i][0]
            DP[1][i][1] = 0
    else:
        if DP[1][i-1][0] + backpack_list[i][0] <= K:
            DP[1][i][0] = backpack_list[i][0]
            DP[1][i][1] = backpack_list[i][1]
        else:
            DP[1][i][0] = backpack_list[i][0]
            DP[1][i][1] = 0





