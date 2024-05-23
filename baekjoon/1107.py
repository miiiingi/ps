import sys
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
if M > 0:
    deleted = list(map(int, sys.stdin.readline().split()))
else:
    deleted = []
if N == 100:
    print(0)
else:
    numbers = list(set([num for num in range(0, 10)]) - set(deleted))
    answer = ''
    for num in list(str(N)):
        min_number = 10
        min_index = None
        if int(num) == 0 and min_number > 0:
            num = 10
        else:
            num = int(num)
        for i in range(len(numbers)):
            if abs(int(num) - numbers[i]) < min_number:
                min_number = int(num) - numbers[i]
                min_index = i
        answer += str(numbers[min_index])
    print(len(answer) + abs(N - int(answer)))