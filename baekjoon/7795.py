import sys
T = int(sys.stdin.readline())
for _ in range(T):
    N, M = map(int, sys.stdin.readline().split())
    N_list = sorted(list(map(int, sys.stdin.readline().split())))
    M_list = sorted(list(map(int, sys.stdin.readline().split())))
    count = 0
    for comp in N_list:
        s, e = 0, len(M_list) - 1
        res = -1
        while s <= e:
            m = (s + e) // 2
            if M_list[m] < comp:
                res = m
                s = m + 1
            else:
                e = m - 1
        count += res + 1
    print(count)
