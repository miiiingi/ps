import sys
import itertools
N, M = map(int, sys.stdin.readline().split())
cards = list(map(int, sys.stdin.readline().split()))
right_case = []
for card in list(itertools.combinations(cards, 3)):
    if sum(card) <= M:
        right_case.append(sum(card))
print(max(right_case))
