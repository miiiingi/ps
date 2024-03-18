import sys
import collections
import heapq


def search_tree(index):
    global answer
    visited[index].append(True)
    for t in town[index]:
        visited[t].append(False)


def dfs(node):
    visited[node] = True
    dp[0][node] = 0  # 해당 마을이 우수마을이 아닌경우
    dp[1][node] = people_list[node]  # 해당 마을이 우수마을인 경우
    for t in town[node]:
        if visited[t]:
            continue
        dfs(t)
        dp[0][node] += max(dp[0][t], dp[1][t]) # 이 부분 해석하기
        dp[1][node] += dp[0][t]


N = int(sys.stdin.readline())
town = collections.defaultdict(list)
people_list = list(map(int, sys.stdin.readline().split()))
queue = []
for i in range(len(people_list)):
    heapq.heappush(queue, (-people_list[i], i))

visited = [None for _ in range(N)]
dp = [[0 for _ in range(N)] for _ in range(2)]
for _ in range(N-1):
    u, v = map(int, sys.stdin.readline().split())
    town[u-1].append(v-1)
    town[v-1].append(u-1)

print(dfs(0))

# for i in range(N):
#     p = heapq.heappop(queue)
#     max_ind = p[1]
#     if not visited[max_ind]:
#         search_tree(max_ind)
#         answer += -1 * p[0]
