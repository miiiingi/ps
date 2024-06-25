import sys
N = int(sys.stdin.readline())
DP = [0 for _ in range(1001)]
if 1 <= N <= 2:
    DP[1] = 1
    DP[2] = 2 
else:
    DP[1] = 1
    DP[2] = 2
    for i in range(3, N+1):
        DP[i] = DP[i-1] + DP[i-2]
print(DP[N] % 10007)
