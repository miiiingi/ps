import sys
import collections
def bfs(index):
    locations = collections.deque([index, 0])
    while locations:
        location, visited = locations.popleft()
        if visited == 0 :
            continue
        pass
N = int(sys.stdin.readline())
town = collections.defaultdict(list)
people_list = list(map(int, sys.stdin.readline().split()))
for _ in range(N-1):
    u, v = map(int, sys.stdin.readline().split())
    town[u].append(v)
    town[v].append(u)

bfs(people_list.index(max(people_list)))



