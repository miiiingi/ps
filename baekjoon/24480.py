import sys
import collections
sys.setrecursionlimit(12345678)

def dfs(startV):
    global visited_order
    queue = collections.deque([startV])
    visited[startV] = visited_order
    while queue:
        q = queue.popleft()
        for v in graph[q]:
            if visited[v] == 0:
                visited_order += 1
                visited[v] = visited_order
                dfs(v)

N, M, R = map(int, sys.stdin.readline().split())
graph = collections.defaultdict(list)
visited = [0] * (N+1)
visited_order = 1
for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)
for k in graph.keys():
    graph[k] = sorted(graph[k], reverse = True)
dfs(R)
for ind in range(1, N+1):
    print(visited[ind])
