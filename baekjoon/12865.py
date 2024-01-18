import sys
N, K = map(int, sys.stdin.readline().split())
backpack_list = []
D = [0 for _ in range(N)]
for _ in range(N):
    W, V = map(int, sys.stdin.readline().split())
    backpack_list.append([W, V])
for i in range(len(backpack_list)):
    for j in range(0, i):
        pass




