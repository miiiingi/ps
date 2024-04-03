import sys
import collections
sys.setrecursionlimit(12345678)
def dfs(node):
    visited[node] = True
    dp[1][node] = 1
    for t in tree[node]:
        if visited[t]:
            continue
        dfs(t)
        dp[0][node] += dp[1][t] # 이 부분 해석하기
        dp[1][node] += min(dp[0][t], dp[1][t])

N = int(sys.stdin.readline())
tree = collections.defaultdict(list)
visited = [False for _ in range(N+1)]
dp = [[0 for _ in range(N+1)] for _ in range(2)]
for _ in range(N-1):
    u, v = map(int, sys.stdin.readline().split())
    tree[u].append(v)
    tree[v].append(u)
dfs(1)
print(min(dp[0][1], dp[1][1]))