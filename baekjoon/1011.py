import sys
n = int(input())


def arithmetic_sequence_with_common_difference_1(n):
    """공차가 1인 등차수열을 생성하는 함수"""
    sequence = [i for i in range(n + 1)]
    return sum(sequence)


for i in range(n):
    x, y = list(map(int, sys.stdin.readline().split()))
    distance = y-x
    if 1 <= distance <= 2:
        print(distance)
    elif 3 <= distance <= 6:
        print()
    
    for i in range(2, y):
        if 3 + i ** 2 <= distance <= 3 + (i + 1) ** 2 - 1:
            print(i + 1)
            break
