# 하나씩 숫자를 비교하면서 만들어가려고 했는데, 반복문 안의 숫자를 비교해서 끝내면 된다!!
# 역시 효율적인 문제 접근 방식을 더 생각해봐야할 듯! 먼저 구현하려고 하지 말고!
import sys
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
if M > 0:
    deleted = list(map(int, sys.stdin.readline().split()))
else:
    deleted = []
min_num = abs(100 - N)
if N == 100:
    print(0)
else:
    for num in range(1000001):
        str_num = str(num)
        for digit in str_num:
            if int(digit) in deleted:
                break
        else:
            # 모든 숫자를 비교하지 말고, 마지막 끝자리 숫자인 경우만 min 값을 계산하고 비교하여 업데이트 하자!
            if digit == str_num[-1]:
                min_num = min(min_num, abs(num - N) + len(str_num))
    print(min_num)