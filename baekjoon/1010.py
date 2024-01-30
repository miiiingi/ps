import sys
import itertools
iter = int(sys.stdin.readline())
for _ in range(iter):
    N, M = map(int, sys.stdin.readline().split())
    denominator = 1
    numerator = 1
    for d in range(1, N+1):
        denominator *= d
    for n in range(M-N+1, M+1):
        numerator *= n
    print(int(numerator / denominator))
