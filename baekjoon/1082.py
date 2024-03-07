import sys
N = int(sys.stdin.readline())
p_list = list(map(int, sys.stdin.readline().split()))
answer = []
M = int(sys.stdin.readline())
if N > 1:
    local_min = min(p_list[1:])
    global_min = min(p_list)
elif N == 1:
    local_min = min(p_list)
    global_min = min(p_list)
if M < local_min:
    print(0)
else:
    answer.append(p_list.index(local_min))
    M -= local_min
    while True:
        if M < global_min:
            break
        answer.append(p_list.index(global_min))
        M -= global_min
    for i in range(len(answer)):
        for j in range(len(p_list))[::-1]:
            diff = p_list[j] - p_list[answer[i]]
            if diff >= 0 and M >= diff:
                answer[i] = j
                M -= diff
                break
    print(int(''.join(str(x) for x in answer)))
