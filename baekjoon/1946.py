import sys
T = int(sys.stdin.readline())
answer = [] 
for _ in range(T):
    N = int(sys.stdin.readline())
    people_list = []
    for _ in range(N):
        people_list.append(list(map(int, sys.stdin.readline().split())))
    people_list = sorted(people_list, key=lambda x: (x[0], x[1]))
    defacto = None
    cnt = 0
    for idx in range(len(people_list)):
        if defacto is None:
            defacto = people_list[idx]
            cnt += 1
        else:
            if defacto[0] < people_list[idx][0] and defacto[1] < people_list[idx][1]:
                continue
            defacto = people_list[idx]
            cnt += 1
    answer.append(cnt)
for a in answer:
    print(a)
