import sys
size = int(input())
num_list = list(map(int, sys.stdin.readline().split()))
D = [0 for _ in range(size)]
for i in range(len(num_list)):
    ind_list = [0]
    for j in range(0, i):
        if num_list[j] < num_list[i]:
            ind_list.append(D[j])
    D[i] = max(ind_list) + 1
print(max(D))
