import sys
N = int(sys.stdin.readline())
for num in range(1, N+1):
    sum_num = num
    for n in str(num):
        sum_num += int(n)
    if sum_num == N:
        print(num)
        break
else:
    print(0)