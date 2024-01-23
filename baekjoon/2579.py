import sys
iter = int(sys.stdin.readline())
stair_list = [int(sys.stdin.readline()) for _ in range(iter)]
dp = [0 for _ in range(iter + 1)]
if iter == 1:
    dp[iter] = stair_list[0]
elif len(stair_list) == 2:
    dp[iter] = stair_list[0] + stair_list[1]
elif len(stair_list) == 3:
    dp[iter] = max(stair_list[0] + stair_list[2], stair_list[1] + stair_list[2])
else:
    dp[1] = stair_list[0]
    dp[2] = stair_list[0] + stair_list[1]
    dp[3] = max(stair_list[0] + stair_list[2], stair_list[1] + stair_list[2])
    for i in range(4, iter + 1):
        dp[i] = max(dp[i-2] + stair_list[i-1], dp[i-3] + stair_list[i-2] + stair_list[i-1])
print(dp[-1])

# 0 0 0 1 X
# 0 1 0 1 X
# 1 0 0 1 X
# 1 1 0 1 0
# 1 1 0 1 1

# 0 0 1 1 X
# 0 1 1 1 X
# 1 0 1 1 0
# 1 1 1 1 X
