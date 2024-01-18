import copy
n = input()
cnt = 0
old_n = copy.deepcopy(n)
while True:
    num = 0
    if int(n) < 10:
        n = '0' + n
        num += int(n)
    else:
        for nn in n:
            num += int(nn)
    new_n = str(num)
    n = n[-1] + new_n[-1]
    cnt += 1
    if int(old_n) == int(n):
        print(cnt)
        break