# 현재 숫자에서 1을 빼게되면, 첫 번째 이전의 숫자가 되고 2를 빼게 되면, 두 번째 이전의 숫자, 3을 빼게 되면 세 번째 이전의 숫자가 된다.
# 따라서, 현재 숫자를 1,2,3으로 구성할 수 있는 수는 첫 번째, 두 번째, 세 번째 이전 숫자를 만드는 경우를 모두 더하면 된다. 따라서 점화식을 구현하면 아래와 같다. 
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

