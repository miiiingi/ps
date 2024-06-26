import sys
import collections
sys.setrecursionlimit(12345678)

def dfs(startV):
    global visited
    queue.append(startV)
    visited.append(startV)
    while queue:
        q = queue.popleft()
        for v in graph[q]:
            if v not in visited:
                dfs(v)

graph = collections.defaultdict(list)
queue = collections.deque()
visited = []
count = 0
num_edges = int(sys.stdin.readline())
num_nodes = int(sys.stdin.readline())
for _ in range(num_nodes):
    s, e = map(int, sys.stdin.readline().split())
    graph[s].append(e)
    graph[e].append(s)
dfs(1)
print(len(visited) - 1)