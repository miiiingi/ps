import sys
def min_p(min):
    s, e = 0, len(dot) - 1
    while s <= e:
        m = (s + e) // 2
        if dot[m] < min:
            s = m + 1
        else:
            e = m - 1
    return e + 1

def max_p(max):
    s, e = 0, len(dot) - 1
    while s <= e:
        m = (s + e) // 2
        if dot[m] <= max:
            s = m + 1
        else:
            e = m - 1
    return e

N, M = map(int, sys.stdin.readline().split())
dot = sorted(list(map(int, sys.stdin.readline().split())))
for _ in range(M):
    M_list = list(map(int, sys.stdin.readline().split()))
    max_ind = max_p(M_list[-1])
    min_ind = min_p(M_list[0])
    print(max_ind - min_ind + 1)