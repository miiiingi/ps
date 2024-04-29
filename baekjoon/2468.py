import sys
sys.setrecursionlimit(12345678)
N = int(sys.stdin.readline())
region = []
max_number = 0
count_list = []
for _ in range(N):
    numbers = list(map(int, sys.stdin.readline().split()))
    if max(numbers) > max_number:
        max_number = max(numbers)
    region.append(numbers)
for r in range(max_number+1):
    new_region = []
    count = 0
    for numbers in region:
        new_region.append([0 if number <= r else number for number in numbers])
    def dfs(i, j):
        if i < 0 or i >= len(new_region) or j < 0 or j >= len(new_region) or new_region[i][j] == 0:
            return
        new_region[i][j] = 0
        dfs(i-1, j)
        dfs(i+1, j)
        dfs(i, j-1)
        dfs(i, j+1)

    for i in range(len(new_region)):
        for j in range(len(new_region[i])):
            if new_region[i][j] == 0:
                continue
            else:
                dfs(i, j)
                count += 1
    count_list.append(count)
print(max(count_list))