import sys
num_people = int(sys.stdin.readline())
times = sorted(list(map(int, sys.stdin.readline().split())))
time_consumed = [0 for _ in range(num_people)]
for i in range(num_people):
    if i == 0:
        time_consumed[i] = times[i]
    else:
        time_consumed[i] = time_consumed[i-1] + times[i]
print(sum(time_consumed))
