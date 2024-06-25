import sys
N = int(sys.stdin.readline())
DP = [0 for _ in range(91)]
if 1 <= N <= 3:
    DP[1] = 1
    DP[2] = 1
    DP[3] = 2
else:
    DP[1] = 1
    DP[2] = 1
    DP[3] = 2
    for i in range(4, N+1):
        DP[i] = DP[i-1] + DP[i-2]
print(DP[N])