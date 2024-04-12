import sys
import collections
sys.setrecursionlimit(12345678)
def dfs(node):
    global deletedNode
    if node == deletedNode:
        nodes[node] = -2
    visited[node] = True
    for c in tree[node]:
        if visited[c]:
            continue
        if node == deletedNode or nodes[c] == -2 or nodes[node] == -2:
            nodes[c] = -2
            nodes[node] = -2
        dfs(c)
N = int(sys.stdin.readline())
nodes = list(map(int, sys.stdin.readline().split()))
deletedNode = int(sys.stdin.readline())
visited=[False for _ in range(N)]
tree = collections.defaultdict(list)
cnt = 0
for i in range(N):
    if nodes[i] != -1:
        tree[nodes[i]].append(i)
        continue
    rootNode = i
dfs(rootNode)
for i in range(len(nodes)):
    if nodes[i] != -2 and i not in nodes:
        cnt += 1
print(cnt)