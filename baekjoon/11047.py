import sys
N, K = map(int, sys.stdin.readline().split())
coin_list = []
answer = 0
for _ in range(N):
    coin = int(sys.stdin.readline())
    coin_list.append(coin)
for c in coin_list[::-1]:
    if K // c != 0:
        answer += K // c
        K -= c * (K // c)
    else:
        continue
print(answer)