# 항상 모든 것을 다 구현하려고 하지말고 문제 풀이에 필요한 과정을 잘 생각해보고 그것을 어떻게하면 가장 효율적으로 풀지 생각해야함
# 괄호 문제 풀 때 카운터 변수를 잘 생각해보자!
import sys
input = sys.stdin.readline

N = int(input())
S = input().rstrip()
min_day = 0
total = 0
for char in S:
    if char == '(':
        total += 1
    else:
        total -= 1
    if abs(total) > min_day:
        min_day = abs(total)
if total == 0:
    print(min_day)
else:
    print(-1)