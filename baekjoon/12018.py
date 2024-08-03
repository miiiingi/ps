import sys
n, m = map(int, sys.stdin.readline().split())
answer = []
cnt = 0 
for _ in range(n):
    p, l = map(int, sys.stdin.readline().split())
    p_list = sorted(list(map(int, sys.stdin.readline().split())))
    if p >= l:
        answer.append(p_list[l-2])
    else:
        answer.append(1)
answer = sorted(answer)
for i in range(m):
    m -= answer[i]
    if m < 0:
        break
    cnt += 1
print(cnt)
