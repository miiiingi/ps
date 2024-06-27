import sys
X, Y = map(int, sys.stdin.readline().split())
Z = (Y * 100) // X
start = 0
end = X
p_list = []
while start <= end:
    uX = (start + end) // 2
    new_Z = (Y + uX) * 100 // (X + uX)
    if new_Z > Z:
        res = uX
        end = uX - 1
    else:
        start = uX + 1
else:
    if Z >= 99:
        print(-1)
    else:
        print(res)