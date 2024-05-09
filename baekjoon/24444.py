import sys
import collections


def bfs(startV):
    global visited_order
    queue = collections.deque([startV])
    visited[startV] = visited_order
    while queue:
        q = queue.popleft()
        for v in graph[q]:
            if visited[v] == 0:
                queue.append(v)
                visited_order += 1
                visited[v] = visited_order

N, M, R = map(int, sys.stdin.readline().split())
graph = collections.defaultdict(list)
visited = [0] * (N+1)
visited_order = 1
for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)
for k in graph.keys():
    graph[k] = sorted(graph[k])
bfs(R)
for ind in range(1, N+1):
    print(visited[ind])
