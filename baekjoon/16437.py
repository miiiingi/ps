import sys
import collections


def dfs(root):
    sheeps = 0
    wolf = 0
    for v in graph[root]:
        if info[v-2][0] == 'S':
            sheeps += info[v-2][1]
        else:
            wolf += info[v-2][1]
        sheeps += dfs(v)
    else:
        pass # 작성
    return sheeps


N = int(sys.stdin.readline())
info = []
sheeps = 0
graph = collections.defaultdict(list)
queue = collections.deque()
sheeps = 0
for _ in range(N-1):
    animal, number, linked_node = list(sys.stdin.readline().split())
    info.append([animal, int(number), int(linked_node)])

for ind, i in enumerate(info):
    graph[i[2]].append(ind+2)
dfs(1)
