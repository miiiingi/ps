import sys
import collections
def dfs(node):
    global cnt
    if node == deletedNode:
        return
    visited[node] = True
    for c in tree[node]:
        if visited[c]:
            continue
        dfs(c)
    else:
        if len(tree[node]) == 0 :
            cnt += 1
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
print(cnt)
