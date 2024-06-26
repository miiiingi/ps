import sys
import collections
sys.setrecursionlimit(12345678)

def dfs(startV):
    global visited
    global count
    global final_count
    queue.append(startV)
    visited.append(startV)
    while queue:
        q = queue.popleft()
        for v in graph[q]:
            if v not in visited:
                count += 1
                if v == e:
                    visited.append(v)
                    final_count = count
                    return
                dfs(v)
                count -= 1

graph = collections.defaultdict(list)
queue = collections.deque()
visited = []
count = 0
final_count = 0
n = int(sys.stdin.readline())
s, e = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())
for _ in range(m):
    p, c = map(int, sys.stdin.readline().split())
    graph[p].append(c)
    graph[c].append(p)
dfs(s)
if e in visited:
    print(final_count)
else:
    print(-1)