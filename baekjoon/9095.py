import sys
iter = int(sys.stdin.readline())
answer_list = [] 
for _ in range(iter):
    dp = [0 for _ in range(12)]
    n = int(sys.stdin.readline())
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4
    for i in range(4, n+1):
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
    answer_list.append(dp[n])
for answer in answer_list:
    print(answer)

