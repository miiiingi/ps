import itertools 
N, K = map(int, input().split())
print(len(list(itertools.combinations([n for n in range(1, N + 1)], K))))