import sys
from datetime import datetime
N = int(sys.stdin.readline())
if N == 0:
    print(0)
else:
    time_list = [[] for _ in range(N)]
    X_1 = 0
    X_2 = 0
    time_format = "%Y/%m/%d %H:%M:%S"
    for ind in range(N):
        t1, t2, l = sys.stdin.readline().split()
        time_list[ind].append(t1)
        time_list[ind].append(t2)
        time_list[ind].append(l)
    time_list = sorted(time_list, key = lambda x : (x[0], x[1]))
    datetime2 = datetime.strptime(f"{time_list[-1][0]} {time_list[-1][1]}", time_format)
    for ind in range(N):
        datetime1 = datetime.strptime(f"{time_list[ind][0]} {time_list[ind][1]}", time_format)
        time_diff = (datetime2 - datetime1)/365
        days_difference = time_diff.days + time_diff.seconds / (24 * 3600)
        X_1 += max(0.5 ** days_difference, 0.9 ** (N-1 - ind)) * int(time_list[ind][2])
        X_2 += max(0.5 ** days_difference, 0.9 ** (N-1 - ind))
    print(round((X_1/X_2), 0))