import sys
T = int(sys.stdin.readline())

for _ in range(T):
    n = int(sys.stdin.readline())
    cnt_zero = 0
    cnt_one = 0
    memory = [[0, 0] for _ in range(n)]
    for i in range(n):
        if i == 0:
            memory[i][0] = 1
            memory[i][1] = 0
        elif i == 1:
            memory[i][0] = 0
            memory[i][1] = 1
        else:
            memory[i][0] = memory[i-1][0] + memory[i-2][0]
            memory[i][1] = memory[i-1][1] + memory[i-2][1]