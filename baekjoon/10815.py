import sys
answer = [] 
N = int(sys.stdin.readline())
N_list = set(list(map(int, sys.stdin.readline().split())))
M = int(sys.stdin.readline())
M_list = list(map(int, sys.stdin.readline().split()))
for m in M_list:
    if m in N_list:
        if m == M_list[-1]:
            print(1)
        else:
            print(1, end = ' ')
    else:
        if m == M_list[-1]:
            print(0)
        else:
            print(0, end = ' ')