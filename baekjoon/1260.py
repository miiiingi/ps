import sys
import collections
def dfs(graph, start_v): # stack
    visited = ''
    stack = collections.deque([start_v])
    while stack:
        p = stack.pop()
        if str(p) not in visited:
            visited += str(p)
            for v in graph[p][::-1]:
                stack.append(v)
    return ' '.join(visited)
def bfs(graph, start_v): # queue
    visited = ''
    queue = collections.deque([start_v])
    while queue:
        p = queue.popleft() 
        if str(p) not in visited:
            visited += str(p)
            for v in graph[p]:
                queue.append(v)
    return ' '.join(visited)


N, M, V = map(int, sys.stdin.readline().split())
graph = collections.defaultdict(list)
for _ in range(M):
    s, e = map(int, sys.stdin.readline().split())
    graph[s].append(e)
    graph[e].append(s)

print(dfs(graph, start_v = V))
print(bfs(graph, start_v = V))