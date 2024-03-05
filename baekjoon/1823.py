import sys
sys.setrecursionlimit(2000000)


def solve(l, r):
    if memory[l][r] != 0:
        return memory[l][r]
    if l == r:
        memory[l][r] = N * deque[l]
        return memory[l][r]
    w = N - (r-l)
    memory[l][r] = max(w*deque[l]+solve(l+1, r), w*deque[r]+solve(l, r-1))
    return memory[l][r]


N = int(sys.stdin.readline())
visited = []
deque = []
memory = [[0 for _ in range(N)]for _ in range(N)]
for _ in range(N):
    deque.append(int(sys.stdin.readline()))
result = solve(0, N-1)
print(result)
