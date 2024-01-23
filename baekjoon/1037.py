import sys
iter = int(sys.stdin.readline())
num_list = sorted([int(n) for n in sys.stdin.readline().split()])
if len(num_list) == 1:
    print(num_list[0] ** 2)
else:
    print(num_list[0] * num_list[-1])